#ifndef INC_1040_CH5_PRACTICEPROJECT_PILOT_H
#define INC_1040_CH5_PRACTICEPROJECT_PILOT_H


#include <map>
#include "../Crew.h"

using namespace std;


class Pilot : public Crew {


private:
    enum class RoleName {
        pilot = 1,
        copilot,
        navigator,
    };
    RoleName roleName{};

    // Point 4: Map
    map<RoleName, string> assignedFlightsMap;

public:// Methods

    Pilot();

    ~Pilot();


    void readPilotProperties(const string &basicString);
};


#endif //INC_1040_CH5_PRACTICEPROJECT_PILOT_H
