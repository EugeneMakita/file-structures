#include<iostream>
#include<string>
#include<fstream>
#include "person.h"

Person::Person(){

}

std::ostream& operator<< (std::ostream &output, Person person){
    output << person .FirstName <<  "|" <<
        person.LastName << "|" <<
        person.Address << "|" <<
        person.City << "|" <<
        person.ZipCode << "|";
    return output;
}