#include <iostream>

#include "AddressBook.h"
#include "Record.h"

using namespace std;
int main(){

	AddressBook book = AddressBook();
	int action = 0;


	while(1){
		system("cls");
		cout << "Ksiazka adresowa" << endl<< endl;
		cout << "-----------------MENU----------" << endl<< endl;
		cout << "1. Dodaj nowa osobe"<< endl;
		cout << "2. Wyszukaj osobe po nazwisku"<< endl;
		cout << "3. Drukuj ksiazke"<< endl;
		cout << "4. usun osobe"<< endl<< endl;
		cout << "-------------------------------"<< endl<< endl;

		cout << "wybierz akcje:";
		cin >> action;
		system("cls");
		switch(action){

			case 1:
				book.insert();
				system ("pause");

				break;

			case 2:
				book.find().print();
				system ("pause");

				break;

			case 3:
				book.print();
				system ("pause");


				break;
			case 4:
				book.rm();
				system ("pause");


				break;
			default:
				book.print();
				system ("pause");

				break;
		}
	}

	cout << "asdF" << endl;
	return 1;
}