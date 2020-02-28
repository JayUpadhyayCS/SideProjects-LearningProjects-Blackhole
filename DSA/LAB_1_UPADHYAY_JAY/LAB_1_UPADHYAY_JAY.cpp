// Lab1 Upadhyay, Jay T TH  2/20/20
// have something to write with
//have cursor on top of program
//zoom 150
//print output file with all test data, main headers, implementations
//dont leave it on the desk, get signature before turning it in.
//leave it whre laptop is on gray table
// write your name across on the program. Put T so she knows which class.


#include <cctype>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
const int ARRSIZE = 100;
using namespace std;

struct InventoryItem {
	string uniqId;// item id
	string itmName;// item name
	int numItems;// quantity on hand
	double itmPrice;// item price
};
class InventoryItems {
private:
	vector<InventoryItem> vecItms;// unsorted inventory tiems
	vector<InventoryItem*> sortedItms;//pointers toward inventory items sorted some way.
public:
	void InputRecords();// Input records into unsorted vec
	void UnsortPrint();//Print Unsorted vec
	void BubSort(int); // sort ptr to a field based on userinput
	void PrintSorted(); // print data sortedvec ptr pointing to
	void SearchInv(string userInput); // Search unsorted vec for id/name
	void PrintReport();// print uniqueitems// total price // total quantity 
};
string strLower(string tempStr);// Make string lowercase
void clearCin(); // Clear cin stream
void RunMenu(InventoryItems&);
void RunSortCase(InventoryItems& itmList);
void RunSearchCase(InventoryItems& itmList);
int main()
{
	InventoryItems itmList;
	itmList.InputRecords();// Input datafile and check for errors If error found, ends program.
	RunMenu(itmList);
	return 0;
}


