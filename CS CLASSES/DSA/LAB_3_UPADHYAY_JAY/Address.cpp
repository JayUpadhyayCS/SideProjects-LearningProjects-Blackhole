#include "Address.h"
#include <string>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
Address::Address()
{
}
Address::Address(std::string firstNameTemp, std::string lastNameTemp, std::string numStreetTemp, std::string streetNameTemp, std::string cityNameTemp,std::string stateTemp, std::string zipCodeTemp, std::string numPhoneTemp)
{
	firstName = firstNameTemp;
	lastName = lastNameTemp;
	numStreet = numStreetTemp;
	streetName = streetNameTemp;
	cityName = cityNameTemp; 
	stateName = stateTemp;
	zipCode = zipCodeTemp;
	numPhone = numPhoneTemp;
	
}
std::string Address::GetLastName()
{
	return lastName;
}
std::string Address::GetPhoneNum()
{
	return numPhone;
}
void Address::Print()
{

	std::cout << std::setw(SPACE) << std::left << firstName << std::setw(SPACE) << lastName << std::left << std::setw(SPACE)
		<< numStreet << std::setw(SPACE) << std::left << streetName << std::setw(SPACE) << std::left << cityName
		<< std::setw(SPACE) << std::left << stateName << std::setw(SPACE) << std::left << zipCode <<  std::right 
		<< "(" << numPhone.substr(0, 3) << ") " << numPhone.substr(4, 3) << " " << numPhone.substr(6, 4)<<std::endl;
}
void Address::SaveToFile(std::ofstream& outFile)
{
	outFile << std::endl << std::setw(SPACE) << std::left << firstName << std::setw(SPACE) << lastName << std::left << std::setw(SPACE)
		<< numStreet << std::setw(SPACE) << std::left << streetName << std::setw(SPACE) << std::left << cityName
		<< std::setw(SPACE) << std::left << stateName << std::setw(SPACE) << std::left << zipCode <<  std::right 
		<< "("<< numPhone.substr(0,3) << ") "<< numPhone.substr(4,3)<< " "<< numPhone.substr(6,4);
	
}
//John Doe 6202 Winnetka Canoga ca 91336
//Record::Record(std::string firstName, std::string lastName, int numStreet, std::string streetName, std::string cityName, int numPhone, int month, int day, int year)
//{
//
//}
Address::~Address()
{
}
