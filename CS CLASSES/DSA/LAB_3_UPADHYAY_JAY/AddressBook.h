#pragma once
#include "Record.h"

struct RecordList {
	Record data;
	RecordList* ptr = nullptr;

};
class AddressBook
{
public:
	
	
	
	AddressBook();
	~AddressBook();
	bool Load();// Load and stores into structure
	void WriteFile();
	void Search(std::string); // Last Name or phone numebr
	void AddEntry(RecordList* buffer,int index);
	void DeleteRec(std::string name);// Last Name or phone number




private:
	RecordList* head = nullptr;// MAY CAUSE ERRORS, MOVED THESE TO PRIVATE
	int size = 0;// did i ever use this????

};
void clearCin();
std::string strLower(std::string tempStr);
void InputMenu(AddressBook& reclist, int choice);
void GetEntryInput(AddressBook& reclist);