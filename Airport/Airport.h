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
#include "../main/Collection.h"

using namespace std;
class Collection;
class Airport {
private:
    // Point 1: List
    list<Flight *> listOfFlights;

    // Point 5: Queue (Arriving Flights)
    queue<Flight *> arrivingFlights;

    // Point 6: Deque (Departing Flights)
    deque<Flight *> departingFlights;


private:
    // Additional Variables
    string airportName;
    string gate;
    string callSign;
    int numberOfGates;

public: //7 points of study methods

    void printInfo() const;

    // Point 1: List
    void addFlightToList(Collection *collection);
    void addFlightToList(Flight *flight); //for reading from file
    void removeFlightFromList(const string &flightNumber);

    list<Flight *> getListOfFlights() const;

    bool isFlightInList(const string &flightNumber) const;



    // Point 5: Queue (Arriving Flights)
    void enqueueArrivingFlight(Flight *flight);

    void dequeueArrivingFlight();

    Flight frontArrivingFlight() const;

    bool isArrivingFlightsEmpty() const;

    void clearArrivingFlights();

    // Point 6: Deque (Departing Flights)
    void pushDepartingFlightFront(Flight *flight);

    void pushDepartingFlightBack(Flight *flight);

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

    list<Flight *> getFlightsInvolvingThisAirport() const;

    string getCallSign() const;

    void setCallSign(const string &basicString);

    void clearListOfFlights();

    void manageFlights(Collection *collection) const;

    void setAirport();

};

#endif //INC_1040_CH5_PRACTICEPROJECT_AIRPORT_H
