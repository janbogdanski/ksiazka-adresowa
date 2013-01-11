#pragma once
#include "Except.h"

#include "Base.h"
class Record// : public Base
{
public:
	friend ostream & operator<< (ostream &out, const Record& record);
	Record(void);
	~Record(void);
	virtual void print(){};

	virtual Record* create(){
		return new Record();
	};
	virtual string getSearchValue(){ return string();};
	int type;
	//string name, surname, address, phone;

};

