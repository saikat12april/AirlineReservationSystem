#ifndef BOOKINGS_H
#define BOOKINGS_H

typedef struct {
    int bookingId;
    int flightId;
    char passengerName[100];
    int seatNumber;
} Booking;

void addBooking(int flightId, const char* passengerName, int seatNumber);
Booking* getBooking(int bookingId);
void listBookings();
void saveBookingsToFile();
void loadBookingsFromFile();

#endif