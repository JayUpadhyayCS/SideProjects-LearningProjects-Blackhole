
#include <iostream>
#include <new>
#include <cctype>
#include <iomanip>
#include <string>
#include "AddressBook.h"
void clearCin()// clear datastream
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
void printLayout()// prints layout for data
{
	std::cout << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
		<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
		<< std::setw(SPACE) << std::left << "State" << std::setw(SPACE) << std::left << "ZipCode" << std::right << "PhoneNumber" << std::endl;
}
std::string strLower(std::string tempStr)// lowers a string and returns
{
	if (!tempStr.size())
	{
		return tempStr;
	}
	tempStr.at(0) = toupper(tempStr.at(0));
	for (int x = 1; x < tempStr.size(); x++)
	{
		tempStr.at(x) = tolower(tempStr.at(x));
	}
	return tempStr;
}
// lowers  multiple pieces of data to reduce clutter
void strAllLower(std::string& fName, std::string& lName, std::string& streetName, std::string&  cityName, std::string& state)
{
	fName = strLower(fName);
	lName = strLower(lName);
	streetName = strLower(streetName);
	cityName = strLower(cityName);
}
//Search and delete menu
void InputMenu(AddressBook& recList, int choice)
{
	std::string name = "";
	while (name != "Quit")
	{

		std::cout << "Enter a name or number youd like to search for.Enter Quit to return to main menu." << std::endl;
		std::cin >> name;
		name = strLower(name);
		clearCin();
		if (choice == 2)
		{
			recList.Search(name);
		}
		else if (choice == 4)
		{
			recList.DeleteRec(name);
		}
	}
	std::cout << "Returning to main menu" << std::endl;
}
//get piece of data to add to linked list
void GetEntryInput(AddressBook& recList)
{
	std::string fName, lName, buildNum, streetName, cityName, state, zip, phoneNum;
	int index;
	do
	{
		std::cout << "Enter in data format below: \n";
		printLayout();
		std::cin >> fName >> lName >> buildNum >> streetName >> cityName >> state >> zip >> phoneNum;
		strAllLower(fName, lName, streetName, cityName, state);
		std::cout << "Enter the index you want to insert it. 1 means at front of list." << std::endl;
		std::cin >> index;
		if (index <= 0 || phoneNum.size() != 10)
		{
			std::cout << "Error with input. Make sure phone number is 10 digits, and index is a positive nonzero number." << std::endl;
		}
	} while (index <= 0 || phoneNum.size() != 10);
	//Record temp = new (std::nothrow) Record(fName,lName,buildNum,streetName,cityName,phoneNum,day,month,year);
	Record temp(fName, lName, buildNum, streetName, cityName, state, zip, phoneNum);
	Node* temp2 = new (std::nothrow) Node(temp, nullptr);
	if (!temp2)
	{
		std::cout << "Could not allocate memory. Returning to main menu." << std::endl;
		return;
	}

	//temp2=( temp,nullptr); 
	//temp2->ptr = nullptr;
	recList.AddEntry(temp2, index - 1);// sent in index -1 to account for starting at 0.
}
