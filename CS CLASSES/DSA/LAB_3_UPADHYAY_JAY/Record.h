#pragma once
#include "Address.h"
class Record {
private:
	Address data;
	Record* next = nullptr;
public:
	Address GetData()const;
	Record* GetPtr()const;
	void SetData(Address);
	void SetPtr(Record*);
	void SetDataPtr(Address input, Record* ptr);
};