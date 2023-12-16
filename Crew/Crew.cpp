
#include "Crew.h"
#include <random>
#include <iostream>

//Random number generator
//    random_device rd;
//    mt19937 generator(rd());
//    uniform_int_distribution<int> distribution(1, 20000);
//    int random_number = distribution(generator);
//    employeeID = random_number;


void Crew::setName(const string &basicString) {

}

Crew::Crew() = default;

Crew::~Crew() = default;

void Crew::setEmployeeID(int newEmployeeID) {
    employeeID = newEmployeeID;
}

int Crew::getEmployeeID() const {
    return employeeID;
}

string Crew::getName() const {
    return name;
}

void Crew::addToUniqueDestinations(const string &destination) {
    uniqueDestinations.insert(destination);
}

void Crew::removeFromUniqueDestinations(const string &destination) {
    uniqueDestinations.erase(destination);
}

set<string> Crew::getUniqueDestinations() const {
return uniqueDestinations;
}

void Crew::printUniqueDestinations() const {
    cout << "Unique Destinations:\n";
    for (const auto &destination : uniqueDestinations) {
        cout << destination << endl;
    }
}

bool Crew::isDestinationInSet(const string &destination) const {
    return uniqueDestinations.find(destination) != uniqueDestinations.end();
}

void Crew::clearUniqueDestinations() {
    uniqueDestinations.clear();
}


void Crew::setAssignedFlightPair(int leg, Flight *flight) {
    auto newFlightPair = make_pair(leg, flight);
    assignedFlightPairs.push_back(newFlightPair);
}

pair<int, Flight *> Crew::getAssignedFlightPair() const {
    if (!assignedFlightPairs.empty()) {
        return assignedFlightPairs.front();
    } else {
        return make_pair(0, nullptr);
    }
}
void Crew::printAssignedFlightPair() const {
    for (const auto &flightPair : assignedFlightPairs) {
        cout << "ID: " << flightPair.first << ", Flight: " << flightPair.second << endl;
    }
}

list<FlightAssignments> Crew::getFlightAssignments() const {
    return flightAssignments;
}
void Crew::addFlightAssignment(int leg, const string &departureCity, const string &arrivalCity) {
    FlightAssignments assignment;
    assignment.flightLeg = leg;
    assignment.departureCity = departureCity;
    assignment.arrivalCity = arrivalCity;
    flightAssignments.push_back(assignment);
}


