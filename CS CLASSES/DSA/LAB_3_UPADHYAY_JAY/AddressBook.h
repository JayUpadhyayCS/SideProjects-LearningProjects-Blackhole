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
	Node* Search(std::string, Node* &prev); // Last Name or phone numebr


	void AddEntry(Node* &buffer);// add an entry to linked list.
	void DeleteNode(Node* current,Node* prev);// Last Name or phone number
	void EmptyList();
private:
	Node* head = nullptr;
	int size = 0;
};
#endif
