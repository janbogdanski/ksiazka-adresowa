#pragma once
#include "Base.h"
#include "Record.h"
class AddressBook :
	public Base
{
public:
	AddressBook();
	AddressBook(const int& in);

	int insert(const Record& record);
	int del(const int& id);
	int read(const int& id);
	int write(const int& id, const Record& record);

	void print();

	~AddressBook();

private:
	//data;
};
