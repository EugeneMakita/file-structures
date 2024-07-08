#include<iostream>
#include<string>
#include<fstream>
#include "person.h"


std::istream& operator>> (std::istream &input, Person &person){
    input >> person.FirstName >> 
        person.LastName >> 
        person.Address >>
        person.City >>
        person.ZipCode;
    return input;
}

int main(){
    Person p;
    std::string filename;
    std::ofstream file;
    std::cout << "Enter filename: " ;
    getline(std::cin, filename);

    file.open(filename, std::ios::app);

    if(file.fail()){
        std::cout << "file failed to open" << std::endl;
    }

    while(true){
        std::cout << "Enter (FirstName, LastName, Address, City, Zipcode): " ;
        std::cin >> p;
        file << p  << std::endl;
    }

    file.close();
}