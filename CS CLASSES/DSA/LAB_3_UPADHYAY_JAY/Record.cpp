#include "Record.h"

Address Record::GetData()const
{
	return data;
}
Record* Record::GetPtr()const
{
	return next;
}

void Record::SetData(Address input)
{
	data=input;
}
void Record::SetPtr(Record* ptr)
{
	next=ptr;
}
void Record::SetDataPtr(Address input, Record* ptr)
{
	data = input;
	next = ptr;
}
