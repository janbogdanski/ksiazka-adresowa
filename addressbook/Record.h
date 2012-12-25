#pragma once
#include "Except.h"

#include "Base.h"
class Record : public Base
{
public:
	Record(void);
	~Record(void);
	void print();
	Record create();

	string name, surname, address, phone;

};

