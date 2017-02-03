/*
 * filename: Event.cpp
 * 
 * Class Description: A data collection ADT class to satisfy Assn 2's requiremetns.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Getters and setters for the attributes "type", "time" and "length". 
 *                   
 *                 
 *
 * Creation date: 06/24/2016
 * Author: Mehrshad Matin & Baoer Li
 */
#include "Event.h"


Event::Event()
{
}

Event::Event(bool arrival, int arrivalTime, int transactionTime)
{
   this->arrival = arrival;
   this->time = arrivalTime;
   this->transactionTime = transactionTime;
}
   
bool Event::isArrival() const
{
   return arrival;
}

int Event::getTime() const
{
   return time;
}

int Event::getTransactionTime() const
{
   return transactionTime;
}
