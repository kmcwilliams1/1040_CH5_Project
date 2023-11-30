#include "Flight.h"
#include <iostream>
#include <algorithm>

using namespace std;


void Flight::addFlightUpdate(const string &newDepartureTime, const string &newDepartureGate) {
    FlightUpdate update;
    update.flightID = this->flightNumber;
    update.newDepartureTime = newDepartureTime;
    update.newDepartureGate = newDepartureGate;

    dynamicFlightUpdates.push_back(update);
}


void Flight::addCrewMember(int employeeID, Crew::EmployeeType type) {
    // First, check if the employee is already in the crew list
    for (const auto &crew: listOfCrewMembers) {
        for (const auto &pilot: crew.pilotList) {
            if (pilot->getEmployeeID() == employeeID) {
                cout << "Employee with ID " << employeeID << " is already in the crew." << endl;
                return;
            }
        }

        // Check the attendant list
        for (const auto &attendant: crew.attendantList) {
            if (attendant->getEmployeeID() == employeeID) {
                cout << "Employee with ID " << employeeID << " is already in the crew." << endl;
                return;
            }
        }
    }

    // If not found, add the employee to the crew list
    CrewList crew;
    if (type == Crew::EmployeeType::Pilot) {
        auto *newPilot = new Pilot();
        newPilot->setEmployeeID();
        crew.pilotList.push_back(newPilot);
    } else if (type == Crew::EmployeeType::Attendant) {
        auto *newAttendant = new Attendant();
        newAttendant->setEmployeeID();
        crew.attendantList.push_back(newAttendant);
    }

    listOfCrewMembers.push_back(crew);

    cout << "Employee with ID " << employeeID << " added to the crew." << endl;
}

void Flight::addCrewMember(const string &name, Crew::EmployeeType type) {
    // Create a new instance of either Pilot or Attendant based on the type
    Crew *newCrewMember = nullptr;

    if (type == Crew::EmployeeType::Pilot) {
        newCrewMember = new Pilot();
    } else if (type == Crew::EmployeeType::Attendant) {
        newCrewMember = new Attendant();
    }

    // Set the name of the crew member
    newCrewMember->setName(name);

    // Add the crew member to the appropriate list
    CrewList crewList;
    if (type == Crew::EmployeeType::Pilot) {
        crewList.pilotList.push_back(dynamic_cast<Pilot *>(newCrewMember));
    } else if (type == Crew::EmployeeType::Attendant) {
        crewList.attendantList.push_back(dynamic_cast<Attendant *>(newCrewMember));
    }

    listOfCrewMembers.push_back(crewList);
}

void Flight::removeCrewMember(int employeeID) {
    for (auto &crewList: listOfCrewMembers) {
        // Remove the crew member with the given employeeID from both lists
        crewList.pilotList.erase(
                remove_if(crewList.pilotList.begin(), crewList.pilotList.end(),
                          [employeeID](const Pilot *pilot) {
                              return pilot->getEmployeeID() == employeeID;
                          }),
                crewList.pilotList.end());

        crewList.attendantList.erase(
                remove_if(crewList.attendantList.begin(), crewList.attendantList.end(),
                          [employeeID](const Attendant *attendant) {
                              return attendant->getEmployeeID() == employeeID;
                          }),
                crewList.attendantList.end());
    }
}

list<CrewList> Flight::getCrewMembers() const {
    return listOfCrewMembers;
}

bool Flight::isCrewMemberInList(int employeeID) const {
    for (const auto &crewList: listOfCrewMembers) {
        // Check if the crew member with the given employeeID is in either list
        if (any_of(crewList.pilotList.begin(), crewList.pilotList.end(),
                   [employeeID](const Pilot *pilot) { return pilot->getEmployeeID() == employeeID; }) ||
            any_of(crewList.attendantList.begin(), crewList.attendantList.end(),
                   [employeeID](const Attendant *attendant) { return attendant->getEmployeeID() == employeeID; })) {
            return true;
        }
    }

    return false;
}

void Flight::clearCrewMembers() {
    for (auto &crewList: listOfCrewMembers) {
        // Clear both lists
        crewList.pilotList.clear();
        crewList.attendantList.clear();
    }

    listOfCrewMembers.clear();
}

