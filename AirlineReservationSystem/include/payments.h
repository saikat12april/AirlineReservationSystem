#ifndef PAYMENTS_H
#define PAYMENTS_H

typedef struct {
    int paymentId;
    int bookingId;
    float amount;
} Payment;

void addPayment(int bookingId, float amount);
Payment* getPayment(int paymentId);
void listPayments();
void savePaymentsToFile();
void loadPaymentsFromFile();

#endif