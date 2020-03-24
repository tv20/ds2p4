#include "file.hpp"

File::File()
{
	this->fileName = "tx.dat";
	read();
}

void File::read()
{
	char num = '1';
	int val;
	std::vector<int> data[4];
	
	for(int i = 0; i < 4; i++)
	{
		this->fileName[1] = num++;
		this->readFile.open(this->fileName);
		
		if(this->readFile.fail())
		{
			std::cout << "--ERROR--\n";
			exit(-1);
		}
		
		while(this->readFile >> val)
		{
			data[i].push_back(val);
		}
		
		Spec temp(data[i].at(0), data[i].at(1), data[i].at(2), data[i].at(3), data[i].at(4));
		
		switch (i)
		{
			case 0: this->t1 = temp;
				break;
			case 1: this->t2 = temp;
				break;
			case 2: this->t3 = temp;
				break;
			case 3: this->t4 = temp;
				break;
			default:
				break;
		}
		
		this->readFile.close();
		this->readFile.clear();
	}
	

}

Spec* File::getSpecs(int t)
{
	Spec* temp = nullptr;
	return temp;
}

void File::dataSets(int)
{
	
}

void File::print(int)
{

}