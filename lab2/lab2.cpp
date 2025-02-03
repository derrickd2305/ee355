#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Matrix {
public:
    int data[10][10]; 
    int target_row;
    int max;
    int max_row;
    int min;
    int min_row;

    void print_mat(ostream &output){
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                output << data[i][j] << "\t"; // Print each element
            }
            output << "\n"; // New line for each row
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

    ofstream output1_1("output_Q1_1.txt");
    ofstream output1_2("output_Q1_2.txt");
    ofstream output2("output_Q2.txt");
    ofstream output3("output_Q3.txt");

    Matrix matrix1;
    Matrix matrix2; 
    Matrix sum_mat1_mat2;
    Matrix mult_mat1_mat2;

    matrix1.target_row = -1;
    matrix2.target_row = -1;

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


    // output for Q1.1
    output1_1 << "Matrix 1: \n";
    if(matrix1.target_row == -1){
        output1_1 << "first value is not repeated" << endl;
    }
    else{
        output1_1 << "first value reappears at row " << matrix1.target_row << endl; 
    }
    output1_1 << "max: " << matrix1.max << " at row " << matrix1.max_row << endl;
    output1_1 << "min: " << matrix1.min << " at row " << matrix1.min_row << endl;

    // output for Q1.2 
    output1_2 << "Matrix 2: \n";
    if(matrix2.target_row == -1){
        output1_2 << "first value is not repeated" << endl;
    }
    else{
        output1_2 << "first value reappears at row " << matrix2.target_row << endl; 
    }
    output1_2 << "max: " << matrix2.max << " at row " << matrix2.max_row << endl;
    output1_2 << "min: " << matrix2.min << " at row " << matrix2.min_row << endl;

    // output for Q2
    output2 << "sum of matrix 1 and matrix 2: \n";
    sum_mat1_mat2.print_mat(output2);

    // output for Q3
    output3 << "product of matrix 1 and matrix 2 \n";
    mult_mat1_mat2.print_mat(output3);

    
    // THE FOLLOWING CODE WAS USED TO PRINT TO TERMINAL FOR TROUBLESHOOTING AND VERIFYING RESULTS

    /*
    cout<<"matrix1: \n";
    matrix1.print_mat();
    cout<<"\n";
    
    cout << "max: " << matrix1.max << " at row " << matrix1.max_row << endl;
    cout << "min: " << matrix1.min << " at row " << matrix1.min_row << endl;
    if(matrix1.target_row == -1){
        cout << "first value is not repeated";
    }
    else{
        cout << "first value reappears at row: " << matrix1.target_row << endl; 
    }
    
    cout<<" \n matrix2: \n";
    matrix2.print_mat();
    cout<<"\n";

    cout << "max: " << matrix2.max << " at row " << matrix2.max_row << endl;
    cout << "min: " << matrix2.min << " at row " << matrix2.min_row << endl;
    if(matrix2.target_row == -1){
        cout << "first value is not repeated";
    }
    else{
        cout << "first value reappears at row: " << matrix2.target_row << endl; 
    }
    
    cout<<"\n sum of matrix 1 and 2: \n";
    sum_mat1_mat2.print_mat();
    cout<<"\n product of matrix 1 and 2: \n";
    mult_mat1_mat2.print_mat();
    */
    


    return 0;
}
