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

void Collection::readFlightProperties(const string &basicString, Flight *flight) {

    istringstream dataStream(basicString);
    string temp;
    int counter;


    getline(dataStream, temp, ',');
    {
        flight->setFlightNumber(temp);
        cout << "flight number: " << flight->getFlightNumber() << endl;
    };
    getline(dataStream, temp, ',');
    {
        flight->setGate(temp);
        cout << "gate number: " << flight->getGate() << endl;
    };
    getline(dataStream, temp, ',');
    {
        flight->setPassengerCount(stoi(temp));
        cout << "passenger count: " << flight->getPassengerCount() << endl;
    };
    getline(dataStream, temp, ',');
    {
        flight->setSeatCount(stoi(temp));
        cout << "seat count: " << flight->getSeatCount() << endl;
    };
    getline(dataStream, temp, ',');
    {
        bool fueled = true;
        (temp == "true") ? fueled = true : fueled = false;
        flight->setIsFueled(fueled);
        flight->setIsFueled(fueled);
        cout << "fuel? " << flight->getIsFueled() << endl;
    };
    getline(dataStream, temp, ',');
    {
        flight->setDepartureTime(temp);
        cout << "Departure time: " << flight->getDepartureTime() << endl;
    };
    getline(dataStream, temp, ',');
    {
        time_t timestamp = stoi(temp);
        flight->setArrivalTime(timestamp);
        cout << "Arrival time: " << flight->getArrivalTime() << endl;
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
    for (int id: flight->getCrewIDs()) {
        cout << "Crew ID: " << id << endl;
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

        cout << "adding " << requestDescriptions.size() << " requests" << endl;
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
    flight->getDepartureAndArrivalCities();


    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    cout << "counter is: " << counter << endl;

    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        size_t startPos = temp.find('(') + 1;
        size_t endPos = temp.find(':') - 1;
        string detailID = temp.substr(startPos, endPos - startPos + 1);
        cout << "DetailID: " << detailID << endl;

        size_t startPos2 = temp.find(':') + 1;
        size_t endPos2 = temp.find(')') - 1;
        string detailInfo = temp.substr(startPos2, endPos2);

        cout << "detailInfo: " << detailInfo << endl;
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

    flight->getUniqueDestinations();


}

void Collection::readCrewProperties(const string &basicString, Crew *thisCrew) {

    istringstream dataStream(basicString);
    string temp;
    int counter;

}

void Collection::readAirportProperties(const string &basicString, Airport *airport) {

    istringstream dataStream(basicString);
    string temp;
    int counter;


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
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ',');
        {
            airport->addToUniqueDestinations(temp);
        }


    }
}
