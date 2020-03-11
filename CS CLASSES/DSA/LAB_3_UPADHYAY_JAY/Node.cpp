#include "Node.h"

Record Node::GetData()const
{
	return data;
}
Node* Node::GetPtr()const
{
	return next;
}

void Node::SetData(Record input)
{
	data=input;
}
void Node::SetPtr(Node* ptr)
{
	next=ptr;
}
Node::Node(){}
Node::Node(Record input, Node* ptr)
{
	data = input;
	next = ptr;
}
