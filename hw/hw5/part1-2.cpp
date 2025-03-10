#include <iostream>

using namespace std;

int factorial(int val){
    if(val <= 1){
        return 1;
    }
    return val * factorial(val-1);
}

int main(){
    int n; 
    cout << "find the factorial of: ";
    cin >> n;

    int fact = factorial(n);

    cout << "factorial of " << n << ": " << fact << endl;

    return 0;
}
