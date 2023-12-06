#include "Flight.h"
#include <iostream>
#include <algorithm>

using namespace std;


void Flight::addFlightUpdate(const string &newDepartureTime, const string &newDepartureGate) {
    FlightUpdate update;
    update.flightNumber = this->flightNumber;
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
    if (newCrewMember != nullptr) newCrewMember->setName(name);

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

        // For Pilots
        for (auto it = crewList.pilotList.begin(); it != crewList.pilotList.end();) {
            if ((*it)->getEmployeeID() == employeeID) {
                it = crewList.pilotList.erase(it);
            } else {
                ++it;
            }
        }

        // For Attendants
        for (auto it = crewList.attendantList.begin(); it != crewList.attendantList.end();) {
            if ((*it)->getEmployeeID() == employeeID) {
                it = crewList.attendantList.erase(it);
            } else {
                ++it;
            }
        }

    }
}


list<CrewList> Flight::getCrewMembers() const {
    return listOfCrewMembers;
}

bool Flight::isCrewMemberInList(int employeeID) const {

    for (const auto &crewList: listOfCrewMembers) {
        for (const auto *pilot: crewList.pilotList) {
            if (pilot->getEmployeeID() == employeeID) {
                return true;
            }
        }

        for (const auto *attendant: crewList.attendantList) {
            if (attendant->getEmployeeID() == employeeID) {
                return true;
            }
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


void Flight::addMaintenanceRequest() {

    char option = 'y';
    string request;

    while (option != 'n' || option != 'N') {
        cout << "Describe your maintenance request: ";
        getline(cin, request);
        cout << endl;

        //TODO: fix
        //descriptionOfRequests.push_back(request);




        cout << "Add another request? (Y/N) ";
        cin >> option;
        cout << endl;
        if (option == 'n' || option == 'N')break;
    }


   // maintenanceRequests.push_back(request);
}

void Flight::removeMaintenanceRequest(int requestID) {
    maintenanceRequests.erase(
            remove_if(maintenanceRequests.begin(), maintenanceRequests.end(),
                      [requestID](const MaintenanceRequests &request) { return request.requestID == requestID; }),
            maintenanceRequests.end());
}

list<MaintenanceRequests> Flight::getMaintenanceRequests() const {
    return maintenanceRequests;
}

bool Flight::isMaintenanceRequestInList(int requestID) const {
    return any_of(maintenanceRequests.begin(), maintenanceRequests.end(),
                  [requestID](const MaintenanceRequests &request) { return request.requestID == requestID; });
}

void Flight::clearMaintenanceRequests() {
    maintenanceRequests.clear();
}


// Point 3: Pair
void Flight::setDepartureAndArrivalCities(const string &departureCity, const string &arrivalCity) {
    departureAndArrivalCities.emplace_back(departureCity, arrivalCity);
}

vector<pair<string, string>> Flight::getDepartureAndArrivalCities() const {
    return departureAndArrivalCities;
}

// Point 4: Map
void Flight::addFlightDetail(int detailID, const string &detailInfo) {
    flightDetailsMap.insert({detailID, detailInfo});
}

void Flight::removeFlightDetail(int detailID) {
    flightDetailsMap.erase(detailID);
}

map<int, string> Flight::getFlightDetails() const {
    return flightDetailsMap;
}

// Point 5: Queue (Arriving Flights)
void Flight::enqueueArrivingFlight(const Flight &arrivingFlight) {
    checkInQueue.push(arrivingFlight);
}

Flight Flight::dequeueArrivingFlight() {
    if (!checkInQueue.empty()) {
        Flight frontFlight = checkInQueue.front();
        checkInQueue.pop();
        return frontFlight;
    } else {
        // Return an empty flight if the queue is empty
        return {};
    }
}

// Point 6: Deque (Departing Flights)
void Flight::enqueueDepartingFlight(const Flight &departingFlight) {
    bookingDeque.push_back(departingFlight);
}

Flight Flight::dequeueDepartingFlight() {
    if (!bookingDeque.empty()) {
        Flight backFlight = bookingDeque.back();
        bookingDeque.pop_back();
        return backFlight;
    } else {
        // Return an empty flight if the deque is empty
        return {};
    }
}

// Point 7: Set
void Flight::addDestinationToSet(const string &destination) {
    uniqueDestinations.insert(destination);
}

void Flight::removeDestinationFromSet(const string &destination) {
    uniqueDestinations.erase(destination);
}

set<string> Flight::getUniqueDestinations() const {
    return uniqueDestinations;
}

Flight::Flight() = default;

Flight::~Flight() = default;
