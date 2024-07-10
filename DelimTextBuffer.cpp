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
            this->BufferSize = 0;
            this->NextByte = 0;
        };

        void Clear(){
            this->BufferSize = 0;
            this->NextByte = 0;
            this->Buffer = new char[this->MaxBytes];
        }

        void PrintBuffer(){
            std::cout << "Contents of buffer:" << Buffer << std::endl;
        }

        int Read(std::istream &input) {
            Clear();
            input.read((char*)&BufferSize, sizeof(int));
            if (BufferSize> MaxBytes){
                return false;
            }
            input.seekg(sizeof(BufferSize));
            input.read(Buffer, BufferSize);
            return input.good();
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
            int len = -1;
            int start = NextByte;
            for (int i = NextByte; i < BufferSize ; i++){
                if (Buffer[i] == Delim){
                    len = i- NextByte;
                    break;
                }
            }
            NextByte += len + 1;
            if (NextByte > BufferSize) { return false;}
            strncpy(str, &Buffer[start], len);
            str[len] = 0;
            return true;
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
