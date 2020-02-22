//CS230 SECTION 12698 LAB ASSIGNMENT 1 UPADHYAY,JAY
#include <iostream>
using namespace std;

int main()
{
	short int data=0;
	int year, month, day;
	cout << "Enter month, day and year between 1-1-1980 and 12-31-2107" << endl;
	// Sample output 3 20 2018 month day year In bit form it becomes year month day
	cin >> month >> day >> year;
	if (!cin)
	{
		cin.ignore(1000, '\n');
		cin.clear();
	}
	// Year -- 7 bits
	// Month-- 4 bits
	// Day -- 5 bits
	//cin >> year >> month >> day;
	//0100 1100 0111 0100
	//Year--010 0110   Month--0 011 Day--1 0100
	//       38                   3          20    
	// Maybe has to do with amount of digits.
	//010 01100000 shift left 4 times
	year -=1980;
	data = data | year;
	data = data << 4;
	cout << "After year operation: "<< data << endl;

	data = data | month;
	
	cout << "After month operation: " << data << endl;
	data = data << 5;
	
	data = data | day;
	
	
	cout << hex << data << endl;

}
