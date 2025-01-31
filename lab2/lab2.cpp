#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Matrix {
public:
    int data[10][10]; 
    int target_row_idx;
    int maximum;
    int minimum;

    void print_mat(){
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << data[i][j] << "\t"; // Print each element
            }
            cout << "\n"; // New line for each row
        }
    }

    Matrix mat_add(Matrix mat2){
        Matrix sum_mat;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                sum_mat.data[i][j] = data[i][j] + mat2.data[i][j];
            }
        }
        return sum_mat;
    }

    Matrix mat_mult(Matrix mat2){
        Matrix product_mat;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 10; k++){
                    product_mat.data[i][j] = product_mat.data[i][j] + data[i][k] + mat2.data[k][j]
                }
            }
        }
        return product_mat;
    }
};

// referred to this website on how to use fstream to pull info from text files https://www.w3schools.com/cpp/ref_fstream_ifstream.asp

int main(){
    ifstream file1("matrix_1.txt");
    ifstream file2("matrix_2.txt");

    Matrix matrix1;
    Matrix matrix2; 
    Matrix sum_mat1_mat2;
    Matrix mult_mat1_mat2;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            file1 >> matrix1.data[i][j];
            file2 >> matrix2.data[i][j]; 
        }
    }

    sum_mat1_mat2 = matrix1.mat_add(matrix2);
    mult_mat1_mat2 = matrix1.mat_mult(matrix2);

    cout<<"matrix1: \n";
    matrix1.print_mat();
    cout<<"\n";
    cout<<"matrix2: \n";
    matrix2.print_mat();
    cout<<"\n";
    cout<<"sum of matrix 1 and 2: \n";
    sum_mat1_mat2.print_mat();
    cout<<"\n product of matrix 1 and 2: \n";
    mult_mat1_mat2.print_mat();


    return 0;
}
