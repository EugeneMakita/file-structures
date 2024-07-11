#include<iostream>
#include<fstream>
#include "personFixed.h"

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
