

#ifndef INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H
#define INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <utility>
#include <string>
#include "../Flight/Flight.h"

using namespace std;

struct MaintenanceUpdate{

};

class Airport {

private: // 7 points of study from Chapter 5
    // Point 1: List
    list<string> listOfFlights;

    // Point 2: Linked List
    list<MaintenanceUpdate> dynamicMaintenanceUpdates;

    // Point 3: Pair
    pair<string, string> flightPair{"A17", "MH137"};

    // Point 4: Map
    map<int, string> flightDetailsMap;

    // Point 5: Queue (Arriving Flights)
    queue<Flight> arrivingFlights;

    // Point 6: Deque (Departing Flights)
    deque<Flight> departingFlights;

    // Point 7: Set
    set<string> uniqueDestinations;


private: // Variables
    string gate;
    int numberOfGates;
    vector<Flight*> flights;

public: // Methods

};


#endif //INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H
