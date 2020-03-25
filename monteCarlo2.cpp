#include "monteCarlo2.hpp"

MonteCarlo2::MonteCarlo2()
{
	this->fileName = "readings.dat";
	this->days = 0;
	this->categories = 0;
	this->units = "";
	readData();
	this->mean = new int[this->categories];
	this->range = new int[this->categories];
	this->occur = new int[this->categories];
}

MonteCarlo2::~MonteCarlo2()
{
	delete [] this->mean;
	delete [] this->range;
	delete [] this->occur;
}

void MonteCarlo2::readData()
{
	this->readFile.open(fileName);
	
	if(this->readFile.fail())
	{
		std::cout << "--ERROR--\n\n";
		exit(-1);
	}
	
	this->readFile >> this->days;
	this->readFile >> this->categories;

	// grabs the last \n character from the previous line	
	std::string temp;
	std::getline(this->readFile, temp);
	
	for(int i = 0; i < this->categories; i++)
	{
		std::string temp;
		std::getline(this->readFile, temp);
		this->cat.push_back(temp);
	}
	
	this->readFile >> this->units;
	
	printData();
	this->readFile.close();
}

void MonteCarlo2::printData()
{
	std::cout << std::endl << std::endl
		  << "     Simulated days: " << this->days << std::endl
		  << "     Number of categories: " << this-> categories << std::endl
		  << "     Ranges and occurences in each range:\n";
	
	for(unsigned int i = 0; i < this->cat.size(); i++)
	{
		std::cout << "     " << cat.at(i) << std::endl;
	}
	
	std::cout << "     Units of measure: " << this->units << std::endl;
}

void MonteCarlo2::compute()
{
	std::string toToken;
	int len = 100;
	char line[len];
	char t1[len];
	char t2[len];
	char t3[len];
	int adder[2] = {0};
	
	for(unsigned int i = 0; i < this->cat.size(); i++)
	{
		toToken = this->cat.at(i);
		for(unsigned int j = 0; j < toToken.length()+1; j++)
		{
			line[j] = toToken[j];
		}
	
		tokenize(line, t1, t2, t3);
		
		int low, high, occ;
		std::stringstream lo(t1), hi(t2), oc(t3);
		lo >> low;
		hi >> high;
		oc >> occ;
		
		this->occur[i] = occ;
		this->mean[i] = (low + high) / 2;
		
		double num = (static_cast<double>(occ) / this->days) * 100;
		adder[1] = num;
		adder[0] += adder[1];
		this->range[i] = adder [0];
	}
	
}

void MonteCarlo2::tokenize(char *line, char *t1, char *t2, char *t3)
{
	int pos1, pos2 ,pos3;
	
	for(pos1 = 0; line[pos1] != '-'; pos1++)
	{
		t1[pos1] = line[pos1];
	}
	t1[pos1] = '\0';
	
	pos2 = pos1 + 1;
	pos1 = 0;
	
	for(; line[pos2] != ':'; pos2++)
	{
		t2[pos1++] = line[pos2];
	}
	t2[pos1] = '\0';
	
	pos3 = pos2 + 1;
	pos1 = 0;
	
	for(; line[pos3] != '\0'; pos3++)
	{
		t3[pos1++] = line[pos3];
	}
	t3[pos1] = '\0';
}

void MonteCarlo2::simulate()
{
	int occurrence[this->categories] = {0};

	// simluates 0-99 and counts how many occurrences for n days
	for(int i = 0; i < this->days; i++)
	{
		int num = rand() % 100;
		
		//std::cout << "i = " << i << ": ";
		
		for(int j = 0; j < this->categories; j++)
		{
			if(num < this->range[j])
			{
				//std::cout << num << " < " << this->range[j] << std::endl;
				occurrence[j]++;
				j = this->categories;
			}
		}		
	}
	
	double totVal = 0;
	double totSimVal = 0;
	
	for(int i = 0; i < this->categories; i++)
	{
		double val = (static_cast<double>(this->mean[i]) * this->occur[i]) / this->days;
		totVal += val;
		
		double simVal = (static_cast<double>(this->mean[i]) * occurrence[i]) / this->days;
		totSimVal += simVal;
	}
	
	std::cout << "     Analytical model: " << std::setprecision(2) << totVal << std::endl;
	std::cout << "     Simulation: " << std::setprecision(2) << totSimVal << std::endl;
}