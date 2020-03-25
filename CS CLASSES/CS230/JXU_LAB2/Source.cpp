#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int SIZE = 30;
int main()
{

	ifstream infile;
	infile.open("C:\\Temp\\Dow30.txt");
	if (!infile)
	{
		cout << "Unable to open C:\\Temp\\Dow30.txt - ending" << endl;
		exit(-2);
	}
	string buffer;
	for (int x = 0; x < SIZE && !infile.eof();x++)
	{
		infile >> buffer;
		infile >> buffer;
		//ADD TO FIRST ARR
		//ADD TO SECOND ARR
		if (x != 30 && infile.eof())
		{
			cout << "File C:\\Temp\\Dow30.txt only contains " << x << " records - ending" << endl;
			exit(-2);
		}
	}
}