#ifndef STACK
#define STACK

#include <iostream>
#include <fstream>
using namespace std;

#include "Order.h"
#include "Queue.h"

typedef Order SElementType;

class Stack {
private:
    class Node {
    public: 
        Node(SElementType data, Node* next = NULL) : data(data), next(next) {}
        SElementType data; // Data stored in the node
        Node* next;        // Pointer to the next node in the stack
    };
    typedef Node* NodePtr;

    NodePtr myTop; // Pointer to the top node of the stack

public:

    /***** Class constructor *****/
    Stack();
/*------------------------------------------------------------------------------
        Initializes an empty stack

        Precondition: None
        Postcondition: A Stack object is created with no elements, and myTop is 
                       initialized to NULL
--------------------------------------------------------------------------------*/

    /***** Class destructor *****/
    ~Stack();
/*------------------------------------------------------------------------------
        Destroys the stack and releases allocated memory

        Precondition: None
        Postcondition: All nodes in the stack are deallocated, leaving the stack empty
--------------------------------------------------------------------------------*/

    bool empty() const;
/*------------------------------------------------------------------------------
        Checks if the stack is empty

        Precondition: None
        Postcondition: Returns true if the stack contains no elements, false otherwise
--------------------------------------------------------------------------------*/

    void push(const SElementType& value);
/*------------------------------------------------------------------------------
        Pushes a new element onto the stack

        Precondition: The value to be added must be valid
        Postcondition: A new node containing the value is added to the top 
                       of the stack
--------------------------------------------------------------------------------*/

    SElementType top() const;
/*------------------------------------------------------------------------------
        Retrieves the top element of the stack

        Precondition: The stack must not be empty
        Postcondition: Returns the element at the top of the stack
--------------------------------------------------------------------------------*/

    void pop();
/*------------------------------------------------------------------------------
        Removes the top element from the stack

        Precondition: The stack must not be empty
        Postcondition: The top node is removed, memory is deallocated, and 
                       myTop points to the next node
--------------------------------------------------------------------------------*/

    double totalRevenue() const;
/*------------------------------------------------------------------------------
        Calculates the total revenue of completed orders stored in the stack

        Precondition: None
        Postcondition: Returns the sum of revenue for all orders in the stack
--------------------------------------------------------------------------------*/

    void displayCompletedOrders(ostream& out) const;
/*------------------------------------------------------------------------------
        Displays all completed orders in the stack

        Precondition: None
        Postcondition: Outputs all the elements in the stack to the provided 
                       output stream
--------------------------------------------------------------------------------*/

    void saveOrdersToFile() const;
/*------------------------------------------------------------------------------
        Saves all completed orders to a file

        Precondition: A valid file path must be accessible for writing
        Postcondition: Writes all orders in the stack to the file in a specified format
--------------------------------------------------------------------------------*/
};

ostream &operator<<(ostream &out, const Stack &stack);

#endif
