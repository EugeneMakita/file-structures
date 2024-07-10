#include<iostream>
#include "personFixed.h"

class DelimTextBuffer{
    char Delim;
    char *Buffer;
    int MaxBytes;
    int BufferSize;
    int NextByte;

    public:
        DelimTextBuffer(char Delim='|', int MaxBytes=1024){
            this->Delim = Delim;
            this->MaxBytes = MaxBytes;
            this->Buffer = new char[this->MaxBytes];
        };

        int Read(std::istream &input){
            input.read((char*)&BufferSize, sizeof(BufferSize));
            return 0;
        }

        int Write(std::ostream &output) const{
            output.write((char*)&BufferSize, sizeof(BufferSize));
            output.write(Buffer, BufferSize);
            return output.good();
        }

        int Pack(const char *str){
            short length;
            length = strlen(str);

            int start = NextByte;
            NextByte += length + 1;

            if (NextByte > MaxBytes) {
                return false;
            }

            memcpy(&Buffer[start], str, length * sizeof(char));
            Buffer[start+length] = Delim;
            BufferSize = NextByte;
            return true;
        }

        int Unpack(char *str){
            return 0;
        }
};

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

    std::ofstream file;
    file.open("name.bin", std::ios::binary);

    Buffer.Pack(person.FirstName);
    Buffer.Pack(person.LastName);
    Buffer.Pack(person.Address);
    Buffer.Pack(person.City);
    Buffer.Pack(person.State);
    Buffer.Pack(person.ZipCode);
    Buffer.Write(file);

    return 0;
}