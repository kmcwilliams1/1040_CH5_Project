#include <sstream>
#include <iostream>
#include <algorithm>
#include "Collection.h"

void Collection::writeFlightProperties(ostream &dataFile) {

}

void Collection::writeCrewProperties(ostream &dataFile) {

}

void Collection::writeAirportProperties(ostream &dataFile) {

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
        bool fueled = true;
        (temp == "true") ? fueled = true : fueled = false;
        flight->setIsFueled(fueled);
        flight->setIsFueled(fueled);
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
    cout << endl << endl;
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
                cout << "Attendant ready to read! " << endl;
                attendant->readAttendantProperties(basicString);
                crew.push_back(attendant);
                break;
            }
            default:
                cerr << "Something went wrong, dawg" << endl;
                break;
        }
    }

}

void Collection::readAirportProperties(const string &basicString) {

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
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ',');
        {
            airport->setFlightIDs(temp);
        }
    }
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
        airport->setFlightPair(departureCity, arrivalCity);

    }

    airports.push_back(airport);

}
