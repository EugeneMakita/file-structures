#include<iostream>
#include<string>
#include<fstream>

class Person{
    public:
        char FirstName[11];
        char LastName[11];
        char Address[16];
        char City[15];
        char State[15];
        char ZipCode[7];
        const int MAX_BUFFER_SIZE = 200;

        Person(){
        }

        int writePerson(std::ostream &output){
            char buffer[MAX_BUFFER_SIZE];
            strcpy(buffer, " ");
            strcpy(buffer, this->FirstName);strcat(buffer, "|");
            strcat(buffer, this->LastName);strcat(buffer, "|");
            strcat(buffer, this->Address);strcat(buffer, "|");
            strcat(buffer,this->City);strcat(buffer, "|");
            strcat(buffer,this->State);strcat(buffer, "|");
            strcat(buffer, this->ZipCode);strcat(buffer, "|");
            long length = strlen(buffer);
            output.write(reinterpret_cast<char*>(&length), sizeof(length));
            output.write(buffer, length);
            return 0;
        }
};

std::istream &operator>>(std::istream &input, Person &person){
    const char DELIMITER = '|';
    std::cin.getline(person.FirstName,11, DELIMITER);
    if (strlen(person.FirstName)==0){return input;}
    std::cin.getline(person.LastName,11, DELIMITER);
    std::cin.getline(person.Address,16, DELIMITER);
    std::cin.getline(person.City,15, DELIMITER);
    std::cin.getline(person.State,15, DELIMITER);
    std::cin.getline(person.ZipCode,7, DELIMITER);
    return input;
}

int main(){
    Person person;
    std::cin >> person;
    std::ofstream file;

    file.open("new2.bin", std::ios::app);
    if (file.is_open()){
        person.writePerson(file);
    }

    file.close();
    return 0;
}