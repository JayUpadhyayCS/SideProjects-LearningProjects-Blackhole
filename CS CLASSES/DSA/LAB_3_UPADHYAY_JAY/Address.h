#ifndef ADDRESS
#define ADDRESS

#include <string>
class Address {
private:
	std::string numStreet;
	std::string streetName;
	std::string cityName;
	std::string stateName;
	std::string zipCode;
public:
	//constructors
	Address() {}
	Address(std::string numStreetTemp,std::string streetNameTemp,
	std::string cityNameTemp,std::string stateNameTemp,std::string zipCodeTemp);
	//getters
	std::string GetStreetNum()const;
	std::string GetStreetName()const;
	std::string GetCityName()const;
	std::string GetStateName()const;
	std::string GetZipCode()const;
};
#endif