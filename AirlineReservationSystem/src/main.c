#include <stdio.h>
#include <stdlib.h>
#include "flights.h"
#include "bookings.h"
#include "payments.h"
#include "utils.h"

int main() {
    // Load data from files
    loadFlightsFromFile();
    loadBookingsFromFile();
    loadPaymentsFromFile();

    int choice;
    do {
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1: {
                char origin[100], destination[100];
                int seats;
                printf("Enter origin: ");
                scanf("%s", origin);
                printf("Enter destination: ");
                scanf("%s", destination);
                printf("Enter seats available: ");
                scanf("%d", &seats);
                addFlight(origin, destination, seats);
                break;
            }
            case 2:
                listFlights();
                break;
            case 3: {
                int flightId, seatNumber;
                char passengerName[100];
                printf("Enter flight ID: ");
                scanf("%d", &flightId);
                printf("Enter passenger name: ");
                scanf("%s", passengerName);
                printf("Enter seat number: ");
                scanf("%d", &seatNumber);
                addBooking(flightId, passengerName, seatNumber);
                break;
            }
            case 4:
                listBookings();
                break;
            case 5: {
                int bookingId;
                float amount;
                printf("Enter booking ID: ");
                scanf("%d", &bookingId);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addPayment(bookingId, amount);
                break;
            }
            case 6:
                listPayments();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    // Save data to files before exiting
    saveFlightsToFile();
    saveBookingsToFile();
    savePaymentsToFile();

    return 0;
}