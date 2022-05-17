/**
 * @file ApplicationManager.h
 * @author Abdelaziz Salah Mohammed  (Abdelaziz132001@gmai,.com)
 * @brief This class should handle the program and interact with the user
 * and excute his commands
 * @version 0.1
 * @date 2022-05-15
 *
 *
 */
#pragma once
#include "Headers.h"
#include "API.h"
#include "Testing.h"
class ApplicationManager
{
private:
	/**
	 * @brief  object from the api to call the functions of the interface
	 *
	 */
	API api;

public:
	ApplicationManager();
	/**
	 * @brief Start function is the main loop of the program in which the user choose which
	 * function he want to be excuted
	 *
	 */
	void Start();
	/**
	 * @brief utility function used to print the main screen
	 *
	 */

	void Test(); 
	void PrintMainScreen();
	~ApplicationManager();
};