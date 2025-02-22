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
    int temp = a;
    a = b;
    b = temp;
}

// Function to swap two integers using pass-by-reference (modifies values)
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to modify array: Double each value (using pass-by-pointer)
void doubleValues(int* arr, int size) {
    for(int i = 0; i < size; i++){
        *(arr+i) *= 2;
    }
}

// Function to compute sum and product using pass-by-reference
void computeSumAndProduct(int* arr, int size, int &sum, int &product) {
    for(int i = 0; i < size; i++){
        sum += *(arr+i);
        product *= *(arr+i);
    }
}

// Function to reverse an array using pointers (without array indexing)
void reverseArray(int* arr, int size) {
    if(size == 1 || size == 0){
        
    }
    else{
        int temp;
        if(size%2 == 0){
            for(int i = 0; i < size/2; i++){
                temp = *(arr+i);
                *(arr+i) = *(arr+size-i-1);
                *(arr+size-i-1) = temp;
            }
        }
        else{
            for(int i = 0; i < (size-1)/2; i++){
                temp = *(arr+i);
                *arr = *(arr+size-i-1);
                *(arr+size-i-1) = temp;
            }
        }
    }
    
}

// Main function
int main(int argc, char* argv[]) {

    
    // Convert command-line arguments to integers
    int* array = new int[argc];
    int size = argc - 1;
    for(int i = 0; i < size; i++){
        array[i] = atoi(argv[i+1]);
    }

    // Open output file
    ofstream output("output_Q2.txt");

    // Print original array
    output << "Original Numbers: ";
    for(int i = 0; i < size; i++){
        output << array[i] << " ";
    }
    output << endl << endl;

    // Extract command-line arguments using pointer-to-pointer
    extractCommandLineArgs(argc, argv, output);

    // Demonstrate pass-by-value (no effect)
    swapByValue(array[0], array[1]);
    output << endl << "Pass-by-Value Swap (No Effect):"<< endl;
    output << "\t" << "Swap("<<array[0]<<", "<<array[1]<<") -> a = "<<array[0]<<", b = "<< array[1] << " (Unchanged)" << endl << endl;
    
    // Demonstrate pass-by-reference (modifies values)
    swapByReference(array[0], array[1]);
    output << "Pass-by-Reference Swap (Successful):"<< endl;
    output << "\t" << "Swap("<<array[0]<<", "<<array[1]<<") -> a = "<<array[0]<<", b = "<< array[1] << endl << endl;

    // Modify array (double values using pointer)
    doubleValues(array, size); // Fill in the arguments
    output << "Pass-by-Pointer Modification:" << endl;
    output << "\t" << "Doubled Values: ";
    for(int i = 0; i < size; i++){
        output << array[i] << " ";
    }
    output << endl << endl;
    
    // Compute sum and product
    int sum = 0, product = 1;
    computeSumAndProduct(array, size, sum, product); // Fill in the arguments
    output << "Sum of Numbers: " << sum << endl;
    output << "Product of Numbers: " << product << endl;
    
    // Reverse array
    reverseArray(array, size); // Fill in the arguments
    output << "Reversed Order: ";
    for(int i = 0; i < size; i++){
        output << array[i] << " ";
    }
    
    delete [] array;
    return 0;
}
