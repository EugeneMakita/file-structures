#include<iostream>
#include<string>
#include<fstream>
#include "personFixed.h"

Person::Person(){
    FirstName[0] = 0;
    LastName[0] = 0;
    Address[0] = 0;
    City[0] = 0;
    State[0] = 0;
    ZipCode[0] = 0;
}

int Person::pack(DelimTextBuffer &Buffer){
    int result;
    result = Buffer.Pack(this->FirstName);
    result = result && Buffer.Pack(this->LastName);
    result = result && Buffer.Pack(this->Address);
    result = result && Buffer.Pack(this->City);
    result = result && Buffer.Pack(this->State);
    result = result && Buffer.Pack(this->ZipCode);
    return result;
}

int Person::unpack(DelimTextBuffer Buffer){
    int result;
    result = Buffer.Unpack(this->FirstName);
    result = result && Buffer.Unpack(this->LastName);
    result = result && Buffer.Unpack(this->Address);
    result = result && Buffer.Unpack(this->City);
    result = result && Buffer.Unpack(this->State);
    result = result && Buffer.Unpack(this->ZipCode);
    return 0;
}

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