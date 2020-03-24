#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <vector>

#include "spec.hpp"

class File
{
	std::ifstream readFile;
	std::string fileName;
	Spec t1, t2, t3, t4;
	std::ofstream writeFile;
	void read();
public:
	File();
	Spec* getSpecs(int);
	void dataSets(int);
	void print(int);
};

#endif