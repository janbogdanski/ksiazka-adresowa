#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Except.h"
#include "Base.h"
#include "Record.h"
#include "FirmRecord.h"
class AddressBook :
	public Base
{
public:
	friend ostream & operator<< (ostream &out, const AddressBook& book);
	fstream data;
	//Record recordss[];
	vector <Record*> records;
	vector <Record*>::iterator it;

	//vector <int> records;
	AddressBook();
	//AddressBook(const int& in);

	int insert();
	int rm();
	int find();
	void print();

	~AddressBook();



private:
	void reload();
	void writeDb();
	//data;
};

