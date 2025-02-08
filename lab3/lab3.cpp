#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// used the following website for vectors: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/


class Matrix {
  public:
    int original_size;
    int new_size;
    vector<vector<int> > data;

    // constructor
    Matrix(int og_size){
      original_size = og_size;
      new_size = modifySize(og_size);
      data.resize(new_size, vector<int>(new_size,0));
    }

    bool isPowerOfTwo(int n){
      if(n <= 0){
        return false;
      }
      while(n % 2 == 0){
        n = n/2;
      }
      return(n == 1);
    }

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

    void fillMatrix(istream& file){
      for(int i = 0; i < original_size; i++){
        for(int j = 0; j < original_size; j++){
          file >> data[i][j];
        }
      }
    }

    void printMatrix() const {
      for (int i = 0; i < new_size; i++) {
          for (int j = 0; j < new_size; j++) {
              cout << data[i][j] << " ";
          }
          cout << endl;
      }
    }

    static Matrix matAdd(Matrix &A, Matrix &B, int size){
      Matrix C(size);
      for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
          C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
      }
      return C;
    }

    static Matrix divAndConq(Matrix &A, Matrix &B, int size){
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
              C.data[i][j] += A.data[i][k] + B.data[k][j];
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
            C.data[i][j] = C11[i][j];
            C.data[i][j + half] = C12[i][j];
            C.data[i+half][j] = C21[i][j];
            C.data[i+half][j+half] = C22[i][j];
          }
        }
      }

      return C;
    }
};

int main(){
  ifstream file("input.txt");
  if (!file) {
      cerr << "Error opening file!" << endl;
      return 1;
  }

  int og_size; 
  file >> og_size;

  Matrix matrix1(og_size);
  Matrix matrix2(og_size);

  matrix1.fillMatrix(file);
  matrix2.fillMatrix(file);

  matrix1.printMatrix();
  matrix2.printMatrix();

  Matrix matrix3 = Matrix.divAndConq(matrix1, matrix2, matrix1.new_size);

  matrix3.printMatrix();
}
