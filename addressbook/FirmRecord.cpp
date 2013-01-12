#include "FirmRecord.h"

FirmRecord::FirmRecord(void)
{
	type = 1;
}

FirmRecord::~FirmRecord(void)
{
}

void FirmRecord::print(){

	cout << "FIRMA" <<endl;
	cout << "\tNazwa firmy: " << firmName << endl;
	cout << "\tREGON: " << regon << endl;
	cout << "\tAdres: " << address << endl;
}

Record* FirmRecord::create(){

	cout << "Podaj nazwe firmy: ";
	cin >> firmName;
	cout << "Podaj REGON firmy: ";
	cin >> regon;
	cout << "Podaj adres firmy: ";
	cin >> address;
	return this;
}
string FirmRecord::getSearchValue(){

	return firmName;
}

//ostream & operator<< (ostream &out,  Record& record){


	//out << "operatorem firma" <<endl;
	//out << "\tname: " << record.name << endl;
	//out << "\taddress: " << record.address << endl;
	//out << "\tphone: " << record.phone << endl << endl;;
//return out;
//}