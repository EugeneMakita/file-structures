#include<string>
#include "courseRegistration.h"

CourseRegistration::CourseRegistration(){
};

CourseRegistration::CourseRegistration(std::string name, Student student, int hours, char grade){
    this->name = name;
    this->student = student;
    this->credit_hours = hours;
    this->grade = grade;
};