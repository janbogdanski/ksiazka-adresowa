#include "AddressBook.h"

/*
Konstruktor!
*/
AddressBook::AddressBook()
{
	reload();
}

/*
Dodawanie rekordu do ksiazki

Tworzy instancje Record (cin wciaga odpowiednie dane) i zapisuje na koncu ksiazki
*/
int AddressBook::insert(){

	Record record;
	record.create();

	data.seekg(0, ios::end);
	data.write((const char*)&record, sizeof(record));
	reload();


	return 1;
}

/*
Usuwanie rekordu
*/
int AddressBook::rm(){

	//czy wymagamy ponownego wczytania DB? Po usunieciu tak
	bool rewrite = false;

	//wyszukiwane slowo(nazwisko)
	string search;
	cout << "Wpisz nazwisko osoby do usuniecia: ";
	cin >> search;

	for(int i = 0; i < records.size(); i++){
		if(search.compare(records[i].surname) == 0){

			//znaleziono rekord w bazie - usuwamy go i wczytujemy baze ponownie
			rewrite = true;
			records.erase(records.begin() + i);
		}
	}

	if(rewrite){

		//po modyfikacji vectora, aktualizujemy tez plik zrodlowy i wczytujemy go ponownie
		writeDb();
		reload();
	}

	return 1;
}

/*
Wyszukiwanie rekordow po nazwisku
*/
Record AddressBook::find(){

	bool found = false;
	string search;
	cout << "Wpisz nazwisko osoby do wyszukania: ";
	cin >> search;

	for(int i = 0; i < records.size(); i++){
		if(search.compare(records[i].surname) == 0){

			//znaleziono
			found = true;
			return records[i];
		}
	}
	if(!found){
		throw myexception("nie ma");
		//todo moze jakos da sie przechwycic aby zwrocic false? except?
		Record record;
		return record;
	}
}


/*
Wypisywanie calej ksiazki na 'ekran'
*/
void AddressBook::print(){
	system("cls");


	for(int i = 0; i < records.size(); i++){
		cout << "wpis " << i + 1<<endl;
		records[i].print();
	}
}

/*
Wczytywanie bazy z pliku do wektora, na ktorym dalej operujemy
*/
void AddressBook::reload(){


	if( !data.is_open() ){

		//jesli plik istnieje, ale nie jest jeszcze otwarty
		data.open("base.txt");
	}

	if( !data.is_open() ){

		//jesli plik NIE istnieje, tworzymy go
		data.open("base.txt", ios_base::in | ios_base::out | ios_base::trunc);
	}

	//sprawdzamy dlugosc pliku i obliczamy ilosc iteracji (tzn wpisow) na podstawie size(record)
	int i, count, length;
	Record record;
	data.seekg(0, ios::end);
	length = data.tellg();
	count = length/sizeof(record);

	//wracamy na poczatek
	data.seekg(0, ios::beg);

	//czyscimy wektor (wazne!)
	records.clear();

	for(i=0; i < count; i++)
	{
		//wczytujemy w petli rekordy do wektora
		data.read((char*)&record, sizeof(record));
		records.push_back(record);
	}
}


/*
Zapis bazy na dysk, na podstawie zawartosci wektora

Operacje przebiegaja na wektorze, aby pozniej byly dostepne, zapisujemy je do pliku
*/
void AddressBook::writeDb(){

	//zamykamy i usuwamy plik (najprostszy sposob na otrzymanie pustego pliku.. :)
	data.close();
	remove("base.txt");

	//tworzymy plik
	if(!data.is_open()){

		data.open("base.txt", ios_base::in | ios_base::out | ios_base::trunc);
	}

	for(int i = 0; i < records.size(); i++){

		//w petli wpisujemy zawartosc wektora do pliku
		data.write((const char*)&records[i], sizeof(records[i]));
	}
}

/*

*/
AddressBook::~AddressBook()
{
}
