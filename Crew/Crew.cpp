
#include "Crew.h"
#include <random>

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

bool Crew::isDestinationInSet(const string &destination) const {
    return uniqueDestinations.find(destination) != uniqueDestinations.end();
}

void Crew::clearUniqueDestinations() {
    uniqueDestinations.clear();
}

pair<int, Flight *> Crew::getAssignedFlightPair() const {
    return pair<int, Flight *>();
}

void Crew::setAssignedFlightPair(int id, Flight *flight) {

}

