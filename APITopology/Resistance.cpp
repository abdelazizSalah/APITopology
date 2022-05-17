#include "Resistance.h"

Resistance::Resistance(string id, float df, float mn, float mx, map<string, string> NL) :TwoTerminals(id, mn, mx, df, NL)
{
	this->setType("resistor");
}

void Resistance::printDev()
{
	TwoTerminals::printDev(); 
	cout << "type = resistor\n"; 
}
