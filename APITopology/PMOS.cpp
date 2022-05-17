#include "PMOS.h"

PMOS::PMOS(string id, float def, float mn, float mx, map<string, string> NL):ThreeTerminals(id, def , mn , mx , NL)
{
	this->setType("pmos"); 
}

void PMOS::printDev()
{
	// to be implemented
	ThreeTerminals::printDev();
	cout << "type = pmos\n";
}
