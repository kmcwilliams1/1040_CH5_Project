
#ifndef INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
#define INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H


#include "../Pilot/Pilot.h"

class Attendant : public Crew  {

    private:
    int attendantID{};
        enum class ServicePosition{
            frontOfPlane = 1,
            middleOfPlane,
            backOfPlane
        };
        ServicePosition servicePosition{};

public:
    void setEmployeeID() override;

    int getEmployeeID() const override;

    Attendant();
};


#endif //INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
