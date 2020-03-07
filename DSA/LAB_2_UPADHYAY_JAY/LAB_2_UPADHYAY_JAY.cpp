// Lab2 Upadhyay, Jay T TH  3/5/20
#include <iostream>
#include <stdlib.h>
#include <string>
double RecPower(double , int);//Recursive exponent power function
int SumSquaresUp(int numInput);// Sum of squares start low then ascend
int SumSquaresDown(int numInput);// sum of squares, start max then descend
void promptMenu();// ask menu and get input
void RunPower();// run case for input for power function
void RunSquareUp();// run sum of squares ascending
void RunSquareDown();// run sum of squares descending
int GetNum();// get number for sum of squares both functions
void clearCin();// clear cin
using namespace std;
int main()
{
//No precondition.
	promptMenu();
	return 0;
}


void promptMenu()
{
	int userInput;
	bool continueProg = true;
	while (continueProg)
	{
		cout << "\n1. Use power function\n2. Sum of Squares(low to high)\n3. Sum of Squares(high to low)\n4. End program\n";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			RunPower();
			break;
		case 2:
			RunSquareUp();
			break;
		case 3:
			RunSquareDown();
			break;
		case 4: 
			// end program//continueProg=false; or exit(0);
			return;
		default:
			clearCin();
		}
	}
}
void RunPower()// no requirements
{
	double base;
	int power;
	bool error = false;
	do {
		error = false;
		cout << "Enter base and power:  ";
		cin >> base >> power;

		if (!cin) {
			cout << "Invalid input" << endl;
			clearCin();
			error = true;
		}
	} while (error);
	double answer = RecPower(base, power);
	if (answer == 99999)
	{
		cout << base << " to the power of " << power << " is undefined!" << endl;// Undefine cases

	}
	else
		cout << base << " to the power of " << power << " equals " << answer << "!" << endl;
}
double RecPower(double base, int exponent)// Recursive power function // requires good input
{
	if (base == 0&& exponent <0)
	{
		return 99999;
	}
	if (exponent < 0)// If its negative exponent, I need to multiple 1/base against itself. Otherwise base*base;
	{
		exponent = -exponent;
		base = 1 / base;
	}
	else if (exponent == 1)
	{
		return base;
	}
	else if (!exponent)
		return 1;
	//exponent--;
	return base * RecPower(base, exponent-1);
}
void RunSquareUp()// gets input and runs respective function
{
	int userInput;
	int numSolution;
	userInput = GetNum();
	while (userInput != -1)
	{

		numSolution = SumSquaresUp(userInput);// requires numInput to be >0 and initialized
		cout << "=" << numSolution << endl;
		userInput = GetNum();
	}
}
void RunSquareDown() // gets input and runs respective function
{
	int userInput;
	int numSolution;
	userInput = GetNum();
	while (userInput != -1)
	{
		numSolution = SumSquaresDown(userInput);// requires numInput to be >0 and initialized
		cout << "=" << numSolution << endl;
		userInput = GetNum();
	}
}
int GetNum() // gets input and returns it for later use
{
	int userInput;
	string quitCheck;
	do
	{
		cout << "Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu." << endl;
		cin >> quitCheck;
		if (quitCheck == "M"|| quitCheck=="m")
			return -1;
		userInput = atoi(quitCheck.c_str());
		if (userInput > 0)
			return userInput;
		else
			cout <<"Error with input. Please retry" << endl;
	}
	while (!cin|| userInput <=0);
}
int SumSquaresUp(int numInput)//require good input >=1
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
int SumSquaresDown(int numInput)//require good input >=1
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
void clearCin()
{
	if (!cin)
	{
		cout << "Error taking input, please try." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
}
/* 
1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1
Enter base and power:  0 0
0 to the power of 0 equals 1!

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1

Enter base and power:  0 -10
0 to the power of -10 is undefined!

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1

Enter base and power:  10 0
10 to the power of 0 equals 1!

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1
Enter base and power:  3 7
3 to the power of 7 equals 2187!

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1
Enter base and power:  -2 -3
-2 to the power of -3 equals -0.125!

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
1
Enter base and power:  -2 3
-2 to the power of 3 equals -8!

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
2
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
-
Error with input. Please retry
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
0
Error with input. Please retry
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
-1
Error with input. Please retry
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
5
1+(2*2)+(3*3)+(4*4)+(5*5)=55
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
3
1+(2*2)+(3*3)=14
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
m

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
3
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
0
Error with input. Please retry
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
-1
Error with input. Please retry
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
5
(5*5)+(4*4)+(3*3)+(2*2)+1=55
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
3
(3*3)+(2*2)+1=14
Enter an amount of terms. Must be a positive integer >0 or enter M to return to main menu.
m

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
4
4

c:\Users\student.CS\source\repos\Project2\Debug\Project2.exe (process 13596) exited with code 0.
Press any key to close this window . . .
*/