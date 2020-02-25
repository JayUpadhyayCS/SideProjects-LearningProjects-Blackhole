#include <iostream>
#include "AddressBook.h"
// ADDRESSBOOK pointer to a person
//PERSON holds data
// PersonList
//Need to fix menu infinite loop bad input. Now it is exiting when it gets string input.
void clearCin();

using namespace std;
int main()
{
	int userChoice=1;
	string userStr;
	AddressBook recList;
	cout << "Loading Addressbook, please hold.\n\n";
	recList.Load();
	while (userChoice)// could be terrible idea
	{
		cout << "\n0.Quit Program\n1.Write Addressbook to file\n2.Search addressbook by last name or phone\n3.Add new entry\n4.Delete entry by name or phone\n"
			<< "Enter number corresponding to your choice:" << endl;
		cin >> userChoice;
		
		switch (userChoice)
		{
		case 0:
			cout << "Exiting program." << endl;
			break;
		case 1:
			recList.WriteFile();
			break;
		case 2:

			cout << "Enter a name or number youd like to search for.Enter Quit to return to main menu." << endl;
			cin >> userStr;
			clearCin();
			//userStr=strLower(userStr);
			if (userStr != "Quit")
			{
				recList.Search(userStr);
			}
			break;
		case 3:
		{
			RecordList* temp = new (nothrow) RecordList;
			if (!temp)
			{
				cout << "Could not allocate memory. Ending program" << endl;
			}
			recList.AddEntry(temp, 1);

			break;
		}
		case 4:
			recList.DeleteRec("string");
			break;
		default:
			cout << "Had error understanding input" << endl;
			clearCin();
		}
	}
	
}

void clearCin()
{
	cin.clear();
	cin.ignore(1000, '\n');
}