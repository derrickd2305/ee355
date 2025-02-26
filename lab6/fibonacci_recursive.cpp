#include <iostream>
#include <cstdlib> // for atoi
using namespace std;

int fibonacci_recursive(int n){
    // base case
    if(n <= 1){
        return n;
    }
    // compute the fibonacci number recursively from scratch for every term other than the base case
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int main(int argc, char* argv[]){
    // getting output from command line, converting to integer
    int input = atoi(argv[1]);

    // allocated memory for fibonacci number and counter
    int fibonacci = 1, n = 1;

    // keep calculating fibonacci numbers bottom-up until it is equal to or greater than our input
    while(fibonacci < input){
        fibonacci = fibonacci_recursive(++n);
    }
    if(fibonacci == input){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl << fibonacci;
    }
    return 0;
}
