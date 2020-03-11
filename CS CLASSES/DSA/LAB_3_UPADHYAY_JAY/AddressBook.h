#ifndef ADDRESSBOOK
#define ADDRESSBOOK
#include "Node.h"
const int SPACE = 15;

class AddressBook
{
public:
	AddressBook();
	~AddressBook();
	
	bool Load();// Load and stores into structure
	void WriteFile();// Writes data into a file
	void Search(std::string); // Last Name or phone numebr
	void AddEntry(Node* buffer,int index);// add an entry to linked list.
	void DeleteRec(std::string name);// Last Name or phone number

private:
	Node* head = nullptr;
	int size = 0;
};
#endif
