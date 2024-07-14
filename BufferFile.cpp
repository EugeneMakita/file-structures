#include "IOBuffer.h"
#include<fstream>
#include<iostream>
#include<string>
#include "DelimTextBuffer.h"
#include "personFixed.h"

class BufferFile{
    protected:
        int HeaderSize;
        DelimTextBuffer &Buffer;

    public:
        std::fstream File;
        BufferFile(DelimTextBuffer &buffer):Buffer(buffer){
        }

        int printObject(){
            std::cout <<"Semaruva: " << &Buffer << std::endl;
            return 0;
        }

        int Open(std::string filename, int mode){
            File.open(filename, std::ios::binary | std::ios::in |std::ios::out);
            if(!File.good()){ 
                return false;
            }
            File.seekg(0, std::ios::beg);
            File.seekp(0, std::ios::beg);
            return true;
        }

        int Create(std::string filename){
            File.open(filename, std::ios::out|std::ios::binary);
            if(!File.good()){
                return false;
            }
            File.seekp(0, std::ios::beg);
            File.seekg(0, std::ios::beg);
            return true;
        }

        int WriteHeader(){
            return 0;
        }

        int Close(){
            File.close();
            return true;
        }

        int Write(){
            return 0;
        }

        int Append(){
            Buffer.PrintBuffer();
            File.seekp(0, std::ios::end);
            return Buffer.Write(File);
        }

        int ReadHeader(){
            return 0;
        }
};

int main(){
    Person person;
    DelimTextBuffer Buffer;
    BufferFile Files(Buffer);

    std::string filename = "DelimitBuffer.bin";
    if (!Files.Open(filename, std::ios::in)){
        Files.Create(filename);
    };

    std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
    std::cin >> person;

    std::cout << person;
    if (person.pack(Buffer)){
        Files.Append();
    }
            //std::cout << "Outside Buffersize "<< Buffer.GetBufferSize() << std::endl;
    
    /*else{
        std::cout << "failed to pack the person" << std::endl;
    }

	std::ifstream input;
	input.open("DelimitBuffer.bin");
	Buffer.Read(input);

    Person person2;
    if(person2.unpack(Buffer)){
        std::cout << person;
    } else {
        std::cout << "failed to unpack" << std::endl;
    };

	input.close();*/
    return 0;
}
