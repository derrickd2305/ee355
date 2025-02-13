#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
    public:
        void setPersonInfo(string newName, int newAge){
            this->name = newName;
            this->age = newAge;
        }
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
    Student student1;
    student1.setPersonInfo("derrick", 19);
    StudentPrivate student2;
    student2.setPersonInfo("derrick", 19);
    student1.displayPersonInfo();
    //student2.displayPersonInfo();
}
