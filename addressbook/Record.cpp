#include "Record.h"

Record::Record(void)
{
}

Record::~Record(void)
{
}


void Record::print(){

	cout << "print record" << endl;
	cout << name << " " << surname << " " << phone << " " << address << endl;
}

Record Record::create(){

	cout << "Podaj imie: ";
	cin >> name;
	cout << "Podaj nazwisko: ";
	cin >> surname;
	cout << "Podaj adres: ";
	cin >> address;
	return *this;
}


