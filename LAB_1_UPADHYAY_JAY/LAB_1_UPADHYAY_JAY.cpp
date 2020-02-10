// Lab1 Upadhyay, Jay 2/9/20
//LAB 1 GRIGORIANTS, NATALIA T TH
// UNIQUEID InventoryItemName QUANTITY PRICE
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
using namespace std;
struct InventoryItem{
	string uniqId;// item id
	string itmName;// item name
	int numItems;// quantity on hand
	double itmPrice;// item price

};
class InventoryItems{
public:
	vector<InventoryItem> vecItms;
	int numUniqItms=0;
	bool InputRecords() {
		ifstream inputStream;
		inputStream.open("input.txt");
		if (!inputStream) return true;// error found
		InventoryItem* bufferItm = new InventoryItem;
		while (!inputStream.eof()) {
			inputStream >> bufferItm->uniqId >> bufferItm->itmName // Need to remove caps off item names
				>> bufferItm->numItems >> bufferItm->itmPrice;
			vecItms.push_back(*bufferItm);
		}
		delete bufferItm;
		return false;// no errors1
	}
	void UnsortPrint()
	{
		cout << left<< setw(SPACE) << "Item ID"  << left << setw(SPACE) << "Item Name" << left <<setw(SPACE) << "Quantity" << left << setw(SPACE) << "Price" << endl;
		for (int x=0; x < vecItms.size(); x++)
		{
			cout  << left << setw(SPACE)<< vecItms.at(x).uniqId  <<left << setw(SPACE)  << left << vecItms.at(x).itmName << setw(SPACE)<< vecItms.at(x).numItems <<left <<  setw(SPACE) << vecItms.at(x).itmPrice << endl;
		}
	}


};
int main()
{
	int userInput;
	InventoryItems itmList;
	bool errorFound = itmList.InputRecords();
	errorFound ? cout << "Error taking input." << endl : cout << "Success taking input.\n" << endl;
	cin >> userInput;
	switch (userInput)
	{
	case 1: // Print Unsorted
		itmList.UnsortPrint();
		break;
	case 2: // Print inventory sorted in ascending order by any field
		break;
	case 3: // Search for item by ID or name
		break;
	case 4: // Print report of number of unique items, and total count/worth of items
		break;
	case 5:// End program
		break;

	}


}