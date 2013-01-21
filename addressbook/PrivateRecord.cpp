#include "PrivateRecord.h"

PrivateRecord::PrivateRecord(void)
{
	type = 2;
}


void PrivateRecord::print(){

	cout << "PRYWATNY" <<endl;
	cout << "\tImie: " << name << endl;
	cout << "\tNazwisko: " << surname << endl;
	cout << "\tTelefon: " << phone << endl;
	//cout << "\tAdres: " << address << endl;
	//cout << "\tPesel: " << pesel << endl;

}


Record* PrivateRecord::create(){

	cout << "Podaj imie osoby: ";
	cin >> name;
	cout << "Podaj nazwisko osoby: ";
	cin >> surname;
	cout << "Podaj telefon osoby: ";
	cin >> phone;
	//cout << "Podaj adres osoby: ";
	//cin >> address;
	//cout << "Podaj pesel osoby: ";
	//cin >> pesel;
	return this;
}
string PrivateRecord::getSearchValue(){

	return surname;
}

