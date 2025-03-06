#include <iostream>
#include <algorithm>
#include <fstream>

void binary_search_recursive(int target, int* arr, int start, int end){
    if(start == end || start > end){
        cout << "No Found";
    }
    int half = (start + end)/2;
    if(target == arr[half]){
        cout << half;
    }
    else if(target < arr[half]){
        binary_search_recursive(target, arr, start, half);
    }
    else{
        binary_search_recursive(target, arr, half, end);
    }
}

int main(){
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

    binary_search_recursive(target, arr, 0, n-1);
}
