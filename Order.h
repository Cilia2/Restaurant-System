#ifndef ORDER_H
#define ORDER_H

#include <stdexcept>
#include <iostream>
using namespace std;

#include "MenuItem.h"
#include "DynamicArrayList.h"
#include "Menu.h"

class Order
{
private:
    /******** Data Members ********/
    static int id;    // Id of the order
    string customerName;  // Name of the customer that made the order
    DynamicArrayList items;  // Array of the menu items the customer ordered
    string status;     // Status of the order

public:
    /******** Function Members ********/
    
    /***** Class constructor *****/
    Order();
/*------------------------------------------------------------------------------
        Construct an order object.

        Precondition:  None
        Postcondition: An empty Order object is constructed; Id initialized to 0;
                       Status is pending
--------------------------------------------------------------------------------*/
    
    /***** Class constructor *****/
    Order(string);
/*------------------------------------------------------------------------------
        Construct a Order object with string customer name given by the user.

        Precondition:  Customer name is taken as a non empty string
        Postcondition: An order is constructed with the customer name given by
                       the user; Id is incremented automatically; Status is set
                       to pending
--------------------------------------------------------------------------------*/
    
    /***** Class destructor *****/
    ~Order();
/*------------------------------------------------------------------------------
        Destroys an order object

        Precondition:  The life of an order object is over.
        Postcondition: The memory dynamically allocated by the constructor
                       for the order pointed has been returned to the heap.
--------------------------------------------------------------------------------*/
    
    /***** Getter *****/
    int getId() const;
/*------------------------------------------------------------------------------
        Get Id of the order

        Precondition:  None
        Postcondition: Return the id of the corresponding order
--------------------------------------------------------------------------------*/   
    
    /***** Getter *****/
    string getCustomerName() const;
/*------------------------------------------------------------------------------
        Get customer name of the order

        Precondition:  None
        Postcondition: Return the name of the customer that place the order
--------------------------------------------------------------------------------*/
    
    /***** Getter *****/
    MenuItem *getItems() const;
/*------------------------------------------------------------------------------
        Get menu items of the order

        Precondition:  None
        Postcondition: Return the pointer to the array of menu items in this order
--------------------------------------------------------------------------------*/
    
    /***** Getter *****/
    string getStatus() const;
/*------------------------------------------------------------------------------
        Get status of the order

        Precondition:  None
        Postcondition: Return the status of the order
--------------------------------------------------------------------------------*/
    
    /***** Getter *****/
    int getSize() const;
/*------------------------------------------------------------------------------
        Get size of the menu item array

        Precondition:  None
        Postcondition: Return the size of the array menu items
--------------------------------------------------------------------------------*/
    
    /***** Getter *****/
    MenuItem getItem(int i) const;
/*------------------------------------------------------------------------------
        Get item by id

        Precondition:  None
        Postcondition: Return the name of the customer that place the order
--------------------------------------------------------------------------------*/
    
    /***** Is empty *****/
    bool isEmpty() const;
/*------------------------------------------------------------------------------
        Check if the menu item array is empty

        Precondition:  None
        Postcondition: Return true if it is empty (mySize = 0) and false otherwise
--------------------------------------------------------------------------------*/
    
    /***** Total price *****/
    double totalPrice() const;
/*------------------------------------------------------------------------------
        Get the total price of the order

        Precondition:  None
        Postcondition: Return the total price of of the order according to the
                       menu items ordered
--------------------------------------------------------------------------------*/
    
    /***** Setter *****/
    void setCustomerName(string);
/*------------------------------------------------------------------------------
        Set customer name of the order

        Precondition: Customer name is taken as a non empty string
        Postcondition: Set the name of the customer to the object if it is valid;
                       If it is not valid throw an invalid argument exception
--------------------------------------------------------------------------------*/
    
    /***** Setter *****/
    void setStatus(string status);
/*------------------------------------------------------------------------------
        Set status of the order

        Precondition: Status is taken as a non empty string 
        Postcondition: Set the status of the order to the object if it is valid 
                       ("pending", "completed", "cancelled");
                       If it is not valid throw an invalid argument exception
--------------------------------------------------------------------------------*/
    
    /***** Setter *****/
    void setOrder(string);
/*------------------------------------------------------------------------------
        Sets the order

        Precondition: Customer name is taken as a non empty string 
        Postcondition: Calls the setCustomerName to check if the name is valid;
                       Id will increment automatically; 
                       Status will me set to pending for new orders
--------------------------------------------------------------------------------*/

    /***** Add item *****/
    void addItem(int id, const Menu &menu);
/*------------------------------------------------------------------------------
        Adds an item from the menu to the order

        Precondition: Id of the item that needs to be added; 
                      The address of the array of menu items of the corresponding order
        Postcondition: Searches in the menu for the item by the given id, 
                       if it exists we insert at the end of the menuItem array 
                       the new item that the customer wants to add
--------------------------------------------------------------------------------*/
    
    /***** Display *****/
    void display(ostream &out) const;
/*------------------------------------------------------------------------------
        Display the Order.

        Precondition: The ostream out is open.
        Postcondition: The Order object has been inserted into out.
--------------------------------------------------------------------------------*/
};
ostream &operator<<(ostream &out, const Order &order);

#endif
