
#ifndef INC_1040_CH5_PRACTICEPROJECT_CREW_H
#define INC_1040_CH5_PRACTICEPROJECT_CREW_H

#include <list>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>

using namespace std;


struct FlightAssignments {
    // Flight update details
};

class Crew {
public:
    Crew();

    ~Crew();


private:// 7 points of study from Chapter 5

    // Point 2: Linked List
    list<FlightAssignments> flightAssignments;

    // Point 3: Pair
    // pair<int, Flight> assignedFlightPair;

    // Point 7: Set
    set<string> uniqueDestinations;


public:
    enum class EmployeeType {
        Pilot,
        Attendant
    };
    string name;
    int employeeID{};


public: //Getter and Setter Methods
    string getName() const;

    void setName(const string &basicString);


    int getEmployeeID() const;

    void setEmployeeID(int newEmployeeID);


    // Point 7: Set
    void addToUniqueDestinations(const string &destination);

    void removeFromUniqueDestinations(const string &destination);

    set<string> getUniqueDestinations() const;

    bool isDestinationInSet(const string &destination) const;

    void clearUniqueDestinations();


};


#endif //INC_1040_CH5_PRACTICEPROJECT_CREW_H
