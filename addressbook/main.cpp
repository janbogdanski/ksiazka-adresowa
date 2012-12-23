#include <iostream>

#include "AddressBook.h"
#include "Record.h"

using namespace std;
int main(){

	AddressBook book = AddressBook();

	book.insert();
	book.print();
	cout << "asdF" << endl;
	return 1;
}