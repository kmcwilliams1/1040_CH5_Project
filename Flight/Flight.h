

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



struct MaintenanceRequests {
    vector<string> descriptionOfRequests;
    int requestID;
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
    list<MaintenanceRequests> maintenanceRequests;

    // Point 3: Pair
    vector<pair<string, string>> departureAndArrivalCities;

    // Point 4: Map
    map<int, string> flightDetailsMap;


    // Point 7: Set
    set<string> uniqueDestinations;

private: // Variables
    string flightNumber;
    string gate;
    int passengerCount{};
    int seatCount{};
    bool isFueled{};
    time_t departureTime{};
    time_t arrivalTime{};
    vector<int> crewIDs{};


public:// 7 points of study from Chapter 5 - Methods

    // Point 1:  List
    void addCrewMember(int employeeID, Crew::EmployeeType type);

    void removeCrewMember(int employeeID);

    list<CrewList> getCrewMembers() const;

    bool isCrewMemberInList(int employeeID) const;

    void clearCrewMembers();


    // Point 2: Linked List
    void addMaintenanceRequest();

    void removeMaintenanceRequest(int requestID);

    list<MaintenanceRequests> getMaintenanceRequests() const;

    void clearMaintenanceRequests();


    // Point 3: Pair
    void setDepartureAndArrivalCities(const string &departureCity, const string &arrivalCity);

    vector<pair<string, string>> getDepartureAndArrivalCities() const;


    // Point 4: Map
    void addFlightDetail(int detailID, const string &detailInfo);

    void removeFlightDetail(int detailID);

    map<int, string> getFlightDetails() const;


    // Point 7: Set
    void addDestinationToSet(const string &destination);

    void removeDestinationFromSet(const string &destination);

    set<string> getUniqueDestinations() const;


public:


    //Getter and Setter for crewIDs
    vector<int> getCrewIDs() const;

    void setCrewIDs(int crewID);

    //Getter and Setter for departureTime
    string getDepartureTime() const;

    void setDepartureTime(const string &time);

    //Getter and Setter for arrivalTime
    string getArrivalTime() const;

    void setArrivalTime(time_t &time);


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

    void addCrewMember(const string &name, Crew::EmployeeType type);

    void pushMaintenanceRequest(int id, const vector<string> &requestDescriptions);

    vector<pair<string, string>> printDepartureAndArrivalCities() const;
};

#endif //INC_1040_CH5_PRACTICEPROJECT_FLIGHT_H
