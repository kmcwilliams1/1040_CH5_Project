
#ifndef INC_1040_CH5_PRACTICEPROJECT_CREW_H
#define INC_1040_CH5_PRACTICEPROJECT_CREW_H

#include <list>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>
using namespace std;


struct FlightAssignments {
    // Flight update details
};

class Crew {
private:// 7 points of study from Chapter 5
    // Point 1: List
    list<string> listOfAssignedFlights;

    // Point 2: Linked List
    list<FlightAssignments> flightAssignments;

    // Point 3: Pair
    pair<int, string> assignedFlightPair;

    // Point 4: Map
    map<int, string> assignedFlightsMap;

    // Point 5: Queue
    queue<FlightAssignments> updateQueue;

    // Point 6: Deque
    deque<FlightAssignments> updateDeque;

    // Point 7: Set
    set<string> uniqueDestinations;
public:
    enum class EmployeeType {
        Pilot,
        Attendant
    }
    string name;
};


#endif //INC_1040_CH5_PRACTICEPROJECT_CREW_H
