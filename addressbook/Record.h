#pragma once
#include <iostream>
#include <string>
#include "Except.h"


class Record
{
public:
	Record(void){};
	virtual void print(){};

	virtual Record* create(){
		return new Record();
	};
	virtual string getSearchValue(){ return string();};
	int type;
	//wlasciwosi przeniesione do konkretnych instancji

};

