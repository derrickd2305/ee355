#include <iostream>

using namespace std;

int main(){
    int n; 
    cout << "find the factorial of: ";
    cin >> n;

    int factorial = 1;
    for(int i = 2; i <= n; i++){
        factorial *= i;
    }

    cout << "factorial of " << n << ": " << factorial << endl;

    return 0;
}
