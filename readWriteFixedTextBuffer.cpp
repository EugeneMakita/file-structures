#include<iostream>
#include "personFixed.h"
#include<string>

int main(){
    std::ofstream output;
    std::string filename = "FixedTextBuffer.bin";
    output.open(filename, std::ios::binary);
    Person person;
    std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
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

    std::cout << p;
    return 0;
}