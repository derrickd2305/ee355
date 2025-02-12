#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
    public:
        void displayPersonInfo(){
            cout<<"name: "<<name<<endl<<"age: "<<age<<endl;
        }
    protected:
        string name = "derrick";
        int age = 19;
};

class Student : public Person {

};

class StudentPrivate : private Person {

};

int main(){
    Student student1;
    StudentPrivate student2;
    student1.displayPersonInfo();
    student2.displayPersonInfo();
}