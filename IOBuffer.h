#ifndef IOBUFFER_H
#define IOBUFFER_H
#include<iostream>

class IOBuffer{
    protected:
        char *Buffer;
        int BufferSize;
        int MaxBytes;

    public:
        IOBuffer(int maxBytes=1024);
        virtual void Clear();
        virtual int Unpack(char *str);
        virtual int Pack(const char *str);
        virtual int Read(std::istream &input);
        virtual int Write(std::ostream &output) const;
};

#endif