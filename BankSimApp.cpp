/*
 * filename: BankSimApp.cpp
 * 
 * Class Description: A data collection ADT class to satisfy Assn 2's requiremetns.
 * Class Invariant: Data collection with the following characteristics:
 *                   -Determines the times at which events occur and to process the events when they do occur.
 *					 -Simulation is event driven
 *
 *
 * Creation date: 06/24/2016
 * Author: Mehrshad Matin
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "PQueue.h"
#include "Event.h"


bool tellerAvailable = true;
int currentTime = 0;
int peopleNumber = 0;
int totalWaiting = 0;


void simulate();
void processArrival(Event arrivalEvent, PQueue& eventListPQueue, Queue& bankQueue);
void processDeparture(Event departureEvent, PQueue& eventListPQueue, Queue& bankQueue);

int main()
{
	simulate();
	return 0;
}

void simulate()
{
	//Create an empty queue bankQueue to represent the bank line
	Queue bankQueue;
	//Create an empty priority queue eventListPQueue for the event list
	PQueue eventListPQueue;
	
	tellerAvailable = true;
	peopleNumber = 0;
	totalWaiting = 0;

	int arrivalTime, transactionTime;
	// Create and add arrival events to event list
	while (cin >> arrivalTime >> transactionTime)
	{
		// Get next arrival time a and transaction time t from file
		Event newArrivalEvent(true, arrivalTime, transactionTime);
		eventListPQueue.enqueue(newArrivalEvent);
	}
	
	// Event loop
	cout << "Simulation Begins" << endl;
	while (!eventListPQueue.isEmpty())
	{
		Event newEvent = eventListPQueue.peek();
		// Get current time
		currentTime = newEvent.getTime();
		if (newEvent.isArrival())
			processArrival(newEvent, eventListPQueue, bankQueue);
		else
			processDeparture(newEvent, eventListPQueue, bankQueue);
	}
	cout << "Simulation Ends" << endl;	

	cout << endl << "Final Statistics:  " << endl;
	cout << "\tTotal number of people processed: " << peopleNumber << endl;
	cout << "\tAverage amount of time spent waiting: " << (double)totalWaiting / (double)peopleNumber << endl;
}

// Processes an arrival event.
void processArrival(Event arrivalEvent, PQueue& eventListPQueue, Queue& bankQueue)
{
	cout << "Processing an arrival event at time:  " << setw(3) << right << arrivalEvent.getTime() << endl;
	peopleNumber++;
	
	// Remove this event from the event list
	eventListPQueue.dequeue();
	Event customer(true, arrivalEvent.getTime(), arrivalEvent.getTransactionTime());
	if (bankQueue.isEmpty() && tellerAvailable)
	{
		int departureTime = currentTime + arrivalEvent.getTransactionTime();
		Event newDepartureEvent(false, departureTime, 0);
		eventListPQueue.enqueue(newDepartureEvent);
		tellerAvailable = false;
	}
	else
	{		
		bankQueue.enqueue(customer);
	}
}

// Processes a departure event .
void processDeparture(Event departureEvent, PQueue& eventListPQueue, Queue& bankQueue)
{
	cout << "Processing a departure event at time: " << setw(3) << right << departureEvent.getTime() << endl;

	// Remove this event from the event list
	eventListPQueue.dequeue();
	if (!bankQueue.isEmpty())
	{
		// Customer at front of line begins transaction
		Event customer = bankQueue.peek();
		bankQueue.dequeue();
		int departureTime = currentTime + customer.getTransactionTime();
		if (currentTime - customer.getTime()>0)
			totalWaiting += currentTime - customer.getTime();
		Event newDepartureEvent = Event(false, departureTime, 0);
		eventListPQueue.enqueue(newDepartureEvent);
	}
	else
		tellerAvailable = true;
}
