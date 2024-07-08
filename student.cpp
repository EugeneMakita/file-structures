#include<iostream>
#include<string>
#include<ctime>
#include "student.h"

Student::Student(){
};

Student::Student(std::string id, std::string name, std::string surname, int credit_Hours){
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->credit_hours = credit_Hours;
};

void Student::operator=(Student student){
    this->id = student.id;
    this->name = student.name;
    this->surname = student.surname;
    this->credit_hours = student.credit_hours;
};

std::string Student::get_full_name(){
    return this->name + " " + this->surname;
}
