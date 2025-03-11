#include <iostream>
using namespace std;

class Fibonacci{
    public:
        Fibonacci(int n){
            length = n;
        }
        int length;
        int arr[100];

        void calculate(){
            arr[0] = 0;
            arr[1] = 1;
            for(int i = 2; i < length; i++){
                arr[i] = arr[i-1] + arr[i-2];
            }
        }

        void display(){
            for(int i = 0; i < length; i++){
                cout << arr[i] <<", ";
            }
            cout << endl;
        }
};

int main(){
    Fibonacci x(10);
    x.calculate();
    x.display();
    return 0;
}

