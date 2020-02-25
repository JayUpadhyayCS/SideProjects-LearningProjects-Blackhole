// Lab1 Upadhyay, Jay T TH  2/20/20
#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
const int ARRSIZE = 100;
using namespace std;

struct InventoryItem{
	string uniqId;// item id
	string itmName;// item name
	int numItems;// quantity on hand
	double itmPrice;// item price
};
class InventoryItems{
private:
	vector<InventoryItem> vecItms;// unsorted inventory tiems
	vector<InventoryItem*> sortedItms;//pointers toward inventory items sorted some way.
public:
	bool InputRecords();// Input records into unsorted vec
	void UnsortPrint();//Print Unsorted vec
	void BubSort(int userInput); // sort ptr to a field based on userinput
	void PrintSorted(); // print data sortedvec ptr pointing to
	void SearchInv(string userInput); // Search unsorted vec for id/name
	void PrintReport();// print uniqueitems// total price // total quantity 
};
string strLower(string tempStr);// Make string lowercase
void clearCin(); // Clear cin stream
void RunMenu(InventoryItems&);

int main()
{
	InventoryItems itmList;
	bool errorFound = itmList.InputRecords();// Input datafile and check for errors
	
	if (errorFound)  
		cout << "Error taking input. File may be missing or empty.\n"; 
	else {// if no errors then continue
		RunMenu(itmList);
	}
}


void RunMenu(InventoryItems & itmList)
{
	int numInput;
	string strInput;
	bool runMenu = true;
	while (runMenu)
	{
		cout << "\nEnter a numeric choice that corresponds to the desired operation.\n"
			<< "1: Print Inventory Unsorted\n2: Print Inventory Sorted\n3. Search Record with ID or Name\n4. Print Totals Report\n5. End Program" << endl;
		cin >> numInput;
		switch (numInput)
		{
		case 1: // Print Unsorted
			itmList.UnsortPrint();
			break;
		case 2: // Print inventory sorted in ascending order by any field
			while (numInput != 5)
			{
				cout << "What would you like to sort by?\n1:ID\n2:Name\n3:Quantity\n4:Price\n5:Back to Main Menu\n";
				cin >> numInput;
				if (numInput > 0 && numInput < 5)//check if it is  one of the options
				{
					itmList.BubSort(numInput);
					itmList.PrintSorted();
				}
				else if (numInput == 5)
				{
					cout << "Returning to main menu" << endl;
				}
				else
				{
					cout << "Putting you back into main menu. Could not understand input.\n";
					clearCin();
				}
			}
			break;

		case 3: // Search for item by ID or name
			do {
				cout << "\nEnter name or ID of an item you are searching for, or enter 1 to return to Main Menu.\n"; cin >> strInput;
				clearCin();
				if (strInput != "1")
				{
					strInput=strLower(strInput);
					itmList.SearchInv(strInput);
				}
			} while (strInput != "1");
			break;
		case 4: // Print report of number of unique items, and total count/worth of items
			itmList.PrintReport();
			break;
		case 5:// End program

			cout << "Terminating program" << endl;
			runMenu= false;
			break;
		default: cout << "Please retry. Could not understand input.\n"; // Input error, clear cin and retry
			clearCin();
		}
	}
}

