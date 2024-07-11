#ifndef LENGTHTEXTBUFFER_H
#define LENGTHTEXTBUFFER_H
#include<iostream>
#include<fstream>

class LengthTextBuffer{
    char * Buffer;
    int MaxBytes;
    int BufferSize;
    int NextBytes;
    int *FieldSizes;

    public:
        LengthTextBuffer(int MaxBytes=1024);
        void Clear();
        int Pack(const char *str);
        int Unpack(char *str);
        int Write(std::ofstream &output);
        int Read(std::ifstream &input);
};
#endif