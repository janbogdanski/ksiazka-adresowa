#include <iostream>

using namespace std;



#include "AddressBook.h"
#include "Record.h"

int main(){

	AddressBook book = AddressBook();
	int action = 0;

	while(1){
		system("cls");
		cout << "Ksiazka adresowa" << endl << endl;
		cout << "-----------------MENU----------" << endl<< endl;
		cout << "1. Dodaj nowy rekord"<< endl;
		cout << "2. Wyszukaj rekord po >>identyfikatorze<<"<< endl;
		cout << "3. Drukuj ksiazke"<< endl;
		cout << "4. Usun rekord"<< endl;
		cout << "5. Zamknij"<< endl
			<< endl;
		cout << "-------------------------------"<< endl<< endl;

		cout << "wybierz akcje: ";
		cin >> (int)action;
		system("cls");
		switch(action){

			case 1:
				book.insert();
				system ("pause");

				break;

			case 2:
				try{

					//wyszukaj i wyswietl znalezione
					book.find();

				}catch(Except& e){
					cout <<e.what();
				}
				system ("pause");

				break;

			case 3:
				cout << book;
				//book.print();
				system ("pause");


				break;
			case 4:
				book.rm();
				system ("pause");


				break;
			case 5: exit(1);
				break;

			case 9: 
				book.clear();
				break;
			default:
				book.rm();
				system ("pause");

				break;
		}
	}

	cout << "asdF" << endl;
	return 1;
}