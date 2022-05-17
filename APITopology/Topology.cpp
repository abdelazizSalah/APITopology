#pragma once
#include "Topology.h"

Topology::Topology(string id)
{
    this->ID = id;
}

Topology::Topology(string id, vector<Device*> DV)
{
    ID = id; 
    Devs = DV; 
}

void Topology::setID(string id)
{
    ID = id; 
}

void Topology::setDevs(vector<Device*> DV)
{
    Devs = DV;
}

string Topology::getID()
{
    return ID;
}

vector<Device*> Topology::getDevs()
{
    return Devs;
}

vector<Device*> Topology::getNodeDevices(string nodeID)
{
    vector<Device*> ConnectedDevs; 
    for (Device* dev : Devs)
    {
        map<string,string> list = dev->getNetList(); 
        for (auto node : list)
        {
            if (node.second == nodeID)
            {
                ConnectedDevs.push_back(dev); 
                break; 
            }
        }
    }
    return ConnectedDevs;
}

void Topology::PrintTopology()
{
    string type; 
    cout << "ID = " << ID; 
    if (Devs.size())
        for (auto it : Devs)
        {
            type = it->getType();
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
}
