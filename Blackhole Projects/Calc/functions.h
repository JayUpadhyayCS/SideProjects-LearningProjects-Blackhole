#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct eq
{
	vector<double> nums;// Declare vector
	vector <char> op;
};
class CalcClass
{
public:

	//TODO FOR OBJECT ORIENTED

	bool getin(string input, eq &str)
	{
		// Hoping to pass iterators to only take parts of the string instead of the whole string. Cannot use sstream. Maybe just check it character by character and add it to the vector accordingly. Can check next character to determine whether its a number/operator/ continuing/ended.
		bool errnum = false;
		bool errchar = false;
		double temp;
		char chartemp;

		stringstream ss; // Declare stringstream, like a cin stream but for a string.

		do // Loops for input until error
		{
			ss.ignore(100, '\n');
			ss.clear();
			str.nums.clear();// empties vector in case of error.
			str.op.clear();
			errnum = false;
			errchar = false;
			ss << input;// put the string into a stream.
			while (!ss.eof()) //Loop until eof.
			{
				ss >> temp;
				if (!ss)
				{
					errnum = true;
					cout << "Error with the number input. Please retry." << endl;
					ss.ignore(100, '\n');
					ss.clear();
					return false;
				}
				errnum = numcheck(temp);
				if (errnum == true)
				{
					ss.ignore(100, '\n');
					ss.clear();
					return false;
				}
				str.nums.push_back(temp); // Adds number to vector.

				ss >> chartemp;

				if (!ss.eof())// If its eof, it will pick up error flags hence the if.
				{
					if (!ss)// checking for input error
					{
						errchar = true;
						cout << "Error with operation. Please retry." << endl;

						ss.ignore(100, '\n');// Clearing stream
						ss.clear();// Clearing error
						return false;
					}

					errchar = charcheck(chartemp);
					if (errchar == true)
					{
						ss.ignore(100, '\n');// Clearing stream
						ss.clear();//Clearing error
						return false;
					}
					str.op.push_back(chartemp);// Dont need else because if has a break in it
				}
			}
		} while (errnum == true || errchar == true);
		return true;
	};

	bool numcheck(double num1)
	{
		//May need to add an additional checker for bad data. Not sure though because everything is either integer or character?
		if (num1 > 10000 || num1 < -10000)
		{
			cout << "Number is too high or low. Please try again." << endl;
			return true;

		}

		return false;

	};
	bool charcheck(char op)
	{

		if (op != '+'&&op != '-'&&op != '*'&&op != '/'&&op != '^'&&op != '='&&op != '('&&op != ')')
		{
			cout << "Please try again. The operation needs to be valid." << endl;
			return true;
		}
		return false;

	};
	double calculate(double num1, double num2, char operation)
	{

		if (operation == '+')
		{
			return num1 + num2;
		}
		else if (operation == '-')
		{
			return num1 - num2;
		}
		else if (operation == '*')
		{
			return num1 * num2;
		}
		else if (operation == '/')
		{
			return num1 / num2;
		}
		else if (operation == '^')
		{
			return RaisedToPower(num1, num2);
		}

	};
	double RaisedToPower(double num1, double num2)
	{
		double newNum = 1;
		for (int i = 0; i < num2; ++i)
		{
			newNum *= num1;
		}
		return newNum;
	};

	

	double solving(string& line)
	{
		bool success = true;

		double solved=2;
		eq calc;
		success = getin(line, calc);
		if (success == false)
		{
			return -999999999;
		}
		do
		{
			
			int loc;// Location of index of operator
			vector<char>::iterator it;
			// Parentheses -> Exponenets ->Mult/Division -> Add/Subtract
			
			if (find(calc.op.begin(), calc.op.end(), '*') != calc.op.end())
			{
				it = find(calc.op.begin(), calc.op.end(), '*');// Looking for multiplicator
				loc = distance(calc.op.begin(), it);
			}
			else if (find(calc.op.begin(), calc.op.end(), '/') != calc.op.end())
			{
				it = find(calc.op.begin(), calc.op.end(), '/');// Looking for division.
				loc = distance(calc.op.begin(), it);
			}
			else
			{
				loc = 0;
			}
			solved = calculate(calc.nums.at(loc), calc.nums.at(loc + 1), calc.op.at(loc));//  takes number 1 number 2 and an operator and returns a solution
			calc.nums.erase(calc.nums.begin() + loc);// Deletes first number
			calc.nums.at(loc) = solved; //places solution in place of second number
			calc.op.erase(calc.op.begin() + loc);// Deletes first operation character meaning next operation is now first operation
		} while (calc.nums.size() >= 2);
		return solved;
	}
		
	
};







