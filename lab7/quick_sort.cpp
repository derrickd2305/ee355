#include <iostream>
#include <fstream>

using namespace std;

void quickSort(int* arr, int n){
    // base case: array is size 1 or less
    if(n <= 1){
        return;
    }
    
    // aribitrarily assinging pivot as first 
    int pivot = arr[0];
    // allocating memory for three arrays
    int c1 = 0, c2 = 0, c3 = 0;
    int* equal = new int[n];
    int* less = new int[n-1];
    int* greater = new int[n-1];

    // copying elements into different arrays depending on if they are less than, greater than, or equal to the pivot value
    for(int i = 0; i < n; i++){
        if(arr[i] == pivot){
            equal[c1] = arr[i];
            c1++;
        }
        else if(arr[i] < pivot){
            less[c2] = arr[i];
            c2++;
        }
        else{
            greater[c3] = arr[i];
            c3++;
        }
    }

    // recursive calls to split and sort
    quickSort(equal, c1);
    quickSort(less, c2);
    quickSort(greater, c3);

    // replacing original array with sorted arrays
    for(int i = 0; i < c2; i++){
        arr[i] = less[i];
    }
    for(int i = 0; i < c1; i++){
        arr[i + c2] = equal[i];
    }
    for(int i = 0; i < c3; i++){
        arr[i + c1 + c2] = greater[i];
    }

    // free memory
    delete [] less;
    delete [] equal;
    delete [] greater;
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

    ofstream outputFile("output_qs.txt");

    quickSort(arr, n);

    for(int i = 0; i < n; i++){
        outputFile << arr[i] << " ";
    }

    outputFile.close();
    delete [] arr;
    return 0;
}
