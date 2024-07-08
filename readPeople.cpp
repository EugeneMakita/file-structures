#include<iostream>
#include<fstream>
#include<string>
#include "person.h"

std::istream& operator>> (std::istream &input, Person &person){
        const char  DELIMITER  = '|';
        getline(input, person.FirstName, DELIMITER);
        getline(input, person.LastName, DELIMITER);
        getline(input, person.Address, DELIMITER);
        getline(input, person.City, DELIMITER);
        getline(input, person.ZipCode, DELIMITER);
    return input;
}

int main(){
    std::ifstream file;
    std::string filename;
    std::cout << "Enter the file name: ";
    getline(std::cin, filename);
    file.open(filename);

    if(!file.is_open()){
        std::cout << "Opening file: " << filename << " failed " << std::endl;
    }

    std::string line;
    while(true){
        Person person;
        file >> person;

        if (person.FirstName.length()==0){
            break;
        }

        std::cout << person;
    }
}