// Lab2 Upadhyay, Jay T TH  2/20/20

//Erro with neg number
#include <iostream>
#include <stdlib.h>
#include <string>
double RecPower(double , int);//Recursive exponenet power function
int SumSquaresUp(int numInput);// Sum of squares start low then ascend
int SumSquaresDown(int numInput);// sum of squares, start max then descend
void promptMenu();

void RunPowerCase();
void RunSquareUp();
void RunSquareDown();
void clearCin();
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
			RunPowerCase();
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
int GetNum() 
{
	int userInput;
	string quitCheck;
	do
	{
		cout << "Enter an amount of terms. Must be a positive integer >0 or enter Q to quit" << endl;
		cin >> quitCheck;
		if (quitCheck == "Q"|| quitCheck=="q")
			return -1;
		userInput = atoi(quitCheck.c_str());
		if (userInput > 0)
			return userInput;
		else
			cout <<"Error with input. Please retry" << endl;
	}
	while (!cin|| userInput <=0);
}
double RecPower(double base, int exponent)// Recursive power function
{
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
void RunPowerCase()
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
	cout << base << " to the power of " << power << " equals " << RecPower(base, power) << "!" << endl;
}
void RunSquareUp()
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
void RunSquareDown() 
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
Please enter base and power in following format, if you want to quit to main menu, enter Q.
2 3
2 to the power of 3 equals 8!
Please enter base and power in following format, if you want to quit to main menu, enter Q.
q

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
2
Enter an amount of terms. Must be a positive integer >0 or enter Q to quit
3
1+(2*2)+(3*3)=14
Enter an amount of terms. Must be a positive integer >0 or enter Q to quit
q

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
3
Enter an amount of terms. Must be a positive integer >0 or enter Q to quit
3
(3*3)+(2*2)+1=14
Enter an amount of terms. Must be a positive integer >0 or enter Q to quit
q

1. Use power function
2. Sum of Squares(low to high)
3. Sum of Squares(high to low)
4. End program
4

c:\Users\student.CS\source\repos\Project2\Debug\Project2.exe (process 13596) exited with code 0.
Press any key to close this window . . .
*/