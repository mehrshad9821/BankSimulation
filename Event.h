#pragma once

class Event
{
   bool arrival;
   int time;
   int transactionTime;

public:
   Event();
   Event(bool arrival, int arrivalTime, int transactionTime);

   bool isArrival() const;
   int getTime() const;
   int getTransactionTime() const;
};
