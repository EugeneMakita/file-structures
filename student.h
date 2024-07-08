#ifndef STUDENT_H
#define STUDENT H
#include<string>

class Student{
    public:
        std::string id, name, surname;
        int credit_hours;
        Student();
        Student(std::string id, std::string name, std::string surname, int credit_Hours);
        void operator=(Student student);
        std::string get_full_name();
        /*std::istream& operator>>(std::istream &input);*/
};
#endif