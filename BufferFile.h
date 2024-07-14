#include<fstream>
#include<iostream>
#include<string>
#include "DelimTextBuffer.h"

class BufferFile{
    protected:
        int HeaderSize;
        DelimTextBuffer &Buffer;

    public:
        std::fstream File;
        BufferFile(DelimTextBuffer &buffer);

        int Open(std::string filename, int mode);

        int Create(std::string filename);

        int Close();

        int InitRead();

        int Read();

        int Append();

        ~BufferFile();
};