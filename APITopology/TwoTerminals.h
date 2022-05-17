/**
 * @file TwoTerminals.h
 * @author Abdelaziz Salah Mohammed (abdelaziz132001@gmail.com)
 * @brief  I have created this class for further extensions such as adding any other 2 terminal devices
 * such as leds, capacitors or inductors
 * it acts as an abstract class for resistor
 * @version 0.1
 * @date 2022-05-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
// i have created this class for further extensions for any two terminal devices such as led or capacitors or something like that
// not only the resistance
#include "Headers.h"
#include "Device.h"
class TwoTerminals : public Device
{
private:
	string T1;
	string T2;

public:
	// constructor
	TwoTerminals(string id, float mn, float mx, float df, map<string, string> NL);

	// setters
	void setT1(string t1);
	void setT2(string t2);

	// getters
	string getT1();
	string getT2();

	// dev printer
	virtual void printDev() = 0;
};