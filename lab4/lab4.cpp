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
        virtual void displayPersonInfo(ostream& file){
            file<<"Person: "<<name<<endl<<"age: "<<age<<endl;
        }
        virtual void displayInfo(ostream& file){}
        virtual void introduce(ostream& file){}
        virtual string getType(){
            return "Person";
        }
    protected:
        string name;
        int age;
};

class Student : public Person {
    public:
        Student(string newName, int newAge, int newID, float newGPA){
            name = newName;
            age = newAge;
            ID = newID;
            GPA = newGPA;
        }
        int ID;
        float GPA;
        void displayPersonInfo(ostream& file){
            file<<"Public Inheritance: Person: "<<name<<", Age: "<<age<<endl;
        }
        void displayInfo(ostream& file){
            file<<"Student: "<<name<<", Age: "<<age<<", ID: "<<ID<<", GPA: "<<GPA<<endl;
        }
        void introduce(ostream& file){
            file<<"I am a student. My name is " << name << "."<< endl;
        }
        string getType(){
            return "Student";
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
        void displayPersonInfo(ostream& file){
            file<<"Private Inheritance: Person: "<<name<<", Age: "<<age<<endl;
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
        void displayInfo(ostream& file){
            file<<"Teacher: "<<name<<", Age: "<<age<<", Subject: "<<subject<<", Experience: "<<yearsOfExp<<" years"<<endl;
        }
        void introduce(ostream& file){
            file<<"I am a teacher. My name is "<<name<<"."<<endl;
        }
        string getType(){
            return "Teacher";
        }
};

int main(){
    //opening/creating files for I/O using fstream
    ifstream input("input.txt");
    ofstream output1("output_Q1.txt");
    ofstream output2("output_Q2.txt");
    ofstream output3("output_Q3.txt");

    // reading number of objects from input.txt
    int count;
    input >> count;

    // allocating memory
    Person* people[count];
    string type;
    string name;
    int age;
    int ID;
    string subject;
    int experience;
    float GPA;

    // reading through file and creating new student/teacher based on the first word of each line
    for(int i = 0; i < count; i++){
        input >> type;
        if(type == "Student"){
            input >> name;
            input >> age;
            input >> ID;
            input >> GPA;

            people[i] = new Student(name, age, ID, GPA);
        }
        else if(type == "Teacher"){
            input >> name;
            input >> age;
            input >> subject;
            input >> experience;

            people[i] = new Teacher(name, age, subject, experience);
        }
        else{
            cout<<"something wrong with type";
            return 0;
        }
    }

    // iterating through the list we made to print to respective output files
    for(int i = 0; i < count; i++){
        if(people[i]->getType() == "Student"){
            people[i]->displayPersonInfo(output1);
        }
        people[i]->displayInfo(output2);
        people[i]->introduce(output3);
    }
    //StudentPrivate student2;
    //student2.setPersonInfo("derrick", 19);
    //student2.displayPersonInfo();

    return 0;
}
