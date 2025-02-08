#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

// used the following website for vectors: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/


class Matrix {
  public:
    int original_size;
    int new_size;
    vector<vector<int> > data;

    // constructor to change size of matrix on declaration, fills the intial matrix with zeros
    Matrix(int og_size){
      original_size = og_size;
      new_size = modifySize(og_size);
      data.resize(new_size, vector<int>(new_size,0));
    }

    // helper function to check if the size is a power of two
    bool isPowerOfTwo(int n){
      if(n <= 0){
        return false;
      }
      while(n % 2 == 0){
        n = n/2;
      }
      return(n == 1);
    }

    // changing size of matrix to be power of two
    int modifySize(int size){
      int modified_size = 1;
      if( isPowerOfTwo(size) == false){
        while(modified_size < size){
          modified_size = modified_size * 2;
        }
      }
      else{
        return size;
      }
      return modified_size;
    }

    // read data from input.txt and fill matrices
    void fillMatrix(istream& file){
      for(int i = 0; i < original_size; i++){
        for(int j = 0; j < original_size; j++){
          file >> data[i][j];
        }
      }
    }

    // output matrix data into text files using fstream
    void printMatrix(ostream& file){
      for (int i = 0; i < original_size; i++) {
          for (int j = 0; j < original_size; j++) {
              file << data[i][j] << " ";
          }
          file << endl;
      }
    }

