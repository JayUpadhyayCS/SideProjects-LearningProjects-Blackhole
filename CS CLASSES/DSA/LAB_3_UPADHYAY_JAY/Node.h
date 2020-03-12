#ifndef NODE
#define NODE
#include "Record.h"
class Node {
private:
	Record data;
	Node* next = nullptr;
public:
	Node();
	Node(Record input, Node* ptr);
	Record GetData()const;
	Node* GetPtr()const;
	void SetData(Record);
	void SetPtr(Node*);
	void LoadNode(std::ifstream &infile);//FOR LOADING INITIAL ifstream
	void LoadNode();// FOR ADDING DATA FROM CIN
};
#endif