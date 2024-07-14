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

        int Open(std::string filename, int mode){
            File.open(filename, std::ios::binary | std::ios::in |std::ios::out);
            if(!File.good()){ 
                return false;
            }

            //HeaderSize = Buffer.ReadHeader(File);
            File.seekp(0, std::ios::beg);
            File.seekg(0, std::ios::beg);
            return true;
        }

        int Create(std::string filename){
            File.open(filename, std::ios::out|std::ios::binary);
            if(!File.good()){
                return false;
            }

            //HeaderSize = Buffer.WriteHeader(File);
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

        int InitRead(){
            File.seekg(0, std::ios::beg);
            return File.good();
        }

        int Read(){
            if(File.eof()){
                return true;
            };
            return Buffer.Read(File);
        }

        int Append(){
            Buffer.PrintBuffer();
            File.seekp(0, std::ios::end);
            return Buffer.Write(File);
        }

        int ReadHeader(){
            return 0;
        }

        ~BufferFile(){
            Close();
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
        /*Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
        Files.Read();
        person2.unpack(Buffer);
        std::cout << person2 << std::endl;
    //}
    //Buffer.PrintBuffer() ;
    //Buffer.Unpack(person2.FirstName);
    //Buffer.Unpack(person2.LastName);
    if(person2.unpack(Buffer)){
        std::cout << person;
    } else {
        std::cout << "failed to unpack" << std::endl;
    };*/

    return 0;
}
