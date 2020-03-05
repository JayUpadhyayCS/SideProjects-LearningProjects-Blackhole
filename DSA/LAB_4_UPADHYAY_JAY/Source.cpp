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
	int index;
	Person* next;
	Person* prev;
};
class PersonList
{
public:
	PersonList();
	~PersonList();
	void InputPpl(int numPpl);
	void HotPotato(int numPass, int numPpl);
	void Clear();
	
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
	//Input and check for errors.
	// Take input and check for errors. Allow -1 through in case user wants to quit.
	// 
	do
	{
		cout << "Enter amount of passes: ";
		cin >> numPass;
		if (numPass > -1)
		{
			cout << "Enter number of people: ";
			cin >> numPpl;
			pplList.InputPpl(numPpl);
			pplList.HotPotato(numPass, numPpl);
			pplList.Clear();
		}
	}
	while (numPass != -1);
}

void PersonList::InputPpl(int numPpl)
{
	string name=" ";
	ifstream inFile;
	inFile.open("input2.txt");
	//while
	Person* trav;
	head=trav = new (nothrow) Person;
	if (!trav)
	{
		cout << "Ran out of heap memory. Ending program";// CHANGEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
		return;
	}
	numPpl--;
	inFile >> name;
	trav->name = name;
	trav->index = 1;

	
	for (int x = 0; x < numPpl; x++)
	{
		trav->next = new (nothrow) Person;
		if (!trav)
		{
			cout << "Ran out of heap memory. Ending program";// CHANGEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
			return;
		}
		trav->next->prev = trav;
		trav = trav->next;
		inFile >> name;
		trav->name = name;
	}
	trav->next = head;// circular linked lsit
	trav->next->prev = trav;
	inFile.close();///// close infile
	
}
void PersonList::HotPotato(int numPass, int numPpl)
{
	Person* trav = head;// HEAD will get lost here unless I make it part of the record class(but its a struct)
	Person* toDelete = trav;
	
	int index = 0;
	while (numPpl != 1)
	{	
		
		if (index == numPass)
		{
			index = 0;
			toDelete = trav;
			cout << "Player "<< trav->name << " lost the game!" << numPpl << " players left!" << endl;
			numPpl--;
			trav->prev->next = trav->next;
			trav->next->prev = trav->prev;// god this logic send help'
			trav = trav->next;
			delete toDelete;
		}
		else
		{
			index++;
			trav = trav->next;
		}
	}
	head = trav;
	cout << trav->name << " has won the game!" << endl;
}
void PersonList::Clear() 
{
	Person* trav;
	trav = head;
	head->prev->next = nullptr;
	Person* toDelete;
	while (trav != nullptr)
	{
		if (trav->next != nullptr)
		{
			toDelete = trav;
			trav = trav->next;
			delete toDelete;
		}
		else
		{
			delete trav;
			trav = nullptr;
		}
	}
	cout << "List is empty." << endl;
}