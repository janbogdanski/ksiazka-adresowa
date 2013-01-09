#include "FirmRecord.h"

FirmRecord::FirmRecord(void)
{
}

FirmRecord::~FirmRecord(void)
{
}

void FirmRecord::print(){

	//cout << "\tname: " << name << endl;
	//cout << "\tphone: " << phone << endl;
	//cout << "\taddress: " << address << endl;
}


Record* FirmRecord::create(){

	cout << "Podaj nazwe firmy: ";
	cin >> name;
	cout << "Podaj telefon firmy: ";
	cin >> phone;
	cout << "Podaj adres firmy: ";
	cin >> address;
	return this;
}

ostream & operator<< (ostream &out,  Record& record){


	//out << "operatorem firma" <<endl;
	//out << "\tname: " << record.name << endl;
	//out << "\taddress: " << record.address << endl;
	//out << "\tphone: " << record.phone << endl << endl;;
return out;
}