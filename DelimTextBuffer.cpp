#include<iostream>
#include "DelimTextBuffer.h"

DelimTextBuffer::DelimTextBuffer(char Delim, int MaxBytes){
    this->Delim = Delim;
    this->MaxBytes = MaxBytes;
    this->Buffer = new char[this->MaxBytes];
    this->BufferSize = 0;
    this->NextByte = 0;
};

void DelimTextBuffer:: Clear(){
    this->BufferSize = 0;
    this->NextByte = 0;
    this->Buffer = new char[this->MaxBytes];
}

void  DelimTextBuffer::PrintBuffer(){
    std::cout << "Contents of buffer:" << Buffer << std::endl;
}

int  DelimTextBuffer::Read(std::istream &input) {
    Clear();
    input.read((char*)&BufferSize, sizeof(int));
    if (BufferSize> MaxBytes){
        return false;
    }
    input.seekg(sizeof(BufferSize));
    input.read(Buffer, BufferSize);
    return input.good();
}

int  DelimTextBuffer::Write(std::ostream &output) const{
    output.write((char*)&BufferSize, sizeof(BufferSize));
    output.write(Buffer, BufferSize);
    return output.good();
}

int  DelimTextBuffer::Pack(const char *str){
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

int  DelimTextBuffer::Unpack(char *str){
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