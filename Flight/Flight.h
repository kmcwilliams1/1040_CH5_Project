

#ifndef INC_1040_CH5_PRACTICEPROJECT_FLIGHT_H
#define INC_1040_CH5_PRACTICEPROJECT_FLIGHT_H

#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <utility>
#include <string>
#include "../Crew/Pilot/Pilot.h"
#include "../Crew/Attendant/Attendant.h"

using namespace std;

struct FlightUpdate {
    string flightID;
    string newDepartureTime;
    string newDepartureGate;
};

struct CrewList {
   vector<Pilot*> pilotList;
   vector<Attendant*> attendantList;
};


class Flight {
private:// 7 points of study from Chapter 5
    // Point 1: List
    list<CrewList> listOfCrewMembers;

    // Point 2: Linked List
    list<FlightUpdate> dynamicFlightUpdates;

    // Point 3: Pair
    pair<string, string> departureAndArrivalCities;

    // Point 4: Map
    map<int, string> flightDetailsMap;

    // Point 5: Queue (Arriving Flights)
    queue<Flight> checkInQueue;

    // Point 6: Deque (Departing Flights)
    deque<Flight> bookingDeque;

    // Point 7: Set
    set<string> uniqueDestinations;

private: // Variables
    string flightNumber;
    string gate;
    int passengerCount;
    int seatCount;
    bool isFueled;
    time_t departureTime;
    time_t landingTime;

public:// Methods

    // Point 1:  List
    void addCrewMember(const string& name, Crew::EmployeeType type);
    void removeCrewMember(int employeeID);
    list<CrewList> getCrewMembers() const;
    bool isCrewMemberInList(int employeeID) const;
    void clearCrewMembers();


    // Point 2: Linked List
    void addFlightUpdate(const string &newDepartureTime, const string &newDepartureGate);


    void addCrewMember(int employeeID, Crew::EmployeeType type);
};

#endif //INC_1040_CH5_PRACTICEPROJECT_FLIGHT_H
