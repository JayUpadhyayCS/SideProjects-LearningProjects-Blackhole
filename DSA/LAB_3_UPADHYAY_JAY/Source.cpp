#include <iostream>
#include "AddressBook.h"
// ADDRESSBOOK pointer to a person
//PERSON holds data
// PersonList

using namespace std;
int main()
{
	AddressBook recList;
	recList.Load();
	recList.Search("818555");
	cout << "Hello world" << endl;
}
