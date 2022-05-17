#include "TwoTerminals.h"

TwoTerminals::TwoTerminals(string id, float mn, float mx, float df, map<string, string>NL) :Device(id, NL, df, mn, mx)
{
}


void TwoTerminals::setT1(string n1)
{
	NetList["t1"] = n1;
}

void TwoTerminals::setT2(string n2)
{
	NetList["t2"] = n2;
}

string TwoTerminals::getT1()
{
	return NetList["t1"];
}

string TwoTerminals::getT2()
{
	return NetList["t2"];
}

void TwoTerminals::printDev()
{
	Device::printDev(); 
	cout << "T1 :" << getT1() << " T2: " << getT2()<<"\n"; 
}
