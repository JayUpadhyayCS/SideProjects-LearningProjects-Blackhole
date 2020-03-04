#include "AddressBook.h"
#include <fstream>
#include <iostream>
#include <new>
#include <cctype>
#include <iomanip>

const int SPACE = 15;
std::string strLower(std::string tempStr)
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
void GetEntryInput(AddressBook& recList)
{
	std::string fName, lName, buildNum, streetName, cityName, phoneNum;
	int day, month, year, index;

	std::cout << "Enter in data format below: \n" << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
		<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
		<< std::setw(SPACE) << std::left << "PhoneNumber" << " DD " << "MM " << " YY" << std::endl;
	std::cin >> fName >> lName >> buildNum >> streetName >> cityName >> phoneNum >> day >> month >> year;
	std::cout << "Enter the index you want to insert it. 1 means at front of list." << std::endl;
	std::cin >> index;
	//Record temp = new (std::nothrow) Record(fName,lName,buildNum,streetName,cityName,phoneNum,day,month,year);
	Record temp(fName, lName, buildNum, streetName, cityName, phoneNum, day, month, year);
	RecordList* temp2 = new (std::nothrow) RecordList;
	if (!temp2)
	{
		std::cout << "Could not allocate memory. Returning to main menu." << std::endl;
		return;
	}
	temp2->data = temp;
	temp2->ptr = nullptr;
	recList.AddEntry(temp2, index - 1);
}
void clearCin()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
AddressBook::AddressBook()
{
}
AddressBook::~AddressBook()
{
}

bool AddressBook::Load()
{
	std::string firstName;
	std::string lastName;
	std::string numStreet;
	std::string streetName;
	std::string cityName;
	std::string numPhone;
	int month;
	int day;
	int year;
	// need single variables
	//rewrite
	// RecordList needs to be dynamically allocated., it is a struct. Structs dont have constructors.
	// if I dynamically allocate a single record, I could save it into record list, may be more efficient and dont need to dynamically allocate the record either.
	Record data;
	std::ifstream inFile;
	inFile.open("E:\\SideProjects\\DSA\\LAB_3_UPADHYAY_JAY\\input.txt");
	if (!inFile)
	{
		std::cout << "Error opening or finding file." << std::endl;
		return false;
	}
	//RecordList* buffer= new (std::nothrow) RecordList;
	
	RecordList* trav = new (std::nothrow) RecordList;
	if (!trav)
	{
		std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
	}
	//inFile.open("input.txt");
	
	//John Doe 6202 Winnetka CanogaPark 8185555555 01 01 1991
	inFile >> firstName >> lastName >> numStreet
		>> streetName >> cityName>> numPhone >> day >> month >> year;
	lastName = strLower(lastName);
	data = Record(firstName, lastName, numStreet, streetName, cityName, numPhone, day, month, year);
	trav->data = data;
	size++;
	head =trav;
	while (!inFile.eof())
	{ 
		
		trav->ptr = new (std::nothrow) RecordList;
		if (!trav->ptr)
		{
			std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
		}
		trav = trav->ptr;
		size++;
		inFile >> firstName >> lastName >> numStreet
			>> streetName >> cityName >> numPhone >> day >> month >> year;
		data = Record(firstName, lastName, numStreet, streetName, cityName, numPhone, day, month, year);
		trav->data = data;
		lastName = strLower(lastName);
		trav->ptr = nullptr;

	}
	inFile.close();
	std::cout << "Complete" << std::endl;
	return true;
}
void AddressBook::Search(std::string name)
{
	RecordList* trav = head;
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

			if (trav->data.GetLastName() == name || trav->data.GetPhoneNum() == name)
			{
				///////////////////////////////////////////////////////Format
				std::cout << "Record #" << index <<" found, Outputting below: \n" << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
					<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
					<< std::setw(SPACE) << std::left << "PhoneNumber" << "DD" << "MM" << "YY" << std::endl;
				found = true;
				trav->data.Print();
				return;
			}
			else
			{
				trav = trav->ptr;
				index++;
			}
		}
		if (!found)
		{
			std::cout << "Sorry could not find any records matching " << name << ". Please try again or another option." << std::endl;
			return;
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
		std::cout << "Successfully added to Addressbook " << std::endl;
	}
	else if (index >= size)// End
	{
		std::cout <<"Adding it to end of file since index exceeded AddressBook size." << std::endl;
		
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
		std::cout << "Successfully added to Addressbook " << std::endl;
	}
	
}
void AddressBook::DeleteRec(std::string name)
{
	RecordList* toDelete;
	int index = 1;
	bool found = false;
	RecordList* trav=head;
	if (name == "Quit")
	{
		//std::cout << "Returning to main menu" << std::endl;
		return;
	}
	else if (trav == nullptr)
	{
		std::cout << "List is empty, cannot delete anything." << std::endl;
	}
	else if (trav->data.GetLastName()== name || trav->data.GetPhoneNum() == name)// if head needs to be deleted
	{
		toDelete = trav;
		head = head->ptr;
		std::cout << "Record #"<< index <<  " found, deleting below: \n" << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
			<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
			<< std::setw(SPACE) << std::left << "PhoneNumber" << "DD" << "MM" << "YY" << std::endl;
		trav->data.Print();
		delete toDelete;
		found = true;
		
	}
	else {
		while (trav->ptr != nullptr && !found) {
			index++;
			if (trav->ptr->data.GetLastName() == name || trav->ptr->data.GetPhoneNum() == name)
			{
				std::cout << "Record "<< index << " found, deleting below: \n" << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
					<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
					<< std::setw(SPACE) << std::left << "PhoneNumber" << "DD" << "MM" << "YY" << std::endl;
				
				trav->ptr->data.Print();
				found = true;
				toDelete = trav->ptr;



				trav->ptr = trav->ptr->ptr;
				delete toDelete;
			}
			if (trav->ptr != nullptr)
				trav = trav->ptr;
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
	outFile.open("test.txt",std::fstream::out);
	outFile << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
		<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
		<< std::setw(SPACE) << std::left << "PhoneNumber" << "DD" << "MM" << "YY" << std::endl;

	for (RecordList* trav = head; trav != nullptr; trav = trav->ptr)
	{
		// could make this record function
		trav->data.SaveToFile(outFile);
		
	}
	outFile.close();
	std::cout << "Successfully entered into file." << std::endl;

}