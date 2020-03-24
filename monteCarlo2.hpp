#ifndef MONTECARLO2_HPP
#define MONTECARLO2_HPP

#include <iostream>
#include <fstream>

class MonteCarlo2
{
	fstream readFile;
	std::string fileName;
public:	
	MonteCarlo2();
	void readData();
	void compute();
	void simulate();

};

#endif