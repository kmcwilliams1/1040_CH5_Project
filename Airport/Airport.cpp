    #include "Airport.h"
    #include <algorithm>
    #include <iostream>

    void Airport::addFlightToList(Collection *collection) {
        auto *flight = new Flight;
        listOfFlights.push_back(flight);
        delete flight;
    }

    void Airport::addFlightToList(Flight *flight) {
        listOfFlights.push_back(flight);
    }

    void Airport::removeFlightFromList(const string &flightNumber) {
        listOfFlights.remove_if([flightNumber](const Flight *flight) {
            return flight->getFlightNumber() == flightNumber;
        });
    }

    list<Flight *> Airport::getListOfFlights() const {
        return listOfFlights;
    }

    bool Airport::isFlightInList(const string &flightNumber) const {
        return any_of(listOfFlights.begin(), listOfFlights.end(), [flightNumber](const Flight *flight) {
            return flight->getFlightNumber() == flightNumber;
        });
    }

    void Airport::clearListOfFlights() {
        listOfFlights.clear();
    }


    // Point 5: Queue (Arriving Flights)
    void Airport::enqueueArrivingFlight(Flight *flight) {
        arrivingFlights.push(flight);
    }

    void Airport::dequeueArrivingFlight() {
        if (!arrivingFlights.empty()) {
            arrivingFlights.pop();
        }
    }

    Flight Airport::frontArrivingFlight() const {
        if (!arrivingFlights.empty()) {
            return *arrivingFlights.front();
        } else {
            // Return a default-constructed Flight or handle the case when the queue is empty
            return {};
        }
    }

    bool Airport::isArrivingFlightsEmpty() const {
        return arrivingFlights.empty();
    }

    void Airport::clearArrivingFlights() {
        while (!arrivingFlights.empty()) {
            arrivingFlights.pop();
        }
    }


    // Point 6: Deque (Departing Flights)
    void Airport::pushDepartingFlightFront(Flight *flight) {
        departingFlights.push_front(flight);
    }

    void Airport::pushDepartingFlightBack(Flight *flight) {
        departingFlights.push_back(flight);
    }

    void Airport::popDepartingFlightFront() {
        if (!departingFlights.empty()) {
            departingFlights.pop_front();
        }
    }

    void Airport::popDepartingFlightBack() {
        if (!departingFlights.empty()) {
            departingFlights.pop_back();
        }
    }

    Flight Airport::frontDepartingFlight() const {
        if (!departingFlights.empty()) {
            return *departingFlights.front();
        } else {
            // Return a default-constructed Flight or handle the case when the deque is empty
            return {};
        }
    }

    Flight Airport::backDepartingFlight() const {
        if (!departingFlights.empty()) {
            return *departingFlights.back();
        } else {
            return {};
        }
    }

    bool Airport::isDepartingFlightsEmpty() const {
        return departingFlights.empty();
    }

    void Airport::clearDepartingFlights() {
        departingFlights.clear();
    }


    //Accesssor Methods
    string Airport::getAirportName() const {
        return airportName;
    }

    void Airport::setAirportName(string &newName) {
        airportName = newName;
    }

    string Airport::getGate() const {
        return gate;
    }

    void Airport::setGate(string &newGate) {
        gate = newGate;
    }

    int Airport::getNumberOfGates() const {
        return numberOfGates;
    }

    void Airport::setNumberOfGates(int newNumberOfGates) {
        numberOfGates = newNumberOfGates;
    }


    list<Flight *> Airport::getFlightsInvolvingThisAirport() const {
        cout << "Schedule: " << endl;
        cout << "--------------------" << endl;
        for (auto &currentFlight: listOfFlights) {
            for (const auto &cityPair: currentFlight->getDepartureAndArrivalCities()) {
                if (cityPair.first == getCallSign() || cityPair.second == getCallSign()) {
                    cout << "Flight: " << currentFlight->getFlightNumber() << endl;
                    cout << "Departure City: " << cityPair.first << " Arrival City: " << cityPair.second << endl;
                    cout << "Gate: " << currentFlight->getGate() << endl;
                    cout << "--------------------" << endl;
                    break;
                }
            }
        }
        cout << "\n";
        return listOfFlights;
    }


    void Airport::setCallSign(const string &basicString) {
        callSign = basicString;
    }

    string Airport::getCallSign() const {
        return callSign;
    }

    void Airport::manageFlights(Collection *collection) const {

        string str;
        auto *tempFlight = new Flight();
        getFlightsInvolvingThisAirport();
        cout << "Which flight would you like to examine? " << endl;
        cin >> str;
        for (char &c: str) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }

        for (auto *currentFlight: getListOfFlights()) {
            if (currentFlight->getFlightNumber() == str) {
                tempFlight = currentFlight;
            }
        }

        cout << "What would you like to do to this flight?" << endl;
        cout << "View in detail:      A" << endl;
        cout << "Edit this flight:    B" << endl;
        cout << "Delete this flight:  C" << endl;
        char option;
        cin >> option;

        switch (option) {
            case 'A':
            case 'a': // view flight
            {
                tempFlight->printInfo();
                break;
            }
            case 'B':
            case 'b': // edit flight
            {
                tempFlight->updateFlight();
                break;
            }
            case 'D':
            case 'd': // delete flight
            {
                collection->deleteFlight(tempFlight);
                break;
            }
            default:
                cout << "Unknown option please try again." << endl;

        }


        delete tempFlight;

    }

    void Airport::setAirport() {
        cout << "What would you like to update?" << endl;
    }

    void Airport::printInfo() const {
        cout << "Airport Name: " << getAirportName() << endl;
        cout << "Call Sign: " << getCallSign() << endl;
        cout << "Number of Gates: " << getNumberOfGates() << endl;
        cout << "View Flights at this location?: (Y/N)";

        char option;
        if (option == 'y' || option == 'Y') {
            getFlightsInvolvingThisAirport();
        }
    }


