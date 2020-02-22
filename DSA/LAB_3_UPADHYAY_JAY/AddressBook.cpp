#include "AddressBook.h"
#include <fstream>
#include <iostream>

AddressBook::AddressBook()
{
}
AddressBook::~AddressBook()
{
}

void AddressBook::Load()
{
	std::ifstream inFile;
	Record buffer;
	inFile.open("input.txt");
	if (!inFile)
	{
		std::cout << "Error opening or finding file." << std::endl;
	}
	//John Doe 6202 Winnetka CanogaPark 8185555555 01 01 1991
	inFile >> buffer.firstName >> buffer.lastName >> buffer.numStreet >> buffer.streetName >> buffer.cityName// Maybe prime 
		>> buffer.numPhone >> buffer.day >> buffer.month >> buffer.year;
	

}
