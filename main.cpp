/***************************************************************************
* COMSC-210 | Lab 30 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/

/***********************************************************************************
* Logic Overview
* The project is to simulate the traffic flow at  three intersections with traffic lights. The cars will come from four
* different directions (North, South, West, and East). The number of cars coming from each directions will be read from
* a text file, each line representing one single car, denoted as one of the four directions. The key-value pair will be
* defined as follows: the key will represent a specific intersection, and the three lists (stored in an array) represent
* cars coming from three different directions.
*/

// Define a Vehicle struct
struct Vehicle
{
};

#include <array>
#include <list>
#include <map>
#include <iostream>
using namespace std;

map<string, array<list<Vehicle>, 3>> trafficMap {};

void initializeTrafficMap(map<string, array<list<Vehicle>, 3>>& trafficMap)
{
    vector<string> intersections {"A", "B", "C"};

    for (const auto& intersection : intersections)
        trafficMap[intersection] = array<list<Vehicle>, 3> {};
}