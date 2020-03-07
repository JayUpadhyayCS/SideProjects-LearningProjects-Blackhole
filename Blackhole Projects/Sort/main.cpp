
#include "header.h"
using namespace std;
int main()
{
	sorter data;
	cout << "Beginning to run" << endl;
	data.data=data.getdata();
	vector<int> temp;
	data.copyVec(data.data, data.bubdata);
	data.copyVec(data.data, data.mergedata);
	//Bub sort
	temp = data.bubsort(data.data);
	data.sorteddata.push_back(temp);
	// Timing Recursive bubble sort
	auto start = std::chrono::high_resolution_clock::now();
	//temp=data.RecBubsort(data.bubdata);
	//data.sorteddata.push_back(temp);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;
	//std::cout << "Recursive Bubble sort takes " << duration.count() << " ms." << endl;
	//Selection sort
	temp=data.selectionsort(data.data);
	data.sorteddata.push_back(temp);
	//temp=data.quicksort(data.data); Not finisheed yet
//	data.sorteddata.push_back(temp);

	//Insertion Sort
	temp = data.insertsort(data.data);
	data.sorteddata.push_back(temp);
	// Merge sort
	//data.mergesort(data.mergedata,0,data.mergedata.size());

	// QuickSort

	cout << data.sorteddata.size() << endl;
	cout << "Finnish" << endl;
}