void RunMenu(InventoryItems& itmList)// Requires inventory populated
{
	int numInput;
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
			RunSortCase(itmList);
			break;

		case 3: // Search for item by ID or name
			RunSearchCase(itmList);

			break;
		case 4: // Print report of number of unique items, and total count/worth of items
			itmList.PrintReport();
			break;
		case 5:// End program

			cout << "Terminating program" << endl;
			runMenu = false;
			break;
		default:
			cout << "Please retry. Could not understand input.\n"; // Input error, clear cin and retry
			clearCin();
		}
	}
}
void InventoryItems::InputRecords() {
	ifstream inputStream;
	//inputStream.open("input.txt");
	inputStream.open("E:\\SideProjects\\DSA\\LAB_1_UPADHYAY_JAY\\input.txt");
	ofstream outStream;
	outStream.open("E:\\SideProjects\\DSA\\LAB_1_UPADHYAY_JAY\\error.txt", ofstream::out);
	if (!inputStream)
	{
		cout << "Error taking input.File may be missing or empty.Ending program.\n";
		exit(-1);// Error Code-1
	}
	InventoryItem bufferItm;
	while (!inputStream.eof() && vecItms.size() < ARRSIZE) {
		inputStream >> bufferItm.uniqId >> bufferItm.itmName
			>> bufferItm.numItems >> bufferItm.itmPrice;
		if (bufferItm.numItems >= 0 && bufferItm.itmPrice >= 0)
		{
			bufferItm.itmName = strLower(bufferItm.itmName);
			vecItms.push_back(bufferItm);

		}
		else
		{
			cout << "Error with this piece of data: " << bufferItm.uniqId << " " << bufferItm.itmName << " "
				<< bufferItm.numItems << " " << fixed << showpoint << setprecision(2) << bufferItm.itmPrice << "\nSaving to error.txt\n";
			outStream << "Error with this piece of data: " << bufferItm.uniqId << " " << bufferItm.itmName << " "
				<< bufferItm.numItems << " " << fixed << showpoint << setprecision(2) << bufferItm.itmPrice << "\n";
		}
	}
	if (vecItms.size() >= ARRSIZE)
	{
		cout << "There were more than " << vecItms.size() << " items in datafile. Stopped after data:\n" << bufferItm.uniqId << " " << bufferItm.itmName << " "
			<< bufferItm.numItems << " " << fixed << showpoint << setprecision(2) << bufferItm.itmPrice << "\n";// Put buffer items details here
	}
	inputStream.close();
	for (int i = 0; i < vecItms.size(); i++)// Initialize array of pointers
	{
		sortedItms.push_back(&vecItms.at(i));
	}
}
void InventoryItems::UnsortPrint()
{
	cout << left << setw(SPACE) << "Item ID" << left << setw(SPACE) << "Item Name" << right << setw(SPACE) << "Quantity" << right << setw(SPACE) << "Price" << endl;
	for (int x = 0; x < vecItms.size(); x++)
	{
		cout << left << setw(SPACE) << vecItms.at(x).uniqId << left << setw(SPACE) << left << vecItms.at(x).itmName << right << setw(SPACE)
			<< vecItms.at(x).numItems << right << setw(SPACE) << fixed << showpoint << setprecision(2) << vecItms.at(x).itmPrice << endl;
	}
}
void InventoryItems::BubSort(int numInput) {
	InventoryItem* temp;
	bool isSwap = true;
	bool repeatLoop = true;
	while (repeatLoop)
	{
		repeatLoop = false;// No error in data position yet
		isSwap = false;
		int vecSize = sortedItms.size() - 1;
		for (int i = 0; i < vecSize; i++)
		{
			isSwap = false;
			//Write one function, that can sort by any field using array of pointers. 
			//Do not copy and paste sort code five times into the same function. Bubble sort  is the easiest to modify.
			switch (numInput)
			{
			case 1:
				isSwap = sortedItms.at(i)->uniqId > sortedItms.at(i + 1)->uniqId;
				break;
			case 2:
				isSwap = sortedItms.at(i)->itmName > sortedItms.at(i + 1)->itmName;
				break;
			case 3:
				isSwap = sortedItms.at(i)->numItems > sortedItms.at(i + 1)->numItems;
				break;
			case 4:
				isSwap = sortedItms.at(i)->itmPrice > sortedItms.at(i + 1)->itmPrice;
				break;
			}
			if (isSwap)
			{
				repeatLoop = true;
				temp = sortedItms.at(i);
				sortedItms.at(i) = sortedItms.at(i + 1);
				sortedItms.at(i + 1) = temp;
			}
		}
	}

}
void InventoryItems::PrintSorted()// Print array of pointer values. Requires pointers initialized and sorted.
{
	cout << left << setw(SPACE) << "Item ID" << left << setw(SPACE) << "Item Name" << right << setw(SPACE) << "Quantity" << right << setw(SPACE) << "Price" << endl;
	int vecSize = sortedItms.size();
	for (int x = 0; x < vecSize; x++)
	{
		cout << left << setw(SPACE) << sortedItms.at(x)->uniqId << left << setw(SPACE) << left << sortedItms.at(x)->itmName << right << setw(SPACE) << sortedItms.at(x)->numItems
			<< right << setw(SPACE) << fixed << showpoint << setprecision(2) << sortedItms.at(x)->itmPrice << endl;
	}
}
void InventoryItems::SearchInv(string userInput)// Requires an inventory to search and valid userInput
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
void InventoryItems::PrintReport()// Basic print records function // requires inventory to calculate current values.
{
	double numTotPrice = 0;
	int numTotAmnt = 0;
	for (int x = 0; x < vecItms.size(); x++)
	{
		numTotPrice += vecItms[x].itmPrice * vecItms[x].numItems;
		numTotAmnt += vecItms[x].numItems;
	}
	cout << "Number of unique items: " << vecItms.size() << "\nTotal Price of Current Inventory: $" << fixed << showpoint << setprecision(2) << numTotPrice
		<< "\nTotal Amount of Items in Inventory: " << numTotAmnt << endl;
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

void RunSortCase(InventoryItems& itmList)
{
	int numInput;
	bool reRun = true;
	while (reRun)
	{
		reRun = false;
		int numInput;
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
			return;
		}
		else
		{
			cout << "Problem with input. Retry and enter a number.\n";
			clearCin();
			reRun = true;

		}
	}
}

