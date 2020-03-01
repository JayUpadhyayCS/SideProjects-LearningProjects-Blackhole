//CS230 SECTION 12698 LAB ASSIGNMENT 1 UPADHYAY,JAY
#include <iostream>
using namespace std;

int main()
{
	int maxDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	short int data=0;
	int year, month, day;
	bool reRun = true;
	while (reRun)
	{
		reRun = false;
		cout << "Enter month, day and year between 1 1 1980 and 12 31 2107 in following format, MM DD YYYY." << endl;
		// Sample output 3 20 2018 month day year In bit form it becomes year month day
		cin >> month >> day >> year;
		if (!cin)
		{
			cin.ignore(1000, '\n');
			cin.clear();
			reRun = true;
		}
		if (month < 1 || month >12)
		{
			cout << "Error with month input." << endl;
			reRun = true;
		}
		else if (day < 1 || day>maxDays[month])
		{
			cout << "Error with day input" << endl;
			reRun = true;
		}
		else if (year < 1980 || year>2107)
		{
			cout << "Error with year input." << endl;
			reRun = true;
		}

	}
	year -=1980;
	data = data | year;
	data = data << 4;

	data = data | month;
	

	data = data << 5;
	
	data = data | day;
	
	
	cout << "The hexadecimal FAT date is: " << hex << data << endl;

}
