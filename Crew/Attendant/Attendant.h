
#ifndef INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
#define INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H


#include "../Pilot/Pilot.h"

class Attendant : public Pilot  {

    private:
        int attendantID{};
        enum class ServicePosition{
            frontOfPlane = 1,
            middleOfPlane,
            backOfPlane
        };
        ServicePosition servicePosition{};

public:
    void setEmployeeID();

    int getEmployeeID() const;
};


#endif //INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
