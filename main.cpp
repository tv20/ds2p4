/**********************************
Thati Vang
main.cpp
project 4
**********************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

#include "file.hpp"
#include "monteCarlo1.hpp"
#include "monteCarlo2.hpp"

int main()
{
	srand(time(0));

	File allData;
	MonteCarlo1 sim1(allData.getSpec(1), allData.getSpec(2), allData.getSpec(3), allData.getSpec(4));

	// based on how many .dat files to read in
	int trials = 4;
	
	std::cout << "PART 1\n";

	for(int i = 1; i <= trials; i++)
	{
		allData.createDataSet(i);
		sim1.readDataSet(i);		
		
		std::string first = "ds";
		std::string last = ".txt";
		Spec* temp = allData.getSpec(i);
		
		// deletes all .txt files created by this run
		for(int j = 0; j < temp->getBatches(); j++)
		{
			std::string c = std::to_string(j);
			std::string toDelete = first + c + last;
			remove(toDelete.c_str());
		}	
	}
	
	std::cout << "PART 2\n\n";

	MonteCarlo2 sim2;
	sim2.compute();
	sim2.simulate();
	
	return 0;
}