bool InventoryItems:: InputRecords() {
	ifstream inputStream;
	inputStream.open("input.txt");
	//inputStream.open("E:\\SideProjects\\DSA\\LAB_1_UPADHYAY_JAY\\input.txt");
	if (!inputStream) 
		return true;// error found
	InventoryItem bufferItm;
	while (!inputStream.eof() && vecItms.size() < ARRSIZE) {
		inputStream >> bufferItm.uniqId >> bufferItm.itmName
			>> bufferItm.numItems >> bufferItm.itmPrice;
		if (!inputStream) 
			return true;// error founds
		if (bufferItm.numItems > 0 && bufferItm.itmPrice > 0)
		{
			bufferItm.itmName=strLower(bufferItm.itmName);
			vecItms.push_back(bufferItm);
		}
		else
		{
			cout << "Error with this piece of data" << bufferItm.uniqId << " " << bufferItm.itmName << " "
				<< bufferItm.numItems << " " << fixed << showpoint << setprecision(2) << bufferItm.itmPrice << "\n";
		}
	}
	if (vecItms.size() >= ARRSIZE)
	{
		cout << "There were more than "<<vecItms.size() <<" items in datafile. Stopped after data:\n" << bufferItm.uniqId << " " << bufferItm.itmName << " " 
			<< bufferItm.numItems << " " <<fixed << showpoint << setprecision(2) << bufferItm.itmPrice << "\n";// Put buffer items details here
	}
	inputStream.close();
	for (int i = 0; i < vecItms.size(); i++)// Initialize array of pointers
	{
		sortedItms.push_back(&vecItms.at(i));
	}
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

void InventoryItems::BubSort(int userChoice) {
	InventoryItem* temp;
	bool isSwap = true;
	bool repeatLoop = true;
	while (repeatLoop)
	{
		repeatLoop = false;// No error in data position yet
		isSwap = false;
		int vecSize = sortedItms.size()-1;
		for (int i = 0; i < vecSize; i++)
		{
			isSwap = false;
			//Write one function, that can sort by any field using array of pointers. 
			//Do not copy and paste sort code five times into the same function. Bubble sort  is the easiest to modify.
			switch (userChoice)
			{
			case 1:
				isSwap = sortedItms.at(i)->uniqId> sortedItms.at(i + 1)->uniqId;
				break;
			case 2:
				isSwap = sortedItms.at(i)->itmName>sortedItms.at(i + 1)->itmName;
				break;
			case 3:
				isSwap = sortedItms.at(i)->numItems> sortedItms.at(i + 1)->numItems;
				break;
			case 4:
				isSwap = sortedItms.at(i)->itmPrice> sortedItms.at(i + 1)->itmPrice;
				break;
			}
			if (isSwap)
			{
				repeatLoop=true;
				temp = sortedItms.at(i);
				sortedItms.at(i) = sortedItms.at(i + 1);
				sortedItms.at(i + 1) = temp;
			}
		}
	}
	
}
void InventoryItems::PrintSorted()// Print array of pointer values
{
	cout << left << setw(SPACE) << "Item ID" << left << setw(SPACE) << "Item Name" << left << setw(SPACE) << "Quantity" << left << setw(SPACE) << "Price" << endl;
	int vecSize = sortedItms.size();
	for (int x = 0; x < vecSize; x++)
	{
		cout << left << setw(SPACE) << sortedItms.at(x)->uniqId << left << setw(SPACE) << left << sortedItms.at(x)->itmName << setw(SPACE) << sortedItms.at(x)->numItems 
			<< left << setw(SPACE) << fixed << showpoint << setprecision(2)<< sortedItms.at(x)->itmPrice << endl;
	}
}
void InventoryItems::SearchInv(string userInput)
{
	bool notFound = true;
	int vecSize = sortedItms.size();
	for (int x = 0; notFound && x < vecSize; x++)// Loop unless finds data or end of vector data
	{
		if (vecItms.at(x).itmName == userInput || vecItms.at(x).uniqId == userInput)
		{
			cout << "Record has been found!" << endl;
			cout << left << setw(SPACE) << vecItms.at(x).uniqId << left << setw(SPACE) << left << vecItms.at(x).itmName << setw(SPACE)
				<< vecItms.at(x).numItems << left << setw(SPACE) << vecItms.at(x).itmPrice << endl;
			notFound = false;
		}
	}
	if (notFound)
	{
		cout << "Record not found. Sorry, Please retry with different data.";
	}
}
void InventoryItems::PrintReport()// Basic print records function
{
	double numTotPrice = 0;
	int numTotAmnt = 0;
	for (int x = 0; x < vecItms.size(); x++)
	{
		numTotPrice += vecItms[x].itmPrice * vecItms[x].numItems;
		numTotAmnt += vecItms[x].numItems;
	}
	cout << "Number of unique items: " << vecItms.size() << "\nTotal Price of Current Inventory: $" <<fixed << showpoint << setprecision(2)<<  numTotPrice
		<< "\nTotal Amount of Items in Inventory: "  <<  numTotAmnt << endl;
}

std::string strLower(std::string tempStr)
{
	if (!tempStr.size())
		return tempStr;
	tempStr.at(0) = toupper(tempStr.at(0));
	for (int x = 1; x < tempStr.size(); x++)
	{
		tempStr.at(x) = tolower(tempStr.at(x));
	}
	return tempStr;
}
void clearCin() 
{
	cin.clear();
	cin.ignore(1000, '\n');
}
