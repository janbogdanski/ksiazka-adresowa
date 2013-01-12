#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#include "Except.h"
#include "Base.h"
#include "Record.h"
#include "FirmRecord.h"
#include "PrivateRecord.h"
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
	void clear();

	~AddressBook();

	/**
	1 - Firma
	2 - Osoba prywatna
	*/
	vector<int> types;
	vector<string> labels;
	vector <int>::iterator intItr;

	int type;




private:
	void reload();
	void writeDb();
	//data;
};

