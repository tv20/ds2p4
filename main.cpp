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
	MonteCarlo1 sim(allData.getSpec(1), allData.getSpec(2), 
			allData.getSpec(3), allData.getSpec(4));

	int trials = 4;
	
	for(int i = 1; i <= trials; i++)
	{
		allData.createDataSet(i);
		sim.readDataSet(i);		
		
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
	
	
	return 0;
}