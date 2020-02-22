// Lab1 Upadhyay, Jay T TH  2/20/20
#include <iostream>
const int MAXNUM = 10;// Maximum number for base, exponent, and sum of squares input
const int MINNUM = -10;// Minumum number for base, exponent input
const int MINPOS = 1;// Minimum input for sum of squares input
float RecPower(double , int&);//Recursive exponenet power function
int SumSquaresUp(int numInput);// Sum of squares start low then ascend
int SumSquaresDown(int numInput);// sum of squares, start max then descend

using namespace std;
int main()
{
	double answer;
	int numInput;
	int userInput;
	bool continueProg = true;// Repeat menu until user wants out
	bool errorCatch = false;// no errors caught so far
	while (continueProg)
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
				errorCatch = false;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter a base and exponent. Example: 1 3" << endl;
				cin >> base >> exponent;
				if (!cin || base > MAXNUM || base<MINNUM || exponent >MAXNUM || exponent < MINNUM)
				{
					cout << "Please reenter input. Two integers with a space between please. Must be in range of -10 to 10." << endl;
					errorCatch = true;
				}
			} while (errorCatch);
			answer = RecPower(base, exponent);
			cout << answer;
			break;
		case 2:
		case 3:
			do {
				errorCatch = false;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Enter numerical input" << endl;
				cin >> numInput;
				if (!cin || numInput > MAXNUM || numInput < MINPOS)
				{
					cout << "Please reenter input. One integer within 1-10." << endl;
					errorCatch = true;
				}
			} while (errorCatch);
			if (userInput == 2)
				answer = SumSquaresUp(numInput);
			else
				answer = SumSquaresDown(numInput);
			cout << "=" <<  answer;
			break;
		//case 3:
		case 4: // end program
			continueProg = false;
			break;
		default:
			cout << "Putting you back into main menu. Could not understand input.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}
float RecPower(double base, int &exponent)// Recursive power function
{
	if (exponent < 0)// If its negative exponent, I need to multiple 1/base against itself. Otherwise base*base;
	{
		exponent = -exponent;
		base = 1 / base;
	}
	else if (!exponent)
		return 1;
	exponent--;
	return base * RecPower(base, exponent);
}
int SumSquaresUp(int numInput)
{
	int answer;
	if (numInput == 1)// end condition 
	{
		cout << "1";
		return 1;
	}
	else
	{
		answer=SumSquaresUp(numInput - 1);// Recursion first, then outputs next line when recursive portion finishes.
		cout << "+(" << numInput << "*" << numInput << ")";
		return (numInput*numInput)+answer;
	}
}
int SumSquaresDown(int numInput)
{
	int answer;
	if (numInput == 1)// end condition
	{
		cout << "1";
		return 1;
	}
	else
	{
		cout << "(" << numInput << "*" << numInput << ")+";
		answer = SumSquaresDown(numInput - 1);// Recursion second, outputs data in function first.
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

////// Error input, testing bounds.

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
0
Putting you back into main menu. Could not understand input.

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1
Enter a base and exponent. Example: 1 3
-11 2
Please reenter input. Two integers with a space between please. Must be in range of -10 to 10.
Enter a base and exponent. Example: 1 3
-2 -1
-0.5
1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
2
Enter numerical input
11
Please reenter input. One integer within 1-10.
Enter numerical input
0
Please reenter input. One integer within 1-10.
Enter numerical input
3
1+(2*2)+(3*3)=14
1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
4

E:\SideProjects\DSA\LAB_2_UPADHYAY_JAY\Debug\LAB_2_UPADHYAY_JAY.exe (process 16272) exited with code 0.
Press any key to close this window . . .

*/