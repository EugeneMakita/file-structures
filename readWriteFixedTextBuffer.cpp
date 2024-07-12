#include<iostream>
#include "personFixed.h"
#include<string>

std::ostream &operator<<(std::ostream &output, Person person){
    std::cout << strlen(person.ZipCode) << std::endl;
    std::cout << "ZipCode: " << person.ZipCode << std::endl;
    /*output << "FirstName: " << person.FirstName << 
        ", LastName: " << person.LastName << 
       ", Address: " << person.Address << 
        ", City: " << person.City <<
        ", State: " << person.State <<
        ", ZipCode: " <<person.ZipCode << std::endl;*/
    return output;
}

int main(){
    std::ofstream output;
    std::string filename = "FixedTextBuffer.bin";
    output.open(filename, std::ios::binary);
    Person person;
    std::cin >> person;
    std::cout << person;

    FixedTextBuffer Buffer;
    person.initFixedTextBuffer(Buffer);
    if(person.pack(Buffer)){
        Buffer.Write(output);
        output.close();
    };

    std::ifstream input;
    input.open(filename, std::ios::binary);
    Buffer.Read(input);
    Person p;
    if(p.unpack(Buffer)){
        input.close();
    }

    std::cout << p.ZipCode;
    return 0;
}