#include <iostream>
#include <ifstream>
#include <sstream>
#include <string>
using namespace std;

class Matrix {
    int data[10][10]; 
    int target_row_idx = 0;
    int maximum = 0;
    int minimum = 0;

    void linear_search();
    void mat_add(mat1, mat2);
    void mat_mult(mat1, mat2);
}

// https://www.w3schools.com/cpp/ref_fstream_ifstream.asp

int main(){
    ifstream file1("matrix_1.txt");
    ifstream file2("matrix_2.txt");

    Matrix matrix1;
    Matrix matrix2; 

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < size; j++){
            file1 >> matrix1[i][j];
            file2 >> matrix2[i][j]; 
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << "\t"; // Print each element
        }
        cout << "\n"; // New line for each row
    }

    return 0;
}
