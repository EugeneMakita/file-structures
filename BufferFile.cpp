#include "BufferFile.h"

BufferFile::BufferFile(DelimTextBuffer &buffer):Buffer(buffer){
}

int BufferFile::Open(std::string filename, int mode){
    File.open(filename, std::ios::binary | std::ios::in |std::ios::out);
    if(!File.good()){ 
        return false;
    }

    //HeaderSize = Buffer.ReadHeader(File);
    File.seekp(0, std::ios::beg);
    File.seekg(0, std::ios::beg);
    return true;
}

int BufferFile::Create(std::string filename){
    File.open(filename, std::ios::out|std::ios::binary);
    if(!File.good()){
        return false;
    }

    //HeaderSize = Buffer.WriteHeader(File);
    File.seekp(0, std::ios::beg);
    File.seekg(0, std::ios::beg);
    return true;
}

int BufferFile::Close(){
    File.close();
    return true;
}

int BufferFile::InitRead(){
    File.seekg(0, std::ios::beg);
    return File.good();
}

int BufferFile::Read(){
    if(File.eof()){
        return true;
    };
    return Buffer.Read(File);
}

int BufferFile::Append(){
    Buffer.PrintBuffer();
    File.seekp(0, std::ios::end);
    return Buffer.Write(File);
}

BufferFile::~BufferFile(){
    Close();
}
