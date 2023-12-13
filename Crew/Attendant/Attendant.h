
#ifndef INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
#define INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H


#include "../Pilot/Pilot.h"

class Attendant : public Crew {

private:
    int attendantID{};
    enum class ServicePosition {
        frontOfPlane = 1,
        middleOfPlane,
        backOfPlane
    };
    ServicePosition servicePosition{};

    // Point 4: Map
    map<ServicePosition, string> assignedFlightsMap;

public:
    Attendant();

    ~Attendant();

    void readAttendantProperties(const string &basicString);
};


#endif //INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
