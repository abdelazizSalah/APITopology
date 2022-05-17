/**
 * @file NMOS.h
 * @author Abdelaziz Salah Mohammed (abdelaziz132001@gmail.com)
 * @brief header file for the Nmos device in which i define the type of that three terminal device
 * @version 0.1
 * @date 2022-05-15
 *
 */
#pragma once
#include "Headers.h"
#include "ThreeTerminals.h"

class NMOS : public ThreeTerminals
{
public:
	/**
	 * @brief Construct a new NMOS object
	 *
	 * @param id
	 * @param mn which is the minimum value for the NMOS
	 * @param def which is the default value for the NMOS
	 * @param mx which is the max value for the NMOS
	 * @param NL which is the NetList of the NMOS
	 */
	NMOS(string id, float mn, float def, float mx, map<string, string> NL);

	/**
	 * @brief  printing the details of the NMOS
	 *
	 */
	virtual void printDev();
};
