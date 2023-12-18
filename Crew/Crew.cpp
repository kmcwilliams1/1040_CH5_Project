
#include "Crew.h"
#include <random>
#include <iostream>
#include "../main/Collection.h"

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

void Crew::printInfo() {

}

void Crew::updateCrew() {

}

list<Crew *> Crew::getListOfCrew() const {
    return listOfCrew;
}

void Crew::manageCrew(Collection *collection) {

    string str;
    cout << "Which crew would you like to examine? " << endl;
    cin >> str;
    for (char &c : str) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }

    Crew *tempCrew = nullptr;

    for (auto *currentCrew : getListOfCrew()) {
        if (currentCrew->getName() == str) {
            tempCrew = currentCrew;
            break;
        }
    }

    if (tempCrew) {
        cout << "What would you like to do to this crew?" << endl;
        cout << "View in detail:      A" << endl;
        cout << "Edit this crew:      B" << endl;
        cout << "Delete this crew:    C" << endl;
        char option;
        cin >> option;

        switch (option) {
            case 'A':
            case 'a': // view crew
                tempCrew->printInfo();
                break;
            case 'B':
            case 'b': // edit crew
                tempCrew->updateCrew();
                break;
            case 'C':
            case 'c': // delete crew
                collection->deleteCrew(tempCrew);
                break;
            default:
                cout << "Unknown option. Please try again." << endl;
        }
    } else {
        cout << "Crew not found." << endl;
    }
}
