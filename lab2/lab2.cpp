#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Matrix {
public:
    int data[10][10]; 
    int target_row = -1;
    int max;
    int max_row;
    int min;
    int min_row;

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
               product_mat.data[i][j] = 0;
                for(int k = 0; k < 10; k++){
                    product_mat.data[i][j] = product_mat.data[i][j] + data[i][k] * mat2.data[k][j];
                }
            }
        }
        return product_mat;
    }

    void linear_search(){
        int first_num = data[0][0];
        max = data[0][0];
        min = data[0][0];
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(max < data[i][j]){
                    max = data[i][j];
                    max_row = i;
                }
                if(min > data[i][j]){
                    min = data[i][j];
                    min_row = i;
                }
                if(i == 0 && j == 0){
                    continue;
                }
                if(first_num == data[i][j]){
                    target_row = i; 
                }
            }
        }
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

    matrix1.linear_search();
    matrix2.linear_search();

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

    cout << "matrix1: max: " << matrix1.max << " at row " << matrix1.max_row << endl;
    cout << "matrix2: min: " << matrix2.min << " at row " << matrix2.min_row << endl;
    if(matrix1.target_row == -1){
        cout << "first value is not repeated";
    }
    else{
        cout << "first value reappears at row: " << matrix1.target_row << endl; 
    }


    return 0;
}
