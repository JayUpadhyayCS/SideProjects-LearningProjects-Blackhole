/*Ask a user for number of peopleand number of passes
To speed up input, debugging, store names of the people in a file.
Output numberand the name of a person being eliminated
Output numberand the name of the winner
Allow user to play the game as many times as user wants
Make sure each function has a description, postand pre conditions
*/
#include <iostream>
#include <fstream>
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
	void InputPpl(Person pplList,int numPpl);
	void HotPotato(int numPass, int numPpl);
private:
	Person* head;

};

PersonList::PersonList()
{
}

PersonList::~PersonList()
{
}
using namespace std;
void main()
{
	int numPass, numPpl;
	PersonList pplList;
	cout << "Enter amount of passes: ";
	cin >> numPass;
	pplList.InputPpl(pplList,numPass);
	cout << "Enter number of people: ";
	cin >> numPpl;
	pplList.HotPotato(numPass, numPpl);
}

void InputPpl(int numPpl)
{
	Person* buffer;
	
	string name;
	ifstream inFile;
	inFile.open("input.txt");
	//while
	
	
	for (int x = 0; x < numPpl; x++)
	{
		inFile >> name;
		buffer = new(nothrow) Person;
		if (!buffer)
		{
			cout << "Ran out of heap memory. Ending program";
			return;
		}
		buffer->name = name;

	}
}