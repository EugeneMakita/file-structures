#include<iostream>
#include<fstream>
#include "personFixed.h"

class FixedTextBuffer{
    char *Buffer;
    int BufferSize;
    int MaxBytes;
    int NextBytes;
    int *FieldSizes;
    int MaxFields;
    int NumberOfFields;
    int Packing;
    int NextField;
    int NextCharecter;

    public:
        FixedTextBuffer(int MaxBytes=60, int MaxFields=6){
            this->MaxBytes = MaxBytes;
            this->Buffer = new char[this->MaxBytes];
            this->MaxFields = MaxFields;
            this->FieldSizes = new int[MaxFields];
            this->BufferSize = 0;
            this->NextBytes = 0;
            this->NumberOfFields = 0;
            this->NextField = 0;
            this->NextCharecter = 0;
            this->Packing = true;
        }

        int AddField(int FieldSize){
            if (NumberOfFields >= MaxFields){
                return false;
            }

            if ((BufferSize+FieldSize) > MaxBytes){
                return false;
            }

            FieldSizes[NumberOfFields] = FieldSize;
            NumberOfFields++;
            BufferSize += FieldSize;
            return true;
        }

        int GetNumberOfFields() const{
            return NumberOfFields;
        }

        void Clear(){
            this->Buffer = new char[this->MaxBytes];
            //this->BufferSize = 0;
            this->NextBytes = 0;
            this->NextField = 0;
        }

        int Unpack(char *str){
            int start = NextCharecter;
            int packSize = FieldSizes[NextField];
            strncpy(str, &Buffer[start], packSize);
            NextCharecter += packSize;
            str[packSize] = 0;
            NextField ++;
            return 0;
        }

        int Pack(char *str){
            if (!Packing){
                return false;
            }

            int length = strlen(str);
            int start = NextCharecter;
            int packSize = FieldSizes[NextField];

            strncpy(&Buffer[start], str, packSize);
            NextCharecter += packSize;
            NextField ++;

            for(int i = (start+length); i < (start+ packSize); i++){
                Buffer[i] = ' ';
            }

            Buffer[NextCharecter] = 0;

            if (NextField == NumberOfFields){
                Packing = false;
                NextField = NextCharecter = 0;
            }

            return true;
        }

        int Read(std::istream &input){
            Clear();
            input.read(Buffer, BufferSize);
            return input.good();
        }

        int Write(std::ostream &output){
            output.write(Buffer, BufferSize);
            return output.good();
        }
};

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