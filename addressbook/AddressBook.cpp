#include "AddressBook.h"

/*
Konstruktor!
*/
AddressBook::AddressBook()
{
	types.push_back(1);
	types.push_back(2);
	labels.push_back("Firma");
	labels.push_back("Prywatna");
	//int types []= {1,2}; 
	//types [] = {1,2};
	//types[0] = 1;
	//types[1] = 2;
	//labels[0] = "Firma";
	//labels[1] = "Prywatna";
	//string labels []= {'Firma', 'Prywatna'};
	reload();
}

/*
Dodawanie rekordu do ksiazki

Tworzy instancje Record (cin wciaga odpowiednie dane) i zapisuje na koncu ksiazki
*/
int AddressBook::insert(){

	cout << "Podaj typ rekordu" << endl;
	//for (intItr = types.begin(); intItr != types.end() ; ++intItr){
	for (int i = 0; i < types.size(); i++){

		cout << types[i] << ": " << labels[i] << endl;
		//cout << *intItr;
	}
	cin >> type;

	Record* record;
	int size;

	if(type == 1){

		record = new FirmRecord();
		size = sizeof(FirmRecord);
	} else if(type == 2){
		record = new FirmRecord();
		size = sizeof(FirmRecord);
	} else{
		return 1;
		record = new FirmRecord();
		size = sizeof(FirmRecord);
	}

	record->create();

	data.seekg(0, ios::end);
	data.write((const char*)&type, sizeof(int));

	data.write((const char*)record, size);
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

	it = records.begin();

	for(int i = 0; i < records.size(); i++){
		if(records[i]->getSearchValue().compare(search) == 0){

			//znaleziono rekord w bazie - usuwamy go i wczytujemy baze ponownie
			rewrite = true;
			cout << "usuwam rekord: " <<endl;
			records[i]->print();
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
	//FirmRecord *record = new FirmRecord();
	Record *record2 = new FirmRecord();

	//czyscimy wektor (wazne!)
	records.clear();

	while(! data.eof()) {

		//wczytujemy w petli rekordy do wektora
		data.read((char*)&type,sizeof(int));
		if(type == 1){

			FirmRecord *record = new FirmRecord();
			data.read((char*)record,sizeof(FirmRecord));
			if(! data.eof()){

				records.push_back(new FirmRecord(*record));
			}
		} else if(type == 2){
			FirmRecord *record = new FirmRecord();
			data.read((char*)record,sizeof(FirmRecord));
			if(! data.eof()){

				records.push_back(new FirmRecord(*record));
			}
		} else{
			FirmRecord *record = new FirmRecord();
			data.read((char*)record,sizeof(FirmRecord));
			if(! data.eof()){

				records.push_back(new FirmRecord(*record));
			}
		}
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

	data.seekg(0, ios::end);
	for (int i = 0; i < records.size(); i++)
	//for (it = records.begin(); it != records.end() ; it++)

	{
		//cout << records[i];
		//cout << "";
		//(*it)->print();
		data.write((const char*)&records[i]->type, sizeof(int));
		data.write((const char*)records[i], sizeof(FirmRecord));

		//cout << (*it) << endl;
		//cout << (*it) << endl;
				//data.write((const char*)(*it)->type, sizeof(int));
		//data.write((const char*)(*it), sizeof(FirmRecord));

			//data.write((const char*)(it), sizeof(FirmRecord));
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
