#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
    public:
        void Person(string newName, int newAge){
            this->name = newName;
            this->age = newAge;
        void displayPersonInfo(){
            cout<<"name: "<<name<<endl<<"age: "<<age<<endl;
        }
    protected:
        string name;
        int age;
};

class Student : public Person {

};

class StudentPrivate : private Person {

};

int main(){
    Student student1("derrick", 19);
    student1.displayPersonInfo();
    //student2.displayPersonInfo();
}
