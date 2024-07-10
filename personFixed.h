#ifndef PERSON_FIXED_H
#define PERSON_FIXED_H
#include<iostream>
#include<string>
#include<fstream>

class Person{
    public:
        char FirstName[11];
        char LastName[11];
        char Address[16];
        char City[15];
        char State[15];
        char ZipCode[7];
        Person();
        friend std::istream &operator>>(std::istream &input, Person &person);
};
#endif