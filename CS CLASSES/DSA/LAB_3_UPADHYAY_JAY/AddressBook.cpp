#include "AddressBook.h"
#include <fstream>
#include <iostream>
#include <new>
#include <cctype>
#include <iomanip>
#include <string>

const int SPACE = 15;
void printLayout()
{
	std::cout << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
		<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
		<< std::setw(SPACE) << std::left <<"State"<<std::setw(SPACE) << std::left <<"ZipCode" << std::right << "PhoneNumber" <<std::endl;
}
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
void strAllLower(std::string& fName, std::string& lName, std::string& streetName, std::string&  cityName, std::string& state)
{
	fName= strLower(fName);
	lName = strLower(lName);
	streetName = strLower(streetName);
	cityName = strLower(cityName);
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
	std::string fName, lName, buildNum, streetName, cityName,state,zip, phoneNum;
	int index;
	do
	{
		std::cout << "Enter in data format below: \n";
		printLayout();
		std::cin >> fName >> lName >> buildNum >> streetName >> cityName >> state>>zip>> phoneNum;
		strAllLower(fName, lName, streetName, cityName,state);
		std::cout << "Enter the index you want to insert it. 1 means at front of list." << std::endl;
		std::cin >> index;
		if (index <= 0 || phoneNum.size() != 10)
		{
			std::cout << "Error with input. Make sure phone number is 10 digits, and index is a positive nonzero number." << std::endl;
		}
	} while (index <= 0 || phoneNum.size() != 10);
	//Record temp = new (std::nothrow) Record(fName,lName,buildNum,streetName,cityName,phoneNum,day,month,year);
	Address temp(fName, lName, buildNum, streetName, cityName,state,zip,phoneNum);
	Record* temp2 = new (std::nothrow) Record;
	if (!temp2)
	{
		std::cout << "Could not allocate memory. Returning to main menu." << std::endl;
		return;
	}
	temp2->SetDataPtr ( temp,nullptr); //////////////////////////////////////////////////////////////////////////////////////// ERROR POSSIBLY
	//temp2->ptr = nullptr;
	recList.AddEntry(temp2, index - 1);// sent in index -1 to account for starting at 0.
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
	printLayout();
	std::string firstName, lastName, numStreet,streetName, cityName,state,zip, numPhone;
	Address data;
	std::ifstream inFile;
	inFile.open("input.txt");
	//inFile.open("E:\\SideProjects\\DSA\\LAB_3_UPADHYAY_JAY\\input.txt");
	if (!inFile)
	{
		std::cout << "Error opening or finding file." << std::endl;
		return false;
	}
	//RecordList* buffer= new (std::nothrow) RecordList;
	
	Record* trav = new (std::nothrow) Record;
	if (!trav)
	{
		std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
	}
	
	
	//John Doe 6202 Winnetka CanogaPark 8185555555 01 01 1991
	inFile >> firstName >> lastName >> numStreet
		>> streetName >> cityName >>state>>zip>> numPhone;
	strAllLower(firstName, lastName, streetName, cityName,state);
	data = Address(firstName, lastName, numStreet, streetName, cityName,state,zip, numPhone);
	trav->SetData( data);
	size++;
	head =trav;
	while (!inFile.eof())
	{ 
		
		trav->SetPtr(new (std::nothrow) Record);////////Test
		if (!trav->GetPtr())//TEST
		{
			std::cout << "Error with allocating dynamic memory, contact system admin." << std::endl;
		}
		trav = trav->GetPtr();
		size++;
		inFile >> firstName >> lastName >> numStreet
			>> streetName >> cityName >> state >> zip >> numPhone;
		strAllLower(firstName, lastName, streetName, cityName,state);
		data = Address(firstName, lastName, numStreet, streetName, cityName, state, zip, numPhone);
		trav->SetDataPtr(data, nullptr);

	}
	inFile.close();
	std::cout << "Complete" << std::endl;
	return true;
}
void AddressBook::Search(std::string name)
{
	Record* trav = head;
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

			if (trav->GetData().GetLastName() == name || trav->GetData().GetPhoneNum() == name)
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
				trav = trav->GetPtr();
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


void AddressBook::AddEntry(Record* buffer, int index) 
{
	//If zero
	Record* trav = head;
	if (!index)
	{
		buffer->SetPtr( head);
		head = buffer;
		size++;
	}
	else if (index >= size)// End
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
	Record* toDelete;
	int index = 1;
	bool found = false;
	Record* trav=head;
	if (name == "Quit")
	{
		//std::cout << "Returning to main menu" << std::endl;
		return;
	}
	else if (trav == nullptr)
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
				
				trav->GetPtr()->GetData().Print();
				found = true;
				toDelete = trav->GetPtr();
				size--;


				trav->SetPtr( trav->GetPtr()->GetPtr());
				delete toDelete;
			}
			if (trav->GetPtr() != nullptr)
				trav = trav->GetPtr();
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

	//outFile.open("E:\\SideProjects\\DSA\\LAB_3_UPADHYAY_JAY\\test.txt", std::fstream::out);
	outFile.open("test.txt", std::fstream::out);
	if (!outFile)
	{
		std::cout << "Could not properly open outfile. Please alter path in source file. Returning to main menu." << std::endl;
		return;
	}
	outFile << std::setw(SPACE) << std::left << "FirstName" << std::setw(SPACE) << "LastName" << std::left << std::setw(SPACE)
		<< "BuildingNum" << std::setw(SPACE) << std::left << "StreetName" << std::setw(SPACE) << std::left << "CityName"
		<< std::setw(SPACE) << std::left << "State" << std::setw(SPACE) << std::left << "ZipCode"  << std::right << "PhoneNumber" << std::endl;

	for (Record* trav = head; trav != nullptr; trav = trav->GetPtr())
	{
		// could make this record function
		trav->GetData().SaveToFile(outFile);
		
	}
	outFile.close();
	std::cout << "Successfully entered into file." << std::endl;

}