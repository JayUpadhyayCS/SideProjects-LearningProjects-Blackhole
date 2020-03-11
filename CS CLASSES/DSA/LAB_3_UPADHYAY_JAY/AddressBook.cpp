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
}

bool AddressBook::Load() //loads data and if false ends program
{
	std::string firstName, lastName, numStreet,streetName, cityName,state,zip, numPhone;
	Record data;
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
	if (!trav)
	{
		std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
	}
	else {}
	
	//John Doe 6202 Winnetka CanogaPark 8185555555 01 01 1991
	inFile >> firstName >> lastName >> numStreet
		>> streetName >> cityName >>state>>zip>> numPhone;// takes all data
	strAllLower(firstName, lastName, streetName, cityName,state);// makes all data proper case
	data = Record(firstName, lastName, numStreet, streetName, cityName,state,zip, numPhone);//constructor for an address
	trav->SetData( data);// set record data
	size++;
	head =trav;// head points to first created node.
	while (!inFile.eof())// go to get rest of nodes
	{ 
		inFile >> firstName >> lastName >> numStreet
			>> streetName >> cityName >> state >> zip >> numPhone;
		strAllLower(firstName, lastName, streetName, cityName, state);
		data = Record(firstName, lastName, numStreet, streetName, cityName, state, zip, numPhone);
		trav->SetPtr(new (std::nothrow) Node(data, nullptr));
		if (!trav->GetPtr())
		{
			std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
		}
		trav = trav->GetPtr();
		size++;
		
		
		//trav=(data, nullptr);// sets data and pointer of the record node

	}
	inFile.close();
	std::cout << "Success taking in data." << std::endl;
	return true;
}
void AddressBook::Search(std::string name)// take in string and traverse LL until found. If not found boolean remains false, and outputed
{
	Node* trav = head;
	int index = 1;
	bool found = false;
	if (name == "Quit")
	{
		//std::cout << "Exiting to main menu" << std::endl;
		return;
	}
	else
	{
		while (trav != nullptr && !found) {

			if (trav->GetData().GetLastName() == name || trav->GetData().GetPhoneNum() == name)// if found
			{
				///////////////////////////////////////////////////////Format
				std::cout << "Record #" << index << " found, Outputting below: \n";
				printLayout();
				found = true;
				trav->GetData().Print();
				return;
			}
			else
			{
				trav = trav->GetPtr();// traverse LL
				index++;
			}
		}
		if (!found)// if not found
		{
			std::cout << "Sorry could not find any records matching " << name << ". Please try again or another option." << std::endl;
			return;
		}
	}
}


void AddressBook::AddEntry(Node* buffer, int index) 
{
	//If zero add to start as head
	Node* trav = head;
	if (!index)
	{
		buffer->SetPtr( head);
		head = buffer;
		size++;
	}
	else if (index >= size)//if or index exceeds linked list size, add to End
	{
		if (index > size)
		{
			std::cout << "Adding it to end of file since index exceeded AddressBook size." << std::endl;
		}
		else
		{
			std::cout << "Adding it to end of file." << std::endl;
		}
		while (trav->GetPtr() != nullptr)
		{
			trav = trav->GetPtr();
		}
		trav->SetPtr( buffer);
		size++;
		
	}
	// Middle
	else {

		while(index)
		{
			index--;
			trav = trav->GetPtr();
			
		}
		buffer->SetPtr( trav->GetPtr());
		trav->SetPtr(  buffer);
		size++;
		
	}
	std::cout << "Successfully added to Addressbook " << std::endl;
}
void AddressBook::DeleteRec(std::string name)
{
	Node* toDelete;// points toward node that needs to be deleted while fixing pointers around it
	int index = 1;
	bool found = false;
	Node* trav=head;
	if (name == "Quit")
	{
		//std::cout << "Returning to main menu" << std::endl;
		return;
	}
	else if (trav == nullptr)// if list is empty
	{
		std::cout << "List is empty, cannot delete anything." << std::endl;
	}
	else if (trav->GetData().GetLastName()== name || trav->GetData().GetPhoneNum() == name)// if head needs to be deleted
	{
		size--;
		toDelete = trav;
		head = head->GetPtr();
		std::cout << "Record #" << index << " found, deleting below: \n";
		printLayout();
		trav->GetData().Print();
		delete toDelete;
		found = true;
		
	}
	else {// middle and end cases
		while (trav->GetPtr() != nullptr && !found) {
			index++;
			if (trav->GetPtr()->GetData().GetLastName() == name || trav->GetPtr()->GetData().GetPhoneNum() == name)
			{
				std::cout << "Record " << index << " found, deleting below: \n";
				printLayout();
				
				trav->GetPtr()->GetData().Print();// next node needs to be deleted
				found = true;
				toDelete = trav->GetPtr();// todelete points to next node
				size--;


				trav->SetPtr(trav->GetPtr()->GetPtr()); //current node needs to point to node after deleted node
				delete toDelete;
			}
			if (trav->GetPtr() != nullptr)
				trav = trav->GetPtr();// traverse list
		}
	}
	if (!found)
	{
		std::cout << "Sorry could not find any records matching, " << name << ". Please try again or another option." << std::endl;
	}
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