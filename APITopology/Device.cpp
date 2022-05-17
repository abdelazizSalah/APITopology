#include "Device.h"
// this class should be an abstract class 
Device::Device()
{
	setDefVal(0);
	setID("");
	setMaxVal(0);
	setMinVal(0);
	setType("");
}

Device::Device(string ID, map<string, string> NL, float d, float mn, float mx)
{
	this->def = d;
	this->id = ID;
	this->max = mx;
	this->min = mn;
	NetList = NL;
}

void Device::setID(string id)
{
	this->id = id;
}

void Device::setNetList(map<string, string> NL)
{
	NetList = NL;
}

void Device::setDefVal(float D)
{
	D >= 0 ? def = D : D = 0;
}

void Device::setMinVal(float mn)
{
	//minimum must be less than the max
	mn < max ? min = mn : min = 0;
}

void Device::setMaxVal(float mx)
{
	//max should be greater than minimum
	mx > min ? max = mx : max = 0;
}

void Device::setType(string tp)
{
	type = tp;
}

string Device::getID()
{
	return id;
}

map<string, string>Device::getNetList()
{
	return NetList;
}

float Device::getDef()
{
	return def;
}

float Device::getMax()
{
	return max;
}

float Device::getMin()
{
	return min;
}

void Device::printDev()
{
	cout << "\nDevice Details :\nID = " <<
		id << " ,DefVal= " << def << " ,MaxVal ="<<max
		<<" ,MinVal= " << min <<"\n";  
}

string Device::getType()
{
	return type;
}
