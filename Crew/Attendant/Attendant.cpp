
#include <random>
#include <sstream>
#include "Attendant.h"


Attendant::Attendant() = default;

Attendant::~Attendant() = default;

void Attendant::readAttendantProperties(const string &basicString) {
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

}
