#ifndef HELPER
#define HELPER

#include "AddressBook.h"
#include <string>

void clearCin();
void printLayout();
std::string strLower(std::string tempStr);// lowers a string and returns

// lowers  multiple pieces of data to reduce clutter
void strAllLower(std::string& fName, std::string& lName, std::string& streetName, std::string& cityName, std::string& state);
//Search and delete menu
void InputMenu(AddressBook& recList, int choice);
//get piece of data to add to linked list
void GetEntryInput(AddressBook& recList);
#endif // !1