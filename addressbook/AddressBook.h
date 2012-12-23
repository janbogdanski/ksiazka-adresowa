#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>


#include "Base.h"
#include "Record.h"
class AddressBook :
	public Base
{
public:
	fstream data;
	//Record recordss[];
	vector <Record> records;
	//vector <int> records;
	AddressBook();
	//AddressBook(const int& in);

	int insert();
	int rm();
	Record find();
	void print();

	~AddressBook();



private:
	void reload();
	void writeDb();
	//data;
};

class myexception: public exception
{
public:

	myexception(const string& message):msg(message) {
	}
  virtual const char* what() const throw()
  {
    //return (const char*)&msg;
    return msg.c_str();
    //return &msg;
  }
private:
	string msg;
	//char msg;
};