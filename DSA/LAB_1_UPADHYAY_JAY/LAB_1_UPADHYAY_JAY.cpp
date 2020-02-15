// Lab1 Upadhyay, Jay 2/9/20
//LAB 1 GRIGORIANTS, NATALIA T TH
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
const int ARRSIZE = 10;
using namespace std;
void strLower(string& tempStr);// Make string lowercase
struct InventoryItem{
	string uniqId;// item id
	string itmName;// item name
	int numItems;// quantity on hand
	double itmPrice;// item price

};
template <class InventoryItems>
bool compVar(InventoryItems a, InventoryItems b);// Compare template
class InventoryItems{
public:
	vector<InventoryItem> vecItms;// unsorted inventory tiems
	vector<InventoryItem*> sortedItms;//pointers toward inventory items sorted some way.
	double numTotPrice=0;// total price
	int numTotAmnt = 0;// Amount of items includign quantity
	bool InputRecords();// Input records into unsorted vec
	void UnsortPrint();//Print Unsorted vec
	void initPtrs();// initialize pointers to unsorted vec
	void sortPtrs(int userInput); // sort ptr to a field based on userinput
	void printPtr(); // print data sortedvec ptr pointing to
	void searchList(string userInput); // Search unsorted vec for id/name
	void printRecords();// print uniqueitems 
};


