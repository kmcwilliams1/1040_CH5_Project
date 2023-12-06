#include <sstream>
#include <iostream>
#include "Collection.h"

void Collection::writeFlightProperties(ostream &dataFile) {

}

void Collection::writeCrewProperties(ostream &dataFile) {

}

void Collection::writeAirportProperties(ostream &dataFile) {

}

void Collection::readFlightProperties(const string &basicString) {

}

void Collection::readCrewProperties(const string &basicString, Crew *thisCrew) {

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
