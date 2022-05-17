/**
 * @file API.h
 * @author Abdelaziz Salah Mohammed (Abdelaziz132001@Gmail.com)
 * @brief This is the API header file which contains the functions for the user to use
 * @version 0.1
 * @date 2022-05-15
 */
#include "Headers.h"
#include "Topology.h"
class API
{
private:
	map<string, Topology *> Topologies; // our memory
										//  topID , TopologyPtr
public:
	/**
	 * @brief Construct a new API object
	 *
	 */
	API();
	/**
	 * @brief Get the memory
	 *
	 * @return all topologies in the memory
	 */
	map<string, Topology *> getTopologies();

	// functions
	/**
	 * @brief Read the Json file and store it in our memory
	 *
	 * @param filePath
	 * @return true if the file has been reed successfully
	 * @return false otherwise
	 */
	bool ReadFromJson(string filePath);

	/**
	 * @brief used by the ReadFromJson function to create a new topology and store the data inside it
	 *
	 * @param DataObj
	 * @return true if the Topology has been intiated successfully
	 * @return false on failure
	 */
	bool InitiateTopology(Json::Value DataObj);

	/**
	 * @brief Called when the user want to Write certain topology in a json file
	 *
	 * @param TopID which represents which topology to be written
	 * @param outFileName which represents the name of the file to write into
	 * @return true if the file has been generated successfully
	 * @return false otherwise
	 */
	bool WriteToJson(string TopID, string outFileName);

	/**
	 * @brief Printing all the ids of all topologies  in the memory for the user
	 *
	 * @return false is there are no topologies in the memory
	 * @return true otherwise
	 */
	bool getTopologiesInMemoryQuere();

	/**
	 * @brief Delete certain topology from the memory
	 *
	 * @param TopID
	 * @return true if the topology has been deleted successfully
	 * @return false otherwise
	 */
	bool DeleteTopology(string TopID);

	/**
	 * @brief  get all the devices which are connected together in certain topology
	 *
	 * @param TopID  which represents the id of the topology from which we need to get its devices
	 * @return vector<Device *>  contains all the devices in certain topology
	 */
	vector<Device *> DevicesInTopology(string TopID);

	/**
	 * @brief look for the devices which are connected to certain node in certain topology
	 *
	 * @param TopID  which represents the id of the topology from which we need to get its devices
	 * @param NodeID which represents the id of the node we need to check
	 * @return vector<Device *>  contains all the devices which are connected to that node in the topology
	 */
	vector<Device *> NodeDevices(string TopID, string NodeID);

	/**
	 * @brief utility funtion to check whethere certain topology exists in the memory or not
	 *
	 * @param TopID  which represents the id of the topology from which we need to get its devices
	 * @return true if it exists
	 * @return false otherwise
	 */
	bool lookForTop(string TopID);

	/**
	 * @brief the following functions are similar to each other as all creates an object from that device, create Dev is the master function and
	 * the other three are slaves depending on the device we need to create we call each of them.
	 * I Use it when i am intiating a topology
	 *
	 * @param DataObj which is an object from the json library contains the data of that device
	 * @param idx represents the index of that device in the json file
	 * @return Device* which has been created
	 */
	Device *createDev(Json::Value DataObj, int idx);
	Device *createResistor(Json::Value DataObj, int idx);
	Device *createNMOS(Json::Value DataObj, int idx);
	Device *createPMOS(Json::Value DataObj, int idx);

	/**
	 * Destructor
	 * @brief Destroy the API object
	 *
	 */
	~API();
};