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
        virtual void displayPersonInfo(){
            cout<<"name: "<<name<<endl<<"age: "<<age<<endl;
        }
    protected:
        string name;
        int age;
};

class Student : public Person {
    public:
        void displayPersonInfo(){
            cout<<"Student: "<<name<<" Age: "<<age<<endl;
        }
};

class StudentPrivate : private Person {

};

class Teacher : public Person {
    public:
        void displayPersonInfo(){
            cout<<"Teacher: "<<name<<" Age: "<<age<<endl;
        }
};

int main(){
    Student student1;
    student1.setPersonInfo("derrick", 19);
    student1.displayPersonInfo();
    
    //StudentPrivate student2;
    //student2.setPersonInfo("derrick", 19);
    //student2.displayPersonInfo();
    
    Teacher teacher1;
    teacher1.setPersonInfo("Mr. Kim", 91);
    teacher1.displayPersonInfo();
}
