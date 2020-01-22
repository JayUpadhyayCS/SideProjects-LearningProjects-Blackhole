#include <iostream>

using namespace std;
class Node {
private:
	int val;
	Node* ptr;
public:
	//constructors
	Node()
	{

		ptr = NULL; // Could cause error
	}
	Node(int input)
	{
		this->val = input;
		ptr = NULL;
	}
	//Destructors
	~Node()
	{
		if (this->ptr != NULL)
		{
			delete(&this->ptr);
		}
		delete ptr;
		ptr = NULL;
	}
	//Insert

	// counter
	// pushback]
	void push_back(int input)// Not recursive
	{
		Node* ptr2 = this;
		while (ptr2 != NULL)
		{
			ptr2 = ptr2->ptr;
		}
		Node* ptr3 = new Node(input);
		*ptr2->ptr = *ptr3;
		ptr2 = NULL;
	}

	void push_back2(int input, Node* ptr)// recursive
	{

		if (ptr != NULL)
		{
			push_back2(input, ptr->ptr);
		}
		else
		{
			ptr = new Node(input);
		}
	}

	// Display all
	// display position
	// delete

};

int main()
{
	Node node(1);
	Node* ptr = &node;
	node.push_back(2);
	node.push_back2(3, ptr);

}