#include "Address.h"
Address::Address(std::string numStreetTemp,std::string streetNameTemp,
	std::string cityNameTemp,std::string stateNameTemp,std::string zipCodeTemp)
{
	numStreet = numStreetTemp;
	streetName = streetNameTemp;
	cityName = cityNameTemp;
	stateName = stateNameTemp;
	zipCode = zipCodeTemp;
}
std::string Address::GetStreetNum()const
{
	return numStreet;
}
std::string Address::GetStreetName()const
{
	return streetName;
}
std::string Address::GetCityName()const
{
	return cityName;
}
std::string Address::GetStateName()const
{
	return stateName;
}
std::string Address::GetZipCode()const
{
	return zipCode;
}