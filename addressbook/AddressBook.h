#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>


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
	vector <Record*> records;
	vector <Record*>::iterator it;

	AddressBook();

	int insert();
	int rm();
	int find();
	void print();
	void clear();

	/**
	1 - Firma
	2 - Osoba prywatna
	*/
	vector<int> types;
	vector<string> labels;

	int type;


private:
	void reload();
	void writeDb();
};