int main()
{
	// One string, 2 booleans, one int
	string strInput;
	int userInput;
	InventoryItems itmList;
	bool errorFound = itmList.InputRecords();// Input datafile and check for errors
	
	if (errorFound) { cout << "Error taking input. File may be missing or empty.\n"; }
	else {// if no errors then continue
		itmList.initPtrs();// initialize vector of pointers toward unsorted vecotr
		bool runProg = true;
		while (runProg)// continue until user wants to quit
		{
			cout << "\nEnter a numeric choice that corresponds to the desired operation.\n"
				<< "1: Print Inventory Unsorted\n2: Print Inventory Sorted\n3. Search Record with ID or Name\n4. Print Totals Report\n5. End Program" << endl;
			cin >> userInput;
			switch (userInput)
			{
			case 1: // Print Unsorted
				itmList.UnsortPrint();
				break;
			case 2: // Print inventory sorted in ascending order by any field
				cout << "What would you like to sort by?\n1:ID\n2:Name\n3:Quantity\n4:Price\n"; cin >> userInput;
				if(userInput>0&&userInput<5)//check if it is  one of the options
					itmList.sortPtrs(userInput);
				else
				{
					cout << "Putting you back into main menu. Could not understand input.\n";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				break;
			case 3: // Search for item by ID or name

				cout << "Enter name or ID of an item you are searching for.\n"; cin >> strInput;
				strLower(strInput);
				itmList.searchList(strInput);
				break;
			case 4: // Print report of number of unique items, and total count/worth of items
				itmList.printRecords();
				break;
			case 5:// End program
				runProg = false;// end switch statement
				break;
			default: cout << "Please retry. Could not understand input.\n"; // Input error, clear cin and retry
				cin.clear();
				cin.ignore(1000, '\n');
				
			}
		}
	}
}


void strLower(string& tempStr)
{
	tempStr.at(0) = toupper(tempStr.at(0));// What if they send empty string
	for (int x = 1; x < tempStr.size(); x++)
	{
		tempStr.at(x) = tolower(tempStr.at(x));
	}
}
bool InventoryItems:: InputRecords() {
	ifstream inputStream;
	inputStream.open("input.txt");
	//inputStream.open("E:\\SideProjects\\LAB_1_UPADHYAY_JAY\\input.txt");
	if (!inputStream) return true;// error found
	InventoryItem* bufferItm = new InventoryItem;
	while (!inputStream.eof() && vecItms.size() < 10) {
		inputStream >> bufferItm->uniqId >> bufferItm->itmName
			>> bufferItm->numItems >> bufferItm->itmPrice;
		if (!inputStream) return true;// error founds
		numTotPrice += bufferItm->itmPrice * bufferItm->numItems;
		numTotAmnt += bufferItm->numItems;
		strLower(bufferItm->itmName);
		vecItms.push_back(*bufferItm);
	}
	if (vecItms.size() >= ARRSIZE)
	{
		cout << "There were more than 10 items in datafile. Stopped at " << bufferItm->uniqId << " " << bufferItm->itmName << " " << bufferItm->numItems << " " << bufferItm->itmPrice << "\n";// Put buffer items details here
	}
	delete bufferItm;
	inputStream.close();
	return false;// no errors1
}
void InventoryItems::UnsortPrint()
{
	cout << left << setw(SPACE) << "Item ID" << left << setw(SPACE) << "Item Name" << left << setw(SPACE) << "Quantity" << left << setw(SPACE) << "Price" << endl;
	for (int x = 0; x < vecItms.size(); x++)
	{
		cout << left << setw(SPACE) << vecItms.at(x).uniqId << left << setw(SPACE) << left << vecItms.at(x).itmName << setw(SPACE)
			<< vecItms.at(x).numItems << left << setw(SPACE) <<fixed << showpoint << setprecision(2) << vecItms.at(x).itmPrice << endl;
	}
}
void InventoryItems::initPtrs() {


	for (int i = 0; i < vecItms.size(); i++)// Initialize array of pointers
	{
		sortedItms.push_back(&vecItms.at(i));
	}
}
void InventoryItems::sortPtrs(int userInput) {
	InventoryItem* temp;
	bool isSwap = true;
	bool switchVar = false;
	while (isSwap)
	{
		isSwap = false;
		for (int i = 0; i < sortedItms.size() - 1; i++)
		{
			switchVar = false;
			//Write one function, that can sort by any field using array of pointers. 
			//Do not copy and paste sort code five times into the same function. Bubble sort  is the easiest to modify.
			switch (userInput)
			{
			case 1:
				switchVar = compVar(sortedItms.at(i)->uniqId, sortedItms.at(i + 1)->uniqId);
				break;
			case 2:
				switchVar = compVar(sortedItms.at(i)->itmName, sortedItms.at(i + 1)->itmName);
				break;
			case 3:
				switchVar = compVar(sortedItms.at(i)->numItems, sortedItms.at(i + 1)->numItems);
				break;
			case 4:
				switchVar = compVar(sortedItms.at(i)->itmPrice, sortedItms.at(i + 1)->itmPrice);
				break;

			}
			if (switchVar)
			{
				isSwap = true;
				temp = sortedItms.at(i);
				sortedItms.at(i) = sortedItms.at(i + 1);
				sortedItms.at(i + 1) = temp;
			}
		}
	}
	printPtr();
}
void InventoryItems::printPtr()
{
	cout << left << setw(SPACE) << "Item ID" << left << setw(SPACE) << "Item Name" << left << setw(SPACE) << "Quantity" << left << setw(SPACE) << "Price" << endl;
	for (int x = 0; x < sortedItms.size(); x++)
	{
		cout << left << setw(SPACE) << sortedItms.at(x)->uniqId << left << setw(SPACE) << left << sortedItms.at(x)->itmName << setw(SPACE) << sortedItms.at(x)->numItems 
			<< left << setw(SPACE) << fixed << showpoint << setprecision(2)<< sortedItms.at(x)->itmPrice << endl;
	}
}
void InventoryItems::searchList(string userInput)
{
	bool found = false;// Terrible var name
	for (int x = 0; !found && x < vecItms.size(); x++)
	{
		if (vecItms.at(x).itmName == userInput || vecItms.at(x).uniqId == userInput)
		{
			cout << "Record has been found!" << endl;
			cout << left << setw(SPACE) << vecItms.at(x).uniqId << left << setw(SPACE) << left << vecItms.at(x).itmName << setw(SPACE)
				<< vecItms.at(x).numItems << left << setw(SPACE) << vecItms.at(x).itmPrice << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "Record not found. Sorry, Please retry with different data.";
	}
}
void InventoryItems::printRecords()
{
	
	cout << "Number of unique items: " << vecItms.size() << "\nTotal Price of Current Inventory: $" <<fixed << showpoint << setprecision(2)<<  numTotPrice
		<< "\nTotal Amount of Items in Inventory: "  <<  numTotAmnt << endl;
}
template <class InventoryItems>
bool compVar(InventoryItems a, InventoryItems b) {
	return (a > b ? true : false);
}