#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

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
