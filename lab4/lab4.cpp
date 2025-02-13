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
        virtual void introduce(){}
    protected:
        string name;
        int age;
};

class Student : public Person {
    public:
        Student(string newName, int newAge, int newID, int newGPA){
            name = newName;
            age = newAge;
            ID = newID;
            GPA = newGPA;
        }
        int ID;
        int GPA;
        void displayPersonInfo(){
            cout<<"Student: "<<name<<" "<<age<<" "<<ID<<" "<<GPA<<endl;
        }
        void introduce(){
            cout<<"I am a student. My name is " << name << "."<< endl;
        }
};

class StudentPrivate : private Person {
    public:
        StudentPrivate(string newName, int newAge, int newID, float newGPA){
            name = newName;
            age = newAge;
            ID = newID;
            GPA = newGPA;
        }
        int ID;
        float GPA;
        void displayPersonInfo(){
            cout<<"Private student: "<<name<<" "<<age<<" "<<ID<<" "<<GPA<<endl;
        }
};

class Teacher : public Person {
    public:
        Teacher(string newName, int newAge, string newSubject, int newYearsOfExp){
            name = newName;
            age = newAge;
            subject = newSubject;
            yearsOfExp = newYearsOfExp;
        }
        string subject;
        int yearsOfExp;
        void displayPersonInfo(){
            cout<<"Teacher: "<<name<<" "<<age<<" "<<subject<<" "<<yearsOfExp<<endl;
        }
        void introduce(){
            cout<<"I am a teacher. My name is "<<name<<"."<<endl;
        }
};

int main(){
    Student student1("Derrick", 19, 677, 4);
    student1.displayPersonInfo();
    student1.introduce();
    
    //StudentPrivate student2;
    //student2.setPersonInfo("derrick", 19);
    //student2.displayPersonInfo();
    
    Teacher teacher1("Bob", 45, "EE355", 15);
    teacher1.displayPersonInfo();   
    teacher1.introduce();
}
