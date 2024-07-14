#include "IOBuffer.h"
#include<fstream>
#include<iostream>
#include<string>
#include "personFixed.h"
#include "BufferFile.h"

int main(){
    Person person;
    DelimTextBuffer Buffer;
    BufferFile Files(Buffer);

    std::string filename = "DelimitBuffer.bin";
    if (!Files.Open(filename, std::ios::in)){
        Files.Create(filename);
    };

    while(true){
        std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
        std::cin >> person;
        std::cout << person;
        if (person.pack(Buffer)){
            Files.Append();
        }
    }

    return 0;
}