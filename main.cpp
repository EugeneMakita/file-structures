#include<iostream>
#include<string>
#include<ctime>
#include "courseRegistration.h"

int main(){
    Student student("034FC", "john", "mangudya", 23);
    std::cout << student;

    Student student1;
    student1 = student;
    std::cout << student1;

    CourseRegistration course("History", student1, 40, 'A');
    std::cout << course;

    Student student2;
    std::cin >> student2; 
    std::cout << student2;

    return 0;
}