#include "NMOS.h"

NMOS::NMOS(string id, float mn, float def, float mx, map<string, string> NL) : ThreeTerminals(id, def, mn, mx, NL)
{
	this->setType("nmos");
}

void NMOS::printDev()
{
	ThreeTerminals::printDev(); 
	cout << "type = nmos\n";
}
