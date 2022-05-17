#pragma once
#include "API.h"

API::API()
{
}

map<string, Topology*> API::getTopologies()
{
	return Topologies; 
}

bool API::ReadFromJson(string filePath)
{
	try {
		unique_ptr<string> httpData(new string());
		ifstream file(filePath);
		if (!file.is_open())
			return false; 
		Json::Value jsonData;
		Json::Reader jsonReader;

		jsonReader.parse(file, jsonData);
		file.close(); 
		if (jsonData.size() != 0)
			return InitiateTopology(jsonData);
		else
			return false;
	}
	catch (string err)
	{
		cout << err;
	}
	return false;

}

bool API::InitiateTopology(Json::Value DataObj)
{
	string id = DataObj["id"].asString();
	vector<Device*> devs;
	for (int i = 0; i < DataObj.size(); i++)
	{
		auto it = createDev(DataObj,i);
		if (it != nullptr)
			devs.push_back(it);
	}

	if (devs.size() != 0)
	{
		Topologies[id] = new Topology(id, devs);
		return true;
	}
	return false;
}

bool API::WriteToJson(string TopID , string outFileName)
{
	// topology is not found
	if (!lookForTop(TopID)) return false; 

	ofstream outfile(outFileName); 
	unique_ptr<string> httpData(new string());
	Json::Value DataWrite;
	DataWrite["id"] = Topologies[TopID]->getID(); 
	vector<Device*> Devs = Topologies[TopID]->getDevs();
	int size = Devs.size(); 
	for (int i = 0; i < size; i++)
	{
		DataWrite["components"][i]["type"] = Devs[i]->getType();
		DataWrite["components"][i]["id"] = Devs[i]->getID();
		DataWrite["components"][i]["type"] = Devs[i]->getType();
		if (dynamic_cast<Resistance*> (Devs[i])) {
			DataWrite["components"][i]["resistance"]["default"] = Devs[i]->getDef();
			DataWrite["components"][i]["resistance"]["min"] = Devs[i]->getMin();
			DataWrite["components"][i]["resistance"]["max"] = Devs[i]->getMax(); 
			map<string, string> NL = Devs[i]->getNetList();
			DataWrite["components"][i]["netlist"]["t1"] = NL["t1"];
			DataWrite["components"][i]["netlist"]["t2"] = NL["t2"];
		}
		else if (dynamic_cast<PMOS*> (Devs[i]) || dynamic_cast<NMOS*> (Devs[i]))
		{
			DataWrite["components"][i]["m(l)"]["default"] = Devs[i]->getDef();
			DataWrite["components"][i]["m(l)"]["min"] = Devs[i]->getMin();
			DataWrite["components"][i]["m(l)"]["max"] = Devs[i]->getMax();
			map<string, string> NL = Devs[i]->getNetList();
			DataWrite["components"][i]["netlist"]["drain"] = NL["drain"];
			DataWrite["components"][i]["netlist"]["gate"] = NL["gate"];
			DataWrite["components"][i]["netlist"]["source"] = NL["source"];
		}
	}

	outfile << DataWrite; 
	outfile.close(); 
	return true;
}

bool API::getTopologiesInMemoryQuere()
{
	if (!Topologies.size()) return false;
	cout << "Topologies in Memory are: \n";
	for (auto it : Topologies)
		cout << "ID = "<< it.second->getID() << "\n";
	return true; 
}

bool API::DeleteTopology(string TopID)
{
	auto it = Topologies.find(TopID);
	if (it != Topologies.end()) // if exist remove it
	{
		Topologies.erase(it);
		return true;
	}
	return false;
}

vector<Device*> API::DevicesInTopology(string TopID)
{
	if (lookForTop(TopID))
		return Topologies[TopID]->getDevs();
	return vector<Device*>(); // empty list
}

vector<Device*> API::NodeDevices(string TopID, string NodeID)
{
	if (lookForTop(TopID))
		return Topologies[TopID]->getNodeDevices(NodeID);
	return vector<Device*>();
}

bool API::lookForTop(string TopID)
{
	auto it = Topologies.find(TopID);
	if (it != Topologies.end())
		return true;
	return false;
}

Device* API::createDev(Json::Value DataObj, int idx)
{
	string type = DataObj["components"][idx]["type"].asString(); 
	switch (type[0])
	{
	case 'n':
		return createNMOS(DataObj, idx);
	case 'p':
		return createPMOS(DataObj,idx);
	case 'r':
		return createResistor(DataObj, idx);
	}
	return nullptr;
}

Device* API::createResistor(Json::Value DataObj,int idx)
{
	map<string, string> NL;
	float min, max, def;
	string id = DataObj["components"][idx]["id"].asString();
	min = DataObj["components"][idx]["resistance"]["min"].asFloat();
	max = DataObj["components"][idx]["resistance"]["max"].asFloat();
	def = DataObj["components"][idx]["resistance"]["default"].asFloat();
	NL["t1"] = DataObj["components"][idx]["netlist"]["t1"].asString();
	NL["t2"] = DataObj["components"][idx]["netlist"]["t2"].asString();
	return new Resistance(id, def, min, max, NL);
}

Device* API::createNMOS(Json::Value DataObj, int idx)
{
	map<string, string> NL;
	float min, max, def;
	string id = DataObj["components"][idx]["id"].asString();
	min = DataObj["components"][idx]["m(l)"]["min"].asFloat();
	max = DataObj["components"][idx]["m(l)"]["max"].asFloat();
	def = DataObj["components"][idx]["m(l)"]["default"].asFloat();
	NL["drain"] = DataObj["components"][idx]["netlist"]["drain"].asString();
	NL["source"] = DataObj["components"][idx]["netlist"]["source"].asString();
	NL["gate"] = DataObj["components"][idx]["netlist"]["gate"].asString();
	return new NMOS(id, min, def, max, NL);
}

Device* API::createPMOS(Json::Value DataObj, int idx)
{
	map<string, string> NL;
	float min, max, def;
	string id = DataObj["components"][idx]["id"].asString();
	min = DataObj["components"][idx]["PMOS"]["min"].asFloat();
	max = DataObj["components"][idx]["PMOS"]["max"].asFloat();
	def = DataObj["components"][idx]["PMOS"]["default"].asFloat();
	NL["drain"] = DataObj["components"][idx]["netlist"]["drain"].asString();
	NL["source"] = DataObj["components"][idx]["netlist"]["source"].asString();
	NL["gate"] = DataObj["components"][idx]["netlist"]["gate"].asString();
	return new PMOS(id, min, def, max, NL);
}

API::~API()
{
	//terminating house keeping
	for (auto& it : Topologies)
		delete it.second;
}
