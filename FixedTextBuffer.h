#ifndef FIXEDTEXTBUFFER_H
#define FIXEDTEXTBUFFER_H
#include<iostream>
#include "IOBuffer.h"

class FixedTextBuffer: public IOBuffer{
    int NextBytes;
    int *FieldSizes;
    int MaxFields;
    int NumberOfFields;
    int Packing;
    int NextField;
    int NextCharecter;

    public:
        FixedTextBuffer(int MaxBytes=60, int MaxFields=6);
        int AddField(int FieldSize);
        int GetNumberOfFields() const;
        void Clear() override;
        int Unpack(char *str) override;
        int Pack(const char *str) override;
        int Read(std::istream &input) override;
        int Write(std::ostream &output) override;
};
#endif