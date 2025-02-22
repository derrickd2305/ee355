#include <iostream>
#include <fstream>
#include <cstdlib> // for atoi
using namespace std;

// Function to extract and display command-line arguments using pointer-to-pointer
void extractCommandLineArgs(int argc, char** argv, ofstream &outputFile) {
    outputFile << "Extracted Command-Line Arguments:\n";
    for(int i = 0; i < argc; i++){
        outputFile << "\t" << "argv[" << i << "] = " << *(argv+i) << endl;
    }
}

// Function to swap two integers using pass-by-value (no effect)
void swapByValue(int a, int b) {
    
}

// Function to swap two integers using pass-by-reference (modifies values)
void swapByReference(int &a, int &b) {
    
}

// Function to modify array: Double each value (using pass-by-pointer)
void doubleValues(int* arr, int size) {
    
}

// Function to compute sum and product using pass-by-reference
void computeSumAndProduct(int* arr, int size, int &sum, int &product) {
    
}

// Function to reverse an array using pointers (without array indexing)
void reverseArray(int* arr, int size) {
    
}

// Main function
int main(int argc, char* argv[]) {

    
    // Convert command-line arguments to integers
    int* array = new int[argc];
    for(int i = 0; i < argc-1; i++){
        array[i] = atoi(argv[i+1]);
    }

    // Open output file
    ofstream output("output_Q2.txt");

    // Print original array
    output << "Original Numbers: ";
    for(int i = 0; i < argc-1; i++){
        output << array[i] << " ";
    }
    output << endl;

    // Extract command-line arguments using pointer-to-pointer
    extractCommandLineArgs(argc, argv, output); // Fill in the arguments

    // Demonstrate pass-by-value (no effect)

    // swapByValue(); // Fill in the arguments
    
    // Demonstrate pass-by-reference (modifies values)
    // swapByReference(); // Fill in the arguments
    
    // Modify array (double values using pointer)
    // doubleValues(); // Fill in the arguments
    

    // Compute sum and product
    // computeSumAndProduct(); // Fill in the arguments
    
    // Reverse array
    // reverseArray(); // Fill in the arguments
    
    return 0;
}
