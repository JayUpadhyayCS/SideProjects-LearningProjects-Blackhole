#include "Record.h"
#include <string>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
Record::Record()
{
}
Record::Record(std::string firstNameTemp, std::string lastNameTemp, std::string numStreetTemp, std::string streetNameTemp, std::string cityNameTemp, std::string numPhoneTemp, int monthTemp, int dayTemp, int yearTemp)
{
	firstName = firstNameTemp;
	lastName = lastNameTemp;
	numStreet = numStreetTemp;
	streetName = streetNameTemp;
	cityName = cityNameTemp; 
	numPhone = numPhoneTemp;
	month = monthTemp;
	day = dayTemp;
	year = yearTemp;
}
std::string Record::GetLastName()
{
	return lastName;
}
std::string Record::GetPhoneNum()
{
	return numPhone;
}
void Record::Print()
{
	std::cout << std::setw(SPACE) << std::left << firstName << std::setw(SPACE) << lastName << std::left << std::setw(SPACE)
		<< numStreet << std::setw(SPACE) << std::left <<streetName << std::setw(SPACE) << std::left << cityName
		<< std::setw(SPACE) << std::left <<  numPhone << std::setw(2) << std::setfill('0')<< std::right << day << std::setw(2) << std::setfill('0') << std::right<< month << year 
		<<std::setfill(' ')<<std::endl;
}
void Record::SaveToFile(std::ofstream& outFile)
{
	outFile << std::endl<< std::setw(SPACE) << std::left << firstName << std::setw(SPACE) << lastName << std::left << std::setw(SPACE)
		<< numStreet << std::setw(SPACE) << std::left << streetName << std::setw(SPACE) << std::left << cityName
		<< std::setw(SPACE) << std::left << numPhone << std::setw(2) << std::setfill('0') << std::right 
		<< day << std::setw(2) << std::setfill('0') << std::right << month << year << std::setfill(' ');
	
}
//John Doe 6202 Winnetka Canoga ca 91336
//Record::Record(std::string firstName, std::string lastName, int numStreet, std::string streetName, std::string cityName, int numPhone, int month, int day, int year)
//{
//
//}
Record::~Record()
{
}
