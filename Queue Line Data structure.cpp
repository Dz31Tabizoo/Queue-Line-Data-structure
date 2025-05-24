

#include <iostream>
#include "clsQueueLine.h"

int main()
{
    clsQueueLine PayBillsQueue("PB", 12);

    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();
    PayBillsQueue.IssueTickets();

    PayBillsQueue.PrintQINFO();

    PayBillsQueue.PrintTicketsFromLTRendRTL();

    PayBillsQueue.PrintAllTickets();

    PayBillsQueue.ServNextClient();
    PayBillsQueue.ServNextClient();

    cout << "\n\n Que info after serv 2 clients " << endl;
    PayBillsQueue.PrintQINFO();
}

