#include <iostream>
using namespace std;

#include "Stack.h"
#include "Queue.h"
#include "Order.h"

Stack::Stack() {
    myTop = NULL; // Set the top pointer to NULL
} 

Stack::~Stack() {
    while (!empty()) { // Loop until the stack is empty
        pop(); // Remove elements one by one
    }
}

bool Stack::empty() const{ 
    return (myTop == NULL); 
}

void Stack::push(const SElementType& value) {
    // Create a new node with the value and link it to the current top
    NodePtr newNode = new Node(value, myTop);
    myTop = newNode; // Update the top pointer to the new node
}

SElementType Stack::top() const {
    if (!empty()) { // Check if the stack is not empty
        return myTop->data; // Return the data of the top node
    } else {
        cerr << "Stack is empty" << endl; // Error message if stack is empty
        return SElementType(); // Return a default-constructed SElementType
    }
}

void Stack::pop() {
    if (!empty()) {
        NodePtr oldTop = myTop; // Save the current top node
        myTop = myTop->next; // Update the top pointer to the next node
        delete oldTop; // Deallocate the old top node
    } else {
        cerr << "Stack is empty! Can't remove a value\n";
    }
}

double Stack::totalRevenue() const {
    NodePtr loopNode = myTop; // Start from the top of the stack
    double totalRevenue = 0.0; 
    while (loopNode != NULL) { // Traverse the stack
        totalRevenue += loopNode->data.totalPrice(); // Add the total price of the order
        loopNode = loopNode->next; // Move to the next node
    }
    return totalRevenue; // Return the calculated total revenue
}

void Stack::displayCompletedOrders(ostream& out) const {
    for (NodePtr current = myTop; current != NULL; current = current->next) {
        out << current->data << endl;
    }
}

void Stack::saveOrdersToFile() const{
    ofstream orderFile; // Create an ofstream object

    orderFile.open("completed_orders.txt"); // Open the file for writing

    if (!orderFile.is_open()) { // Check if the file was opened successfully
        cerr << "Error: Unable to open file" << endl; // Error message if file can't be opened
        return;
    }

    NodePtr loopNode = myTop; // Start from the top of the stack
    while (loopNode != NULL) {
        // Write the order details to the file
        orderFile << "Order id"<<loopNode->data.getId() << ", Customer Name : " 
                << loopNode->data.getCustomerName() << ",\nItems :\n";

        MenuItem* items = loopNode->data.getItems(); // Retrieve the items in the order
        int numItems = loopNode->data.getSize(); // Get the number of items in the order
        DynamicArrayList temp; // Temporary list to store items 
        for (int i = 0; i < numItems; ++i) {
            temp.insertatend(items[i]); // Add each item to the temporary list
        }
     
        for(int i = 0; i < numItems; i++) {
            orderFile << temp.getItem(i) << endl; // Write each item to the file
        }

        orderFile << endl; // Add a blank line between orders
        loopNode = loopNode->next;  // Move to the next node
    }
    
    orderFile.close(); // Close the file
    cout << "Orders saved successfully!" << endl; // Confirmation message
}

ostream& operator<<(ostream& out, const Stack& stack) {
    out << " --- Orders --- " << endl;
    stack.displayCompletedOrders(out);
    return out;
}
