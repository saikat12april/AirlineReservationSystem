#include "payments.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAYMENTS 100
#define PAYMENTS_FILE "data/payments.dat"

Payment payments[MAX_PAYMENTS];
int paymentCount = 0;

void addPayment(int bookingId, float amount) {
    if (paymentCount < MAX_PAYMENTS) {
        payments[paymentCount].paymentId = paymentCount + 1;
        payments[paymentCount].bookingId = bookingId;
        payments[paymentCount].amount = amount;
        paymentCount++;
    } else {
        printf("Payment limit reached.\n");
    }
}

Payment* getPayment(int paymentId) {
    for (int i = 0; i < paymentCount; i++) {
        if (payments[i].paymentId == paymentId) {
            return &payments[i];
        }
    }
    return NULL;
}

void listPayments() {
    for (int i = 0; i < paymentCount; i++) {
        printf("Payment ID: %d, Booking ID: %d, Amount: %.2f\n",
               payments[i].paymentId, payments[i].bookingId, payments[i].amount);
    }
}

void savePaymentsToFile() {
    FILE *file = fopen(PAYMENTS_FILE, "wb");
    if (file == NULL) {
        perror("Failed to open payments file for writing");
        return;
    }
    fwrite(&paymentCount, sizeof(int), 1, file);
    fwrite(payments, sizeof(Payment), paymentCount, file);
    fclose(file);
}

void loadPaymentsFromFile() {
    FILE *file = fopen(PAYMENTS_FILE, "rb");
    if (file == NULL) {
        perror("Failed to open payments file for reading");
        return;
    }
    fread(&paymentCount, sizeof(int), 1, file);
    fread(payments, sizeof(Payment), paymentCount, file);
    fclose(file);
}