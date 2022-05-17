/**
 * @file ThreeTerminals.h
 * @author your name (you@domain.com)
 * @brief  I have created this class for further extensions such as adding any other 3 terminal devices
 * such as Cmos or BJTs not only NMOS and CMOS
 * it acts as an abstract class for NMOSes and PMOSes
 * @version 0.1
 * @date 2022-05-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "Headers.h"
#include "Device.h"

class ThreeTerminals : public Device
{
private:
	string Src;
	string Dest;
	string Gnd;

public:
	/**
	 * @brief Construct a new Three Terminals pointer
	 *
	 * @param id of the device
	 * @param def  default value of the device
	 * @param mn minimum value of the device
	 * @param mx maximum value
	 * @param NL Netlist of the Device
	 */
	ThreeTerminals(string id, float def, float mn, float mx, map<string, string> NL);

	// setters which sets the values of the
	void setSrc(string src);
	void setDrain(string drn);
	void setGate(string gt);

	// getters which get the value of data members
	string getSrc();
	string getDrain();
	string getGate();

	// printFunc
	virtual void printDev()= 0;
};