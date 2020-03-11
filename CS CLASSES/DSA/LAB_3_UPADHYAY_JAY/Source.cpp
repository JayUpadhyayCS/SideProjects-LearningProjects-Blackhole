#include <iostream>
#include "AddressBook.h"
// ADDRESSBOOK pointer to a person
//PERSON holds data
// PersonList

using namespace std;
int main()
{
	int userChoice=1;
	string userStr;
	string record;
	AddressBook recList;
	cout << "Loading Addressbook, please hold.\n\n";
	if (recList.Load())
	{
		while (userChoice)// could be terrible idea
		{
			cout << "\n0.Quit Program\n1.Write Addressbook to file\n2.Search addressbook by last name or phone\n3.Add new entry\n4.Delete entry by name or phone\n"
				<< "Enter number corresponding to your choice:" << endl;
			cin >> userChoice;
			if (!cin)
			{
				userChoice = 5;
				
			}
			switch (userChoice)
			{
			case 0:
				cout << "Exiting program." << endl;
				break;
			case 1:
				recList.WriteFile();
				break;
			case 2:
			case 4:
				InputMenu(recList, userChoice);
				break;
			case 3:
			{
				GetEntryInput(recList);
				break;
			}
			default:
			case 5:
				cout << "Had error understanding input" << endl;
				clearCin();
			}
		}
	}
	
}
