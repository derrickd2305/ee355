#include <iostream>
#include <fstream>
using namespace std;

void print_array(int* ptr, int count, ostream &file){
    for(int i = 0; i < count; i++){
        file << *(ptr + i) << "\t";
    }
    file << endl;
}

int main()
{
    // opening files for input and output
    ifstream input("input.txt");
    ofstream output("output_Q1.txt");

    // reading values from input.txt and storing in an array using pointers
    int count;
    input >> count;
    int* array = new int[count];
    int* ptr = array;

    for(int i = 0; i < count; i++){
        input >> *(ptr + i);
    }

    // output original matrix
    output << "original matrix \n";
    print_array(ptr, count, output);

    // doubling all even numbers and squaring all odd numbers in place
    for(int i = 0; i < count; i++){
        if(*(ptr+i) % 2 == 0){
            *(ptr+i) = *(ptr+i) * 2;
        }
        else{
            *(ptr+i) = *(ptr+i) * *(ptr+i);
        }
    }
    
    output << "evens doubled, odds squared: \n";
    print_array(ptr, count, output);

    // finding and printing the maximum and minimum values using pointers
    int max = *ptr, min = *ptr;
    for(int i = 0; i < count; i++){
        if(max < *(ptr+i)){
            max = *(ptr+i);
        }
        if(min > *(ptr+i)){
            min = *(ptr+i);
        }
    }

    output << "maximum: " << max << endl << "minimum: " << min << endl;

    // computing a prefix sum array using only pointers
    int sum = 0;
    for(int i = 0; i < count; i++){
        sum += *(ptr+i);
        *(ptr+i) = sum;
    }

    output << "prefix sum array:\n";
    print_array(ptr, count, output);

    delete [] array;
    return 0;
}
