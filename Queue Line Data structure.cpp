

#include <iostream>
#include "clsQueueLine.h"

int main()
{
    clsQueueLine PayBillsQueue("P F", 12);

    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();

    PayBillsQueue.PrintQINFO();

}

