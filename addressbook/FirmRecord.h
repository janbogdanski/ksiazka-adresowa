#pragma once
#include "record.h"

class FirmRecord :
	public Record
{
public:
	friend ostream & operator<< (ostream &out, const Record& record);

	FirmRecord(void);
	~FirmRecord(void);
	void print();
	Record* create();

	string getSearchValue();

	string name, phone, address;

	int getSize(){ return sizeof(FirmRecord); }
};
