

#include <random>
#include <sstream>
#include "Pilot.h"



Pilot::Pilot() = default;

Pilot::~Pilot() = default;

void Pilot::readPilotProperties(const string &basicString) {

    istringstream dataStream(basicString);
    string temp;

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

    }

}
