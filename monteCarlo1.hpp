/**********************************
Thati Vang
monteCarlo1.hpp
project 4
**********************************/

#ifndef MONTECARLO1_HPP
#define MONTECARLO1_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

#include "spec.hpp"

class MonteCarlo1
{
	Spec *t1, *t2, *t3, *t4;
	std::ifstream readFile;
	void analyze(Spec*,int);
public:
	MonteCarlo1(Spec*,Spec*,Spec*,Spec*);
	void readDataSet(int n);
};

#endif