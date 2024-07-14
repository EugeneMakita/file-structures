#include<iostream>
#include "IOBuffer.h"

class DelimTextHeader{
    public:
        char Delim;
        DelimTextHeader(char delim){
            Delim = delim;
        }
    
        int Pack(IOBuffer &Buffer){
            return 0;
        }

        int Unpack(IOBuffer &Buffer){
            return 0;
        }
};