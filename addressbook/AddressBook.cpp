

#include "AddressBook.h"

AddressBook::AddressBook()
{
	reload();
}


int AddressBook::insert(){

	Record record;
	record.create();

	data.seekg(0, ios::end);
	//cout << "qq";
	//record.print();
	data.write((const char*)&record, sizeof(record));
	reload();


	return 1;
}
int AddressBook::rm(){

	Record record;
	bool rewrite = false;
	string search;
	cout << "podaj nazw";
	cin >> search;

	for(int i = 0; i < records.size(); i++){
		if(search.compare(records[i].surname) == 0){

			//znaleziono
			rewrite = true;
			records.erase(records.begin() + i);
			//cout << records[i].surname << " " << search.compare(records[i].surname) << endl;
		}
	}

	if(rewrite){

		writeDb();
		reload();
	}

	return 1;
}
Record AddressBook::find(){

	Record record;
	string search;
	cout << "podaj nazw";
	cin >> search;

	for(int i = 0; i < records.size(); i++){
		if(search.compare(records[i].surname) == 0){

			//znaleziono
			return records[i];

			//cout << records[i].surname << " " << search.compare(records[i].surname) << endl;
		}
	}
	return record;
}
int AddressBook::update(const int& id, const Record& record){

	return 1;
}

void AddressBook::print(){
	system("cls");


	for(int i = 0; i < records.size(); i++){
		cout << "wpis " << i + 1<<endl;
		cout << "\tname: " << records[i].name << endl;
		cout << "\tsurname: " << records[i].surname << endl;
		cout << "\taddress: " << records[i].address << endl;
		cout << "\tphone: " << records[i].phone << endl << endl;;

	}
	cout << "print ksiazki" << endl;
}
void AddressBook::reload(){
	if( !data.is_open() ){

		data.open("base.txt");
	}

	if( !data.is_open() )
		data.open("base.txt", ios_base::in | ios_base::out | ios_base::trunc);
	Record record;
	int i, count, length;
	data.seekg(0, ios::end);

	length = data.tellg();
	count = length/sizeof(record);
	data.seekg(0, ios::beg);

	records.clear();

	for(i=0; i < count; i++)
	{
		data.read((char*)&record, sizeof(record));
		records.push_back(record);
	}

}

void AddressBook::writeDb(){

	//data.close;
	data.close();
	remove("base.txt");
	cout << 'asdf';
	if( !data.is_open() )
		data.open("base.txt", ios_base::in | ios_base::out | ios_base::trunc);

	for(int i = 0; i < records.size(); i++){

		data.write((const char*)&records[i], sizeof(records[i]));

	}
}


AddressBook::~AddressBook()
{
}
