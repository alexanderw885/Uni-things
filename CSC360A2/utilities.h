#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

typedef struct Customer Customer;
struct Customer
{
    int id;
    int class;
    int arrivalTime;
    int serviceTime;
};

void makeCust(Customer* head, char info[]);
double currTime(double start);

#endif