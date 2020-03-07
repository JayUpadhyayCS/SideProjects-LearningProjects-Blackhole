// Upadhyay, Jay CS516 Section 11107 Date completed 11/19/19
// Lab 4 - Instruction Decoding
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
struct Node {
	string opcode;
	string name;
	string format;
	string abbrev;
};
bool checkChar(string input);
int convChar(char input);
int main() {
	char again='Y';
	bool found=true;
	Node table[45];
	bool error;
	string input;
	string opcode;
	ifstream infile;
	infile.open("F:\\opcode.txt");
	if (!infile)
	{
		cout << "Error" << endl;
		exit(2);
	}
	for (int x = 0; !infile.eof(); x++)
	{
		infile >> table[x].abbrev >> table[x].name >> table[x].format >> table[x].opcode;
	}
	cout << "Pierce College CS516 Fall 2019 Lab Assignment 4 - Upadhyay, Jay" << endl;
	do{
		do {

			error = false;
			cout << "Enter the machine instruction in hexadecimal -- must be four, eight, or twelve digits only." << endl;
			cin >> input;
			if (input.size() != 4 && input.size() != 8 && input.size() != 12)
			{
				cout << "Value " << input << " is not a valid length -- re-enter" << endl;
				error = true;
			}
			else if (!cin)
			{
				error = true;
			}
			else if (checkChar(input))
			{
				error = true;
			}
			else {
				opcode = input.substr(0, 2);
				for (int x = 0; x < 44; x++)
				{
					// Search table for opcode.// TODO
					if (opcode == table[x].opcode)
					{
						found = true;
						if (table[x].format == "RR"&&input.size() == 4)
						{
							cout << table[x].name << "\t" << table[x].abbrev << "\t" << convChar(input.at(2)) << "," << convChar(input.at(3)) << endl;

						}
						else if (table[x].format == "RX"&&input.size() == 8)
						{
							cout << table[x].name << "\t" << table[x].abbrev << "\t" << convChar(input.at(2)) << ",";
							cout << convChar(input.at(7)) + (convChar(input.at(6)) * 16) + (convChar(input.at(5)) *(16 * 16));
							cout << "(" << convChar(input.at(3)) << "," << convChar(input.at(4)) << ")" << endl;

						}
						else {

							cout << "Length of input does not agree with operation code format -- output may be inaccurate" << endl;
							if (input.size() == 4)
								cout << table[x].name << "\t" << table[x].abbrev << "\t" << convChar(input.at(2)) << "," << convChar(input.at(3)) << endl;
							else if (input.size() == 8)
							{
								cout << table[x].name << "\t" << table[x].abbrev << "\t" << convChar(input.at(2)) << ",";
								cout << convChar(input.at(7)) + (convChar(input.at(6)) * 16) + (convChar(input.at(5)) *(16 * 16));
								cout << "(" << convChar(input.at(3)) << "," << convChar(input.at(4)) << ")" << endl;
							}
						}
					}
					if (found == false) {
						error = true;
						cout << "Replace " << opcode << " with the two characters of the input value which could not be located in the operation code table." << endl;
					}
				}
			}

		} while (error);
		do {
			cout << "Enter 'Y' to decode another instruction, or 'N' to end." << endl;
			cin >> again;
			again = toupper(again);
		} while (again != 'Y' && again != 'N');
	} while (again == 'Y');
	
	
	cout << "Ending execution.  We hope this program was as unpleasant to use as it was to write." << endl;
}


int convChar(char input)
{
	
	if (input >= 65 && input <= 70)
	{
		return input - 55;
	}
	else if (input >= 48 && input <= 57)
	{
		return input - 48;
	}
}


bool checkChar(string input) {
	for (int i = 0; i < input.size(); i++)//Uppercases all characters and checks all characters for validity.
	{
		input.at(i) = toupper(input.at(i));
		if (!((input.at(i) >= 65 && input.at(i) <= 70) || (input.at(i) >= 48 && input.at(i) <= 57)))
		{
			cout << "Digit " << input.at(i) << " is not valid, must be 0-9 or A-F, re-enter." << endl;
			return true;
		}
	}
	return false;
}