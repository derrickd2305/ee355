#include <iostream>
using namespace std;

int main(){
    cout << "array of size: ";
    int size;
    cin >> size;

    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        cout << "input value: ";
        cin >> arr[i];
    }
    cout << endl;

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    delete [] arr;
    return 0;

}
