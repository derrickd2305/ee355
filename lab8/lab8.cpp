#include "lodepng.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// A simple class to handle PNG images
class PNGImage {
public:
    std::vector<unsigned char> image; // stores image data in RGBA format
    unsigned width, height;

    PNGImage() : width(0), height(0) {}

    // Load a PNG file into the image vector.
    bool load(const std::string &filename) {
        unsigned error = lodepng::decode(image, width, height, filename);
        if(error){
            cout << "Error loading png: " << lodepng_error_text(error) << endl;
            return false;
        }
        return true;
    }

    // Save the image vector into a PNG file.
    bool save(const std::string &filename) {
        unsigned error = lodepng::encode(filename, image, width, height);
        if(error){
            cout << "Error encoding png: " << lodepng_error_text(error) << endl;
            return false;
        }
        return true;
    }
};

// Function to apply a tint by scaling the red, green, and blue channels.
void tintImage(std::vector<unsigned char>& image, double rFactor, double gFactor, double bFactor) {
	// data is stored in a 1D array with format RGBA, so we increment by 4 each time for each pixel
    for(int i = 0; i < image.size(); i = i+4){
        image[i] = min(255.0, image[i]*rFactor);      //R
        image[i+1] = min(255.0, image[i+1]*gFactor);  //G
        image[i+2] = min(255.0, image[i+2]*bFactor);  //B
    }
}

// Function to invert the image colors.
void invertImage(std::vector<unsigned char>& image) {
    for(int i = 0; i < image.size(); i = i+4){
        image[i] = 255 - image[i];          //R
        image[i+1] = 255 - image[i+1];      //G
        image[i+2] = 255 - image[i+2];      //B
    }
}

// Function to add Gaussian noise to the image.
void addGaussianNoise(std::vector<unsigned char>& image, double mean, double stddev) {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d(mean, stddev);
    // iterate across every pixel, every RGB value
    for(int i = 0; i < image.size(); i += 4){
        for(int j = 0; j < 3; j++){
            // add noise, using int variable to prevent overflow
            int noisyPixel = static_cast<int>(image[i+j]) + round(d(gen));
            // make sure value is still between 0-255
            image[i+j] = static_cast<unsigned char>(max(0, min(255, noisyPixel)));
        }
    }
}

// Function to add salt-and-pepper noise to the image.
void addSaltPepperNoise(std::vector<unsigned char>& image, double noiseRatio) {
    size_t totalPixels = image.size() / 4;
    size_t numNoisy = static_cast<size_t>(totalPixels * noiseRatio);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, totalPixels - 1);
    for(int i = 0; i < numNoisy; i++){
        // index of the random pixel, starting at R
        int randomPixel = dis(gen) * 4;
        // black pixels
        if(rand() % 2 == 0){
            for(int j = 0; j < 3; j++){
                image[randomPixel + j] = 255;
            }
        }
        // white pixels
        else{
            for(int j = 0; j < 3; j++){
                image[randomPixel + j] = 0;
            }
        }
    }    
}

// Function to zoom the image using nearest-neighbor interpolation.
std::vector<unsigned char> zoomImage(const std::vector<unsigned char>& image, unsigned width, unsigned height, double scale, unsigned &newWidth, unsigned &newHeight) {
	// calculate size of zoomed in image
    newHeight = round(height * scale);
    newWidth = round(width * scale);
    // create vector to store new image, with 4 elements per pixel
    std::vector<unsigned char> zoomed(newWidth*newHeight*4);
    // iteratre over every pixel
    for(int i = 0; i < newHeight; i++){
        for(int j = 0; j < newWidth; j++){
            // calculate pixel's index in original array
            unsigned int origI = floor(i / scale);
            unsigned int origJ = floor(j / scale);
            unsigned int origIndex = (origI * width + origJ) * 4;
            // calculate pixel's new index
            unsigned int newIndex = (i * newWidth + j) * 4;

            // copy RGBA from original image
            for(int k = 0; k < 4; k++){
                zoomed[newIndex+k] = image[origIndex + k];
            }

        }
    }
    return zoomed;
}

// Function to apply a glass effect.
// For each pixel, a nearby random pixel (within a specified radius) is used.
std::vector<unsigned char> glassEffect(const std::vector<unsigned char>& src, unsigned width, unsigned height, int radius) {
    std::vector<unsigned char> dst(src.size());
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-radius, radius);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // randomly generate an offset for both dimensions
            int newI = i + dis(gen);
            int newJ = j + dis(gen);

            // ensure we stay within bounds
            newI = max(0, min((newI), static_cast<int>(height) - 1));
            newJ = max(0, min(newJ, static_cast<int>(width) - 1));

            // calculate the new index
            int newIndex = (newI * width + newJ) * 4;

            // the actual location of the pixel
            int ogIndex = (i * width + j) * 4;

            // for each RGBA
            for(int k = 0; k < 4; k++){
                dst[ogIndex + k] = src[newIndex + k];
            }
        }
    }
    return dst;
}

