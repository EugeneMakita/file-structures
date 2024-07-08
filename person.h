#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include<fstream>

class Person{
    public:
        std::string FirstName;
        std::string LastName;
        std::string Address;
        std::string ZipCode;
        std::string State;
        std::string City;

        Person();
        friend std::ostream& operator<< (std::ostream &output, Person person);
        friend std::istream& operator>> (std::istream &input, Person &person);
};
#endif