#include "FirmRecord.h"

FirmRecord::FirmRecord(void)
{
	type = 1;
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

