// Attendant.h

#ifndef INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
#define INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H

#include <map>
#include "../Crew.h"

class Collection;
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

    void readAttendantProperties(const string &basicString, Collection *collection);

    ServicePosition servicePositionFromString(const string &positionStr);

    // Public methods for assignedFlightsMap
    void addAssignedFlight(ServicePosition position, const string &flight);
    const map<ServicePosition, string>& getAssignedFlights() const;
    void clearAssignedFlights();
};

#endif //INC_1040_CH5_PRACTICEPROJECT_ATTENDANT_H
