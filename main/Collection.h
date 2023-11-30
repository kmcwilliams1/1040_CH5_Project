
#ifndef INC_1040_CH5_PRACTICEPROJECT_COLLECTION_H
#define INC_1040_CH5_PRACTICEPROJECT_COLLECTION_H


#include "../Crew/Crew.h"
#include "../Flight/Flight.h"
#include "../Passengers/Passengers.h"

class Collection {
public:
    vector<Passenger*> passengers;
    vector<Crew*> crew;
    vector<Flight*> flights;

    void readPassengerProperties(const string &basicString);
    void readCrewProperties(const string &basicString);
    void readFlightProperties(const string &basicString);

    void writePassengerProperties(ostream& dataFile);
    void writeCrewProperties(ostream& dataFile);
    void writeFlightProperties(ostream& dataFile);


};


#endif //INC_1040_CH5_PRACTICEPROJECT_COLLECTION_H
