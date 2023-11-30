
#ifndef INC_1040_CH5_PRACTICEPROJECT_PASSENGERS_H
#define INC_1040_CH5_PRACTICEPROJECT_PASSENGERS_H

#include <list>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>

using namespace std;


struct BookingChange {
    // Booking change details
};

struct CheckInRequest {
    // Check-in request details
};

class Passenger {
private:
    // Point 1: List
    std::list<std::string> listOfBookedFlights;

    // Point 2: Linked List
    std::list<BookingChange> bookingChanges;

    // Point 3: Pair
    std::pair<int, std::string> bookingPair;

    // Point 4: Map
    std::map<int, std::string> flightBookingMap;

    // Point 5: Queue
    std::queue<CheckInRequest> checkInQueue;

    // Point 6: Deque
    std::deque<BookingChange> bookingDeque;

    // Point 7: Set
    std::set<std::string> uniqueDestinations;

public:
    // Methods for managing passenger bookings, changes, check-ins, etc.
};


#endif //INC_1040_CH5_PRACTICEPROJECT_PASSENGERS_H
