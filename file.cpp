#include "file.hpp"

File::File()
{
	this->fileName = "tn.dat";
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
		
		Spec temp(data[i].at(0), data[i].at(1), 
			  data[i].at(2), data[i].at(3), 
			  data[i].at(4));
		
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

Spec* File::getSpec(int n)
{
	Spec *temp = nullptr;
	
	switch (n)
	{
		case 1: temp = &t1;
			break;
		case 2: temp = &t2;
			break;
		case 3: temp = &t3;
			break;
		case 4: temp = &t4;
			break;
		default:
			break;
	}
	return temp;
}

void File::createDataSet(int n)
{
	print(n);
	
	Spec temp;
	
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
	
	int bad = temp.getBatches() / (temp.getBatches() * temp.getBadBatches() / 100);
	int badRange = temp.getBadItems() * temp.getBatches() / 100;
	int badSet = 0;
	std::string first = "ds";
	std::string last = ".txt";
	
	std::cout << "Generating Data sets:\n\n"
		  << std::setw(20) << "Bad Set Batch #" 
		  << std::setw(12) << "Total Bad"
		  << std::setw(14) << "Total Items" 
		  << std::setw(9) << "% Bad\n";
	line();

	for(int i = 0; i < temp.getBatches(); i++)
	{
		int totalBad = 0;
		std::string c = std::to_string(i);
		std::string name = first + c + last;
		
		// makes sure the total number of bad 
		// batches does not go over its max
		double percent = temp.getBadBatches();
		double maxBad1 = (percent / 100 ) * temp.getBatches();
		int maxBad2 = static_cast<int>(maxBad1);
		
		this->writeFile.open(name);
		
	
		if(i % bad == 0 && badSet < maxBad2)
		{
			for(int j = 0; j < temp.getItems(); j++)
			{
				int num = rand() % temp.getBatches();
				
				if(num >= 0 && num < badRange)
				{
					this->writeFile << "b\n";
					totalBad++;
				}
				else
				{
					this->writeFile << "g\n";
				}
			}
			
			badSet++;
			
			std::cout << std::setw(12) << i << std::setw(17) << totalBad 
				  << std::setw(14) << temp.getItems() << std::setw(9) 
				  << temp.getBadItems() << std::endl;
		}
		else
		{
			for(int j = 0; j < temp.getItems(); j++)
			{
				this->writeFile << "g\n";
			}
		}
			
		this->writeFile.close();
		this->writeFile.clear();
	}
	std::cout << "\n     Total bad sets = " << badSet << std::endl;
}

void File::print(int n)
{
	Spec temp;
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
	
	int w1 = 50;
	int w2 = 4;
	
	std::cout << "\nSimulation " << n  << ":\n"
		  << std::setw(w1) << std::left << "    Number of batches of items:" 
		  << std::setw(w2) << std::right << temp.getBatches() << std::endl
		  << std::setw(w1) << std::left << "    Number of items in each batch:" 
		  << std::setw(w2) << std::right << temp.getItems() << std::endl
		  << std::setw(w1) << std::left << "    Percentage of batches containing bad items:" 
		  << std::setw(w2) << std::right << temp.getBadBatches() << "%" << std::endl
		  << std::setw(w1) << std::left << "    Percentage of items that are bad in a bad set:" 
		  << std::setw(w2) << std::right << temp.getBadItems() << "%" << std::endl
		  << std::setw(w1) << std::left << "    Items sampled from each set:" 
		  << std::setw(w2) << std::right << temp.getSample() 
		  << std::endl << std::endl;
}

void File::line()
{
	std::cout << "     ";
	for(int i = 0; i < 49; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

























