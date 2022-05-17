/**
 * @file Testing.h
 * @author Abdelaziz Salah Mohammed (abdelaziz132001@gmail.com)
 * @brief  this class is used to automatically test the functionalities of the API
 * @version 0.1
 * @date 2022-05-16
 *
 */
#pragma once
#include "Headers.h"
#include "ApplicationManager.h"
class Testing
{
private:
	API api;

public:
	/**
	 * @brief Construct a new Testing object
	 *  in which i read a json file on which i apply all the functionalities
	 */
	Testing();
	// test Reading
	void TestReadJson();
	// test Writing into Json File
	void TestWrite();
	// test to check for the Topologies in the memory
	void TestTopologiesInMemory();
	// test to delete certain topology
	void TestDeleteTopology();
	// test to detect devices in certian device
	void TestDevicesInTopologies();
	// test to detect devices connected at certain node
	void TestDevicesWithNodes();
};