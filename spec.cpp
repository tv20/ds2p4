/**********************************
Thati Vang
spec.cpp
project 4
**********************************/

#include "spec.hpp"

Spec::Spec()
{
	this->batches = 0;
	this->items = 0;
	this->badBatches = 0;
	this->badItems = 0;
	this->sample = 0;
}

Spec::Spec(int batches, int items, int badBatches, int badItems, int sample)
{
	this->batches = batches;
	this->items = items;
	this->badBatches = badBatches;
	this->badItems = badItems;
	this->sample = sample;
}

int Spec::getBatches()
{
	return this->batches;
}

int Spec::getItems()
{
	return this->items;
}

int Spec::getBadBatches()
{
	return this->badBatches;
}

int Spec::getBadItems()
{
	return this->badItems;
}

int Spec::getSample()
{
	return this->sample;
}