

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
    string flightNumber;
    string newDepartureTime;
    string newDepartureGate;
};

struct MaintenanceRequests {
    vector<string> descriptionOfRequests;
    int requestID;
    string flightNumber;
};

struct CrewList {
    vector<Pilot *> pilotList;
    vector<Attendant *> attendantList;
};


class Flight {
public:
    Flight();

    ~Flight();

private:// 7 points of study from Chapter 5
    // Point 1: List
    list<CrewList> listOfCrewMembers;

    // Point 2: Linked List
    list<FlightUpdate> dynamicFlightUpdates;
    // Point 2: Linked List
    list<MaintenanceRequests> maintenanceRequests;

    // Point 3: Pair
    vector<pair<string, string>> departureAndArrivalCities;

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
    int passengerCount{};
    int seatCount{};
    bool isFueled{};
    time_t departureTime{};
    time_t landingTime{};


public:// 7 points of study from Chapter 5 - Methods

    // Point 1:  List
    void addCrewMember(const string &name, Crew::EmployeeType type);

    void removeCrewMember(int employeeID);

    list<CrewList> getCrewMembers() const;

    bool isCrewMemberInList(int employeeID) const;

    void clearCrewMembers();


    // Point 2: Linked List
    void addFlightUpdate(const string &newDepartureTime, const string &newDepartureGate);

    void addMaintenanceRequest();

    void removeMaintenanceRequest(int requestID);

    list<MaintenanceRequests> getMaintenanceRequests() const;

    bool isMaintenanceRequestInList(int requestID) const;

    void clearMaintenanceRequests();


    // Point 3: Pair
    void setDepartureAndArrivalCities(const string &departureCity, const string &arrivalCity);

    vector<pair<string, string>> getDepartureAndArrivalCities() const;


    // Point 4: Map
    void addFlightDetail(int detailID, const string &detailInfo);

    void removeFlightDetail(int detailID);

    map<int, string> getFlightDetails() const;


    // Point 5: Queue (Arriving Flights)
    void enqueueArrivingFlight(const Flight &arrivingFlight);

    Flight dequeueArrivingFlight();


    // Point 6: Deque (Departing Flights)
    void enqueueDepartingFlight(const Flight &departingFlight);

    Flight dequeueDepartingFlight();


    // Point 7: Set
    void addDestinationToSet(const string &destination);

    void removeDestinationFromSet(const string &destination);

    set<string> getUniqueDestinations() const;


public:
    void addCrewMember(int employeeID, Crew::EmployeeType type);

    // Getter and Setter for flightNumber
    const string &getFlightNumber() const {
        return flightNumber;
    }

    void setFlightNumber(const string &newFlightNumber) {
        flightNumber = newFlightNumber;
    }

    // Getter and Setter for gate
    const string &getGate() const {
        return gate;
    }

    void setGate(const string &newGate) {
        gate = newGate;
    }

    // Getter and Setter for passengerCount
    int getPassengerCount() const {
        return passengerCount;
    }

    void setPassengerCount(int newPassengerCount) {
        passengerCount = newPassengerCount;
    }

    // Getter and Setter for seatCount
    int getSeatCount() const {
        return seatCount;
    }

    void setSeatCount(int newSeatCount) {
        seatCount = newSeatCount;
    }

    // Getter and Setter for isFueled
    bool getIsFueled() const {
        return isFueled;
    }

    void setIsFueled(bool newIsFueled) {
        isFueled = newIsFueled;
    }


};

#endif //INC_1040_CH5_PRACTICEPROJECT_FLIGHT_H
