// Upadhyay,Jay CS516 SECTION 11107
// First Laboratory Assignment-Bit Manipulation
#include <locale>
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
	stringstream ss;
	unsigned int hexnum;
	int bits[32]{ 0 };
	bool badInput = false;
	string input;
	int bitnum;
	unsigned int bitmask;
	unsigned int inverse_mask;
	unsigned int value = 0;//May need to reinitialize to 0 later
	string input2;
	cout << "Pierce College CS516 Fall 2019 Lab Assignment 1 - Upadhyay, Jay" << endl;
	cout << "Enter the hexadecimal value, eight digits maximum." << endl;
	do
	{
		value = 0;
		badInput = false;
		cin >> input;

		while (input.size() > 8)
		{
			cout << "Value user's value is too long -- re-enter" << endl;
			cin >> input;
		}
		for (int i = 0; i < input.size(); i++)//Uppercases all characters and checks all characters for validity.
		{
			input.at(i) = toupper(input.at(i));
			if (!((input.at(i) >= 65 && input.at(i) <= 70) || (input.at(i) >= 48 && input.at(i) <= 57)))
			{
				cout << "Digit " << input.at(i) << " is not valid, must be 0-9 or A-F, re-enter." << endl;
				badInput = true;
				break;
			}
		}
	} while (badInput);


	ss << input << endl;// Takes input and  changesit to hex.
	ss >> hex >> value;
	ss.clear();


	while (true)// Loop until user hits END
	{
		do {
			cout << "Enter 'Set' to change bits, 'Test' to check bit values, 'Toggle' to reverse a bit, or 'End' to finish." << endl;
			cin >> input2;
			if (!cin)
			{
				cin.clear();
				cin.ignore(10000, '\n');
			}
			for (int i = 0; i < input2.size(); i++)
			{
				input2.at(i) = toupper(input2.at(i));// Changing input to uppercase
			}
		} while (input2 != "SET" &&input2 != "TEST"&& input2 != "TOGGLE" && input2 != "END");
		if (input2 == "END")
		{
			exit(1);
		}


		if (input2 == "SET")
		{
			do {
				cout << "Enter bit number (0 to 31)" << endl;
				cin >> bitnum;
				if (!cin)
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}
			} while (bitnum < 0 || bitnum>31);
			bitmask = pow(2, bitnum);// Create bitmask with bit on.
			do {
				cout << "Enter new bit value(0 or 1)." << endl;
				cin >> bitnum;
				if (!cin)
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}
			} while (bitnum != 0 && bitnum != 1);
			inverse_mask = ~bitmask;// Makes mask with one bit off.
			if (bitnum == 1)
				value = value | bitmask;//If either value or both are on, it gets turned on.
			else
				value = value & inverse_mask;// If both are on or off, it gets turned on. 
			ss << value;
			ss >> hex >> input;
			ss.clear();
			transform(input.begin(), input.end(), input.begin(), toupper);
			cout << "Value changed to " << input << "." << endl;
		}


		else if (input2 == "TEST")
		{
			do {
				cout << "Enter bit number (0 to 31)" << endl;
				cin >> bitnum;
				if (!cin)
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}
			} while (bitnum < 0 || bitnum>31);
			int bin;
			bin = pow(2, bitnum);
			if (value&bin)// If true, it means both values are on at the exact bit.
			{
				cout << "Bit " << bitnum << " has binary value of 01" << endl;
			}
			else
			{
				cout << "Bit " << bitnum << " has binary value of 00" << endl;
			}

		}


		else if (input2 == "TOGGLE")
		{
			do {
				cout << "Enter bit number (0 to 31)" << endl;
				cin >> bitnum;
				if (!cin)
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}
			} while (bitnum < 0 || bitnum>31);
			bitmask = pow(2, bitnum);
			value = bitmask ^ value;// If both are on, turns off. if bitmask is off, turns it on.
			ss << value;
			ss >> hex >> input;
			ss.clear();
			transform(input.begin(), input.end(), input.begin(), toupper);
			cout << "Value changed to " << input << "." << endl;
		}
		
	}
}