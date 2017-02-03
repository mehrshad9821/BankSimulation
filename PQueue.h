#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Queue.h"
#include "Node.h"

class PQueue : public Queue
{
	Node* head;
	bool compare(const Event& element1, const Event& element2) const;
public:
	PQueue();
	~PQueue();

	// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Inserts newElement in sort order.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is sorted.   
	// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.           
	bool enqueue(const Event& newElement);

	// Description: Removes the element with the "highest" priority.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is not empty.
	bool dequeue();

	// Description: Retrieves (but does not remove) the element with the "highest" priority.
	// Precondition: This Priority Queue is not empty.
	// Postcondition: This Priority Queue is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
	Event peek() const throw(EmptyDataCollectionException);
};