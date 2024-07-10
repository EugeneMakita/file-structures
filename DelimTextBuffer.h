#ifndef DELIMTEXTBUFFER_H
#define DELIMTEXBUFFER_H
#include<iostream>

class DelimTextBuffer{
    char Delim;
    char *Buffer;
    int MaxBytes;
    int BufferSize;
    int NextByte;

    public:
        DelimTextBuffer(char Delim='|', int MaxBytes=1024);
        void Clear();
        void PrintBuffer();
        int Read(std::istream &input);

        int Write(std::ostream &output) const;

        int Pack(const char *str);

        int Unpack(char *str);
};
#endif