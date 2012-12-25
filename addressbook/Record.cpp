#include "Record.h"

/*
Konstruktor!
*/
Record::Record(void)
{
}

/*

*/
Record::~Record(void)
{
}


/*
Wypisywanie zaeartosci rekordu na ekran
*/
void Record::print(){

	cout << "\tname: " << name << endl;
	cout << "\tsurname: " << surname << endl;
	cout << "\taddress: " << address << endl;
	cout << "\tphone: " << phone << endl << endl;;
}

/*
Tworzenie rekordu
*/
Record Record::create(){

	cout << "Podaj imie: ";
	cin >> name;
	cout << "Podaj nazwisko: ";
	cin >> surname;
	cout << "Podaj adres: ";
	cin >> address;
	return *this;
}


ostream & operator<< (ostream &out, const Record& record){

	out << "operatorem" <<endl;
	out << "\tname: " << record.name << endl;
	out << "\tsurname: " << record.surname << endl;
	out << "\taddress: " << record.address << endl;
	out << "\tphone: " << record.phone << endl << endl;;
return out;
}