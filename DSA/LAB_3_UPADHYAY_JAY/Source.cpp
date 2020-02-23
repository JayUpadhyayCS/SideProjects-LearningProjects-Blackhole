#include <iostream>
#include "AddressBook.h"
// ADDRESSBOOK pointer to a person
//PERSON holds data
// PersonList

using namespace std;
int main()
{
	int userChoice=1;
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
			cout << "Exitting program." << endl;
			break;
		case 1:
			recList.WriteFile();
			break;
		case 2:
			recList.Search("string");
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
		}
	}
	
}
