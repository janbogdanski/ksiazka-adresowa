#include <iostream>

using namespace std;



#include "AddressBook.h"
#include "Record.h"
#include "Templatee.h"


int main(){

	//AddressBook<int>* book = new AddressBook<int>();// = AddressBook();
Templatee<int> t = Templatee<int>();

	//system ("pause");
	int action = 0;
	while(1){
		system("cls");
		cout << "Ksiazka adresowa" << endl << endl;
		cout << "-----------------MENU----------" << endl<< endl;
		cout << "1. Dodaj nowa osobe"<< endl;
		cout << "2. Wyszukaj osobe po nazwisku"<< endl;
		cout << "3. Drukuj ksiazke"<< endl;
		cout << "4. Usun osobe"<< endl;
		cout << "5. Zamknij"<< endl
			<< endl;
		cout << "-------------------------------"<< endl<< endl;

		cout << "wybierz akcje: ";
		cin >> (int)action;
		system("cls");
		switch(action){

			case 1:
				//book.insert();
				system ("pause");

				break;

			case 2:
				try{

					//cout << book.find() << endl;
					//book.find().print();
				}catch(Except& e){
					cout <<e.what();
				}
				system ("pause");

				break;

			case 3:
				//cout << book;
				//book.print();
				system ("pause");


				break;
			case 4:
				//book.rm();
				system ("pause");


				break;
			case 5: exit(1);
				break;
			default:
				//book.print();
				system ("pause");

				break;
		}
	}

	cout << "asdF" << endl;
	return 1;
}