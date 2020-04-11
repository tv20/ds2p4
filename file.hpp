/**********************************
Thati Vang
file.hpp
project 4
**********************************/

#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

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
	Spec* getSpec(int);
	void createDataSet(int);
	void print(int);
	void line();	
};

#endif