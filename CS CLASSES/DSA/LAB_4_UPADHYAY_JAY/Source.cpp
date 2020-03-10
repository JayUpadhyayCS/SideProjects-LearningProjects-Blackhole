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
	//int index;
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
bool GetInput(int &numPass,int& numPpl);//Input and check for errors. if true, run program, if false quit.
void clearCin();
void main()
{
	int numPass, numPpl;
	PersonList pplList;
	//Input and check for errors.
	// Take input and check for errors. Allow -1 through in case user wants to quit.
	// 
	while (GetInput(numPass, numPpl))
	{
		pplList.InputPpl(numPpl);
		pplList.HotPotato(numPass, numPpl);
		pplList.Clear();
	}
}

void PersonList::InputPpl(int numPpl)
{
	string name=" ";
	ifstream inFile;
	inFile.open("input2.txt");
	if (!inFile)
	{
		cout << "Error with file. Most likely finding the file to open. Ending program." << endl;
		exit(-1);
	}
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
	if (!inFile)
	{
		cout << "Error with file. Most likely lack of data. Ending program." << endl; 
		exit(-1);
	}
	trav->name = name;
	//trav->index = 1;

	
	for (int x = 0; x < numPpl; x++)
	{
		if (!inFile || inFile.eof())
		{
			cout << "You entered a higher number than we have names for! Please add more names to input file. Exiting program." << endl;

			inFile.close();///// close infile
			exit(-5);
		}
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
			cout << numPpl << " players left!" << " Player "<< trav->name << " lost the game!" << endl;
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
	cout << "Emptied list for reuse." << endl;
}
bool GetInput(int& numPass, int& numPpl)
{
	//ask for one piece of input, if its bad repeat, if they want exit quit.
	// ask for second piece 
	bool errorFound;
	do
	{
		cout << "Enter -1 to end program at any time.\nEnter amount of passes: ";
		cin >> numPass;
		if (!cin || numPass < -1)
		{
			cout << "Please reenter input. One integer greater than or equal to zero. " << endl;
			clearCin();
			numPass = -2;// get caught in error while loop.
		}
		else if (numPass == -1)
			return false;

	} while ( numPass < -1);
	do {

		cout << "Enter number of people: ";
		cin >> numPpl;
		if (!cin || numPpl < 2)
		{
			cout << "Please reenter input. One integer greater than or equal to two. " << endl;
			clearCin();
			numPpl = -2;// get caught in error while loop
		}
		else if (numPpl == -1)
			return false;
	} while (numPpl < 2);
	return true;
}
void clearCin()
{	
	cin.clear();
	cin.ignore(1000, '\n');
}
