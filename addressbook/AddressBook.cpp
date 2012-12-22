#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "AddressBook.h"

AddressBook::AddressBook()
{
    ifstream    data("base.txt");
    string      line;

    while(std::getline(data,line,'\n'))
    {
		if(line == "\n") cout <<"line";
		cout << data.eof();
		cout << line. << endl;
        stringstream    str(line);
        std::string          text;

        std::getline(str,text,'=');

        double   value;
        str >> value;
    }
	data.close();
	//todo load boook
}
AddressBook::AddressBook(const int& in){
cout << "Asdf";
}

int AddressBook::insert(const Record& record){

	return 1;
}
int AddressBook::del(const int& id){

	return 1;
}
int AddressBook::read(const int& id){

	return 1;

}
int AddressBook::write(const int& id, const Record& record){

	return 1;
}

void AddressBook::print(){

	cout << "print ksiazki" << endl;
}

AddressBook::~AddressBook()
{
}