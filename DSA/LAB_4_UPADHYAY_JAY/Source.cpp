/*Ask a user for number of peopleand number of passes
To speed up input, debugging, store names of the people in a file.
Output numberand the name of a person being eliminated
Output numberand the name of the winner
Allow user to play the game as many times as user wants
Make sure each function has a description, postand pre conditions
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Linked lists of names/strings
struct Person
{
	string name;
	Person* next;
};
class PersonList
{
public:
	PersonList();
	~PersonList();
	void InputPpl(int numPpl);
	//void HotPotato(int numPass, int numPpl);
private:
	Person* head = nullptr;

};

PersonList::PersonList()
{
}

PersonList::~PersonList()
{
}

void main()
{
	int numPass, numPpl;
	PersonList pplList;
	cout << "Enter amount of passes: ";
	cin >> numPass;
	
	cout << "Enter number of people: ";
	cin >> numPpl;
	pplList.InputPpl(numPpl);
	//pplList.HotPotato(numPass, numPpl);
}

void PersonList::InputPpl(int numPpl)
{
	Person* buffer;
	
	string name=" ";
	ifstream inFile;
	inFile.open("input.txt");
	//while
	Person* trav;
	head=trav = new (nothrow) Person;
	numPpl--;
	inFile >> name;
	trav->name = name;

	if (!trav)
	{
		cout << "Ran out of heap memory. Ending program";// CHANGEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
		return;
	}
	for (int x = 0; x < numPpl; x++)
	{
		trav->next = new (nothrow) Person;
		if (!trav)
		{
			cout << "Ran out of heap memory. Ending program";// CHANGEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
			return;
		}
		trav = trav->next;
		inFile >> name;
		trav->name = name;
	}
	trav->next = nullptr;
	
}