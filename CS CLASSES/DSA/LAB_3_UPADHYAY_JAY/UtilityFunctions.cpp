
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
	do 
	{
		Node* prev;
		Node* current;
		std::cout << "Enter a name or number youd like to search for.Enter Quit to return to main menu." << std::endl;
		std::cin >> name;
		name = strLower(name);
		clearCin();
		if (name!="Quit")
		{
			current = recList.Search(name, prev);// search
			if (!current)// if not found
			{
				std::cout << "Sorry could not find any records matching " << name << ". Please try again or another option." << std::endl;
			}
			else
			{
				std::cout << "Data found. Outputting below:" << std::endl;
				printLayout();
				current->GetData().Print();// printing found data
				if (choice == 4)//if user selected delete
				{
					recList.DeleteNode(current,prev);
					std::cout << "Completed delete operation" << std::endl;
				}
			}
		}
		
	} while (name != "Quit");
	std::cout << "Returning to main menu" << std::endl;
}
//get piece of data to add to linked list
void GetEntryInput(AddressBook& recList)
{
	std::string fName, lName, buildNum, streetName, cityName, state, zip, phoneNum;
	
	int index;
	
	std::cout << "Enter in data format below: \n";
	printLayout();
	std::cin >> fName >> lName >> buildNum >> streetName >> cityName >> state >> zip >> phoneNum;
	strAllLower(fName, lName, streetName, cityName, state);
	Node * newRecord= new(std::nothrow)Node(Record(fName, lName, buildNum, streetName, cityName, state, zip, phoneNum), nullptr);
	if (!newRecord)
	{
		std::cout << "Error with allocating dynamic memory, returning to main menu." << std::endl;
		return;
	}
	recList.AddEntry(newRecord);// sent in index -1 to account for starting at 0.
}
