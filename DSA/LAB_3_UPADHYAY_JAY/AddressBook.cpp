#include "AddressBook.h"
#include <fstream>
#include <iostream>
#include <new>
#include <cctype>
#include <iomanip>

const int SPACE = 15;
AddressBook::AddressBook()
{
}
AddressBook::~AddressBook()
{
}
std::string strLower(std::string tempStr)
{
	if (!tempStr.size())
	{
		return tempStr;
	}
	tempStr.at(0) = toupper(tempStr.at(0));// What if they send empty string
	for (int x = 1; x < tempStr.size(); x++)
	{
		tempStr.at(x) = tolower(tempStr.at(x));
	}
	return tempStr;
}
void clearCin()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
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
		buffer->data.lastName = strLower(buffer->data.lastName);
		buffer->ptr = nullptr;

	}
	
	std::cout << "Complete" << std::endl;
	//oscar peterson
	//beatles essentia

}
void AddressBook::Search()
{
	RecordList* trav = head;
	bool found = false;
	std::string name;
	bool rePrompt = true;
	while (rePrompt)
	{
		found = false;
		trav = head;
		std::cout << "Enter a name or number youd like to search for.Enter Quit to return to main menu." << std::endl;
		std::cin >> name;
		name=strLower(name);
		clearCin();
		if (name == "Quit"||name== "quit")
		{
			std::cout << "Exiting to main menu" << std::endl;
			rePrompt = false;
		}
		else
		{
			do {

				if (trav->data.lastName == name || trav->data.numPhone == name)
				{
					///////////////////////////////////////////////////////Format
					std::cout << "Record found, Outputting below: \n" << trav->data.firstName << std::setw(SPACE) << trav->data.lastName << std::setw(SPACE) << trav->data.numStreet << std::setw(SPACE) << trav->data.streetName
						<< std::setw(SPACE) << trav->data.cityName << std::setw(SPACE) << trav->data.numPhone << std::setw(SPACE) << trav->data.day << trav->data.month << trav->data.year << std::endl;
					found = true;
				}
				else
				{
					trav = trav->ptr;
				}
			} while (trav != nullptr && !found);
			if (!found)
			{
				std::cout << "Sorry could not find any records matching " << name << ". Please try again or another option." << std::endl;
			}
		}
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
	RecordList* toDelete;
	bool found = false;
	RecordList* trav=head;
	name = strLower(name);
	if (trav->data.lastName == name || trav->data.numPhone == name)// if head needs to be deleted
	{
		toDelete = trav;
		head = head->ptr;
		std::cout << "Record found, deleting following record below: \n" << trav->data.firstName << trav->data.lastName << trav->data.numStreet << trav->data.streetName
			<< trav->data.cityName << trav->data.numPhone << trav->data.day << trav->data.month << trav->data.year << std::endl;
		delete toDelete;
		found = true;
		
	}
	else {

		do {
			if (trav->ptr->data.lastName == name || trav->ptr->data.numPhone == name)
			{

				///////////////////////////////////////////////////////Format
				std::cout << "Record found, deleting following record below: \n" << trav->ptr->data.firstName << trav->ptr->data.lastName << trav->ptr->data.numStreet << trav->ptr->data.streetName
					<< trav->ptr->data.cityName << trav->ptr->data.numPhone << trav->ptr->data.day << trav->ptr->data.month << trav->ptr->data.year << std::endl;
				found = true;
				toDelete = trav->ptr;
				trav->ptr = trav->ptr->ptr;
				delete toDelete;
			}
			trav = trav->ptr;
		} while (trav->ptr != nullptr && !found);
	}
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