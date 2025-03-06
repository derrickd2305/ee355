#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(int* arr, int n){
    int temp, j;
    bool swapped = false;
    for(int i = 0; i < n; i++){
        if(arr[i] > arr[i+1]){
            // swapping values
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            // set swapped flag to true
            swapped = true;
            j = i;
            while(swapped == true && j > 0){
                if(arr[j] < arr[j-1]){
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
                else{
                    swapped = false;
                }
            }
        }
    }
}

int main(){
    // starter code ***************************
    ifstream inputFile("input.txt");
    if(!inputFile){
        cout<<"unable to open file"<<endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        inputFile >> arr[i];
    }
    inputFile.close();
    // ***************************************

    // output file
    ofstream outputFile("output_bs.txt");

    bubbleSort(arr, n);
}
