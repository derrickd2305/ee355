#include <iostream>
#include <cstdlib> // for atoi
using namespace std;

int fibonacci_dp(int n, int mem[]){
    // base case
    if(n <= 1){
        return n;
    }

    // check if we haven't computed that fibonacci number already
    if(mem[n] == -1){
        mem[n] = fibonacci_dp(n-1, mem) + fibonacci_dp(n-2, mem);
    }
    return mem[n];
}

int main(int argc, char* argv[]){
    // obtain input from command line
    int input = atoi(argv[1]);

    if(intput == 1 || input == 0){
        cout << "1";
        return 0;
    }
    else if(input < 0){
        cout << "0";
        return 0;
    }

    // allocate memory for fibonacci number, what term it is, and an array for memoization
    int fibonacci = 1, n = 1;
    int* mem = new int[input + 2];  // small values of input may not have enough memory, hence the +2

    // fill array with initial value as a way to check if we have computed that value before
    for(int i = 0; i < input; i++){
        mem[i] = -1;
    }

    // keep calculating fibonacci numbers bottom-up, until our fibonacci number is equal to or greater than the input
    while(fibonacci < input){
        fibonacci = fibonacci_dp(++n, mem);
    }
    if(fibonacci == input){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl << fibonacci << endl;
    }
    delete [] mem;
    return 0;
}

