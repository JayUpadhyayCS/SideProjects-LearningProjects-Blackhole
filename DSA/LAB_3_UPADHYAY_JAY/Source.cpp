#include <iostream>
// ADDRESSBOOK pointer to a person
//PERSON holds data
// PersonList
class Record // Made class in case they want to alter data. Methods should be here.
{
private:
	string firstName;
	string lastName;
	int numStreet;
	string streetName;
	string cityName;
	int numPhone;
	int month;
	int day;
	int year;
public:
	Record();
	~Record();
};
struct node {
	Record data;
	Record* ptr = nullptr;
};
using namespace std;
int main()
{
	cout << "Hello world" << endl;
}