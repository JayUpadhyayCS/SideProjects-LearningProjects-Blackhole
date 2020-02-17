#include <iostream>

float recPow(double , int&);//Recursive exponenet power function
int sumSquaresUp(int numInput);// Sum of squares 
int sumSquaresDown(int numInput);
const int MAXNUM = 10;
const int MINNUM = -10;
const int MINPOS = 0;
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
				if (!cin || base>MAXNUM || base<MINNUM||exponent >MAXNUM|| exponent<MINNUM)
					cout << "Please reenter input. Two integers with a space between please. Must be in range of -10 to 10." << endl;
			} while (!cin);
			answer = recPow(base, exponent);
			cout << answer;
			break;
		case 2:
			do {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter numerical input" << endl;
				cin >> numInput;
				if (!cin||numInput>MAXNUM||numInput<MINPOS)
					cout << "Please reenter input. One integer within 1-10." << endl;
			} while (!cin);
			answer = sumSquaresUp(numInput);
			cout << "=" <<  answer;
			break;
		case 3:
			do {
				cin.clear();
				cin.ignore(1000, '\n');
			cout << "Enter numerical input" << endl;
			cin >> numInput;
			if (!cin || numInput > MAXNUM || numInput < MINPOS)
				cout << "Please reenter input. One integer within 1-10." << endl;
			} while (!cin);
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
		return 1;
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
		return 1;
	}
	else
	{
		cout << "(" << numInput << "*" << numInput << ")+";
		answer = sumSquaresDown(numInput - 1);
		//cout << "\nTEST:" << numInput*numInput + answer << " \n";
		return (numInput * numInput) + answer;
	}
}



/*// REGULAR INPUT

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1
Enter a base and exponent. Example: 1 3
2 3
8
1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
2
Enter numerical input
5
1+(2*2)+(3*3)+(4*4)+(5*5)=55
1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
3
Enter numerical input
5
(5*5)+(4*4)+(3*3)+(2*2)+1=55
1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
4

E:\SideProjects\DSA\LAB_2_UPADHYAY_JAY\Debug\LAB_2_UPADHYAY_JAY.exe (process 14232) exited with code 0.
Press any key to close this window . . .
*/