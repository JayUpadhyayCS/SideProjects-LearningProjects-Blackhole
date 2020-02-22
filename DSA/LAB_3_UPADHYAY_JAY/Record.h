#pragma once
#include <string>
class Record // Made class in case they want to alter data. Methods should be here.
{
public:
	std::string firstName;
	std::string lastName;
	std::string numStreet;
	std::string streetName;
	std::string cityName;
	std::string numPhone;
	int month;
	int day;
	int year;
public:
	Record();
	Record(std::string firstName, std::string lastName, std::string numStreet, std::string streetName, std::string cityName, std::string numPhone, int month, int day, int year);
	~Record();
};