void RunSearchCase(InventoryItems& itmList)
{
	string strInput = "";

	
	do
	{
		cout << "\nEnter name or ID of an item you are searching for, or enter 1 to return to Main Menu.\n";
		cin >> strInput;
		clearCin();
		if (strInput != "1")
		{
			strInput = strLower(strInput);
			itmList.SearchInv(strInput);
		}
		
	} while (strInput != "1");
}
/*
Error with this piece of data: 404 PeanutButter -2 2.00
Saving to error.txt
Error with this piece of data: 1404 Jelly 2 -2.00
Saving to error.txt

Enter a numeric choice that corresponds to the desired operation.
1: Print Inventory Unsorted
2: Print Inventory Sorted
3. Search Record with ID or Name
4. Print Totals Report
5. End Program
1
Item ID        Item Name             Quantity          Price
1228           Apple                        1           1.00
9653           Orange                       9           1.50
1338           Banana                       2           0.50
9658           Bagels                       3           0.00
1010           Bread                       15           0.15
1991           Coke                        12           1.00
92             Fanta                       12           1.00
388            Granolabar                   1           1.50
2828           Tissues                     50           0.05
6767           Paper                     1000           0.10
95             Milk                         0           5.00
1000           Poptarts                     2           1.50

Enter a numeric choice that corresponds to the desired operation.
1: Print Inventory Unsorted
2: Print Inventory Sorted
3. Search Record with ID or Name
4. Print Totals Report
5. End Program
2
What would you like to sort by?
1:ID
2:Name
3:Quantity
4:Price
5:Back to Main Menu
1
Item ID        Item Name             Quantity          Price
1000           Poptarts                     2           1.50
1010           Bread                       15           0.15
1228           Apple                        1           1.00
1338           Banana                       2           0.50
1991           Coke                        12           1.00
2828           Tissues                     50           0.05
388            Granolabar                   1           1.50
6767           Paper                     1000           0.10
92             Fanta                       12           1.00
95             Milk                         0           5.00
9653           Orange                       9           1.50
9658           Bagels                       3           0.00
What would you like to sort by?
1:ID
2:Name
3:Quantity
4:Price
5:Back to Main Menu
3
Item ID        Item Name             Quantity          Price
95             Milk                         0           5.00
1228           Apple                        1           1.00
388            Granolabar                   1           1.50
1000           Poptarts                     2           1.50
1338           Banana                       2           0.50
9658           Bagels                       3           0.00
9653           Orange                       9           1.50
1991           Coke                        12           1.00
92             Fanta                       12           1.00
1010           Bread                       15           0.15
2828           Tissues                     50           0.05
6767           Paper                     1000           0.10
What would you like to sort by?
1:ID
2:Name
3:Quantity
4:Price
5:Back to Main Menu
4
Item ID        Item Name             Quantity          Price
9658           Bagels                       3           0.00
2828           Tissues                     50           0.05
6767           Paper                     1000           0.10
1010           Bread                       15           0.15
1338           Banana                       2           0.50
1228           Apple                        1           1.00
1991           Coke                        12           1.00
92             Fanta                       12           1.00
388            Granolabar                   1           1.50
1000           Poptarts                     2           1.50
9653           Orange                       9           1.50
95             Milk                         0           5.00
What would you like to sort by?
1:ID
2:Name
3:Quantity
4:Price
5:Back to Main Menu
5
Returning to main menu

Enter a numeric choice that corresponds to the desired operation.
1: Print Inventory Unsorted
2: Print Inventory Sorted
3. Search Record with ID or Name
4. Print Totals Report
5. End Program
3

Enter name or ID of an item you are searching for, or enter 1 to return to Main Menu.
hello
Record not found. Sorry, Please retry with different data.
Enter name or ID of an item you are searching for, or enter 1 to return to Main Menu.
banana
Record has been found!
1338           Banana         2              0.50

Enter name or ID of an item you are searching for, or enter 1 to return to Main Menu.
1

Enter a numeric choice that corresponds to the desired operation.
1: Print Inventory Unsorted
2: Print Inventory Sorted
3. Search Record with ID or Name
4. Print Totals Report
5. End Program
4
Number of unique items: 12
Total Price of Current Inventory: $148.75
Total Amount of Items in Inventory: 1107

Enter a numeric choice that corresponds to the desired operation.
1: Print Inventory Unsorted
2: Print Inventory Sorted
3. Search Record with ID or Name
4. Print Totals Report
5. End Program
5
Terminating program

c:\Users\student.CS\source\repos\Project1\Debug\Project1.exe (process 11364) exited with code 0.
Press any key to close this window . . .
*/