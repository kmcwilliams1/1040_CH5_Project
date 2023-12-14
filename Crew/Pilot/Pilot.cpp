

#include <sstream>
#include <iostream>
#include "Pilot.h"
#include "../../main/Collection.h"

Pilot::Pilot() = default;

Pilot::~Pilot() = default;

void Pilot::readPilotProperties(const string &basicString, Collection *collection) {

    istringstream dataStream(basicString);
    string temp;
    int counter;

    dataStream.clear();
    dataStream.seekg(0);


    getline(dataStream, temp, ',');
    getline(dataStream, temp, ',');
    {
        name = temp;
        cout << "Name: " << getName() << endl;
    }
    getline(dataStream, temp, ',');
    {
        employeeID = stoi(temp);
        cout << "ID: " << getEmployeeID() << endl;
    }
    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    cout << "Number of flights: " << counter << endl;
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        Flight *currentFlight = nullptr;

        string leg, flightNumber;
        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);

        // Extract leg and flightNumber (same as before)
        if (commaPos != string::npos) {
            leg = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
        } else {
            leg = temp.substr(openParenPos + 1, temp.length() - openParenPos - 1);
        }

        flightNumber = temp.substr(commaPos + 1, temp.length() - commaPos - 1);


        // Look for matching flight in collection
        for (auto &flight : collection->flights) {
            if (flight->getFlightNumber() == flightNumber) {
                currentFlight = flight;
                break; // Found matching flight, stop searching
            }
        }

        // Check if a flight was found and assign
        if (currentFlight) {
            setAssignedFlightPair(stoi(leg), currentFlight);
        } else {
            // Handle case where no matching flight found (optional)
            cerr << "No matching flight found for leg " << leg << " with flight number " << flightNumber << endl;
        }
    }

    cout << "Now printing all flights \n";
    printAssignedFlightPair();

    getline(dataStream, temp, ',');
    {
        counter = stoi(temp);
    }
    cout << "Number of flights: " << counter << endl;

    // Iterate through each flight assignment
    for (int i = 0; i < counter; i++) {
        getline(dataStream, temp, ')');

        // Extract flight details
        size_t openParenPos = temp.find('(');
        size_t commaPos = temp.find(',', openParenPos + 1);

        // Extract leg and flightNumber
        string leg = temp.substr(openParenPos + 1, commaPos - openParenPos - 1);
        string flightNumber = temp.substr(commaPos + 1, temp.length() - commaPos - 1);

        // Extract additional flight details
        vector<pair<int, string>> additionalDetails;
        size_t nextCommaPos = temp.find(',', openParenPos + 1);
        while (nextCommaPos != string::npos) {
            // Extract the next set of flight details
            size_t nextOpenParenPos = temp.find('(', nextCommaPos);
            size_t nextCloseParenPos = temp.find(')', nextCommaPos);

            string detailID = temp.substr(nextOpenParenPos + 1, nextCommaPos - nextOpenParenPos - 1);
            string detailInfo = temp.substr(nextCommaPos + 1, nextCloseParenPos - nextCommaPos - 1);

            additionalDetails.emplace_back(stoi(detailID), detailInfo);

            // Move to the next set of flight details
            nextCommaPos = temp.find(',', nextCloseParenPos + 1);
        }

        // Add flight assignment and details
        addFlightAssignment(stoi(leg), flightNumber, additionalDetails);
    }

}

