
#include <random>
#include <sstream>
#include <iostream>
#include "Attendant.h"


Attendant::Attendant() = default;

Attendant::~Attendant() = default;

void Attendant::readAttendantProperties(const string &basicString) {
    cout << "Basic String: " << basicString << endl;
    istringstream dataStream(basicString);
    string temp;
    int counter;

    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        name = temp;
    }
    getline(dataStream, temp, ',');
    {
        employeeID = stoi(temp);
    }

    // Continue reading Attendant properties here
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    // Iterate through each flight assignment
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

    // Read assignedFlightsMap
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);
        string position, flightNumber;
        if (openParenPos != string::npos && commaPos != string::npos) {
            position = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
            flightNumber = temp.substr(commaPos + 1, temp.length() - commaPos - 1);

            ServicePosition newPosition = servicePositionFromString(position);

            addAssignedFlight(newPosition, flightNumber);
        } else {
            cerr << "Invalid format for assignedFlightsMap in line: " << temp << endl;
        }
    }

    // Read and update uniqueDestinations set
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ',');
        addToUniqueDestinations(temp);
    }
}


Attendant::ServicePosition Attendant::servicePositionFromString(const string &positionStr) {
    if (positionStr == "frontOfPlane") {
        return ServicePosition::frontOfPlane;
    } else if (positionStr == "middleOfPlane") {
        return ServicePosition::middleOfPlane;
    } else if (positionStr == "backOfPlane") {
        return ServicePosition::backOfPlane;
    } else {
        cerr << "Unknown service position: " << positionStr << endl;
        return ServicePosition::backOfPlane; // Default to backOfPlane in case of an error
    }
}

void Attendant::addAssignedFlight(Attendant::ServicePosition position, const string &flight) {
    assignedFlightsMap[position] = flight;
}

const map<Attendant::ServicePosition, string> &Attendant::getAssignedFlights() const {
    return assignedFlightsMap;
}

void Attendant::clearAssignedFlights() {
    assignedFlightsMap.clear();
}
