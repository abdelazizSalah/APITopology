/**
 * @file Topology.h
 * @author Abdelaziz Salah Mohammed (abdelaziz132001@gmail.com)
 * @brief this class is used to create topologies and connect devices with each others
 * @version 0.1
 * @date 2022-05-15
 *
 *
 */
#pragma once
#include "Headers.h"
#include "NMOS.h"
#include "PMOS.h"
#include "Resistance.h"
class Topology
{
private:
	/**
	 * @brief vector to store the devices in each topology
	 *
	 */
	vector<Device *> Devs;

	// ID which identifies each topology
	string ID;

public:
	// constructors
	Topology(string id);
	Topology(string id, vector<Device *> DV);

	// setters
	void setID(string id);
	void setDevs(vector<Device *> DV);

	// getters
	string getID();

	/**
	 * @brief Get the the List of devices in the topology
	 *
	 * @return vector<Device *>
	 */
	vector<Device *> getDevs();

	// returns all components which are connected with certain node
	vector<Device *> getNodeDevices(string nodeID);

	// print all devices in the topology
	void PrintTopology();
};