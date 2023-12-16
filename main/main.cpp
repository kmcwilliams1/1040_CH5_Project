#include <iostream>
#include <fstream>
#include "Collection.h"
#include <ctime>
#include <sstream>

using namespace std;


struct Time {
    vector<string> daysOfTheWeek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    string getToday() {
        time_t currentTime;
        struct tm *localTime;

        time(&currentTime);                   // Get the current time
        localTime = localtime(&currentTime);  // Convert the current time to the local time

        return daysOfTheWeek[localTime->tm_wday];
    }


    int getDayIndex(const string &day) {
        for (int i = 0; i < daysOfTheWeek.size(); ++i) {
            if (daysOfTheWeek[i] == day) {
                return i;
            }
        }
        return -1; // Not found
    }
};


int main() {

    auto *airport = new Airport();
    auto *crew = new Crew();
    auto *flight = new Flight();


    auto *collection = new Collection();
    Time calendar;
    ifstream fin("AirportData.dat");

    if (!fin.is_open()) {
        cerr << "Failed to open AirportData.dat" << endl;
        return 1;
    }


    string readingLine;
    string role;
    char option;
    string crewSearchWord = "#Crew";
    string airportSearchWord = "#Airport";
    string flightSearchWord = "#Flight";
    string lastRole;


    while (getline(fin, readingLine)) {
        istringstream lineStream(readingLine);


        if (readingLine.empty() || readingLine[0] == '#') {
            lineStream >> role;
            lastRole = role;
            continue;
        }

        getline(lineStream, role, ',');

        if (lastRole == airportSearchWord) {
            collection->readAirportProperties(readingLine, collection);
        } else if (lastRole == crewSearchWord) {
            collection->readCrewProperties(readingLine, collection);
        } else if (lastRole == flightSearchWord) {
            collection->readFlightProperties(readingLine);
        }


    }
    cout << "\n\n\n\n\n\n";


    cout << "Airport size: " << collection->airports.size() << endl;
    cout << "Flight size: " << collection->flights.size() << endl;
    cout << "Crew size: " << collection->crew.size() << endl;


    fin.clear();
    fin.seekg(0, ios::beg);

    while (true) {


        cout << "     ____                                  ____                             _  \n"
                "    / ___|   _ _ __  _ __ (_)_ __   __ _  | __ ) _   _ __________ _ _ __ __| | \n"
                "   | |  | | | | '_ \\| '_ \\| | '_ \\ / _` | |  _ \\| | | |_  /_  / _` | '__/ _` | \n"
                "   | |__| |_| | | | | | | | | | | | (_| | | |_) | |_| |/ / / / (_| | | | (_| | \n"
                "    \\____\\__,_|_| |_|_| |_|_|_| |_|\\__, |_|____/ \\__,_/___/___\\__,_|_|  \\__,_| \n"
                "                            / \\  (_)___/| (_)_ __   ___  ___                   \n"
                "                           / _ \\ | | '__| | | '_ \\ / _ \\/ __|                  \n"
                "                          / ___ \\| | |  | | | | | |  __/\\__ \\                  \n"
                "                         /_/   \\_\\_|_|  |_|_|_| |_|\\___||___/          " << endl;

        cout << "| ********************************* Main Menu *************************************** |" << endl;
        cout << "| ** A.    View Flights   ** |" << "| ** B.  Manage Flights   ** |" << "| ** C.  Manage Crew   ** |"
             << endl;;
        cout << "| *********************************************************************************** |" << endl;


        cin >> option;
        string str;
        switch (option) {
            case 'A':
            case 'a': // View Flights
            {
                cout << "Which airport would you like to view \n" << endl;
                for (auto *currentAirport: collection->airports) {
                    cout << currentAirport->getAirportName() << " - " << currentAirport->getCallSign() << endl;
                }
                cout << "Enter Airport Abbreviation:   ";
                cin >> str;
                for (char &c: str) {
                    c = std::toupper(c);
                }
//TODO - do the time bit, for now, just do airports

//                cout << "Which day would you like to view? " << endl;
//                string today = calendar.getToday();
//                cout << "Today :" << today << ", ";
//
//                // Display the next 6 days
//                for (int i = 1; i <= 6; ++i) {
//                    int nextDayIndex = (calendar.getDayIndex(today) + i) % 7;
//                    cout << calendar.daysOfTheWeek[nextDayIndex] << ((i < 6) ? ", " : "\n");
//                }



                for (auto &currentAirport: collection->airports) {

                    if (currentAirport->getCallSign() == str) {
                        cout << "\n";
                        currentAirport->getFlightsInvolvingThisAirport();
                        break;
                    }
                }


            }
                break;


            case 'B':
            case 'b': // Manage Flights


                cout << "Do you want to create a new flight or update a preexisting one? (C/U) " << endl;
                cin >> option;


                if (option == 'c' || option == 'C') {
                    collection->addNewFlight();
                } else if (option == 'u' || option == 'U') {
                    auto *tempFlight = new Flight();

                    cout << "Edit from airport or flight list? (A/F) " << endl;
                    cin >> option;


                    if (option == 'a' || option == 'A') {

                        cout << "Which airport would you like to manage " << endl;
                        for (auto *currentAirport: collection->airports) {
                            cout << currentAirport->getAirportName() << "   " << currentAirport->getCallSign() << endl;
                        }
                        cout << "Enter Airport Abbreviation: ";
                        cin >> str;
                        for (char &c: str) {
                            c = std::toupper(c);
                        }

                        for (auto &currentAirport: collection->airports) {
                            if (currentAirport->getCallSign() == str) {
                                cout << "Found " << str << endl;
                                cout << "\n";
                                currentAirport->getFlightsInvolvingThisAirport();


                                cout << "Which flight would you like to manage? " << endl;
                                cin >> str;
                                for (char &c: str) {
                                    c = std::toupper(c);
                                }
                                cout << "searching for " << str << endl;
                                for (auto *currentFlight: currentAirport->getListOfFlights()) {
                                    if (currentFlight->getFlightNumber() == str) {
                                        cout << "WEEHEE " << endl;
                                        tempFlight = currentFlight;
                                    }
                                }

                                tempFlight->getDepartureTime();

                                break;

                            }
                        }
                    } else if (option == 'F' || option == 'f') {
                        for (auto &currentFlight: collection->flights) {
                            currentFlight->getFlightNumber();
                        }
                        cout << "Which flight do you want to edit?" << endl;
                        cin >> str;
                        for (char &c: str) {
                            c = std::toupper(c);
                        }

                        for (auto &currentFlight: collection->flights) {
                            if (str == currentFlight->getFlightNumber()) {

                            }
                        }

                    }

                    delete tempFlight;
                }


                break;


            case 'c':
            case 'C': // Manage Crew
                cout << "Managing crew!" << endl;


                break;
            case 'd':
            case 'D': //Exit
            {
                ofstream fout("AirportData.dat");

                // Check if the file is successfully opened
                if (!fout) {
                    cerr << "Failed to open output file" << endl;
                    return 1;
                }

                for (auto currentCrew: collection->crew) {
                    collection->writeCrewProperties(fout);
                }
                fout << endl;

                for (auto currentAirport: collection->airports) {
                    collection->writeAirportProperties(fout);
                }
                fout << endl;

                for (auto currentFlight: collection->flights) {
                    collection->writeFlightProperties(fout);
                }
                fout << endl;


                delete collection;

                fout << endl;

                fout.close();
                cout << "Goodbye" << endl;
                return 0;
            }


            default:
                cout << "Unknown entry please try again" << endl;
                break;
        }

    }
    return 0;
}
