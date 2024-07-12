#ifndef PERSON_FIXED_H
#define PERSON_FIXED_H
#include<iostream>
#include<string>
#include<fstream>
#include "DelimTextBuffer.h"
#include "lengthTextBuffer.h"
#include "FixedTextBuffer.h"

class Person{
    public:
        char FirstName[11];
        char LastName[11];
        char Address[16];
        char City[15];
        char State[15];
        char ZipCode[7];

        Person();
        friend std::istream &operator>>(std::istream &input, Person &person);
        friend std::ostream &operator<<(std::ostream &input, Person &person);
        int pack(DelimTextBuffer &buffer);
        int pack(LengthTextBuffer &buffer);
        int pack(FixedTextBuffer &buffer);
        int unpack(DelimTextBuffer buffer);
        int unpack(LengthTextBuffer buffer);
        int unpack(FixedTextBuffer buffer);
        void initFixedTextBuffer(FixedTextBuffer &buffer);
};
#endif