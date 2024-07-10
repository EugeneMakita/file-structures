#include<iostream>
#include<string>
#include<fstream>
#include "personFixed.h"

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