// Function to perform edge detection using a Sobel-like operator.
// The image is converted to grayscale and the edge magnitude is computed.
std::vector<unsigned char> edgeDetection(const std::vector<unsigned char>& src, unsigned width, unsigned height) {
    std::vector<unsigned char> dst(src.size(), 255); // Initialize with white pixels.
    std::vector<unsigned char> gray(width * height, 0);
    // Convert to grayscale.
    for(int i = 0; i < src.size(); i+=4){
        // weighted sum to calculate grayscale value
        float grayscale = 0.299 * src[i] + 0.587 * src[i+1] + 0.114 * src[i+2];
        // casting
        unsigned char roundedGrayscale = static_cast<unsigned char>(round(grayscale));
        // copying that value
        gray[i/4] = roundedGrayscale;
    }

    // Apply a simple Sobel operator.
    for (unsigned y = 1; y < height - 1; y++) {
        for (unsigned x = 1; x < width - 1; x++) {
            int gx = -gray[(y-1)*width + (x-1)] + gray[(y-1)*width + (x+1)]
                     -2 * gray[y*width + (x-1)] + 2 * gray[y*width + (x+1)]
                     -gray[(y+1)*width + (x-1)] + gray[(y+1)*width + (x+1)];
            int gy = -gray[(y-1)*width + (x-1)] - 2 * gray[(y-1)*width + x] - gray[(y-1)*width + (x+1)]
                     + gray[(y+1)*width + (x-1)] + 2 * gray[(y+1)*width + x] + gray[(y+1)*width + (x+1)];
            int edgeVal = std::min(255, abs(gx) + abs(gy));
            size_t dstIndex = (y * width + x) * 4;
            dst[dstIndex]   = edgeVal;
            dst[dstIndex+1] = edgeVal;
            dst[dstIndex+2] = edgeVal;
            dst[dstIndex+3] = 255;
        }
    }
    return dst;
}

// Function to smooth the image using a simple 3x3 average filter.
std::vector<unsigned char> smoothImage(const std::vector<unsigned char>& src, unsigned width, unsigned height) {
    std::vector<unsigned char> dst(src.size());
    // iterate across each pixel
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // the index of the pixel in the smoothed image
            int index = (i * width + j) * 4;
            // edge pixels remain the same
            if(i == 0 || j == 0 || i == height-1 || j == width - 1){
                for(int k = 0; k < 4; k++){
                    dst[index + k] = src[index + k];
                }
                continue;
            }
            // create variables to store averages for RGBA
            float avgR = 0, avgG = 0, avgB = 0, avgA = 0;
            // iterate across the 3x3 area around each pixel
            for(int subHeight = -1; subHeight < 2; subHeight++){
                for(int subWidth = -1; subWidth < 2; subWidth++){
                    // calculate the index for each pixel in the 3x3 grid
                    int smoothI = i + subHeight;
                    int smoothJ = j + subWidth;
                    int smoothIndex = (smoothI * width + smoothJ) * 4;

                    // find the average of the RGBA values within the 3x3 grid
                    avgR += src[smoothIndex]/9.0;
                    avgG += src[smoothIndex + 1]/9.0;
                    avgB += src[smoothIndex + 2]/9.0;
                    avgA += src[smoothIndex + 3]/9.0;
                }
            }
            // assigning the values of the pixel in the smoothed image
            dst[index] = static_cast<unsigned char>(avgR);
            dst[index+1] = static_cast<unsigned char>(avgG);
            dst[index+2] = static_cast<unsigned char>(avgB);
            dst[index+3] = static_cast<unsigned char>(avgA);
        }
    }
    return dst;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: png_lab <input_png_file>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    PNGImage img;
    if (!img.load(inputFile)) {
        cerr << "Error: Could not load the image file." << endl;
        return 1;
    }

    // Create copies of the image data for each operation.
    vector<unsigned char> tinted       = img.image;
    vector<unsigned char> inverted     = img.image;
    vector<unsigned char> gaussianNoisy = img.image;
    vector<unsigned char> spNoisy       = img.image;

    // Apply tint: Increase the red channel.
    tintImage(tinted, 1.2, 1.0, 1.0);

    // Invert colors.
    invertImage(inverted);

    // Add Gaussian noise (mean=0, stddev=30).
    addGaussianNoise(gaussianNoisy, 0.0, 30.0);

    // Add salt-and-pepper noise (affect 5% of pixels).
    addSaltPepperNoise(spNoisy, 0.05);

    // Zoom the image by a factor of 1.5.
    unsigned newWidth, newHeight;
    vector<unsigned char> zoomed = zoomImage(img.image, img.width, img.height, 1.5, newWidth, newHeight);

    // Apply glass effect with a displacement radius of 3.
    vector<unsigned char> glass = glassEffect(img.image, img.width, img.height, 3);

    // Perform edge detection.
    vector<unsigned char> edges = edgeDetection(img.image, img.width, img.height);

    // Smooth the image using a 3x3 average.
    vector<unsigned char> smooth = smoothImage(img.image, img.width, img.height);

    // Save all output images.
    PNGImage outImg;
    outImg.width = img.width;
    outImg.height = img.height;

    outImg.image = tinted;
    outImg.save("tinted.png");

    outImg.image = inverted;
    outImg.save("inverted.png");

    outImg.image = gaussianNoisy;
    outImg.save("gaussian_noisy.png");

    outImg.image = spNoisy;
    outImg.save("saltpepper_noisy.png");

    outImg.image = zoomed;
    outImg.width = newWidth;
    outImg.height = newHeight;
    outImg.save("zoomed.png");

    outImg.image = glass;
    outImg.width = img.width;
    outImg.height = img.height;
    outImg.save("glass.png");

    outImg.image = edges;
    outImg.width = img.width;
    outImg.height = img.height;
    outImg.save("edge.png");

    outImg.image = smooth;
    outImg.width = img.width;
    outImg.height = img.height;
    outImg.save("smooth.png");

    cout << "Processing completed. Check the output PNG files." << endl;
    return 0;
}
