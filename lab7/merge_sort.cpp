#include <iostream>
#include <fstream>

using namespace std;

void merge_sort(int* arr, int n){
    // base case: arrays of size 1 or less are already sorted
    if(n <= 1){
        return;
    }

    // splitting arrays in half
    int n1 = n/2;
    int n2 = n - n1;
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

     // copy elements from og array into the two arrays
    for(int i = 0; i < n1; i++){
        arr1[i] = arr[i];
    }
    for(int i = 0; i < n2; i++){
        arr2[i] = arr[n1 + i];
    }

    // recursive call to sort the two halves
    merge_sort(arr1, n1);
    merge_sort(arr2, n2);
    
    
    // merging
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        if(c1 < n1 && c2 < n2){
            if(arr1[c1] < arr2[c2]){
                arr[i] = arr1[c1];
                c1++;
            }
            else{
                arr[i] = arr2[c2];
                c2++;
            }
        }
        else{
            if(c1 < n1){
                arr[i] = arr1[c1];
                c1++;
            }
            else{
                arr[i] = arr2[c2];
                c2++;
            }
        }
    }
    
    // freeing memory
    delete [] arr1;
    delete [] arr2;
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

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    merge_sort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete [] arr;
    return 0;
}
