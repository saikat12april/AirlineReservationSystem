#include "flights.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define FLIGHTS_FILE "data/flights.dat"

Flight flights[MAX_FLIGHTS];
int flightCount = 0;

void addFlight(const char* origin, const char* destination, int seatsAvailable) {
    if (flightCount < MAX_FLIGHTS) {
        flights[flightCount].flightId = flightCount + 1;
        strncpy(flights[flightCount].origin, origin, 99);
        strncpy(flights[flightCount].destination, destination, 99);
        flights[flightCount].seatsAvailable = seatsAvailable;
        flightCount++;
    } else {
        printf("Flight limit reached.\n");
    }
}

Flight* getFlight(int flightId) {
    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightId == flightId) {
            return &flights[i];
        }
    }
    return NULL;
}

void listFlights() {
    for (int i = 0; i < flightCount; i++) {
        printf("Flight ID: %d, Origin: %s, Destination: %s, Seats Available: %d\n",
               flights[i].flightId, flights[i].origin, flights[i].destination, flights[i].seatsAvailable);
    }
}

void saveFlightsToFile() {
    FILE *file = fopen(FLIGHTS_FILE, "wb");
    if (file == NULL) {
        perror("Failed to open flights file for writing");
        return;
    }
    fwrite(&flightCount, sizeof(int), 1, file);
    fwrite(flights, sizeof(Flight), flightCount, file);
    fclose(file);
}

void loadFlightsFromFile() {
    FILE *file = fopen(FLIGHTS_FILE, "rb");
    if (file == NULL) {
        perror("Failed to open flights file for reading");
        return;
    }
    fread(&flightCount, sizeof(int), 1, file);
    fread(flights, sizeof(Flight), flightCount, file);
    fclose(file);
}