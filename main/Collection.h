
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


    void readAirportProperties(const string &basicString, Collection *collection);

    void readCrewProperties(const string &basicString, Collection *collection);

    void readFlightProperties(const string &basicString);

    void writeAirportProperties(ostream &dataFile, Airport *currentAirport);

    void writeCrewProperties(ostream &dataFile, Crew *currentCrew);

    void writeFlightProperties(ostream &dataFile, Flight *currentFlight);


    void addNewFlight(Flight *flight);
    void addNewAirport(Airport *airport);
    void addNewCrew(Crew *crew);


    void deleteAirport(Airport *pAirport);
    void deleteFlight(Flight *pFlight);
    void deleteCrew(Crew *pCrew);
};


#endif //INC_1040_CH5_PRACTICEPROJECT_COLLECTION_H
