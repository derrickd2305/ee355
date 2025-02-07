#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// used the following website for vectors: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/


class Matrix {
  public:
    int size;
    vector<vector<int> > data;

    // constructor
    Matrix(int og_size){
      size = modifySize(og_size);
      data.resize(size, vector<int>(size,0));
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
      for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
          file >> data[i][j];
        }
      }
    }

    void printMatrix() const {
      for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
              cout << data[i][j] << " ";
          }
          cout << endl;
      }
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
}
