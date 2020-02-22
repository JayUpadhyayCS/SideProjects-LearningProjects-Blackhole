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
	AddressBook();
	~AddressBook();
	void Load();// Load and stores into structure
	void Search(std::string); // Last Name or phone numebr
	void AddEntry();
	void Delete();// Last Name or phone number




private:
	

};
