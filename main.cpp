#include<iostream>
#include<string>
#include<ctime>
#include "courseRegistration.h"

std::istream& operator>>(std::istream &input, Student &student){
    input >> student.id >> student.name >> student.surname >> student.credit_hours;
    return input;
}

std::ostream& operator<<(std::ostream &output, Student student){
    output << "ID: " << student.id << " ,name: " <<student.name << " ,surname: " <<student.surname << " ,credit hours: " << student.credit_hours << " " << std::endl;
    return output;
}
int main(){
    Student student("034FC", "john", "mangudya", 23);
    std::cout << student;

    Student student1;
    student1 = student;
    std::cout << student1;

    CourseRegistration course("History", student1, 40, 'A');
    std::cout << "Course Name: " << course.name << " ,student: " << course.student.get_full_name() << " ,credit hours: " <<course.credit_hours << " , grade: " << course.grade << " " << std::endl;

    Student student2;
    std::cin >> student2; 
    std::cout << student2;

    return 0;
}