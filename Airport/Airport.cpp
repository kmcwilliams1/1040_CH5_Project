#include "Airport.h"
#include <algorithm>
#include <iostream>


void Airport::addFlightToList(const string &flightData) {
    size_t colonPos = flightData.find(':');
    if (colonPos != string::npos) {

        cout << "Reading FlightID: " << flightData << endl;
        string details = flightData.substr(colonPos + 1);

        Flight newFlight;
        newFlight.setFlightNumber(flightData);

        cout << "Hitting here " << details << endl;
        listOfFlights.push_back(newFlight);
    } else {
        // Handle invalid format or provide an error message
        cout << "Invalid flight data format: " << flightData << endl;
    }
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


// Point 3: Pair
void Airport::setFlightPair(const string &departureCity, const string &arrivalCity) {
    flightPair = make_pair(departureCity, arrivalCity);
}

pair<string, string> Airport::getFlightPair() const {
    return flightPair;
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


// Point 6: Deque (Departing Flights)
void Airport::pushDepartingFlightFront(const Flight &flight) {
    departingFlights.push_front(flight);
}

void Airport::pushDepartingFlightBack(const Flight &flight) {
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

void Airport::setFlights(const vector<Flight *> &newFlights) {
    flights = newFlights;
}

void Airport::setCallSign(string &basicString) {
    callSign = basicString;
}

string Airport::getCallSign() const {
    return callSign;
}

string Airport::getFlightIDs() const {
    for (string currentFlightID: flightIDs) {
        return currentFlightID;
    };
    return "";
};

void Airport::setFlightIDs(const string &newFlightID) {
    flightIDs.push_back(newFlightID);
}
