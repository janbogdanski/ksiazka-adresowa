#pragma once
#include "Except.h"

#include "Base.h"
class Record : public Base
{
public:
	friend ostream & operator<< (ostream &out, const Record& record);
	Record(void);
	~Record(void);
	void print();
	Record create();

	string name, surname, address, phone;

};

