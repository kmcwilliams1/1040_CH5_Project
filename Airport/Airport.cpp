#include "Airport.h"
#include <algorithm>

// airport.cpp

#include "Airport.h"
#include <algorithm>

void Airport::addFlightToList(const Flight &flight) {
    listOfFlights.push_back(flight);
}

void Airport::removeFlightFromList(const string &flightNumber) {
    listOfFlights.remove_if([flightNumber](const Flight &flight) {
        return flight.getFlightNumber() == flightNumber;
    });
}

list<Flight> Airport::getListOfFlights() const {
    return listOfFlights;
}

bool Airport::isFlightInList(const string &flightNumber) const {
    return any_of(listOfFlights.begin(), listOfFlights.end(), [flightNumber](const Flight &flight) {
        return flight.getFlightNumber() == flightNumber;
    });
}

void Airport::clearListOfFlights() {
    listOfFlights.clear();
}

// Point 2: Linked List
void Airport::addMaintenanceUpdate(const MaintenanceRequests &maintenanceUpdate) {
    dynamicMaintenanceUpdates.push_back(maintenanceUpdate);
}

void Airport::removeMaintenanceRequest(int requestID) {
    dynamicMaintenanceUpdates.remove_if([requestID](const MaintenanceRequests &request) {
        return true;
    });
}

list<MaintenanceRequests> Airport::getMaintenanceUpdates() const {
    return dynamicMaintenanceUpdates;
}

bool Airport::isMaintenanceRequestInList(int requestID) const {
    return any_of(dynamicMaintenanceUpdates.begin(), dynamicMaintenanceUpdates.end(),
                  [requestID](const MaintenanceRequests &request) {
                      return true;
                  });
}

void Airport::clearMaintenanceUpdates() {
    dynamicMaintenanceUpdates.clear();
}

// Point 3: Pair
void Airport::setFlightPair(const string &departureCity, const string &arrivalCity) {
    flightPair = make_pair(departureCity, arrivalCity);
}

pair<string, string> Airport::getFlightPair() const {
    return flightPair;
}

// Point 4: Map
void Airport::addFlightDetails(int flightID, const string &details) {
    flightDetailsMap[flightID] = details;
}

void Airport::removeFlightDetails(int flightID) {
    flightDetailsMap.erase(flightID);
}

string Airport::getFlightDetails(int flightID) const {
    auto it = flightDetailsMap.find(flightID);
    if (it != flightDetailsMap.end()) {
        return it->second;
    } else {
        // Return an empty string or handle the case when flightID is not found
        return "";
    }
}

bool Airport::isFlightDetailsInMap(int flightID) const {
    return flightDetailsMap.find(flightID) != flightDetailsMap.end();
}

void Airport::clearFlightDetailsMap() {
    flightDetailsMap.clear();
}

// Point 5: Queue (Arriving Flights)
void Airport::enqueueArrivingFlight(const Flight &flight) {
    arrivingFlights.push(flight);
}

void Airport::dequeueArrivingFlight() {
    if (!arrivingFlights.empty()) {
        arrivingFlights.pop();
    }
}

Flight Airport::frontArrivingFlight() const {
    if (!arrivingFlights.empty()) {
        return arrivingFlights.front();
    } else {
        // Return a default-constructed Flight or handle the case when the queue is empty
        return {};
    }
}

bool Airport::isArrivingFlightsEmpty() const {
    return arrivingFlights.empty();
}

void Airport::clearArrivingFlights() {
    while (!arrivingFlights.empty()) {
        arrivingFlights.pop();
    }
}

// airport.cpp

#include "Airport.h"

// Point 6: Deque (Departing Flights)
void Airport::pushDepartingFlightFront(const Flight& flight) {
    departingFlights.push_front(flight);
}

void Airport::pushDepartingFlightBack(const Flight& flight) {
    departingFlights.push_back(flight);
}

void Airport::popDepartingFlightFront() {
    if (!departingFlights.empty()) {
        departingFlights.pop_front();
    }
}

void Airport::popDepartingFlightBack() {
    if (!departingFlights.empty()) {
        departingFlights.pop_back();
    }
}

Flight Airport::frontDepartingFlight() const {
    if (!departingFlights.empty()) {
        return departingFlights.front();
    } else {
        // Return a default-constructed Flight or handle the case when the deque is empty
        return {};
    }
}

Flight Airport::backDepartingFlight() const {
    if (!departingFlights.empty()) {
        return departingFlights.back();
    } else {
        return {};
    }
}

bool Airport::isDepartingFlightsEmpty() const {
    return departingFlights.empty();
}

void Airport::clearDepartingFlights() {
    departingFlights.clear();
}

// Point 7: Set
void Airport::addToUniqueDestinations(const string& destination) {
    uniqueDestinations.insert(destination);
}

void Airport::removeFromUniqueDestinations(const string& destination) {
    uniqueDestinations.erase(destination);
}

set<string> Airport::getUniqueDestinations() const {
    return uniqueDestinations;
}

bool Airport::isDestinationInSet(const string& destination) const {
    return uniqueDestinations.find(destination) != uniqueDestinations.end();
}

void Airport::clearUniqueDestinations() {
    uniqueDestinations.clear();
}





//Accesssor Methods
string Airport::getAirportName() const {
    return airportName;
}

void Airport::setAirportName(string &newName) {
        airportName = newName;
}

string Airport::getGate() const {
    return gate;
}

void Airport::setGate(string &newGate) {
    gate = newGate;
}

int Airport::getNumberOfGates() const {
    return numberOfGates;
}

void Airport::setNumberOfGates(int newNumberOfGates) {
    numberOfGates = newNumberOfGates;
}

vector<Flight *> Airport::getFlights() const {
    return flights;
}

void Airport::setFlights(const vector<Flight*>& newFlights) {
    flights = newFlights;
}

void Airport::setCallSign(string &basicString) {
    callSign = basicString;
}

string Airport::getCallSign() const {
    return callSign;
}
