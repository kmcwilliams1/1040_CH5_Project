// In Pilot.h

#ifndef INC_1040_CH5_PRACTICEPROJECT_PILOT_H
#define INC_1040_CH5_PRACTICEPROJECT_PILOT_H

#include <map>
#include <vector>
#include "../Crew.h"

using namespace std;

class Collection;

class Pilot : public Crew {

private:


public:

    enum class RoleName {
        pilot = 1,
        copilot,
        navigator,
    };
    RoleName roleName{};

    vector<map<RoleName, string>> assignedFlightsMap;

    // Methods
    Pilot();
    ~Pilot();

    void readPilotProperties(const string &basicString, Collection *collection);

    RoleName roleNameFromString(const string &roleStr);

    // Public methods for assignedFlightsMap
    void addAssignedFlight(const map<RoleName, string> &flight);
    const vector<map<RoleName, string>>& getAssignedFlights() const;
    void clearAssignedFlights();

    void addPilotParameters(Collection *collection);
};

#endif //INC_1040_CH5_PRACTICEPROJECT_PILOT_H
