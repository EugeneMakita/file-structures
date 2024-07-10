#include<iostream>
#include<fstream>

class Person{
    public:
        char FirstName[11];
        char LastName[11];
        char Address[16];
        char City[15];
        char State[15];
        char ZipCode[7];
        Person(){
            FirstName[0] = 0;
            LastName[0] = 0;
            Address[0] = 0;
            City[0] = 0;
            State[0] = 0;
            ZipCode[0] = 0;
        }
};

std::istream &operator>>(std::istream &input, Person &person){
    const char DELIMITER = '|';
    std::cin.getline(person.FirstName,11, DELIMITER);
    if (strlen(person.FirstName)==0){return input;}
    std::cin.getline(person.LastName,11, DELIMITER);
    std::cin.getline(person.Address,16, DELIMITER);
    std::cin.getline(person.City,15, DELIMITER);
    std::cin.getline(person.State,15, DELIMITER);
    std::cin.getline(person.ZipCode,7, DELIMITER);
    return input;
}

std::ostream &operator<<(std::ostream &input, Person person){
    std::cout << "FirstName: " << person.FirstName << 
        ", LastName: " << person.LastName << 
        ", Address: " << person.Address << 
        ", City: " << person.City <<
        ", State: " << person.State <<
        ", ZipCode: " <<person.ZipCode << std::endl;
    return input;
}

class LengthTextBuffer{
    char * Buffer;
    int MaxBytes;
    int BufferSize;
    int NextBytes;
    int *FieldSizes;

    public:
        LengthTextBuffer(int MaxBytes=1024){
            this->MaxBytes = MaxBytes;
            Buffer = new char[this->MaxBytes];
            BufferSize = 0;
            NextBytes = 0;
        }

        void Clear(){
            Buffer = new char[this->MaxBytes];
            BufferSize = 0;
            NextBytes = 0;
        }

        int Addfield(){
            return 0;
        }

        int Pack(const char *str){
            short len = strlen(str);
            int startBytes = NextBytes;

            NextBytes += len + sizeof(len);
            if (NextBytes > MaxBytes){
                return false;
            }

            memcpy(&Buffer[startBytes],&len, sizeof(len));
            memcpy(&Buffer[startBytes+sizeof(len)], str, len*sizeof(char));
            BufferSize = NextBytes;
            return true;
        }

        int Unpack(char *str){
            int startByte  = NextBytes;
            short size;
            memcpy(&size, &Buffer[startByte], sizeof(size));
            if ((startByte+sizeof(size) > BufferSize)){
                return false;
            }
            memcpy(str, &Buffer[startByte+sizeof(size)], size);
            str[size] = 0;
            NextBytes += (sizeof(size) + size);
            return true;
        }

        int Write(std::ofstream &output){
            output.write((char *)&BufferSize, sizeof(BufferSize));
            output.write(Buffer, BufferSize);
            return output.good();
        }

        int Read(std::ifstream &input){
            Clear();
            input.read((char*)&BufferSize, sizeof(int));
            std::cout << BufferSize << std::endl;
            if (BufferSize> MaxBytes){
                return false;
            }

            input.seekg(sizeof(BufferSize));
            input.read(Buffer, BufferSize);

            return input.good();
        }
};

int main(){
    Person person;
    LengthTextBuffer Buffer;
    std::cout << "Enter Name,surname,address,city,state,zipCode:" <<std::endl;
    std::cin >> person;

    std::cout << person;

    std::ofstream output;
    output.open("lengthTextBuffer.bin", std::ios::binary);
    Buffer.Pack(person.FirstName);
    Buffer.Pack(person.LastName);
    Buffer.Pack(person.Address);
    Buffer.Pack(person.City);
    Buffer.Pack(person.State);
    Buffer.Pack(person.ZipCode);
    Buffer.Write(output);
    output.close();

    std::ifstream input;
    input.open("lengthTextBuffer.bin", std::ios::binary);
    Buffer.Read(input);
    Person person2;
    Buffer.Unpack(person2.FirstName);
    Buffer.Unpack(person2.LastName);
    Buffer.Unpack(person2.Address);
    Buffer.Unpack(person2.City);
    Buffer.Unpack(person2.State);
    Buffer.Unpack(person2.ZipCode);
    std::cout << person2 << std::endl;
    input.close();

    return 0;
}