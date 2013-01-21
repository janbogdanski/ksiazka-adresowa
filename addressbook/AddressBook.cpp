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
	
	reload();
}

/*
Dodawanie rekordu do ksiazki

Tworzy instancje Record (cin wciaga odpowiednie dane) i zapisuje na koncu ksiazki
*/
int AddressBook::insert(){

	cout << "Podaj typ rekordu" << endl;

	//petla po dostepnych typach rekordow
	for (int i = 0; i < types.size(); i++){

		//printuje powiazana etykiete typu rekordu
		cout << types[i] << ": " << labels[i] << endl;
	}
	cin >> (int)type;

	Record* record;
	int size;

	if(type == 1){

		record = new FirmRecord();
		size = sizeof(FirmRecord);
	} else if(type == 2){
		record = new PrivateRecord();
		size = sizeof(PrivateRecord);
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
	cout << "Wpisz >>identyfikator<< rekordu do usuniecia: ";
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
	cout << "Wpisz >>identyfikator<< rekordu do wyszukania: ";
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
			PrivateRecord *record = new PrivateRecord();
			data.read((char*)record,sizeof(PrivateRecord));
			if(! data.eof()){

				records.push_back(new PrivateRecord(*record));
			}
		} else{
			//jakies smieci..
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
	for (int i = 0; i < records.size(); i++){
		data.write((const char*)&records[i]->type, sizeof(int));


		if(records[i]->type == 1){

		data.write((const char*)records[i], sizeof(FirmRecord));
			
		} else if(records[i]->type == 2){
		data.write((const char*)records[i], sizeof(PrivateRecord));
			
		} else{
		data.write((const char*)records[i], sizeof(FirmRecord));
			
		}
	}
}


void AddressBook::clear(){

	data.close();
	data.open("base.txt", ios_base::in | ios_base::out | ios_base::trunc);
	reload();


}
ostream & operator<< (ostream &out, const AddressBook& book){

	system("cls");

	out << "operatorem" << endl;
	for(int i = 0; i < book.records.size(); i++){
		out << "wpis " << i + 1<<endl;
		book.records[i]->print();
	}
	return out;
}
