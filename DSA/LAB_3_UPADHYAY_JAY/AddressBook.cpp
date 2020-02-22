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
	inFile >> buffer->data.firstName >> buffer->data.lastName >> buffer->data.numStreet;
	inFile >> buffer->data.streetName >> buffer->data.cityName>> buffer->data.numPhone >> buffer->data.day >> buffer->data.month >> buffer->data.year;
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
		inFile >> buffer->data.firstName >> buffer->data.lastName >> buffer->data.numStreet >> buffer->data.streetName >> buffer->data.cityName// Maybe prime 
			>> buffer->data.numPhone >> buffer->data.day >> buffer->data.month >> buffer->data.year;
		buffer->ptr = nullptr;

	}
	//nullptrs are false
	std::cout << "Complete" << std::endl;
	//oscar peterson
	//beatles essentia

}
void AddressBook::Search(std::string name)
{
	RecordList* trav = head;
	do {
		trav
	}while (trav->ptr != nullptr);
	

}

