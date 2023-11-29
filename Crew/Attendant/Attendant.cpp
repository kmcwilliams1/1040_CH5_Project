
#include <random>
#include "Attendant.h"

int Attendant::getEmployeeID() const {
    return attendantID;
}

void Attendant::setEmployeeID() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    attendantID = random_number;
}
