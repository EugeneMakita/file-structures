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

std::ostream &operator<<(std::ostream &output, CourseRegistration course){
    output << "Course Name: " << course.name << " ,student: " << course.student.get_full_name() << " ,credit hours: " <<course.credit_hours << " , grade: " << course.grade << " " << std::endl;
    return output;
};