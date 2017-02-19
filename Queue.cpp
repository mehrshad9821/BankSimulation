/*
 * filename: Queue.cpp
 * 
 * Class Description: A data collection ADT class to satisfy Assn 2's requiremetns.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Class invariants: FIFO or LILO
 *                   - Once it has been ascertained that the element has not already been 
 *                     inserted, its data structure allows insertion in O(1)
 *                   - Once the element to be removed as been found, 
 *                     its data structure allows removal in O(1).
 *                		
 *
 * Creation date: 06/24/2016
 * Author: Mehrshad Matin 
 */
#include "Queue.h"

// Description: contructor
Queue::Queue()
{
	head = 0;
	tail = 0;
}

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool Queue::isEmpty() const
{
	return head == tail;
}

// Description: Adds newElement to the "back" of this queue and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue(const Event& newElement)
{
	if (tail+1!=head)
	{
		eventsArray[tail]  = newElement;
		tail++;
		tail = tail % 100; 
		return true;
	}
	return false;
}

// Description: Removes the element at the "front" of this queue and 
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool Queue::dequeue()
{
	if (!isEmpty())
	{
		head++;
		head = head % 100;
		return true;
	}
	return false;
}

// Description: Retrieves (but does not remove) the element at the  
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event Queue::peek() const throw(EmptyDataCollectionException)
{	
	if (isEmpty())
		throw EmptyDataCollectionException();
	else	
		return eventsArray[head];
}
