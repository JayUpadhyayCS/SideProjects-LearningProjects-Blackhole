#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int SIZE = 30;
const double DIVISOR = 0.14748071991788;
int main()
{
	string stockSymbols[SIZE];
	double stockPrices[SIZE];
	ifstream infile;
	double total=0;
	char input;
	infile.open("C:\\Temp\\Dow30.txt");
	if (!infile)
	{
		cout << "Unable to open C:\\Temp\\Dow30.txt - ending" << endl;
		exit(-2);
	}
	for (int x = 0; x < SIZE && !infile.eof();x++)
	{
		infile >> stockSymbols[x];
		infile >> stockPrices[x];
		total += stockPrices[x];
		//ADD TO FIRST ARR
		//ADD TO SECOND ARR
		if (x != 30 && infile.eof())
		{
			cout << "File C:\\Temp\\Dow30.txt only contains " << x << " records - ending" << endl;
			exit(-2);
		}
	}
	total = total / DIVISOR;
	cout << "Dow Jones Industrial Average is " << setprecision(2) << fixed << total << "." << endl;
	cout << "Calculate new value of average?    Reply 'Y' or 'N'." << endl;
	//cin << input;
	//if ()
}