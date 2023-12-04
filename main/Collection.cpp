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

void Collection::readCrewProperties(const string &basicString) {

}

void Collection::readAirportProperties(const string &basicString) {
    istringstream dataStream(basicString);
    string temp;

    auto *airport = new Airport;


    getline(dataStream, temp, ',');
    {
        airport->setAirportName(temp);
        cout << "Airport name " << airport->getAirportName() << endl;
    };
    getline(dataStream, temp, ',');
    {
        airport->setCallSign(temp);
        cout << "Airport call sign " << airport->getCallSign() << endl;

    }
    getline(dataStream, temp, ',');
    {
        airport->setNumberOfGates(stoi(temp));
        cout << "Num of gates: "<< airport->getNumberOfGates();
    }
}
