#include "Flight.h"
#include <iostream>

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
        newPilot->setEmployeeID(employeeID);
        crew.pilotList.push_back(newPilot);
    } else if (type == Crew::EmployeeType::Attendant) {
        auto *newAttendant = new Attendant();
        newAttendant->setEmployeeID(employeeID);
        crew.attendantList.push_back(newAttendant);
    }

    listOfCrewMembers.push_back(crew);

    cout << "Employee with ID " << employeeID << " added to the crew." << endl;
}
