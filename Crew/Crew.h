#ifndef INC_1040_CH5_PRACTICEPROJECT_CREW_H
#define INC_1040_CH5_PRACTICEPROJECT_CREW_H

#include <list>
#include <set>
#include <utility>
#include <string>
#include <vector>

class Flight;
class Collection;

using namespace std;

struct FlightAssignments {
    int flightLeg;
    string arrivalCity;
    string departureCity;
};

class Crew {
public:
    Crew();

    ~Crew();

private:
    // 7 points of study from Chapter 5
    // Point 1: List
    list<Crew *> listOfCrew;

    // Point 2: Linked List
    list<FlightAssignments> flightAssignments;

    // Point 3: Pair
    vector<pair<int, Flight *>> assignedFlightPairs;

    // Point 7: Set
    set<string> uniqueDestinations;

public:
    enum class EmployeeType {
        Pilot,
        Attendant
    };
    string name;
    int employeeID{};

public: // Getter and Setter Methods
    string getName() const;

    void setName(const string &basicString);

    int getEmployeeID() const;

    void setEmployeeID(int newEmployeeID);

    // Point 2: Linked List
    list<FlightAssignments> getFlightAssignments() const;

    void addFlightAssignment(int leg, const string &departureCity, const string &arrivalCity);

    // Point 3: Pair
    pair<int, Flight *> getAssignedFlightPair() const;

    void setAssignedFlightPair(int leg, Flight *flight);

    void printAssignedFlightPair() const;

    // Point 7: Set
    void addToUniqueDestinations(const string &destination);

    void removeFromUniqueDestinations(const string &destination);

    set<string> getUniqueDestinations() const;

    bool isDestinationInSet(const string &destination) const;

    void clearUniqueDestinations();

    void printUniqueDestinations() const;

    void printInfo();

    void updateCrew();

    list<Crew *> getListOfCrew() const;

    void manageCrew(Collection *pCollection);

};

#endif //INC_1040_CH5_PRACTICEPROJECT_CREW_H
