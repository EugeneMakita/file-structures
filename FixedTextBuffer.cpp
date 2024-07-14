#include<iostream>
#include<fstream>
#include "personFixed.h"
#include "FixedTextBuffer.h"

FixedTextBuffer:: FixedTextBuffer(int MaxBytes, int MaxField){
    this->MaxBytes = MaxBytes;
    this->Buffer = new char[this->MaxBytes];
    this->MaxFields = MaxField;
    this->FieldSizes = new int[MaxFields];
    this->BufferSize = 0;
    this->NextBytes = 0;
    this->NumberOfFields = 0;
    this->NextField = 0;
    this->NextCharecter = 0;
    this->Packing = true;
}

int FixedTextBuffer::AddField(int FieldSize){
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

int FixedTextBuffer::GetNumberOfFields() const{
    return NumberOfFields;
}

void FixedTextBuffer::Clear(){
    this->Buffer = new char[this->MaxBytes];
    this->NextBytes = 0;
    this->NextField = 0;
}

int FixedTextBuffer::Unpack(char *str){
    if (Packing){
        return false;
    }

    int start = NextCharecter;
    int packSize = FieldSizes[NextField];
    strncpy(str, &Buffer[start], packSize);
    NextCharecter += packSize;
    str[packSize] = 0;
    NextField ++;
    return true;
}

int FixedTextBuffer::Pack(const char *str){
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

    if (NextField >= NumberOfFields){
        Packing = false;
        NextField = NextCharecter = 0;
    }

    return true;
}

int FixedTextBuffer::Read(std::istream &input){
    Clear();
    input.read(Buffer, BufferSize);
    return input.good();
}

int FixedTextBuffer::Write(std::ostream &output) {
    output.write(Buffer, BufferSize);
    return output.good();
}