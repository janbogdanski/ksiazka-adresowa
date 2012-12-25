#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>


#include "Except.h"
#include "Base.h"
#include "Record.h"
template <class T>
class AddressBook :
	public Base
{
public:
	friend ostream & operator<< (ostream &out, const AddressBook<T>& book);
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

	//~AddressBook();



private:
	void reload();
	void writeDb();
	//data;
};

