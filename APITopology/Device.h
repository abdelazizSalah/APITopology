/**
 * @file Device.h
 * @author Abdelaziz Salah Mohammed (abdelaziz132001@gmail.com)
 * @brief This Class is Used as an abstract class for 2 other classes which are
 * Two Terminal Device Class and Three Terminal Device Class
 * in which i have implemented the common functions that will be in any general device
 * @version 0.1
 * @date 2022-05-15
 *
 */
#pragma once
#include "Headers.h"
class Device
{
	/**
	 * @brief protected to be accessible by the children classes
	 */
protected:
	// id of each device
	string id;

	// nodes which each device is connected to
	map<string, string> NetList;

	// values for each device
	float def, min, max;

	// type of that device
	string type; // will be used in the inherting classes
public:
	// default constructor
	Device();

	// intiating constructor
	Device(string ID, map<string, string> NL, float d, float mn, float mx);

	// setters used to set the values of each datamember
	void setID(string);
	void setNetList(map<string, string>);
	void setDefVal(float);
	void setMinVal(float);
	void setMaxVal(float);
	void setType(string);

	// getters
	map<string, string> getNetList();
	string getID();
	string getType();
	float getDef();
	float getMax();
	float getMin();

	/**
	 * @brief virtual function to be overridden by the inherting classes
	 * in which each device can print its properties and datamembers
	 *
	 */
	virtual void printDev() = 0;
};