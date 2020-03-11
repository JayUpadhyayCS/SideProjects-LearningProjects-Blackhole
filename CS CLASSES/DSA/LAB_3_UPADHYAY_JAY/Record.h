#ifndef RECORD
#define RECORD
#include "Address.h"
#include <fstream>
class Record 
{
private:
	std::string firstName;
	std::string lastName;
	// needs to be in seperate class
	Address homeAddress;
	// seperate
	std::string numPhone;

public:
	Record();
	Record(std::string firstName, std::string lastName, std::string numStreet, std::string streetName, std::string cityName, std::string stateName,std::string zipCodeTemp, std::string numPhone);
	std::string GetPhoneNum()const;
	std::string GetLastName()const;


	void Print();
	void SaveToFile(std::ofstream &);
	~Record();
};
#endif RECORD