#pragma once
#include <string>
class Record // Made class in case they want to alter data. Methods should be here.
{
private:
	std::string firstName;
	std::string lastName;
	int numStreet;
	std::string streetName;
	std::string cityName;
	int numPhone;
	int month;
	int day;
	int year;
public:
	Record();
	~Record();
};