

#include <random>
#include <sstream>
#include "Pilot.h"


Pilot::Pilot() = default;

Pilot::~Pilot() = default;

void Pilot::readPilotProperties(const string &basicString) {

    istringstream dataStream(basicString);
    string temp;
    int counter;

    dataStream.clear();
    dataStream.seekg(0);


    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        name = temp;
        getName();
    }
    getline(dataStream, temp, ',');
    {
        employeeID = stoi(temp);
        getEmployeeID();
    }
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ',');
        {
            string leg, flightNumber;
            getline(dataStream, temp, ',');
            {
                size_t openParenPos = temp.find('(');
                flightNumber = temp.substr(openParenPos + 1, temp.length());

            }

            getline(dataStream, temp, ',');
            {
                size_t closeParenPos = temp.find(')');
                leg = temp.substr(0, closeParenPos);
            }
            //setFlightPair(flightNumber, leg);
        }
    }
}
