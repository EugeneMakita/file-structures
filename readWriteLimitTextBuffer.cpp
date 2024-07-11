#include<iostream>
#include<fstream>
#include "lengthTextBuffer.h"

class Person{
    public:
        char FirstName[11];
        char LastName[11];
        char Address[16];
        char City[15];
        char State[15];
        char ZipCode[7];
        Person(){
            FirstName[0] = 0;
            LastName[0] = 0;
            Address[0] = 0;
            City[0] = 0;
            State[0] = 0;
            ZipCode[0] = 0;
        }

        int pack(LengthTextBuffer &Buffer){
            int result;
            result = Buffer.Pack(this->FirstName);
            result = result && Buffer.Pack(this->LastName);
            result = result && Buffer.Pack(this->Address);
            result = result && Buffer.Pack(this->City);
            result = result && Buffer.Pack(this->State);
            result = result && Buffer.Pack(this->ZipCode);
            return result;
        }

        int unpack(LengthTextBuffer Buffer){
            int result;
            result = Buffer.Unpack(this->FirstName);
            result = result && Buffer.Unpack(this->LastName);
            result = result && Buffer.Unpack(this->Address);
            result = result && Buffer.Unpack(this->City);
            result = result && Buffer.Unpack(this->State);
            result = result && Buffer.Unpack(this->ZipCode);
            return result;
        }
    };

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

std::ostream &operator<<(std::ostream &input, Person person){
    std::cout << "FirstName: " << person.FirstName << 
        ", LastName: " << person.LastName << 
        ", Address: " << person.Address << 
        ", City: " << person.City <<
        ", State: " << person.State <<
        ", ZipCode: " <<person.ZipCode << std::endl;
    return input;
}

int main(){
    Person person;
    LengthTextBuffer Buffer;
    std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
    std::cin >> person;

    std::cout << person;

    std::ofstream output;
    output.open("lengthTextBuffer.bin", std::ios::binary);

    if(person.pack(Buffer)){
        Buffer.Write(output);
        output.close();
    }else{
        std::cout << "Failed to pack the object" << std::endl;
    }


    std::ifstream input;
    input.open("lengthTextBuffer.bin", std::ios::binary);
    Buffer.Read(input);

    Person person2;
    if(person2.unpack(Buffer)){
        std::cout << person2 << std::endl;
        input.close();
    }else{
        std::cout << "Failed to unpack" << std::endl;
    };

    return 0;
}
