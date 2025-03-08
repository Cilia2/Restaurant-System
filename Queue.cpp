#include "Queue.h"
#include "Stack.h"
#include "Order.h"

#include <stdexcept>
#include <iostream>
using namespace std;

Queue::Queue(){
    myFront = NULL; // initialize front of the queue to null 
    myBack = NULL; // initialize front of the queue to null 
    size = 0;
}

Queue::~Queue() {
    while (!empty()) {
        deleteOrder(); 
    }
}

bool Queue::empty() const{
    return (myFront == NULL);
}

void Queue::addOrder(const QElementType& value) {
    NodePtr newNode = new Node(value); // create a new node to add the element 

    if (empty()){
        // if the queue is empty assign myFront to myBack to the newNode
        myFront = myBack = newNode;
    } else {
        // assign the element after the last node
        myBack->next = newNode;
        //Update myBack
        myBack = newNode;
    }
    //Increment size
    size++;
}

QElementType Queue::front() const {
    if (empty()) {
        cerr << "Queue is empty!" << endl;
        throw std::runtime_error("Queue is empty! Cannot access front element.");
        //If it is empty assign a garbage value and return it
        QElementType garbage;
        return garbage;
    }
    // return first element data
    return myFront->data;
}

void Queue::deleteOrder() {
    if (empty()) {
        cerr << "Queue is empty! Can't remove new item." << endl;
        throw runtime_error("Cannot delete from an empty queue"); 
    }
    
    // Temp node oldFront to hold the value of the first element 
    NodePtr oldFront = myFront; 
    // Update myFront
    myFront = myFront->next;   

    if (myFront == NULL) {
        myBack = NULL;
    }

    // Delete temp node
    delete oldFront; 
    // decrement size
    size--;
}

void Queue::displayPendingOrders(ostream& out) const {
    for (NodePtr current = myFront; current != NULL; current = current->next) {
        out << current->data << "  ";
    }
    out << endl;
}

ostream& operator<<(ostream& out, const Queue& queue) {
    out << " --- Orders --- " << endl;
    queue.displayPendingOrders(out);
    return out;
}
