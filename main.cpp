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
    int id;
    int speed;
    int position;
};

#include <array>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void simulateStep(map<string, array<list<Vehicle>, 3>>& trafficMap);
void initializeTrafficMap(map<string, array<list<Vehicle>, 3>>& trafficMap);

int main()
{
    map<string, array<list<Vehicle>, 3>> trafficMap {};
    initializeTrafficMap(trafficMap);

    simulateStep(trafficMap);
    cout << "-----------------------------------\n";

    for (int step = 0; step < 25; step++)
    {
        cout << "Simulation Step: " << step << "\n";

        for (const auto& [intersection, lanes] : trafficMap)
        {
            cout << "Intersection: " << intersection << ":\n";
            for (int i = 0; i < lanes.size(); i++)
            {
                cout << "\tLane " << i << ": ";
                for (const auto& vehicle : lanes[i])
                {
                    cout << "[" << vehicle.id << ": pos " << vehicle.position << "] ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}

void initializeTrafficMap(map<string, array<list<Vehicle>, 3>>& trafficMap)
{
    srand(time(0));

    vector<string> intersections {"A", "B", "C"};

    for (const auto& intersection : intersections)
        trafficMap[intersection] = array<list<Vehicle>, 3> {};

    ifstream fin("traffic.txt");

    for (int i = 0; i < 34; i++)
    {
        Vehicle aVehicle;
        if (fin >> aVehicle.id)
        {
            fin >> aVehicle.speed;
            fin >> aVehicle.position;
        }

        trafficMap[ intersections[ rand() % 3 ] ][ rand() % 3 ].emplace_back(aVehicle);
    }

    fin.close();
}

void simulateStep(map<string, array<list<Vehicle>, 3>>& trafficMap)
{
    for (auto& [intersection, lanes] : trafficMap)
    {
        for (auto& lane : lanes)
        {
            for (auto it = lane.begin(); it != lane.end(); )
            {
                it->position += it->speed;

                if (it->position > 300)
                    it = lane.erase(it);
                else
                    it++;
            }
        }
    }
}