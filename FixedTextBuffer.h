#ifndef FIXEDTEXTBUFFER_H
#define FIXEDTEXTBUFFER_H
#include<iostream>

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
        FixedTextBuffer(int MaxBytes=60, int MaxFields=6);
        int AddField(int FieldSize);
        int GetNumberOfFields() const;
        void Clear();
        void PrintBuffer();
        int Unpack(char *str);
        int Pack(char *str);
        int Read(std::istream &input);
        int Write(std::ostream &output);
};
#endif