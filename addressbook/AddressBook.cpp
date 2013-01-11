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

	int type = 1;
	Record* record = new FirmRecord();
	//Record record;
	//(&record).create();//->create();
	record->create();

	data.seekg(0, ios::end);
	data.write((const char*)&type, sizeof(int));
	data.write((const char*)record, sizeof(FirmRecord));
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

	
	//for(int i = 0; i < records.size(); i++){
	//if(search.compare(records[i].surname) == 0){

	//znaleziono rekord w bazie - usuwamy go i wczytujemy baze ponownie
	//rewrite = true;
	//records.erase(records.begin() + i);
	//}
	//}

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
int AddressBook::find(){

	bool found = false;
	string search;
	cout << "Wpisz nazwisko osoby do wyszukania: ";
	cin >> search;

	for (it = records.begin(); it != records.end() ; ++it)
	{

	if((*it)->getSearchValue().compare(0,search.size(), search) == 0){
		
			found = true;
			(*it)->print();
		}
	}
	if(found){
		return 1;
	} else{
		throw Except("nie ma");
	}
}


/*
Wypisywanie calej ksiazki na 'ekran'
*/
void AddressBook::print(){
	system("cls");

	for (it = records.begin(); it != records.end() ; ++it)
	{
		(*it)->print();
	}
	////for(int i = 0; i < records.size(); i++){
		//cout << "wpis " << i + 1 << endl;

		//records[i].print();
		//cout << records[i];
	//}
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
	data.seekg(0, ios::beg);

	int type;
	FirmRecord *record = new FirmRecord();
	Record *record2 = new FirmRecord();

	//czyscimy wektor (wazne!)
	records.clear();

	while(! data.eof()) {
		data.read((char*)&type,sizeof(int));
		data.read((char*)record,sizeof(FirmRecord));

		//wczytujemy w petli rekordy do wektora
		records.push_back(new FirmRecord(*record));
		//records.push_back(record2);
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

	//for(int i = 0; i < records.size(); i++){

	//w petli wpisujemy zawartosc wektora do pliku
	//data.write((const char*)&records[i], sizeof(records[i]));
	//}
}

/*

*/
AddressBook::~AddressBook()
{
}

ostream & operator<< (ostream &out, const AddressBook& book){

	system("cls");

	out << "operatorem" << endl;
	//for (it = book.records.begin(); it != book.records.end() ; ++it)
	//{
	//(*it)->print();
	//}
	for(int i = 0; i < book.records.size(); i++){
		out << "wpis " << i + 1<<endl;
		out << book.records[i];
	}
	return out;
}
