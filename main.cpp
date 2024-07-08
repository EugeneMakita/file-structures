#include<iostream>
#include<string>
#include<ctime>

class Student{
    public:
        std::string id, name, surname;
        int credit_hours;

        Student(){

        }

        Student(std::string id, std::string name, std::string surname, int credit_Hours){
            this->id = id;
            this->name = name;
            this->surname = surname;
            this->credit_hours = credit_Hours;
        }

        void operator=(Student student){
            this->id = student.id;
            this->name = student.name;
            this->surname = student.surname;
            this->credit_hours = student.credit_hours;
        }
};

int main(){
    Student student("034FC", "john", "mangudya", 23);
    std::cout << "ID: " << student.id << " ,name: " <<student.name << " ,surname: " <<student.surname << " ,credit hours: " << student.credit_hours << " " << std::endl;

    Student student1;
    student1 = student;
    std::cout << "ID: " << student1.id << " ,name: " <<student1.name << " ,surname: " <<student1.surname << " ,credit hours: " << student1.credit_hours << " " << std::endl;
    return 0;
}