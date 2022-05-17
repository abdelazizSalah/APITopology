/**
 * @file Resistance.h
 * @author Abdelaziz Salah Mohammed (abdelaziz132001@gmail.com)
 * @brief header file for the Resistor device in which i define the type of that two terminal device as Resistor
 * @version 0.1
 * @date 2022-05-15
 *
 */
#pragma once
#include "Headers.h"
#include "TwoTerminals.h"

class Resistance : public TwoTerminals
{
public:
	/**
	 * @brief Construct a new Resistor object
	 *
	 * @param id
	 * @param mn which is the minimum value for the Resistor
	 * @param def which is the default value for the Resistor
	 * @param mx which is the max value for the Resistor
	 * @param NL which is the NetList of the Resistor
	 */

	Resistance(string id, float df, float mn, float mx, map<string, string> NL);

	// printing all the properties of the Resistor
	virtual void printDev();
};