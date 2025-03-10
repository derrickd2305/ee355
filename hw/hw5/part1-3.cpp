// Write a C++ program to generate the Fibonacci series up to the nth term using recursion.

#include <iostream>

using namespace std;

fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    cout << "generate a Fibonacci series with n terms: ";
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = fibonacci(i);
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete [] arr;
}
