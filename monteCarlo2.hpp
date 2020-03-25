#ifndef MONTECARLO2_HPP
#define MONTECARLO2_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

class MonteCarlo2
{
	std::fstream readFile;
	std::string fileName;
	int days;
	int categories;
	std::vector<std::string> cat;
	std::string units;
	int *mean;
	int *range;
	int *occur;
	void readData();
	void printData();
	void tokenize(char*,char*,char*,char*);
public:	
	MonteCarlo2();
	~MonteCarlo2();
	void compute();
	void simulate();
};

#endif