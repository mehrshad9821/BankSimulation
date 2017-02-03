#pragma once

#include "Event.h"
#include "EmptyDataCollectionException.h"

class Queue
{
	Event eventsArray[100];
	int head;
	int tail;
public:
	// Description: contructor
	Queue();

	// Description: Returns "true" is this queue is empty, otherwise "false".
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Adds newElement to the "back" of this queue and 
	//              returns "true" if successful, otherwise "false".
	// Time Efficiency: O(1)
	bool enqueue(const Event& newElement);

	// Description: Removes the element at the "front" of this queue and 
	//              returns "true" if successful, otherwise "false".
	// Precondition: This queue is not empty.
	// Time Efficiency: O(1)
	bool dequeue();

	// Description: Retrieves (but does not remove) the element at the  
	//              "front" of this queue and returns it.
	// Precondition: This queue is not empty.
	// Postcondition: This queue is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
	// Time Efficiency: O(1)
	Event peek() const throw(EmptyDataCollectionException); 
};