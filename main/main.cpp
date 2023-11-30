#include <iostream>
#include <fstream>
#include "Collection.h"
using namespace std;



int main() {

    auto *collection = new Collection();
    ifstream fin("AirportData.dat");

    string readingLine;
    string role;
    char option;
    string driverSearchWord = "Crew";
    string passengerSearchWord = "Passenger";
    string rideSearchWord = "Flight";

    while (fin >> readingLine) {
        role = readingLine.substr(0, readingLine.find(','));

        {
            if (role == driverSearchWord) {

                collection->readAirportProperties(readingLine);

            } else if (role == rideSearchWord) {

                collection->readCrewProperties(readingLine);

            } else if (role == passengerSearchWord) {

                collection->readFlightProperties(readingLine);

            }
        }
    };

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
                "                         /_/   \\_\\_|_|  |_|_|_| |_|\\___||___/          "<< endl;

        cout << "| ********************************* Main Menu *************************************** |" << endl;
        cout << "| ** A.    View Flights   ** |" << "| ** B.   Manage Flights  ** |" << "| ** C.     Exit       ** |" << endl; ;
        cout << "| *********************************************************************************** |" << endl;


        cin >> option;

        switch (option) {
            case 'A':
            case 'a': // View Flights
                cout << "For which day would you like to view? " << endl;



                break;


            case 'B':
            case 'b': // Manage Flights



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
