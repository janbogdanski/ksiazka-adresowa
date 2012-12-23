#pragma once
#include "Base.h"
class Record : public Base
{
public:
	Record(void);
	~Record(void);
		void print();
	string name, surname, address, phone;

};

