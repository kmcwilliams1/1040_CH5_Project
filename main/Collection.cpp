#include <sstream>
#include <iostream>
#include <algorithm>
#include <random>
#include "Collection.h"

void Collection::writeFlightProperties(ostream &dataFile, Flight *currentFlight) {

}

void Collection::writeCrewProperties(ostream &dataFile, Crew *currentCrew) {

}

void Collection::writeAirportProperties(ostream &dataFile, Airport *currentAirport) {

}

void Collection::readFlightProperties(const string &basicString) {

    istringstream dataStream(basicString);
    string temp;
    int counter;

    auto *flight = new Flight;

    getline(dataStream, temp, ',');
    {
        flight->setFlightNumber(temp);
    };
    getline(dataStream, temp, ',');
    {
        flight->setGate(temp);
    };
    getline(dataStream, temp, ',');
    {
        flight->setPassengerCount(stoi(temp));
    };
    getline(dataStream, temp, ',');
    {
        flight->setSeatCount(stoi(temp));
    };
    getline(dataStream, temp, ',');
    {
        flight->setDepartureTime(temp);
    };
    getline(dataStream, temp, ',');
    {
        time_t timestamp = stoi(temp);
        flight->setArrivalTime(timestamp);
    };

    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ',');
        {
            flight->setCrewIDs(stoi(temp));
        }
    }

    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        // Extract Request
        size_t startPos = temp.find(':') - 4;
        size_t endPos = temp.find(':');
        string id = temp.substr(startPos, endPos - startPos);

        // Extract Request
        size_t startPos2 = temp.find(':') + 1;
        size_t endPos2 = temp.find(':');
        string request = temp.substr(startPos2, endPos2 - startPos2);

        vector<string> requestDescriptions;

        if (request.find(',') != string::npos) {
            istringstream requestStream(request);
            string temp2;

            while (getline(requestStream, temp2, ',')) {
                requestDescriptions.push_back(temp2);
            }
        } else {
            requestDescriptions.push_back(request);
        }

        flight->pushMaintenanceRequest(stoi(id), requestDescriptions);
    }
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    for (int i = 0; i < counter; i++) {

        string arrivalCity, departureCity;
        getline(dataStream, temp, ',');
        {

            size_t openParenPos = temp.find('(');
            departureCity = temp.substr(openParenPos + 1, temp.length());

        }

        getline(dataStream, temp, ',');
        {
            size_t closeParenPos = temp.find(')');
            arrivalCity = temp.substr(0, closeParenPos);
        }

        flight->setDepartureAndArrivalCities(departureCity, arrivalCity);

    }


    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }

    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        size_t startPos = temp.find('(') + 1;
        size_t endPos = temp.find(':') - 1;
        string detailID = temp.substr(startPos, endPos - startPos + 1);

        size_t startPos2 = temp.find(':') + 1;
        size_t endPos2 = temp.find(')') - 1;
        string detailInfo = temp.substr(startPos2, endPos2);

        {
            flight->addFlightDetail(stoi(detailID), detailInfo);
        }
    }
    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }


    for (int i = 0; i < counter; i++) {
        string destination;
        getline(dataStream, destination, ',');

        if (!destination.empty()) {
            destination.erase(remove_if(destination.begin(), destination.end(), ::isspace), destination.end());
            flight->addDestinationToSet(destination);
        }

    }

    flights.push_back(flight);
    flight = nullptr;

}

void Collection::readCrewProperties(const string &basicString, Collection *collection) {

    istringstream dataStream(basicString);
    string temp;
    int counter;

    getline(dataStream, temp, ',');
    {
        const string &role = temp;
        int subClass = 0;
        if (role == "Pilot") {
            subClass = 1;
        } else if (role == "Attendant") {
            subClass = 2;
        }

        switch (subClass) {
            case 1: {
                auto *pilot = new Pilot;
                pilot->readPilotProperties(basicString, collection);
                crew.push_back(pilot);
                break;
            }
            case 2: {
                auto *attendant = new Attendant;
                attendant->readAttendantProperties(basicString, collection);
                crew.push_back(attendant);
                break;
            }
            default:
                cerr << "Something went wrong, dawg" << endl;
                break;
        }
    }

}

