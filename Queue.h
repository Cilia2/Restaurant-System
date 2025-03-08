#ifndef QUEUE_H
#define QUEUE_H

#include "Order.h"

class Stack;

#include <iostream>
using namespace std;

typedef Order QElementType;

class Queue {
private:
    class Node {
    public:
        Node(QElementType data) : data(data), next(NULL) {}
        QElementType data; // Data of the node, of type QElementType
        Node* next;        // Pointer to the next node in the queue
    };
    typedef Node* NodePtr;

    NodePtr myFront;  // Pointer to the front of the queue
    NodePtr myBack;   // Pointer to the back of the queue
    int size;         // Current size of the queue

public:
    
    /***** Class constructor *****/
    Queue();
/*------------------------------------------------------------------------------
        Initializes an empty queue

        Precondition: None
        Postcondition: A Queue object is created with no elements, 
                       and size is initialized to 0
--------------------------------------------------------------------------------*/

    /***** Class destructor *****/
    ~Queue();
/*------------------------------------------------------------------------------
        Destroys the queue and releases allocated memory

        Precondition: None
        Postcondition: All nodes in the queue are deallocated, 
                       leaving the queue empty
--------------------------------------------------------------------------------*/

    bool empty() const;
/*------------------------------------------------------------------------------
        Checks if the queue is empty

        Precondition: None
        Postcondition: Returns true if the queue contains no elements, 
                       false otherwise
--------------------------------------------------------------------------------*/
    
    void addOrder(const QElementType& value);
/*------------------------------------------------------------------------------
        Adds an order to the back of the queue

        Precondition: The value to be added must be valid
        Postcondition: A new node containing the value is added to the back 
                       of the queue, and size is incremented
--------------------------------------------------------------------------------*/

    QElementType front() const;
/*------------------------------------------------------------------------------
        Retrieves the front element of the queue

        Precondition: The queue must not be empty
        Postcondition: Returns the element at the front of the queue 
--------------------------------------------------------------------------------*/

    void deleteOrder();
/*------------------------------------------------------------------------------
        Removes the front element from the queue

        Precondition: The queue must not be empty
        Postcondition: The front node is removed, memory is deallocated, 
                       and size is decremented
--------------------------------------------------------------------------------*/

    void displayPendingOrders(ostream& out) const;
/*------------------------------------------------------------------------------
        Displays all pending orders in the queue

        Precondition: None
        Postcondition: Outputs all the elements in the queue to the provided 
                       output stream
--------------------------------------------------------------------------------*/
};

ostream &operator<<(ostream &out, const Queue &queue);

#endif
