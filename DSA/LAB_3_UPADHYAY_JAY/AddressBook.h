#pragma once
#include "Record.h"

struct RecordList {
	Record data;
	RecordList* ptr;
};
class AddressBook
{
public:
	RecordList* head=nullptr;
	int size=0;
	AddressBook();
	~AddressBook();
	void Load();// Load and stores into structure
	void Search(std::string); // Last Name or phone numebr
	void AddEntry(RecordList* buffer,int index);
	void Delete(string name);// Last Name or phone number




private:
	

};
