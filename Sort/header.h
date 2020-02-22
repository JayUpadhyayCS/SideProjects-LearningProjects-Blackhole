#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <algorithm>


class sorter
{
	private:
		

		
	    /* data */
	public:
		std::vector<int> data;// Holds unsorted data
		std::vector<std::vector<int>> sorteddata;// vector of data sorted through various methods
		std::vector<int> bubdata;
		std::vector<int> mergedata;

		void copyVec(std::vector<int>data, std::vector<int>&sorteddata)
		{
			sorteddata = data;
		}

		std::vector<int> getdata()
		{
			auto start = std::chrono::high_resolution_clock::now();
			std::vector<int> data;
			
			int buffer;
			std::ifstream infile;
			infile.open("C:\\Users\\Jay\\Desktop\\Sort\\input.txt");
			if (!infile)
			{
				std::cout << "Infile" << std::endl;
				exit(1);
			}
			while (!infile.eof())
			{
				infile >> buffer;
				data.push_back(buffer);
			}
			infile.close();
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration = end - start;
			std::cout << "Putting data into a vector takes " << duration.count() << " ms." << std::endl;
			return data;
		}
		std::vector<int> selectionsort(std::vector<int>data)
		{
			auto start = std::chrono::high_resolution_clock::now();
			bool sort = true;
			while (sort)
			{
				sort = false;
				for (int x = 0; x < data.size(); x++)
				{
					for (int y = x + 1; y < data.size() - 1; y++)
						if (data.at(x) > data.at(y))
						{
							int buffer;
							buffer = data.at(x);
							data.at(x) = data.at(y);
							data.at(y) = buffer;
							sort = true;

						}
				}
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration = end - start;
			std::cout << "Selection sort takes " << duration.count() << " ms." << std::endl;
			return data;
		}
		std::vector<int> quicksort(std::vector<int>data)
		{

			if (data.at(0) > data.at(data.size() / 2))
			{
				std::vector<int>::iterator pivot = data.begin() + (data.size() / 2);
			}
			for (std::vector<int>::iterator it = data.begin(); it < data.end(); it++)
			{
				//if (*it < (*pivot))
			}

		}
		std::vector<int> RecBubsort( std::vector <int>& data)
		{
			for (int x = 0; x < (data.size()-1); x++)
			{
				if (data.at(x) > data.at(x + 1))
				{
					int* buffer=new(int);
					*buffer = data.at(x);
					data.at(x) = data.at(x + 1);
					data.at(x+1) = *buffer;
					RecBubsort(data);
					free (buffer);
				}
			}
			return data;
		}
		std::vector<int> bubsort(std::vector <int> data)
		{
			auto start = std::chrono::high_resolution_clock::now();
			bool finish=false;
			while (!finish)
			{
				finish = true;
				for (int x = 0; x < (data.size() - 1); x++)
				{
					if (data.at(x) > data.at(x + 1))
					{
						int buffer;
						buffer = data.at(x);
						data.at(x) = data.at(x + 1);
						data.at(x + 1) = buffer;
						finish = false;

					}
				}
			}

			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration = end - start;
			std::cout << "Bubble sort(Not recursive) takes " << duration.count() << " ms." << std::endl;
			return data;
		}
		std::vector<int> insertsort(std::vector <int> data)
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int x = 1; x < (data.size() - 1); x++)
			{
				for (int y = 0; y < x; y++)
				{
					if (data.at(x) < data.at(y))
					{
						data.insert(data.begin() + y, data.at(x));
						data.erase(data.begin()+x+1);
						break;
					}
				}
			}
			
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration = end - start;
			std::cout << "Insertion Sort takes " << duration.count() << " ms." << std::endl;
			return data;
		}
		void mergesort(std::vector <int> &data, int s, int e)// Not working
		{
			if (s == e)
				return;
			int mid=((e/2));
			mergesort(data, s, mid);
			mergesort(data, mid, e);
			while (s != mid)
			{
				
				if (data.at(s) > data.at(mid))
				{
					data.insert(data.begin() + s, data.at(mid));
					data.erase(data.begin() + mid + 1);
					s++;

				}
				else
				{
					data.insert(data.begin() + s +1, data.at(mid));
					data.erase(data.begin() + mid + 1);
				}
				
			}
			return;
		}
		vector<int> quicksort(std::vector <int> data)// Not working
		{
			auto start = std::chrono::high_resolution_clock::now();
			int pivot = (data.at(0) > data.at(data.size() - 1)) ? 0 : (data.size() - 1);
			pivot = (pivot > data.at(data.size() / 2)) ? pivot : data.size() / 2;
			
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::milli> duration = end - start;
			std::cout << "Quicksort takes " << duration.count() << " ms." << std::endl;
			return data;
			
		}


};
