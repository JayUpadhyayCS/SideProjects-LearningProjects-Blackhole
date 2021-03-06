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
		//BROKEN
	}
	bool rejectInput();
	//Insert
	void insert(int index, int input)
	{
		Node* ptr4 = new Node(input);
		// Find fix for inserting first element
		Node*  ptr2=this;
		Node* ptr3= ptr2;
		while (index != 0)
		{
			index--;
			ptr3 = ptr2;
			ptr2 = ptr2->ptr;
		}
		if (ptr3 == ptr2)
		{
			ptr4->ptr = ptr2;
			ptr2 = this;
			
		}
		ptr4->ptr = ptr2;
		ptr3->ptr = ptr4;


	}

	// counter
	void count()
	{
		Node* ptr2 = this;
		int counter = 1;
		while (ptr2->ptr != NULL)
		{
			ptr2 = ptr2->ptr;
			counter++;
		}
		cout << counter << endl;

	}
	// pushback]
	void push_back(int input)// Not recursive
	{
		Node* ptr2 = this;
		while (ptr2->ptr != NULL)
		{
			ptr2 = ptr2->ptr;
		}
		ptr2->ptr = new Node(input);
	}

	void push_back2(int input, Node* ptr2)// recursive
	{

		if (ptr2->ptr != NULL)
		{
			push_back2(input, ptr2->ptr);
		}
		else
		{
			ptr2->ptr = new Node(input);
		}
	}

	// Display all
	void display()
	{
		Node* ptr2 = this;
		cout << this->val << " ";
		while (ptr2->ptr != NULL)
		{
			ptr2 = ptr2->ptr;
			cout << ptr2->val << " ";
		}
		cout << endl;
		

	}
	// display position
	void display2(int index)
	{
		Node* ptr2 = this;

		
		while (index!=0)
		{
			ptr2 = ptr2->ptr;
			index--;
		}
		cout << ptr2->val<< endl;
	}
	// delete
	void remove(int index)
	{
		Node* ptr2 = this;//points to element after
		Node* ptr3 = ptr2;// points to element before
		
		if (index == 0)
		{
			
			ptr2 = ptr2->ptr;
			ptr3->ptr = NULL;
			delete ptr3;
			ptr3=this;
			ptr3 = ptr2;
		}
		else {
			while (index != 0)
			{
				index--;
				ptr3 = ptr2;
				ptr2 = ptr2->ptr;
			}
			Node* ptr4 = ptr2->ptr;
			delete ptr2;
			ptr3->ptr = ptr4;
		}
		
		
	}

};

int main()
{
	Node* node=new Node(1);
	Node* ptr = node;
	node->push_back(2);
	node->push_back2(3, ptr);
	node->push_back(4);
	node->push_back2(5, ptr);
	node->display();
	node->count();
	node->display2(2);
	node->insert(2, 10);
	node->display2(2);
	node->display();
	node->remove(2);
	node->display();
	
}