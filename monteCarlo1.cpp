#include "monteCarlo1.hpp"

MonteCarlo1::MonteCarlo1(Spec* t1, Spec* t2, Spec* t3, Spec* t4)
{
	this->t1 = t1;
	this->t2 = t2;
	this->t3 = t3;
	this->t4 = t4;
}

void MonteCarlo1::readDataSet(int n)
{
	Spec *temp;
	char gb;
	
	switch (n)
	{
		case 1: temp = this->t1;
			break;
		case 2: temp = this->t2;
			break;
		case 3: temp = this->t3;
			break;
		case 4: temp = this->t4;
			break;
		default:
			break;
	}
	
	std::string first = "ds";
	std::string last = ".txt";
	int found = 0;
	
	std::cout << "\n\nAnalyzing Data Sets:\n\n";
	
	for(int i = 0; i < temp->getBatches(); i++)
	{
		std::string c = std::to_string(i);
		std::string fileName = first + c + last;
		this->readFile.open(fileName);
		// std::cout << "filename: " << fileName << std::endl;
		
		if(this->readFile.fail())
		{
			std::cout << "--ERROR--\n";
		}
		
		for(int j = 0; j < temp->getSample(); j++)
		{
			readFile >> gb;
			
			if(gb == 'b')
			{
				std::cout << "     Batch #" << i  << " is bad\n";
				found++;
				j = temp->getSample();
			}
		}
		
		this->readFile.close();
		this->readFile.clear();
	}
	
	analyze(temp,found);
	
	for(int i = 0; i < 60; i++)
	{
		std::cout << "_";
	}
	std::cout << std::endl;
}

void MonteCarlo1::analyze(Spec *temp, int found)
{
	double percentFound = found / (static_cast<double>(temp->getBadBatches()) * temp->getBatches() / 100);
	double base = 1 - static_cast<double>(temp->getBadItems()) / 100;
	std::cout << "\nbase: " <<  std::fixed << base
		  << ", Exponent = " << temp->getSample() << std::endl
		  << "P(failure to detect bad batch) = " << pow(base,temp->getSample()) << std::endl
		  << "Percentage of bad batches actually detected = " << percentFound * 100 << "%" << std::endl;
}
