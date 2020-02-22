#include "Record.h"
#include <string>
Record::Record()
{
}
Record::Record(std::string firstNameTemp, std::string lastNameTemp, std::string numStreetTemp, std::string streetNameTemp, std::string cityNameTemp, int numPhoneTemp, int monthTemp, int dayTemp, int yearTemp)
{
	firstName = firstNameTemp;
	lastName = lastNameTemp;
	numStreet = numStreetTemp;
	cityName = cityNameTemp; 
	numPhone = numPhoneTemp;
	month = monthTemp;
	day = dayTemp;
	year = yearTemp;
}
//John Doe 6202 Winnetka Canoga ca 91336
//Record::Record(std::string firstName, std::string lastName, int numStreet, std::string streetName, std::string cityName, int numPhone, int month, int day, int year)
//{
//
//}
Record::~Record()
{
}
