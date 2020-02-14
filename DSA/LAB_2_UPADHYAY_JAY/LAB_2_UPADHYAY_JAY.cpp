#include <iostream>

float recPow(double , int&);
int sumSquaresUp(int numInput);
int sumSquaresDown(int numInput);
using namespace std;
int main()
{
	double answer;
	int numInput;
	int userInput;
	bool repeat = true;
	while (repeat)
	{
		cout << "\n1. Use power function\n2. Sum of Squares(low to high)\n3. Sum of Squares(high to low)\n4. End program\n";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			double base;
			int exponent;
			do
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter a base and exponent. Example: 1 3" << endl;
				cin >> base >> exponent;
				if (!cin)
					cout << "Please reenter input. Must be numeric and within choices given." << endl;
			} while (!cin);
			answer = recPow(base, exponent);
			cout << answer;
			break;
		case 2:
			
			cout << "Enter numerical input" << endl;
			cin>> numInput;
			answer = sumSquaresUp(numInput);
			cout << "=" <<  answer;
			break;
		case 3:
			
			cout << "Enter numerical input" << endl;
			cin >> numInput;
			answer = sumSquaresDown(numInput);
			cout << "=" << answer;
			break;
		case 4: // end program
			repeat = false;
			break;
		default:
			cout << "Putting you back into main menu. Could not understand input.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}
float recPow(double base, int &exponent)
{
	if (exponent < 0)// If its negative exponent, I need to multiple 1/base against itself. Otherwise base*base;
	{
		exponent = -exponent;
		base = 1 / base;
	}
	else if (!exponent)
		return 1;
	exponent--;
	return base * recPow(base, exponent);
}
int sumSquaresUp(int numInput)
{
	int answer;
	if (numInput == 1)
	{
		cout << "1";
		return pow(1, 2);
	}
	else
	{
		answer=sumSquaresUp(numInput - 1);
		cout << "+(" << numInput << "*" << numInput << ")";
		//cout << "\nTEST:" << numInput*numInput + answer << " \n";
		return (numInput*numInput)+answer;
	}
}
int sumSquaresDown(int numInput)
{
	int answer;
	if (numInput == 1)
	{
		cout << "1";
		return pow(1, 2);
	}
	else
	{
		cout << "(" << numInput << "*" << numInput << ")+";
		answer = sumSquaresDown(numInput - 1);
		//cout << "\nTEST:" << numInput*numInput + answer << " \n";
		return (numInput * numInput) + answer;
	}
}