void Collection::readAirportProperties(const string &basicString, Collection *collection) {

    istringstream dataStream(basicString);
    string temp;
    int counter;

    auto *airport = new Airport;

    getline(dataStream, temp, ',');
    {
        airport->setAirportName(temp);
    };
    getline(dataStream, temp, ',');
    {
        airport->setCallSign(temp);

    }
    getline(dataStream, temp, ',');
    {
        airport->setNumberOfGates(stoi(temp));
    }


    //listOfFlights
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ',');

        // Remove leading and trailing whitespaces from the flight name
        temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());

        if (!temp.empty()) {
            Flight *currentFlight = nullptr;
            const string &flightName = temp;

            for (auto &flight: collection->flights) {
                if (flight->getFlightNumber() == flightName) {
                    currentFlight = flight;
                    break;
                }
            }

            if (currentFlight) {
                airport->addFlightToList(currentFlight);
                airport->enqueueArrivingFlight(currentFlight);
                airport->pushDepartingFlightBack(currentFlight);
            } else {
                cerr << "No matching flight found for currentFlight " << flightName << endl;
            }
        }
    }


    airports.push_back(airport);

}

void Collection::addNewFlight(Flight *pFlight) {

    cout << "What is the flight number?" << endl;
    string flightNumber;
    cin >> flightNumber;
    pFlight->setFlightNumber(flightNumber);

    cin.ignore();

    cout << "Available Airports:" << endl;
    for (auto &currentAirport: airports) {
        cout << currentAirport->getAirportName() << " (" << currentAirport->getCallSign() << ")" << endl;
    }

    cout << "What is the starting airport (by call sign)?" << endl;
    string departureCity;
    cin >> departureCity;

    bool validDepartureCity = false;
    for (auto &currentAirport: airports) {
        if (currentAirport->getCallSign() == departureCity) {
            validDepartureCity = true;
            break;
        }
    }

    if (!validDepartureCity) {
        cout << "Invalid departure city. Please enter a valid call sign." << endl;
        return;
    }

    cout << "What is the destination airport (by call sign)?" << endl;
    string arrivalCity;
    cin >> arrivalCity;

    bool validArrivalCity = false;
    for (auto &currentAirport: airports) {
        if (currentAirport->getCallSign() == arrivalCity) {
            validArrivalCity = true;
            break;
        }
    }

    if (!validArrivalCity) {
        cout << "Invalid arrival city. Please enter a valid call sign." << endl;
        return;
    }

    pFlight->setDepartureAndArrivalCities(departureCity, arrivalCity);

    cin.ignore();
    pFlight->addDepartureTime();

    flights.push_back(pFlight);
}


void Collection::addNewCrew() {


    char option;
    cout << "Are they a pilot or an attendant? (P/A)" << endl;
    if (option == 'P' || option == 'p') {
        auto *pilot = new Pilot;
        pilot->addPilotParameters(this);
    } else if (option == 'A' || option == 'a') {
        auto *attendant = new Attendant;
        attendant->addAttendantParameters();
    } else { cout << "Not a valid input, please try again" << endl; }


}

void Collection::addNewAirport(Airport *pAirport) {

    cout << "What is the name of the airport?" << endl;
    string name;
    cin >> name;
    pAirport->setAirportName(name);

    cin.ignore();
    cout << "What is the call sign of the airport?" << endl;
    cin >> name;
    pAirport->setCallSign(name);

    cin.ignore();
    cout << "How many gates does the airport have?" << endl;
    int gates;
    cin >> gates;
    pAirport->setNumberOfGates(gates);

    airports.push_back(pAirport);
    cout << "Hello mrs lady " << endl;

}


void Collection::deleteAirport(Airport *pAirport) {
    auto it = find(airports.begin(), airports.end(), pAirport);
    if (it != airports.end()) {
        airports.erase(it);
        delete *it;
    }
}

void Collection::deleteFlight(Flight *pFlight) {

}

void Collection::deleteCrew(Crew *pCrew) {

}
