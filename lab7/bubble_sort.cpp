#include <iostream>
#include <fstream>

using namespace std;

void bubbleSort(int* arr, int n){
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            // first swap
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            // set swapped flag to true
            bool swapped = true;
            int j = i;
            // after initial swap, more swaps may be necessary
            while(swapped){
                //compare swapped value to previous value
                if(arr[j] < arr[j-1] && j > 0){
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    j--;    // iterate down the array
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
    ofstream outputFile("output_bubble.txt");

    bubbleSort(arr, n);

    // fill text file with sorted array
    for(int i = 0; i < n; i++){
        outputFile << arr[i] << " ";
    }

    outputFile.close();
    delete [] arr;

    return 0;
}
