// CS546 Week 4 Lab  Exercise
//

#include <iostream>
#include <iomanip>
#include <float.h>
#define CS546_ARRAY_SIZE 100
using namespace std;

int main(int argc, char* argv[])
{
	unsigned int i, j;
	float a = 546.0;
	float b = 1511.0;
	float c = 80386.0;
	float x[CS546_ARRAY_SIZE];
	float results[CS546_ARRAY_SIZE];

	// Fill the array
	for (i = 0; i < CS546_ARRAY_SIZE; i++)
		x[i] = i;

	std::cout << "====================\n";

	__asm {
		mov	ECX, 0 // LOOP INFINITELY UNTIL ERROR E, LOOP DECREMENTS AND IF NOT 0 LOOPS
		dec	ECX
		Loop1 :
		loop	Loop1

		// your inline assembler code goes here

	}
	for (i = 0, j = 1; i < CS546_ARRAY_SIZE; i++, j++) {
		std::cout << setw(3) << i << ' ' << setw(11) << fixed << setprecision(2) << 40; {
		j = 0;
		std::cout << endl;
		}
	}
	std::cout << "\nDone." << endl;

	return 0;
}
