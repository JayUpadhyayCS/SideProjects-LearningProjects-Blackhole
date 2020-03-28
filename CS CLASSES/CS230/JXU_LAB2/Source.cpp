#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctype.h>
#include <stdio.h>
using namespace std;
const int SIZE = 30;
bool isStrUpper(string);
int searchArr(string symbols[SIZE], string sym);
const double DIVISOR = 0.14748071991788;
int main()
{
	string stockSymbols[SIZE];
	double stockPrices[SIZE];
	ifstream infile;
	double total=0;
	double stockPrice;
	char input = ' ';
	string stockSym;
	bool errorCatch = false;
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
	while (input != 'N')
	{
		cout << "Calculate new value of average?    Reply 'Y' or 'N'." << endl;
		cin >> input;
		if (input != 'Y' && input != 'N')
		{
			cout << "Value " << input << " not valid, try again." << endl;
		}
		else if (input == 'N')
		{
			cout << "Ending execution." << endl;
			exit(0);
		}
		else {
			errorCatch = false;
			cout << "Enter a new stock symbol and value" << endl;
			cin >> stockSym >> stockPrice;
			if (stockSym.size() > 5 || stockSym.size() < 1|| !isStrUpper(stockSym))// and not uppercase
			{
				cout << "Invalid stock symbol "<< stockSym<<" , must be between one and five characters long and all upper case " << endl;
				input = 'e';
			}
			else if (!searchArr(stockSymbols,stockSym))// not found
			{
				cout << "Stock symbol " << stockSym << " was not found, re-enter" << endl;
				input = 'e';
			}
			else if (stockPrice <= 0)
			{
				cout << "Stock price " << stockPrice << " is not valid, re-enter" << endl;
				input = 'e';
			}
			else
			{
				int loc = searchArr(stockSymbols, stockSym)-1;
				char text[] = "%s %s";
				__asm
				{ // Remember Inst dest,src
					//lea eax, stockPrices[0]// Load effective address'
					
					mov eax, [stockPrices]//; Move the pointer value of arrayOfLetters into eax.
					//mov dl, byte ptr[eax]//; De - reference the pointer and move the byte into eax.
					//mov stockPrice, dl//; Move the value in dl into max.
					//mov   stockPrices[0], eax
					/*
					push eax   // put eax at the top of the stack
					lea eax, stockPrices[loc]  // eax = address of hi
					push eax
					lea eax, text
					push eax
					call DWORD ptr printf
					// or the indierct call
					// mov eax, printf
					// call eax
					pop ebx // clean up the stack
					pop ebx
					pop ebx
					*/
				}
				/// hard part
				//10. Update the stock price in the array.This processing must be done in Intel assembly language using x87 instructions.
				//	11.Calculate the new industrial average.This processing must be done in Intel assembly language using x87 instructions.
				//	12.Display message 3, then return to step 4.
				cout << "Dow Jones Industrial Average is nnnnn.nn." << endl;
			}
		}
	}
	

}
bool isStrUpper(string input)
{
	for (int x = 0; x < input.size(); x++)
	{
		if (!isupper(input[x]))
			return false;
	}
	return true;
}
int searchArr(string symbols[SIZE],string sym)
{
	for (int x = 0; x < SIZE; x++)
	{
		if(symbols[x]==sym)
			return x+1;
	}
	return 0;
}