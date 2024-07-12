#include<iostream>
#include<fstream>
#include "lengthTextBuffer.h"

LengthTextBuffer::LengthTextBuffer(int MaxBytes){
    this->MaxBytes = MaxBytes;
    Buffer = new char[this->MaxBytes];
    BufferSize = 0;
    NextBytes = 0;
}

void LengthTextBuffer::Clear(){
    Buffer = new char[this->MaxBytes];
    BufferSize = 0;
    NextBytes = 0;
    return;
}

int LengthTextBuffer::Pack(const char *str){
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

int LengthTextBuffer::Unpack(char *str){
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

int LengthTextBuffer::Write(std::ostream &output) const{
    output.write((char *)&BufferSize, sizeof(BufferSize));
    output.write(Buffer, BufferSize);
    return output.good();
}

int LengthTextBuffer::Read(std::istream &input){
    Clear();
    input.read((char*)&BufferSize, sizeof(int));
    if (BufferSize> MaxBytes){
        return false;
    }

    input.seekg(sizeof(BufferSize));
    input.read(Buffer, BufferSize);

    return input.good();
}