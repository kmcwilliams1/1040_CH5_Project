
#include <sstream>
#include <iostream>
#include "Attendant.h"
#include "../../main/Collection.h"


Attendant::Attendant() = default;

Attendant::~Attendant() = default;

void Attendant::readAttendantProperties(const string &basicString, Collection *collection) {
    cout << "Basic String: " << basicString << endl;
    istringstream dataStream(basicString);
    string temp;
    int counter;

    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        name = temp;
        cout << "Name: " << name << endl;
    }
    getline(dataStream, temp, ',');
    {
        cout << "temp: " << temp << endl;
        employeeID = stoi(temp);
    }




// Iterate through each assignedFlightPair
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    cout << "assignedFlightPair counter: " << counter << endl;
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

        cout << "Leg " << leg << " flightNumber " << flightNumber << endl;

        for (auto &flight: collection->flights) {
            if (flight->getFlightNumber() == flightNumber) {
                currentFlight = flight;
                cout << "Flight " << flight->getFlightNumber() << endl;
                break;
            }
        }


        if (currentFlight != nullptr) {
             setAssignedFlightPair(stoi(leg), currentFlight);
        } else {
            cerr << "No matching flight found for leg " << leg << " with flight number " << flightNumber << endl;
        }
    }





// Iterate through each FlightAssignments
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');

    {
        counter = stoi(temp);
    }
    cout << "FlightAssignment counter " << counter << endl;
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);
        string arrivalCity, departureCity;
        if (openParenPos != string::npos && commaPos != string::npos) {
            arrivalCity = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
            departureCity = temp.substr(commaPos + 1, temp.length() - commaPos - 1);

            cout << "Arrival City: " << arrivalCity << " Departure City: " << departureCity << endl;

              addFlightAssignment(i + 1, departureCity, arrivalCity);
        } else {
            cerr << "Invalid format for city information in line: " << temp << endl;
        }
    }



    // Read subClassMap
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    cout << "subClassMap size: " << counter << endl;
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);
        string position, flightNumber;
        if (openParenPos != string::npos && commaPos != string::npos) {
            position = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
            flightNumber = temp.substr(commaPos + 1, temp.length() - commaPos - 1);

            cout << "Position: " << position << " Flight Number: " << flightNumber << endl;

            ServicePosition newPosition = servicePositionFromString(position);

              addAssignedFlight(newPosition, flightNumber);
        } else {
            cerr << "Invalid format for assignedFlightsMap in line: " << temp << endl;
        }
    }



    // Read and update uniqueDestinations set
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    cout << "uniqueDestinations size: " << counter << endl;

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
