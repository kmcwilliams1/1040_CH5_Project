#include "Flight.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <limits>

using namespace std;


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
        crew.pilotList.push_back(newPilot);
    } else if (type == Crew::EmployeeType::Attendant) {
        auto *newAttendant = new Attendant();
        crew.attendantList.push_back(newAttendant);
    }

    listOfCrewMembers.push_back(crew);

    cout << "Employee with ID " << employeeID << " added to the crew." << endl;
}

void Flight::addCrewMember(const string &name, Crew::EmployeeType type) {


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
        MaintenanceRequests newRequest;
        cout << "Describe your maintenance request: ";
        getline(cin, request);
        cout << endl;
        newRequest.descriptionOfRequests.push_back(request);
        newRequest.requestID = rand() % 10000;
        cout << "Add another request? (Y/N) ";
        cin >> option;
        cout << endl;
        maintenanceRequests.push_back(newRequest);

        if (option == 'n' || option == 'N')break;
    }


}

void Flight::pushMaintenanceRequest(int id, const vector<string> &requestDescriptions) {
    MaintenanceRequests newRequest;
    newRequest.requestID = id;
    newRequest.descriptionOfRequests = requestDescriptions;

    maintenanceRequests.push_back(newRequest);
}

void Flight::removeMaintenanceRequest(int requestID) {
    maintenanceRequests.erase(
            remove_if(maintenanceRequests.begin(), maintenanceRequests.end(),
                      [requestID](const MaintenanceRequests &request) { return request.requestID == requestID; }),
            maintenanceRequests.end());
}

list<MaintenanceRequests> Flight::getMaintenanceRequests() const {
    list<MaintenanceRequests> copyMaintenanceRequests = maintenanceRequests;

    for (const auto &request: copyMaintenanceRequests) {
        for (const auto &description: request.descriptionOfRequests) {
            cout << "Request ID: " << request.requestID << ", Description: " << description << endl;
        }
    }

    // Return the copied list (not necessary for printing but consistent with your function signature)
    return copyMaintenanceRequests;
}


void Flight::clearMaintenanceRequests() {
    maintenanceRequests.clear();
}


// Point 3: Pair
void Flight::setDepartureAndArrivalCities(const string &departureCity, const string &arrivalCity) {
    departureAndArrivalCities.emplace_back(departureCity, arrivalCity);
}

vector<pair<string, string>> Flight::getDepartureAndArrivalCities() const {
    vector<pair<string, string>> cities;

    cities.reserve(departureAndArrivalCities.size());
    for (const auto &currentPair: departureAndArrivalCities) {
        cities.push_back(currentPair);
    }

    for (const auto &cityPair : cities) {
        cout << "Departure City: " << cityPair.first << "\n   Arrival City: " << cityPair.second << endl;
    }

    return cities;
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

// Point 7: Set
void Flight::addDestinationToSet(const string &destination) {
    uniqueDestinations.insert(destination);
}

void Flight::removeDestinationFromSet(const string &destination) {
    uniqueDestinations.erase(destination);
}

set<string> Flight::getUniqueDestinations() const {
    set<string> destinations;

    for (const auto& dest : uniqueDestinations) {
        cout << "Destination: " << dest << endl;
        destinations.insert(dest);
    }

    return destinations;
}
string Flight::getDepartureTime() const {
    struct tm *timeInfo;
    timeInfo = localtime(&departureTime);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    return string(buffer);
}

void Flight::setDepartureTime(const string &theTime) {

    if (!theTime.empty()) {
        departureTime = stoi(theTime);
    }
    if (theTime.empty()) {

        struct tm timeInfo{};
        time_t userTime;
        int month, day, hour, minute;
        char inputChar;


        cout << "Creating a new departure time..." << endl;

        cout << "Is it this month (Y/N): ";
        cin >> inputChar;

        while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> inputChar;
        }

        if (inputChar == 'N' || inputChar == 'n') {
            cout << "Enter month (1-12): ";
            cin >> month;

            while (month < 1 || month > 12) {
                cout << "Invalid input. Please enter a month between 1 and 12: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> month;
            }
        }

        cout << "Enter Day: ";
        cin >> day;

        while (day < 1 || day > 31) {
            cout << "Invalid input. Please enter a day between 1 and 31: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> day;
        }

        cout << "Pickup Hour (0-23): ";
        cin >> hour;

        while (hour < 0 || hour > 23) {
            cout << "Invalid input. Please enter an hour between 0 and 23: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> hour;
        }

        cout << "Pickup Minute (0-59): ";
        cin >> minute;

        while (minute < 0 || minute > 59) {
            cout << "Invalid input. Please enter a minute between 0 and 59: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> minute;
        }

        cout << endl;

        int hours, minutes;
        cout << "Enter the duration of the flight:" << endl;
        cout << "Hours: ";
        cin >> hours;
        cout << "Minutes: ";
        cin >> minutes;

        // Calculate the arrival time
        arrivalTime = departureTime + (hours * 3600) + (minutes * 60);
        setArrivalTime(arrivalTime);

        time_t now;
        time(&now);
        timeInfo = *localtime(&now);

        /* Previous months are 'next year', so add +1 to the year */
        if (inputChar == 'N' || inputChar == 'n') {
            if (month < timeInfo.tm_mon + 1) {
                timeInfo.tm_year++;
            }
            timeInfo.tm_mon = month - 1;
        }

        timeInfo.tm_mday = day;
        timeInfo.tm_hour = hour;
        timeInfo.tm_min = minute;
        timeInfo.tm_sec = 0;
        timeInfo.tm_isdst = -1;

        userTime = mktime(&timeInfo);
        departureTime = userTime;
    }
}

string Flight::getArrivalTime() const {
    struct tm *timeInfo;
    timeInfo = localtime(&departureTime);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    return string(buffer);
}


void Flight::setArrivalTime(time_t &time) {
    arrivalTime = time;
}

void Flight::setCrewIDs(int crewID) {
    crewIDs.push_back(crewID);
}

vector<int> Flight::getCrewIDs() const {
    return crewIDs;
};


Flight::Flight() = default;

Flight::~Flight() = default;
