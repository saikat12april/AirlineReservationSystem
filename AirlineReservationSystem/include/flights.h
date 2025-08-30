#ifndef FLIGHTS_H
#define FLIGHTS_H

typedef struct {
    int flightId;
    char origin[100];
    char destination[100];
    int seatsAvailable;
} Flight;

void addFlight(const char* origin, const char* destination, int seatsAvailable);
Flight* getFlight(int flightId);
void listFlights();
void saveFlightsToFile();
void loadFlightsFromFile();

#endif