#include<iostream>
#include<string>
#include<fstream>
#include "personFixed.h"

std::istream &operator>>(std::istream &input, Person &person){
    const char DELIMITER = '|';
    std::cin.getline(person.FirstName,11, DELIMITER);
    if (strlen(person.FirstName)==0){return input;}
    std::cin.getline(person.LastName,11, DELIMITER);
    std::cin.getline(person.Address,16, DELIMITER);
    std::cin.getline(person.City,15, DELIMITER);
    std::cin.getline(person.State,15, DELIMITER);
    std::cin.getline(person.ZipCode,7, DELIMITER);
    return input;
}

int main(){
    Person person;
    std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
    std::cin >> person;
    std::cout << person.FirstName << std::endl;
    std::cout << person.LastName << std::endl;
    std::cout << person.Address << std::endl;
    std::cout << person.City << std::endl;
    std::cout << person.State << std::endl;
    std::cout << person.ZipCode << std::endl;
    return 0;
}