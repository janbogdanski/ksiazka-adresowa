#pragma once
#include "record.h"

class PrivateRecord :
	public Record
{
public:
	PrivateRecord(void);
	void print();
	Record* create();

	string getSearchValue();

	string name,surname, phone;
};
