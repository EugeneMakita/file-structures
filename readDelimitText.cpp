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

    Person person2;
    Files.InitRead(); 
    while(Files.Read()){
        person2.unpack(Buffer);
        std::cout << person2 ;
    }

    return 0;
}