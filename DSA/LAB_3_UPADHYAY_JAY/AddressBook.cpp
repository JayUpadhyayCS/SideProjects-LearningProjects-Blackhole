#include "AddressBook.h"
#include <fstream>
#include <iostream>
#include <new>
AddressBook::AddressBook()
{
}
AddressBook::~AddressBook()
{
}

void AddressBook::Load()
{
	std::ifstream inFile;
	RecordList* buffer= new (std::nothrow) RecordList;
	RecordList* trav = buffer;
	if (!buffer)
	{
		std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
	}
	inFile.open("input.txt");
	if (!inFile)
	{
		std::cout << "Error opening or finding file." << std::endl;
	}
	//John Doe 6202 Winnetka CanogaPark 8185555555 01 01 1991
	inFile >> buffer->data.firstName >> buffer->data.lastName >> buffer->data.numStreet
		>> buffer->data.streetName >> buffer->data.cityName>> buffer->data.numPhone >> buffer->data.day >> buffer->data.month >> buffer->data.year;
	size++;
	head =trav= buffer;
	while (!inFile.eof())
	{
		buffer = new (std::nothrow) RecordList;
		if (!buffer)
		{
			std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
		}
		trav->ptr = buffer;
		trav = buffer;
		size++;
		inFile >> buffer->data.firstName >> buffer->data.lastName >> buffer->data.numStreet >> buffer->data.streetName >> buffer->data.cityName// Maybe prime 
			>> buffer->data.numPhone >> buffer->data.day >> buffer->data.month >> buffer->data.year;
		buffer->ptr = nullptr;

	}
	
	std::cout << "Complete" << std::endl;
	//oscar peterson
	//beatles essentia

}
void AddressBook::Search(std::string name)
{
	RecordList* trav = head;
	bool found = false;
	do {
		if (trav->data.lastName == name || trav->data.numPhone == name)
		{
			///////////////////////////////////////////////////////Format
			std::cout << "Record found, Outputting below: \n" << trav->data.firstName << trav->data.lastName << trav->data.numStreet << trav->data.streetName
				<< trav->data.cityName << trav->data.numPhone << trav->data.day << trav->data.month << trav->data.year << std::endl;
			found = true;
		}
		trav = trav->ptr;
	}while (trav != nullptr&&!found);
	if (!found)
	{
		std::cout<<"Sorry could not find any records matching " << name << ". Please try again or another option." << std::endl;
	}
	

}

void AddressBook::AddEntry(RecordList* buffer, int index) 
{
	//If zero
	RecordList* trav = head;
	if (!index)
	{
		buffer->ptr = head;
		head = buffer;
	}
	else if (index >= size)// End
	{
		std::cout <<"Adding it to end of file since index exceeded Book size." << std::endl;
		
		while (trav->ptr != nullptr)
		{
			trav = trav->ptr;
		}
		trav->ptr = buffer;

	}
	// Middle
	else {

		while(index)
		{
			index--;
			trav = trav->ptr;
			
		}
		buffer->ptr = trav->ptr;
		trav->ptr = buffer;

	}
}
void AddressBook::DeleteRec(std::string name)
{
	bool found = false;
	RecordList* trav=head;
	do {
		if (trav->ptr->data.lastName == name || trav->ptr->data.numPhone == name)
		{
			RecordList* toDelete;
			///////////////////////////////////////////////////////Format
			std::cout << "Record found, deleting following record below: \n" << trav->data.firstName << trav->data.lastName << trav->data.numStreet << trav->data.streetName
				<< trav->data.cityName << trav->data.numPhone << trav->data.day << trav->data.month << trav->data.year << std::endl;
			found = true;
			toDelete = trav->ptr;
			trav->ptr = trav->ptr->ptr;
			delete toDelete;
		}
		trav = trav->ptr;
	} while (trav != nullptr && !found);
	if (!found)
	{
		std::cout << "Sorry could not find any records matching, " << name << ". Please try again or another option." << std::endl;
	}
}
void AddressBook::WriteFile()
{
	std::ofstream outFile;
	outFile.open("test.txt",std::fstream::out);
	RecordList* trav=head;
	outFile << trav->data.firstName << trav->data.lastName << trav->data.numStreet << trav->data.streetName
		<< trav->data.cityName << trav->data.numPhone << trav->data.day << trav->data.month << trav->data.year << std::endl;

}