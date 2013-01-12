#pragma once
#include "record.h"

class PrivateRecord :
	public Record
{
public:
	//friend ostream & operator<< (ostream &out, const Record& record);

	PrivateRecord(void);
	~PrivateRecord(void);
	void print();
	Record* create();

	string getSearchValue();

	string name,surname, phone;

	int getSize(){ return sizeof(PrivateRecord); }
};
