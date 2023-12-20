

#include <sstream>
#include <iostream>
#include <random>
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

void Pilot::addPilotParameters(Collection *collection) {
    string str;
    cout << "What is the pilot's name?" << endl;
    cin >> str;
    setName(str);


    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);

    setEmployeeID(random_number);


    cout << "Would you like to create a schedule for " << name << " ?" << endl;
    char option;

    if (option == 'y' || option == 'Y') {


        // loop through flights or airports
        // then crew.addFlightAssignment
        // then pilot.addPilotParameters
        // ask to add another leg, if so, repeat


        cout << "Do you want to start out at an airport or with a specific flight? (A/F)" << endl;
        cin >> option;
        if (option == 'f' || option == 'F') {
            for (auto &currentFlights: collection->flights) {
                cout << currentFlights->getFlightNumber() << endl;
            }
        } else if (option == 'a' || option == 'A') {
            for (auto &currentAirport: collection->airports) {
                cout << currentAirport->getAirportName() << endl;
            }
            cout << "Which airport?" << endl;
            cin >> str;
            for (auto &currentAirport: collection->airports) {
                if (str == currentAirport->getAirportName()) {
                    currentAirport->getFlightsInvolvingThisAirport();
                }
            }
            cout << "Add pilot to which flight at this airport?" << endl;
            cin >> str;
            for (auto &currentFlight: collection->flights) {
                if (str == currentFlight->getFlightNumber()) {
                    currentFlight->addCrewMember({{employeeID, Pilot}});
                }
            }

        } else { cout << "Not a valid input, please try again" << endl; };



        //addAssignedFlight();


    } else {
        return;
    }


}




