#include "bookings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100
#define BOOKINGS_FILE "data/bookings.dat"

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;

void addBooking(int flightId, const char* passengerName, int seatNumber) {
    if (bookingCount < MAX_BOOKINGS) {
        bookings[bookingCount].bookingId = bookingCount + 1;
        bookings[bookingCount].flightId = flightId;
        strncpy(bookings[bookingCount].passengerName, passengerName, 99);
        bookings[bookingCount].seatNumber = seatNumber;
        bookingCount++;
    } else {
        printf("Booking limit reached.\n");
    }
}

Booking* getBooking(int bookingId) {
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingId == bookingId) {
            return &bookings[i];
        }
    }
    return NULL;
}

void listBookings() {
    for (int i = 0; i < bookingCount; i++) {
        printf("Booking ID: %d, Flight ID: %d, Passenger: %s, Seat: %d\n",
               bookings[i].bookingId, bookings[i].flightId, bookings[i].passengerName, bookings[i].seatNumber);
    }
}

void saveBookingsToFile() {
    FILE *file = fopen(BOOKINGS_FILE, "wb");
    if (file == NULL) {
        perror("Failed to open bookings file for writing");
        return;
    }
    fwrite(&bookingCount, sizeof(int), 1, file);
    fwrite(bookings, sizeof(Booking), bookingCount, file);
    fclose(file);
}

void loadBookingsFromFile() {
    FILE *file = fopen(BOOKINGS_FILE, "rb");
    if (file == NULL) {
        perror("Failed to open bookings file for reading");
        return;
    }
    fread(&bookingCount, sizeof(int), 1, file);
    fread(bookings, sizeof(Booking), bookingCount, file);
    fclose(file);
}