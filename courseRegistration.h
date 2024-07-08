#ifndef COURSEREGISTRATION_H
#define COURSEREGISTRATION_H
#include<iostream>
#include<string>
#include<ctime>
#include "student.h"

class CourseRegistration {
    public:
        std::string name;
        Student student;
        int credit_hours;
        char grade;

    CourseRegistration();
    CourseRegistration(std::string name, Student student, int hours, char grade);
};

#endif