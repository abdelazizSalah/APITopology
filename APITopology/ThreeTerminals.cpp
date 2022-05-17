#include "ThreeTerminals.h"


ThreeTerminals::ThreeTerminals(string id, float def, float mn, float mx, map<string, string> NL) :Device(id, NL, def, mn, mx)
{
}

void ThreeTerminals::setSrc(string src)
{
	if (src != "")
		NetList["source"] = src;
}

void ThreeTerminals::setDrain(string drain)
{
	if (drain != "")
		NetList["drain"] = drain;
}

void ThreeTerminals::setGate(string g)
{
	if (g != "")
		NetList["gate"] = g;
}

string ThreeTerminals::getSrc()
{
	return NetList["source"];
}

string ThreeTerminals::getDrain()
{
	return NetList["drain"];
}

string ThreeTerminals::getGate()
{
	return NetList["gate"];
}

void ThreeTerminals::printDev()
{
	Device::printDev(); 
	cout << "Source: " << getSrc()
		 << ", Drain: " << getDrain() 
		 << ", Gate: "<< getGate() <<'\n'; 
}
