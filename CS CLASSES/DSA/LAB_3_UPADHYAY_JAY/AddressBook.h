#pragma once
#include "Record.h"


class AddressBook
{
public:
	
	
	
	AddressBook();
	~AddressBook();
	bool Load();// Load and stores into structure
	void WriteFile();
	void Search(std::string); // Last Name or phone numebr
	void AddEntry(Record* buffer,int index);
	void DeleteRec(std::string name);// Last Name or phone number




private:
	Record* head = nullptr;
	int size = 0;

};
void clearCin();
std::string strLower(std::string tempStr);
void InputMenu(AddressBook& reclist, int choice);
void GetEntryInput(AddressBook& reclist);