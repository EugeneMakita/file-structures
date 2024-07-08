#include<iostream>
#include<string>
#include<ctime>
#include "courseRegistration.h"


int main(){
    Student student("034FC", "john", "mangudya", 23);
    std::cout << "ID: " << student.id << " ,name: " <<student.name << " ,surname: " <<student.surname << " ,credit hours: " << student.credit_hours << " " << std::endl;

    Student student1;
    student1 = student;
    std::cout << "ID: " << student1.id << " ,name: " <<student1.name << " ,surname: " <<student1.surname << " ,credit hours: " << student1.credit_hours << " " << std::endl;

    CourseRegistration course("History", student1, 40, 'A');
    std::cout << "Course Name: " << course.name << " ,student: " << course.student.get_full_name() << " ,credit hours: " <<course.credit_hours << " , grade: " << course.grade << " " << std::endl;

    return 0;
}