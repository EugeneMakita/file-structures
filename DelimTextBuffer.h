#ifndef DELIMTEXTBUFFER_H
#define DELIMTEXTBUFFER_H
#include<iostream>
#include "IOBuffer.h"

class DelimTextBuffer: public IOBuffer{
    char Delim;
    int NextByte;

    public:
        DelimTextBuffer(char Delim='|', int MaxBytes=1024);
        void Clear() override;
        void PrintBuffer();
        int GetBufferSize();
        int Read(std::istream &input) override;

        int Write(std::ostream &output) const override;

        int Pack(const char *str) override;

        int Unpack(char *str) override;
};
#endif