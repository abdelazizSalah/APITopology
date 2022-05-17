#include "Testing.h"

Testing::Testing()
{
	api.ReadFromJson("topology.json");
}

void Testing::TestReadJson()
{
	if (api.lookForTop("top1")) // id of this json file
		cout << "the file has been read successfully\n";
	else
		cout << "Failure\n";
}

void Testing::TestWrite()
{
	api.WriteToJson("top1", "output.json");
	if (api.ReadFromJson("output.json"))
		cout << "the file has been written successfully\n";
	else
		cout << "failer\n";
}

void Testing::TestTopologiesInMemory()
{
	if (api.getTopologies().size())
	{
		for (auto it : api.getTopologies())
			if (it.second->getID() == "top1")
				cout << "topologies in memory succeeded\n";
			else
				cout << "Failed\n";
	}
	else
		cout << "Testing Topologies Failed\n";
}

void Testing::TestDeleteTopology()
{
	api.DeleteTopology("top1");
	if (!api.getTopologies().size())
		cout << "Deleted successfully\n";
	else
		cout << "Deleting Failed!\n";
}

void Testing::TestDevicesInTopologies()
{
	for (auto it : api.DevicesInTopology("top1"))
	{
		if (it->getType() == "resistor" || it->getType() == "nmos")
			continue;
		else
		{
			cout << "TestDevices Failed!\n";
			return;
		}
	}
	cout << "Testing Devices in Topologies Succeded\n";
}

void Testing::TestDevicesWithNodes()
{
	for (auto it : api.NodeDevices("top1", "n1"))
	{
		if (it->getType() != "resistor" && it->getType() != "nmos")
		{
			cout << "TestDevicesWithNodes Failed\n";
			return;
		}
	}
	cout << "Test Devices With Nodes Succeded\n";
}
