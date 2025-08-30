#include "utils.h"
#include <stdio.h>

void displayMenu() {
    printf("1. Add Flight\n");
    printf("2. List Flights\n");
    printf("3. Add Booking\n");
    printf("4. List Bookings\n");
    printf("5. Add Payment\n");
    printf("6. List Payments\n");
    printf("7. Exit\n");
}

int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}