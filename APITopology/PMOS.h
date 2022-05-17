/**
 * @file PMOS.h
 * @author Abdelaziz Salah Mohammed (abdelaziz132001@gmail.com)
 * @brief header file for the PMOS device in which i define the type of that three terminal device as PMOS
 * @version 0.1
 * @date 2022-05-15
 *
 */
#pragma once
#include "Headers.h"
#include "ThreeTerminals.h"

class PMOS : public ThreeTerminals
{
public:
	/**
	 * @brief Construct a new PMOS object
	 *
	 * @param id
	 * @param mn which is the minimum value for the PMOS
	 * @param def which is the default value for the PMOS
	 * @param mx which is the max value for the PMOS
	 * @param NL which is the NetList of the PMOS
	 */

	PMOS(string id, float def, float mn, float mx, map<string, string> NL);

	virtual void printDev();
};