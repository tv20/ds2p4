/**********************************
Thati Vang
spec.hpp
project 4
**********************************/

#ifndef SPEC_HPP
#define SPEC_HPP

class Spec
{
	int batches;
	int items;
	int badBatches;
	int badItems;
	int sample;
public:
	Spec();
	Spec(int,int,int,int,int);
	int getBatches();
	int getItems();
	int getBadBatches();
	int getBadItems();
	int getSample();
};

#endif