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

    /*std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
    std::cin >> person;

    std::cout << person;
    if (person.pack(Buffer)){
        Files.Append();
    }*/
    
    /*else{
        std::cout << "failed to pack the person" << std::endl;
    }

	std::ifstream input;
	input.open("DelimitBuffer.bin");
	Buffer.Read(input);*/

    Person person2;
    Files.InitRead(); 
    while(Files.Read()){
        person2.unpack(Buffer);
        std::cout << person2 ;
    }

    return 0;
}