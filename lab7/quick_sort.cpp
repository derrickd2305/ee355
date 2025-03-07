#include <iostream>
#include <fstream>

using namespace std;

void quickSort(int* arr, int left, int right){
    // base case: array is size 1 or less and is thus already sorted
    if(left >= right){
        return;
    }

    // arbitrarily chosing the right-most element as pivot
    int pivot = arr[right];
    
    // partitioning the array by moving smaller elements to the left
    // keep track of where the smaller elements end using i
    int i = left;
    for(int j = 0; j < right; j++){
        if(arr[j] < pivot){
            // swapping values
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    // swap the positions of the pivot and the first greater term
    int temp = pivot;
    arr[right] = arr[i+1];
    arr[i+1] = pivot;

    // recursive call to quick sort the two partitioned arrays
    quickSort(arr, left, i);
    quickSort(arr, i+1, right);
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

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        outputFile << arr[i] << " ";
    }

    outputFile.close();
    delete [] arr;
    return 0;
}
