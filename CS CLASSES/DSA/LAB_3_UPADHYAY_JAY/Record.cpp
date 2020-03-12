#include "Record.h"
#include <string>
#include <iostream>
#include <iomanip>
const int SPACE = 15;
Record::Record()
{
}
Record::Record(std::string firstNameTemp, std::string lastNameTemp, std::string numStreetTemp, std::string streetNameTemp, std::string cityNameTemp,std::string stateTemp, std::string zipCodeTemp, std::string numPhoneTemp)
{
	firstName = firstNameTemp;
	lastName = lastNameTemp;
	homeAddress=Address(numStreetTemp,streetNameTemp,cityNameTemp,stateTemp,zipCodeTemp);
	numPhone = numPhoneTemp;
	
}
std::string Record::GetLastName()const
{
	return lastName;
}
std::string Record::GetPhoneNum()const
{
	return numPhone;
}
void Record::Print()
{

	std::cout << std::setw(SPACE) << std::left << firstName << std::setw(SPACE) << lastName << std::left << std::setw(SPACE)
		<< homeAddress.GetStreetNum() << std::setw(SPACE) << std::left << homeAddress.GetStreetName() << std::setw(SPACE) << std::left << homeAddress.GetCityName()
		<< std::setw(SPACE) << std::left << homeAddress.GetStateName() << std::setw(SPACE) << std::left << homeAddress.GetZipCode() <<  std::right 
		<< "(" << numPhone.substr(0, 3) << ") " << numPhone.substr(4, 3) << " " << numPhone.substr(6, 4)<<std::endl;
}
void Record::SaveToFile(std::ofstream& outFile)
{
	outFile << std::endl << std::setw(SPACE) << std::left << firstName << std::setw(SPACE) << lastName << std::left << std::setw(SPACE)
		<< homeAddress.GetStreetNum() << std::setw(SPACE) << std::left << homeAddress.GetStreetName() << std::setw(SPACE) << std::left << homeAddress.GetCityName()
		<< std::setw(SPACE) << std::left << homeAddress.GetStateName() << std::setw(SPACE) << std::left << homeAddress.GetZipCode() << std::right
		<< "(" << numPhone.substr(0, 3) << ") " << numPhone.substr(4, 3) << " " << numPhone.substr(6, 4);
	
}
//John Doe 6202 Winnetka Canoga ca 91336
//Record::Record(std::string firstName, std::string lastName, int numStreet, std::string streetName, std::string cityName, int numPhone, int month, int day, int year)
//{
//
//}
Record::~Record()
{
}
