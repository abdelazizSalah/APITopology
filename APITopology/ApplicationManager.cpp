#include "ApplicationManager.h"

ApplicationManager::ApplicationManager()
{

}

void ApplicationManager::Start()
{
	// items to be used 
	string filepath;
	string TopID;
	string NodeID;
	string type; 
	vector<Device*> Devs; 
	bool exit = false;
	while (1) {
		PrintMainScreen(); 
		int ans; cin >> ans;
		// to clear the screen 
 		system("CLS");
		switch (ans)
		{
		case 1:
			cout << "Enter the (.json) file path \n";
			cin >> filepath; 
			// check that the file is json 
			if (filepath.find(".json") == string::npos) {
				cout << "Wrong path!\n";
				break;
			}
			if (api.ReadFromJson(filepath))
				cout << "File has been read successfully\n";
			else
				cout << "an error has occurred during reading the JSON file \n";
			break;
		case 2:
			// writing into the Json File
			cout << "Enter the Topology ID you want to write: \n"; cin >> TopID; 
			cout << "Enter the output file name you want: (name).json  \n"; cin >> filepath; 
			if (api.WriteToJson(TopID, filepath))
				cout << "Topology has been written successfully!\n";
			else
				cout << "An Error has occured during writing\n";
			break;
		case 3:
			if (!api.getTopologiesInMemoryQuere())
				cout << "Memory is Empty!\n"; 
			break;
		case 4:
			cout << "Enter Topology ID: "; cin >> TopID;
			if (api.DeleteTopology(TopID))
				cout << "Topology has been deleted\n";
			else
				cout << "No such Topology exists\n";
			break;
		case 5:
			cout << "Enter Topology ID: "; cin >> TopID;
			Devs =  api.DevicesInTopology(TopID); 
			if (Devs.size())
				for (auto it : Devs)
				{
					type = 	it->getType();
					switch (type[0]) {
					case 'n':
						dynamic_cast<NMOS*>(it)->printDev();
						break;
					case 'p':
						dynamic_cast<PMOS*>(it)->printDev();
						break;
					case 'r':
						dynamic_cast<Resistance*>(it)->printDev();
						break;
					}
				}
			else
				cout << "There is no Devices in this Topology\n";
			break;
		case 6:
			cout << "Enter Topology ID: "; cin >> TopID;
			cout << "Enter The Node ID: "; cin >> NodeID; 
			Devs = api.NodeDevices(TopID, NodeID); 
			if (Devs.size())
				for (auto it : Devs)
					cout << "ID: " << it->getID() << endl;
			else
				cout << "There is no Devices connected to this node\n"; 
			break;
		case 7:
			Test(); 
			break;
		case 8:
			exit = true; 
			break; 
		default:
			//Clearing the input buffer to avoid the bad input case such as inserting character instead on integer
			cin.clear();
			if (cin) {
				cin.ignore(std::cin.rdbuf()->in_avail()); // ignore what is buffered
			}
			cout << "Wrong Input!\n";
			break;
		}
		if (exit)
			break; 
	}

	cout << "Exited Normally\n"; 
}

void ApplicationManager::Test()
{
	Testing Ts; 
	Ts.TestReadJson();
	Ts.TestWrite();
	Ts.TestTopologiesInMemory();
	Ts.TestDevicesInTopologies();
	Ts.TestDevicesWithNodes();
	Ts.TestDeleteTopology();
}

void ApplicationManager::PrintMainScreen()
{
	cout << "Please Choose number from 1-8:\n";
	cout << "1- Read From Json\n";
	cout << "2- Write to Json\n";
	cout << "3- Check Topologies in memory\n";
	cout << "4- Delete Topology\n";
	cout << "5- Check Devices in certain topology\n";
	cout << "6- Check devices connected to certain node\n";
	cout << "7- Testing all functionalities\n";
	cout << "8- Exit\n";
}

ApplicationManager::~ApplicationManager()
{
}
