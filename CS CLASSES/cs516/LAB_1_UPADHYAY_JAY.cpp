// Lab1 Upadhyay, Jay 2/9/20
//LAB 1 GRIGORIANTS, NATALIA T TH
// UNIQUEID InventoryItemName QUANTITY PRICE
//vet user input
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
const int ARRSIZE = 10;
using namespace std;
void strLower(string& tempStr);
struct InventoryItem{
	string uniqId;// item id
	string itmName;// item name
	int numItems;// quantity on hand
	double itmPrice;// item price

};
template <class InventoryItems>
bool compVar(InventoryItems a, InventoryItems b) {
	return (a > b ? true : false);
}
class InventoryItems{
public:
	vector<InventoryItem> vecItms;
	vector<InventoryItem*> sortedItms;
	double numTotPrice=0;
	int numTotAmnt = 0;

	
	bool InputRecords() {
		ifstream inputStream;
		inputStream.open("input.txt");
		if (!inputStream) return true;// error found
		InventoryItem* bufferItm = new InventoryItem;
		while (!inputStream.eof() && vecItms.size()<10) {
			inputStream >> bufferItm->uniqId >> bufferItm->itmName 
				>> bufferItm->numItems >> bufferItm->itmPrice;
			if (!inputStream) return true;// error founds
			numTotPrice += bufferItm->itmPrice;
			numTotAmnt += bufferItm->numItems;
			
			strLower( bufferItm->itmName);
			
			vecItms.push_back(*bufferItm);
		}
		if (vecItms.size() >= 10)
		{
			cout << "There were more than 100 items in datafile. Stopped at \n";// Put buffer items details here
		}
		delete bufferItm;
		return false;// no errors1
	}
	void UnsortPrint()
	{
		cout << left<< setw(SPACE) << "Item ID"  << left << setw(SPACE) << "Item Name" << left <<setw(SPACE) << "Quantity" << left << setw(SPACE) << "Price" << endl;
		for (int x=0; x < vecItms.size(); x++)
		{
			cout  << left << setw(SPACE)<< vecItms.at(x).uniqId  <<left << setw(SPACE)  << left << vecItms.at(x).itmName << setw(SPACE)
				<< vecItms.at(x).numItems <<left <<  setw(SPACE) << vecItms.at(x).itmPrice << endl;
		}
	}
	void initPtrs() {
		
		
		for (int i = 0; i < vecItms.size(); i++)// Initialize array of pointers
		{
			sortedItms.push_back(&vecItms.at(i));
		}
		
		//cout << sortedList[sortedList.size()-1]->itmName<< endl;// Testing couting a value
		//Change the pointers depending on the parameters what is to be searched
		//Problem is how to write this so you can sort each parameter

	}
	void sortPtrs(int userInput) {
		initPtrs();
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

					switchVar=compVar(sortedItms.at(i)->uniqId, sortedItms.at(i+1)->uniqId);

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
					InventoryItem* temp = sortedItms.at(i);
					sortedItms.at(i) = sortedItms.at(i + 1);
					sortedItms.at(i + 1) = temp;

				}
			}
		}
		printPtr();
	}
	void printPtr()
	{
		cout << left << setw(SPACE) << "Item ID" << left << setw(SPACE) << "Item Name" << left << setw(SPACE) << "Quantity" << left << setw(SPACE) << "Price" << endl;
		for (int x = 0; x < sortedItms.size(); x++)
		{
			cout << left << setw(SPACE) << sortedItms.at(x)->uniqId << left << setw(SPACE) << left << sortedItms.at(x)->itmName << setw(SPACE) << sortedItms.at(x)->numItems << left << setw(SPACE) 
				<< sortedItms.at(x)->itmPrice << endl;
		}
	}
	void searchList(string userInput)
	{
		bool found = false;// Terrible var name
		for (int x = 0;!found && x<vecItms.size(); x++)
		{
			if (vecItms.at(x).itmName == userInput || vecItms.at(x).uniqId == userInput)
			{
				cout << "Record has been found!"<< endl;
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

	void printRecords()
	{
		cout << "Number of unique items: " << vecItms.size() << "\nTotal Price of Current Inventory: " << numTotPrice << "\nTotal Amount of Items in Inventory: " << numTotAmnt << endl;
	}
};


int main()
{
	// One string, 2 booleans, one int
	string strInput;
	int userInput;
	InventoryItems itmList;
	bool errorFound = itmList.InputRecords();// What happens when error gets hit?
	if (errorFound) { cout << "Error taking input. File may be missing or empty.\n"; }
	else {
		bool runProg = true;
		while (runProg)
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
				switch (userInput)
				{
				case 1:
					itmList.sortPtrs(userInput);
					break;
				case 2:
					itmList.sortPtrs(userInput);
					break;
				case 3:
					itmList.sortPtrs(userInput);
					break;
				case 4:
					itmList.sortPtrs(userInput);
					break;
				default:
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
				runProg = false;
				break;
			default: cout << "Please retry. Could not understand input.\n";
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