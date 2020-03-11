#include "Node.h"
#include "UtilityFunctions.h"
//constructors 
Node::Node() {}
Node::Node(Record input, Node* ptr)
{
	data = input;
	next = ptr;
}
// getters
Record Node::GetData()const
{
	return data;
}
Node* Node::GetPtr()const
{
	return next;
}
// setters
void Node::SetData(Record input)
{
	data=input;
}
void Node::SetPtr(Node* ptr)
{
	next=ptr;
}
// methods
void Node::LoadNode(std::ifstream & inFile)
{
	std::string firstName, lastName, numStreet, streetName, cityName, state, zip, numPhone;
	inFile >> firstName >> lastName >> numStreet
		>> streetName >> cityName >> state >> zip >> numPhone;// takes all data
	strAllLower(firstName, lastName, streetName, cityName, state);// makes all data proper case
	 data=Record(firstName, lastName, numStreet, streetName, cityName, state, zip, numPhone);//constructor for an address
	 next = nullptr;
}
