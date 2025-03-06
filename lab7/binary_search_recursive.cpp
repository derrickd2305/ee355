#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

// implementing binary search recursively
void binary_search_recursive(int target, int* arr, int start, int end, ostream& file){
    // target is not in array
    if(start > end){
        file << "No Found";
        return;
    }
    int half = (start + end)/2;
    // target is found
    if(target == arr[half]){
        file << half;
        return;
    }
    // check lower half
    else if(target < arr[half]){
        binary_search_recursive(target, arr, start, half - 1, file);
    }
    // check upper half
    else{
        binary_search_recursive(target, arr, half + 1, end, file);
    }
}

int main(){

    // starter code ************************
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
    // ****************************************

    ofstream outputFile("output_bs.txt");

    binary_search_recursive(target, arr, 0, n-1, outputFile);

    delete [] arr;
    outputFile.close();

    return 0;
}
