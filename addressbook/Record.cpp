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

/*
Tworzenie rekordu
*/



ostream & operator<< (ostream &out, const Record& record){

	out << "operatorem" <<endl;
	out << "\tname: " << record.name << endl;
	out << "\tsurname: " << record.surname << endl;
	out << "\taddress: " << record.address << endl;
	out << "\tphone: " << record.phone << endl << endl;;
return out;
}