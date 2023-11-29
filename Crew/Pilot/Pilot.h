#ifndef INC_1040_CH5_PRACTICEPROJECT_PILOT_H
#define INC_1040_CH5_PRACTICEPROJECT_PILOT_H


#include "../Crew.h"

using namespace std;


class Pilot : Crew {

private:
    int pilotID{};
    enum class RoleName {
        pilot = 1,
        copilot,
        navigator,
    };
    RoleName roleName{};


public:// Methods

    int getEmployeeID() const;

    void setEmployeeID();
};


#endif //INC_1040_CH5_PRACTICEPROJECT_PILOT_H
