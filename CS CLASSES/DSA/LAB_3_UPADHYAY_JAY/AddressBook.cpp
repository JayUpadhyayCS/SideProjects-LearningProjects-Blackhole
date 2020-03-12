#include "AddressBook.h"
#include "UtilityFunctions.h"
#include <fstream>
#include <iostream>
#include <new>
#include <cctype>
#include <iomanip>
#include <string>


AddressBook::AddressBook()
{
}
AddressBook::~AddressBook()
{
	EmptyList();
}

bool AddressBook::Load() //loads data and if false ends program
{
	
	std::ifstream inFile;
	//inFile.open("input.txt");
	inFile.open("E:\\SideProjects\\CS CLASSES\\DSA\\LAB_3_UPADHYAY_JAY\\input.txt");
	if (!inFile)
	{
		std::cout << "Error opening or finding file." << std::endl;
		return false;
	}
	//RecordList* buffer= new (std::nothrow) RecordList;
	
	Node* trav = new (std::nothrow) Node;
	trav->LoadNode(inFile);
	if (!trav)
	{
		std::cout << "Error with allocating dynamic memory, ending program. Please reduce file size and try again." << std::endl;
		return false;
	}
	size++;
	head =trav;// head points to first created node.
	while (!inFile.eof())// go to get rest of nodes
	{ 
		trav->SetPtr(new (std::nothrow) Node());
		if (!trav->GetPtr())
		{
			std::cout << "Error with allocating dynamic memory, ending program. Please reduce file size and try again." << std::endl;
			return false;
		}
		trav = trav->GetPtr();// traverse forward
		trav->LoadNode(inFile);
		size++;
	}
	inFile.close();
	std::cout << "Success taking in data." << std::endl;
	return true;
}
Node* AddressBook::Search(std::string name, Node* &prev)// take in string and traverse LL until found. If not found boolean remains false, and outputed
{
	Node* trav = head;
	if (!trav)
	{
		return nullptr;
	}
	int index = 1;
	if (trav->GetData().GetLastName() == name || trav->GetData().GetPhoneNum() == name)
	{
		prev = head;
		return prev;
	}
	while (trav->GetPtr() != nullptr) {

		if (trav->GetPtr()->GetData().GetLastName() == name || trav->GetPtr()->GetData().GetPhoneNum() == name)// if found
		{	
			prev = trav;
			return trav->GetPtr();// EXIT IF FOUND
		}
		else
		{
			trav = trav->GetPtr();// traverse LL
			index++;
		}
	}
	return nullptr;// EXIT IF NOT FOUND
}

void AddressBook::AddEntry(Node* &buffer) 
{
	//If zero add to start as head
	buffer->SetPtr(head);
	head = buffer;
	size++;
	std::cout << "Successfully added to Addressbook " << std::endl;
}
void AddressBook::DeleteNode(Node* current,Node* prev)
{
	Node* toDelete = current;
	if (prev == current)// if first node needs to be deleted
	{
		if (current->GetPtr() == nullptr)
			head = nullptr;
		else
			head = current->GetPtr();
	}
	else// delete at the midle or end.
	{
		prev->SetPtr(prev->GetPtr()->GetPtr()); //current node needs to point to node after deleted node
	}
	delete toDelete;
	size--;
}

void AddressBook::WriteFile()
{
	std::ofstream outFile;

	outFile.open("E:\\SideProjects\\CS CLASSES\\DSA\\LAB_3_UPADHYAY_JAY\\outfile.txt", std::fstream::out);
	//outFile.open("test.txt", std::fstream::out);
	if (!outFile)
	{
		std::cout << "Could not properly open outfile. Please alter path in source file. Returning to main menu." << std::endl;
		return;
	}
	outFile << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
		<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
		<< std::setw(SPACE) << std::left << "State" << std::setw(SPACE) << std::left << "ZipCode"  << std::right << "PhoneNumber" << std::endl;

	for (Node* trav = head; trav != nullptr; trav = trav->GetPtr())
	{
		// could make this record function
		trav->GetData().SaveToFile(outFile);
		
	}
	outFile.close();
	std::cout << "Successfully entered into file." << std::endl;

}

void AddressBook::EmptyList()
{
	Node* toDelete;
	while (head != nullptr)
	{
		
		toDelete = head;
		head = head->GetPtr();
		delete toDelete;
		size--;
	}
}