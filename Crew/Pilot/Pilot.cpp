

#include <sstream>
#include <iostream>
#include "Pilot.h"
#include "../../main/Collection.h"

Pilot::Pilot() = default;

Pilot::~Pilot() = default;

void Pilot::readPilotProperties(const string &basicString, Collection *collection) {

    istringstream dataStream(basicString);
    string temp;
    int counter;

    dataStream.clear();
    dataStream.seekg(0);


    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        name = temp;
    }
    getline(dataStream, temp, ',');
    {
        employeeID = stoi(temp);
    }



    //AssignedFlightPair
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        Flight *currentFlight = nullptr;

        string leg, flightNumber;
        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);

        if (commaPos != string::npos) {
            leg = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
        } else {
            leg = temp.substr(openParenPos + 1, temp.length() - openParenPos - 1);
        }

        flightNumber = temp.substr(commaPos + 1, temp.length() - commaPos - 1);


        for (auto &flight: collection->flights) {
            if (flight->getFlightNumber() == flightNumber) {
                currentFlight = flight;
                break;
            }
        }

        if (currentFlight) {
            setAssignedFlightPair(stoi(leg), currentFlight);
        } else {
            cerr << "No matching flight found for leg " << leg << " with flight number " << flightNumber << endl;
        }
    }

    cout << "Well i got it done!" << endl;


    //FlightAssignments
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');


        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);
        string arrivalCity, departureCity;
        if (openParenPos != string::npos && commaPos != string::npos) {
            arrivalCity = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
            departureCity = temp.substr(commaPos + 1, temp.length() - commaPos - 1);
            addFlightAssignment(i + 1, departureCity, arrivalCity);


        } else {
            cerr << "Invalid format for city information in line: " << temp << endl;
        }


    }





    //subClassMap
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);
        string role, flightNumber;
        if (openParenPos != string::npos && commaPos != string::npos) {
            role = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
            flightNumber = temp.substr(commaPos + 1, temp.length() - commaPos - 1);

            RoleName newRoleName = roleNameFromString(role);

            addAssignedFlight({{newRoleName, flightNumber}});
        } else {
            cerr << "Invalid format for RoleName in line: " << temp << endl;
        }
    }


    // uniqueDestinations
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ',');
        addToUniqueDestinations(temp);
    }


}

void Pilot::addAssignedFlight(const map<RoleName, string> &flight) {
    assignedFlightsMap.push_back(flight);
}

const vector<map<Pilot::RoleName, string>> &Pilot::getAssignedFlights() const {
    return assignedFlightsMap;
}

void Pilot::clearAssignedFlights() {
    assignedFlightsMap.clear();
}

Pilot::RoleName Pilot::roleNameFromString(const string &roleStr) {
    if (roleStr == "Pilot") {
        return RoleName::pilot;
    } else if (roleStr == "CoPilot") {
        return RoleName::copilot;
    } else if (roleStr == "Navigator") {
        return RoleName::navigator;
    } else {
        cerr << "Unknown role: " << roleStr << endl;

        return RoleName::pilot;
    }
}

