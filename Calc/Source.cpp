#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include "functions.h"
using namespace std;

int main()
{
	eq str;
	double solved;
	CalcClass calc;
	bool success=false;
	int first;
	int sec;
	string buffer;
	string userInput = "a";
	cout << "Please enter a mathematical equation or enter Q to quit." << endl;
	getline(cin, userInput);



	while (userInput != "q" && userInput != "Q")
	{
		while (userInput.find('(') != userInput.npos)
		{
			//use pair here?
			first = userInput.find_first_of('(') + 1;// Starts after first parenthesis
			sec = userInput.find_first_of(')')-1 ;// Ends before ending paranthesis
			buffer = userInput.substr(first, sec - first+1);// buffer is a string of the inside // ADDED ONE HERE. NOT SURE WHY BUT FIXED ERROR. CANT LOGICALLY UNDERSTAND WHY.
			solved = calc.solving(buffer);// returns solution of inside
			userInput.replace(first - 1, sec, to_string(solved));
			cout << "a" << endl;

		}
		solved = calc.solving(userInput);
		if (solved != -999999999)
		{
			cout << solved << " is the solution." << endl;
		}

		cout << "Press enter a mathematical equation or press Q or q to quit..." << endl;
		getline(cin, userInput);

		
	}
}