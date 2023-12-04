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

    auto *collection = new Collection();
    Time calendar;
    ifstream fin("AirportData.dat");

    if (!fin.is_open()) {
        cerr << "Failed to open AirportData.dat" << endl;
        return 1;
    } else {
        cout << "AirportData is open" << endl;
    }


    string readingLine;
    string role;
    char option;
    string crewSearchWord = "Crew";
    string airportSearchWord = "Passenger";
    string flightSearchWord = "Flight";

    cout << "\n\n";
    while (getline(fin, readingLine)) {

        cout << "Reading line: " << readingLine << endl;


        if (!readingLine.empty() && readingLine[0] == '#') {
            cout << "This line is going to be skipped" << endl;
            cout << "\n";
            continue;

        }

        istringstream lineStream(readingLine);
        getline(lineStream, role, ',');
        cout << "Role: " << role << endl;

        if (role == airportSearchWord) {
            cout << "airportSearchWord is being used" << endl;
            collection->readAirportProperties(readingLine);
        } else if (role == crewSearchWord) {
            collection->readCrewProperties(readingLine);
        } else if (role == flightSearchWord) {
            collection->readFlightProperties(readingLine);
        }
        cout << "\n";
    }





    cout << "Airport size: " << collection->airports.size() << endl;
    cout << "Flight size: " << collection->flights.size() << endl;
    cout << "Crew size: " << collection->crew.size() << endl;


    fin.clear();
    fin.seekg(0, ios::beg);

    while (true) {


        cout << "     ____                  _               ____                             _  \n"
                "    / ___|   _ _ __  _ __ (_)_ __   __ _  | __ ) _   _ __________ _ _ __ __| | \n"
                "   | |  | | | | '_ \\| '_ \\| | '_ \\ / _` | |  _ \\| | | |_  /_  / _` | '__/ _` | \n"
                "   | |__| |_| | | | | | | | | | | | (_| | | |_) | |_| |/ / / / (_| | | | (_| | \n"
                "    \\____\\__,_|_| |_|_| |_|_|_| |_|\\__, |_|____/ \\__,_/___/___\\__,_|_|  \\__,_| \n"
                "                            / \\  (_)___/| (_)_ __   ___  ___                   \n"
                "                           / _ \\ | | '__| | | '_ \\ / _ \\/ __|                  \n"
                "                          / ___ \\| | |  | | | | | |  __/\\__ \\                  \n"
                "                         /_/   \\_\\_|_|  |_|_|_| |_|\\___||___/          " << endl;

        cout << "| ********************************* Main Menu *************************************** |" << endl;
        cout << "| ** A.    View Flights   ** |" << "| ** B.   Manage Flights  ** |" << "| ** C.     Exit       ** |"
             << endl;;
        cout << "| *********************************************************************************** |" << endl;


        cin >> option;

        switch (option) {
            case 'A':
            case 'a': // View Flights
            {
                cout << "Which airport would you like to view " << endl;
                for (auto *currentAirport: collection->airports) {
                    cout << currentAirport->getAirportName() << endl;
                }

                cout << "Which day would you like to view? " << endl;
                string today = calendar.getToday();
                cout << "Today (" << today << "), ";

                // Display the next 6 days
                for (int i = 1; i <= 6; ++i) {
                    int nextDayIndex = (calendar.getDayIndex(today) + i) % 7;
                    cout << calendar.daysOfTheWeek[nextDayIndex] << ((i < 6) ? ", " : "\n");
                }

            }
                break;


            case 'B':
            case 'b': // Manage Flights


                cout << "Which airport would you like to manage " << endl;
                for (auto *currentAirport: collection->airports) {
                    cout << currentAirport->getAirportName() << endl;
                }
                cout << "Which day would you like to manage? " << endl;
                break;


            case 'c':
            case 'C': // Exit
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
