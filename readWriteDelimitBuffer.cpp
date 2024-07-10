#include<iostream>
#include "personFixed.h"

int main(){
    Person person;
    DelimTextBuffer Buffer;
    std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
    std::cin >> person;

    std::cout << person;
    std::ofstream output;
    output.open("name.bin", std::ios::binary);

    if (person.pack(Buffer)){
        Buffer.Write(output);
        output.close();
    }else{
        std::cout << "failed to pack the person" << std::endl;
    }

	std::ifstream input;
	input.open("name.bin");
	Buffer.Read(input);

    Person person2;
    if(person2.unpack(Buffer)){
        std::cout << person;
    } else {
        std::cout << "failed to unpack" << std::endl;
    };

	input.close();
    return 0;
}
