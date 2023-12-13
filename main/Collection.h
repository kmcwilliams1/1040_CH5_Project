
#ifndef INC_1040_CH5_PRACTICEPROJECT_COLLECTION_H
#define INC_1040_CH5_PRACTICEPROJECT_COLLECTION_H


#include "../Crew/Crew.h"
#include "../Flight/Flight.h"
#include "../Airport/Airport.h"

class Collection {
public:
    vector<Airport *> airports;
    vector<Crew *> crew;
    vector<Flight *> flights;


    void readAirportProperties(const string &basicString, Airport *airport);

    void readCrewProperties(const string &basicString);

    void readFlightProperties(const string &basicString, Flight *flight);

    void writeAirportProperties(ostream &dataFile);

    void writeCrewProperties(ostream &dataFile);

    void writeFlightProperties(ostream &dataFile);


};


#endif //INC_1040_CH5_PRACTICEPROJECT_COLLECTION_H
