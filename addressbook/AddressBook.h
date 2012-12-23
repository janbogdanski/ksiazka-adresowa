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
	int del(const int& id);
	int read(const int& id);
	int update(const int& id, const Record& record);

	void print();

	~AddressBook();



private:
	void reload();
	//data;
};
