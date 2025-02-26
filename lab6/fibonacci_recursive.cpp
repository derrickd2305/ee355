#include <iostream>
#include <cstdlib> // for atoi
using namespace std;

int fibonacci_recursive(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int main(int argc, char* argv[]){
    int input = atoi(argv[1]);
    int fibonacci = 1, n = 1;
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
