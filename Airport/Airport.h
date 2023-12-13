#ifndef INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H
#define INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H

#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <utility>
#include <vector>
#include "../Flight/Flight.h"

using namespace std;

class Airport {
private:
    // Point 1: List
    list<Flight> listOfFlights;

    // Point 3: Pair
    pair<string, string> flightPair;

    // Point 5: Queue (Arriving Flights)
    queue<Flight> arrivingFlights;

    // Point 6: Deque (Departing Flights)
    deque<Flight> departingFlights;


private:
    // Additional Variables
    string airportName;
    string gate;
    string callSign;
    int numberOfGates;
    vector<Flight *> flights;
    vector<string> flightIDs;

public: //7 points of study methods

    // Point 1: List
    void addFlightToList(const string &flightData);

    void removeFlightFromList(const string &flightNumber);

    list<Flight> getListOfFlights() const;

    bool isFlightInList(const string &flightNumber) const;


    // Point 3: Pair
    void setFlightPair(const string &departureCity, const string &arrivalCity);

    pair<string, string> getFlightPair() const;


    // Point 5: Queue (Arriving Flights)
    void enqueueArrivingFlight(const Flight &flight);

    void dequeueArrivingFlight();

    Flight frontArrivingFlight() const;

    bool isArrivingFlightsEmpty() const;

    void clearArrivingFlights();

    // Point 6: Deque (Departing Flights)
    void pushDepartingFlightFront(const Flight &flight);

    void pushDepartingFlightBack(const Flight &flight);

    void popDepartingFlightFront();

    void popDepartingFlightBack();

    Flight frontDepartingFlight() const;

    Flight backDepartingFlight() const;

    bool isDepartingFlightsEmpty() const;

    void clearDepartingFlights();


public: //Accessor Mehthods
    string getAirportName() const;

    void setAirportName(string &newName);

    string getGate() const;

    void setGate(string &newGate);

    int getNumberOfGates() const;

    void setNumberOfGates(int newNumberOfGates);

    vector<Flight *> getFlights() const;

    void setFlights(const vector<Flight *> &newFlights);

    string getFlightIDs() const;

    void setFlightIDs(const string &flightIDs);

    string getCallSign() const;

    void setCallSign(string &basicString);

    void clearListOfFlights();
};

#endif //INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H
//INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H
