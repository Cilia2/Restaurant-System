/*------------------------------------------------------------------------------
    Order.cpp
    This file implements Order member functions.
--------------------------------------------------------------------------------*/

#include "Order.h"
#include "Menu.h"
#include <stdexcept>

// Static member definition
int Order::id = 0;

//--- Definition of class no-arg constructor
Order::Order(){
    id = 0;
    status = "Pending";
}

//--- Definition of class with arg constructor
Order::Order(string customerName)
{
    setOrder(customerName);
    id++;
    status = "Pending";
}

//--- Definition of class destructor
Order::~Order()
{
    items.clear();
}

//--- Definition of getId()
int Order::getId() const
{
    return id;
}

//--- Definition of getCustomerName()
string Order::getCustomerName() const
{
    return customerName;
}

//--- Definition of getItems()
MenuItem *Order::getItems() const
{
    return items.getItems();
}

//--- Definition of getStatus()
string Order::getStatus() const
{
    return status;
}

//--- Definition of getSize()
int Order::getSize() const {
    return items.getSize();
}

//--- Definition of setCustomerName()
void Order::setCustomerName(string customerName)
{
    //Check if customer name is empty
    if (customerName.empty())
    {
        //If customer name is empty throw invalid argument exception
        throw std::invalid_argument("Customer name cannot be empty");
    }
    //Set customer name to the customer name given by user
    this->customerName = customerName;
}

//--- Definition of setStatus()
void Order::setStatus(string status)
{
    //Check if status is valid
    if (status != "pending" && status != "completed" && status != "cancelled")
    {
        //If status is not valid throw invalid argument exception
        throw std::invalid_argument("Invalid order status");
    }
    //Set status to the status given by user
    this->status = status;
}

//--- Definition of setOrder()
void Order::setOrder(string customerName)
{
    setCustomerName(customerName);
}

//--- Definition of display()
void Order::display(ostream &out) const
{
    out << "Order ID: " << getId() << endl;
    out << "Customer Name: " << getCustomerName() << endl;
    out << "Items: ";
    out << items;

    out << endl;
    out << "Status: " << getStatus() << endl;
}

//--- Definition of isEmpty()
bool Order::isEmpty() const
{
    return items.empty();
}

//--- Definition of addItem()
void Order::addItem(int id, const Menu &menu) {
    // Use findById to search for the MenuItem
    const MenuItem menuItem = menu.menuFindById(id);
    if (true) { //add condition
        items.insertatend(menuItem);
        cout << "Item with ID " << id << " added to the order." << endl;
    } else {
        // If not found, show an error
        cout << "Error: Item with ID " << id << " not found in the menu." << endl;
    }
}

//--- Definition of getItem()
MenuItem Order::getItem(int id) const {
    return items.getItem(id);
}

//--- Definition of totalPrice()
double Order::totalPrice() const
{
    return items.getTotalPrice();
}

ostream &operator<<(ostream &out, const Order &order)
{
    out << "--- Order ---" << endl;
    order.display(out); 
    return out;
}
