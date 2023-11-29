

#include <random>
#include "Pilot.h"

int Pilot::getEmployeeID() const {
    return pilotID;
}

void Pilot::setEmployeeID() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    pilotID = random_number;
}
