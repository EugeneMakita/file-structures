#include<iostream>
#include "personFixed.h"
#include "DelimTextBuffer.h"

int main(){
    Person person;
    DelimTextBuffer Buffer;
    std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
    std::cin >> person;

    std::cout << person.FirstName << std::endl;
    std::cout << person.LastName << std::endl;
    std::cout << person.Address << std::endl;
    std::cout << person.City << std::endl;
    std::cout << person.State << std::endl;
    std::cout << person.ZipCode << std::endl;

    std::ofstream output;
    output.open("name.bin", std::ios::binary);

    Buffer.Pack(person.FirstName);
    Buffer.Pack(person.LastName);
    Buffer.Pack(person.Address);
    Buffer.Pack(person.City);
    Buffer.Pack(person.State);
    Buffer.Pack(person.ZipCode);
    Buffer.Write(output);
    output.close();

	std::ifstream input;
	input.open("name.bin");
	Buffer.Read(input);
	input.close();

    Person person2;

    Buffer.Unpack(person2.FirstName);
    std::cout << "person2: " << person2.FirstName << std::endl;

    Buffer.Unpack(person2.LastName);
    std::cout << "person2: " << person2.LastName << std::endl;

    Buffer.Unpack(person2.Address);
    std::cout << "person2: " << person2.Address << std::endl;

    Buffer.Unpack(person2.City);
    std::cout << "person2: " << person2.City << std::endl;

    Buffer.Unpack(person2.State);
    std::cout << "person2: " << person2.State << std::endl;

    Buffer.Unpack(person2.ZipCode);
    std::cout << "person2: " << person2.ZipCode << std::endl;
    return 0;
}
