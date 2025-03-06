#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    // starter code **********************
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

    int target;
    inputFile >> target; 

    inputFile.close();

    sort(arr, arr + n);
    // *************************************

    // declaring variables to partition and index through array
    int start = 0, end = n - 1;
    int half = (start + end)/2;

    while(target != arr[half]){
        // target not in array
        if(start > end){
            cout << "Not Found" << endl;
            return 0;
        }
        // check upper half
        else if(target > arr[half]){
            start = half + 1;
        }
        // check lower half
        else if(target < arr[half]){
            end = half - 1;
        }
        half = (start + end)/2;
    }

    // print statement will only execute if target was found
    cout << half << endl;

    delete [] arr;

    return 0;
}