    // matrix addition helper function
    static Matrix matAdd( const Matrix& A, const Matrix& B, int size){
      Matrix C(size);
      for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
          C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
      }
      return C;
    }

    // matrix subtraction helper function
    static Matrix matSub(const Matrix& A, const Matrix& B, int size){
      Matrix C(size);
      for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
          C.data[i][j] = A.data[i][j] - B.data[i][j];
        }
      }
      return C;
    }

    // Q1: Divide and conquer method of matrix multiplication
    static Matrix divAndConq(Matrix A, Matrix B, int size){
      Matrix C(size);
      // case 1: the matrix is a single element and no division necessary
      if( size == 1){
        C.data[0][0] = A.data[0][0] * B.data[0][0];
      }
      // case 2: the matrix has either been divided as small as possible or was already a 2x2
      else if( size == 2){
        for(int i = 0; i < size; i++){
          for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
              C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
          }
        }
      }
      // case 3: the matrix is larger and must be divided into smaller submatrices and multiplied recursively
      else{

        // creating submatrices with dimensions half as large as the original matrix
        int half = size/2;
        Matrix A11(half), A12(half), A21(half), A22(half), B11(half), B12(half), B21(half), B22(half);

        // loading data from original matrix into smaller matrices
        for(int i = 0; i < half; i++){
          for (int j = 0; j < half; j++){
            A11.data[i][j] = A.data[i][j];
            A12.data[i][j] = A.data[i][j+half];
            A21.data[i][j] = A.data[i+half][j];
            A22.data[i][j] = A.data[i+half][j+half];

            B11.data[i][j] = B.data[i][j];
            B12.data[i][j] = B.data[i][j+half];
            B21.data[i][j] = B.data[i+half][j];
            B22.data[i][j] = B.data[i+half][j+half];
          }
        }

        // multiply the submatrices
        Matrix C11 = matAdd(divAndConq(A11, B11, half), divAndConq(A12, B21, half), half);
        Matrix C12 = matAdd(divAndConq(A11, B12, half), divAndConq(A12, B22, half), half);
        Matrix C21 = matAdd(divAndConq(A21, B11, half), divAndConq(A22, B21, half), half);
        Matrix C22 = matAdd(divAndConq(A21, B12, half), divAndConq(A22, B22, half), half);

        // recombine the submatrices
        for(int i = 0; i < half; i++){
          for(int j = 0; j < half; j++){
            C.data[i][j] = C11.data[i][j];
            C.data[i][j + half] = C12.data[i][j];
            C.data[i+half][j] = C21.data[i][j];
            C.data[i+half][j+half] = C22.data[i][j];
          }
        }
      }

      return C;
    }

    // Q2: Strassen's Method (note: case 1 and 2 are exact same, parts of case 3 are the exact same)
    static Matrix strassen(Matrix A, Matrix B, int size){
      Matrix C(size);
      // case 1: the matrix is a single element and no division necessary
      if( size == 1){
        C.data[0][0] = A.data[0][0] * B.data[0][0];
      }
      // case 2: the matrix has either been divided as small as possible or was already a 2x2
      else if( size == 2){
        for(int i = 0; i < size; i++){
          for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
              C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
          }
        }
      }
      // case 3: the matrix is larger and must be divided into smaller submatrices and multiplied recursively
      else{
        // creating submatrices with dimensions half as large as the original matrix
        int half = size/2;
        Matrix A11(half), A12(half), A21(half), A22(half), B11(half), B12(half), B21(half), B22(half);

        // loading data from original matrix into smaller matrices
        for(int i = 0; i < half; i++){
          for (int j = 0; j < half; j++){
            A11.data[i][j] = A.data[i][j];
            A12.data[i][j] = A.data[i][j+half];
            A21.data[i][j] = A.data[i+half][j];
            A22.data[i][j] = A.data[i+half][j+half];

            B11.data[i][j] = B.data[i][j];
            B12.data[i][j] = B.data[i][j+half];
            B21.data[i][j] = B.data[i+half][j];
            B22.data[i][j] = B.data[i+half][j+half];
          }
        }

        // strassen calculation: defining 7 new matrices
        Matrix M1 = strassen(matAdd(A11, A22, half), matAdd(B11,B22, half), half);
        Matrix M2 = strassen(matAdd(A21, A22, half), B11, half);
        Matrix M3 = strassen(A11, matSub(B12, B22, half), half);
        Matrix M4 = strassen(A22, matSub(B21,B11,half), half);
        Matrix M5 = strassen(matAdd(A11,A12,half), B22, half);
        Matrix M6 = strassen(matSub(A21, A11, half), matAdd(B11,B12,half), half);
        Matrix M7 = strassen(matSub(A12,A22,half), matAdd(B21,B22,half), half);

        // strassen calculation calculating target matrix C
        Matrix C11 = matAdd(matSub(matAdd(M1, M4, half), M5, half), M7, half);
        Matrix C12 = matAdd(M3, M5, half);
        Matrix C21 = matAdd(M2, M4, half);
        Matrix C22 = matAdd(matSub(matAdd(M1, M3, half), M6, half), M2, half);

        // combing target matrix's submatrices
        for(int i = 0; i < half; i++){
          for(int j = 0; j < half; j++){
            C.data[i][j] = C11.data[i][j];
            C.data[i][j + half] = C12.data[i][j];
            C.data[i+half][j] = C21.data[i][j];
            C.data[i+half][j+half] = C22.data[i][j];
          }
        }
      }
      return C;
    }
};

int main(){
  // open text file
  ifstream file("input.txt");
  ofstream output1("output_m1.txt");
  ofstream output2("output_m2.txt");
  ofstream output3("output_q3.txt");

  // read matrix size from text file
  int og_size; 
  file >> og_size;

  // allocating memory for matrices, then reading the data from text file
  Matrix matrix1(og_size);
  Matrix matrix2(og_size);

  matrix1.fillMatrix(file);
  matrix2.fillMatrix(file);

  // variables used to time both methods
  time_t start1, end1, start2, end2;

  // calculating matrix1 * matrix2 using the divide and conquer method
  start1 = clock();
  Matrix matrix3 = Matrix::divAndConq(matrix1, matrix2, matrix1.new_size);
  end1 = clock();
  matrix3.original_size = og_size;
  matrix3.printMatrix(output1);

  // calculating matrix1 * matrix2 using straussen's method
  start2 = clock();
  Matrix matrix4 = Matrix::strassen(matrix1, matrix2, matrix1.new_size);
  end2 = clock();
  matrix4.original_size = og_size;
  matrix4.printMatrix(output2);

  // outputting times
  int time1 = end1 - start1;
  int time2 = end2 - start2;
  output3 << time1 << " " << time2;
}
