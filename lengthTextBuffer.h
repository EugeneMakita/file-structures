#ifndef LENGTHTEXTBUFFER_H
#define LENGTHTEXTBUFFER_H
#include<iostream>
#include<fstream>
#include "IOBuffer.h"

class LengthTextBuffer: public IOBuffer{
    int NextBytes;

    public:
        LengthTextBuffer(int MaxBytes=1024);
        void Clear() override;
        int Pack(const char *str) override;
        int Unpack(char *str) override;
        int Write(std::ostream &output) override;
        int Read(std::istream &input) override;
};
#endif