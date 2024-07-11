#include<iostream>
#include "personFixed.h"

int main(){
    std::ofstream output;
    output.open("FixedTextBuffer.bin", std::ios::binary);
    Person person;
    std::cin >> person;
    std::cout << person;
    FixedTextBuffer Buffer;
    Buffer.AddField(10);
    Buffer.AddField(10);
    Buffer.AddField(10);
    Buffer.AddField(10);
    Buffer.AddField(10);
    Buffer.AddField(10);
    Buffer.Pack(person.FirstName);
    Buffer.Pack(person.LastName);
    Buffer.Pack(person.Address);
    Buffer.Pack(person.City);
    Buffer.Pack(person.State);
    Buffer.Pack(person.ZipCode);
    Buffer.Write(output);
    output.close();

    std::ifstream input;
    input.open("FixedTextBuffer.bin", std::ios::binary);
    Buffer.Read(input);
    Person p;
    Buffer.Unpack(p.FirstName);
    Buffer.Unpack(p.LastName);
    Buffer.Unpack(p.Address);
    Buffer.Unpack(p.City);
    Buffer.Unpack(p.State);
    Buffer.Unpack(p.ZipCode);
    input.close();
    std::cout << p;
    
    return 0;
}