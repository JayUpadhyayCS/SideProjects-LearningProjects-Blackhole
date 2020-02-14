#include <iostream>

int recPow(int,int&);
using namespace std;
int main()
{
	int userInput;
	cout << "1. Use power function\n 2.Sum of Squares(low to high)\n3.Sum of Squares(high to low)\n";
	cin >> userInput;
	switch (userInput)
	{
	case 1:
		int base;
		int exponent;
		cout << "Enter a base" << endl;
		cin >> base;
		cout << "Enter an exponent" << endl;
		cin >> exponent;
		recPow(base, exponent);
	}
}
int recPow(int base, int &exponent)
{
	if (exponent)// if exponent is not 0
	{
		// If its negative exponent, I need to multiple 1/base against itself. Otherwise base*base;
	}

}