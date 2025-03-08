/*-- RestaurantOrderManagementSystem.h -----------------------------------

This header file defines a RestaurantOrderManagementSystem data type.
  Basic operations:
    displayMenu: Displays all menu items
    addMenuItem: Adds a new item to the menu
    deleteMenuItem: Deletes an item from the menu
    resetMenu: Resets the entire menu
    addNewOrder: Adds a new order
    processNextOrder: Processes the next order in the queue
    displayOrders: Displays all pending and completed orders
    deleteOrder: Deletes an order from the pending orders queue
    calculateTotalRevenue: Calculates the total revenue from completed orders
    saveCompletedOrdersToFile: Saves completed orders to a file
    constructor: Constructs a RestaurantOrderManagementSystem object
    run: Runs the Restaurant Order Management System
-------------------------------------------------------------------------*/

#ifndef RESTAURANTORDERSYSTEM_H
#define RESTAURANTORDERSYSTEM_H

#include "Menu.h"
#include "Queue.h"
#include "Stack.h"

class RestaurantOrderManagementSystem {
private:
  Menu menu; // Menu object to manage menu items
  Queue queue; // Queue to manage pending orders
  Stack stack; // Stack to manage completed orders

  /***** Display the menu *****/
  void displayMenu();

  /*----------------------------------------------------------------------
    Display all menu items.

    Precondition: None.
    Postcondition: All menu items are displayed to the user.
  -----------------------------------------------------------------------*/

  /***** Add a menu item *****/
  void addMenuItem();

  /*----------------------------------------------------------------------
    Add a new item to the menu.

    Precondition: User provides details of the new menu item.
    Postcondition: The new menu item is added to the menu and saved to file.
  -----------------------------------------------------------------------*/

  /***** Delete a menu item *****/
  void deleteMenuItem();

  /*----------------------------------------------------------------------
    Delete an item from the menu.

    Precondition: User provides the ID of the item to be deleted.
    Postcondition: The item is deleted from the menu and the menu is saved to file.
  -----------------------------------------------------------------------*/

  /***** Reset the menu *****/
  void resetMenu();

  /*----------------------------------------------------------------------
    Reset the entire menu.

    Precondition: None.
    Postcondition: All items are removed from the menu.
  -----------------------------------------------------------------------*/

  /***** Add a new order *****/
  void addNewOrder();

  /*----------------------------------------------------------------------
    Add a new order.

    Precondition: User provides customer name and item IDs for the order.
    Postcondition: The new order is added to the queue of pending orders.
  -----------------------------------------------------------------------*/

  /***** Process the next order *****/
  void processNextOrder();

  /*----------------------------------------------------------------------
    Process the next order in the queue.

    Precondition: There are pending orders in the queue.
    Postcondition: The next order is processed and moved to the stack of completed orders.
  -----------------------------------------------------------------------*/

  /***** Display all orders *****/
  void displayOrders() const;

  /*----------------------------------------------------------------------
    Display all pending and completed orders.

    Precondition: None.
    Postcondition: All orders are displayed to the user.
  -----------------------------------------------------------------------*/

  /***** Delete an order *****/
  void deleteOrder();

  /*----------------------------------------------------------------------
    Delete an order from the pending orders queue.

    Precondition: There are pending orders in the queue.
    Postcondition: The first order in the queue is deleted.
  -----------------------------------------------------------------------*/

  /***** Calculate total revenue *****/
  void calculateTotalRevenue() const;

  /*----------------------------------------------------------------------
    Calculate the total revenue from completed orders.

    Precondition: None.
    Postcondition: The total revenue is calculated and displayed to the user.
  -----------------------------------------------------------------------*/

  /***** Save completed orders to file *****/
  void saveCompletedOrdersToFile() const;

  /*----------------------------------------------------------------------
    Save completed orders to a file.

    Precondition: None.
    Postcondition: All completed orders are saved to a file.
  -----------------------------------------------------------------------*/

public:
  /***** Class constructor *****/
  RestaurantOrderManagementSystem();

  /*----------------------------------------------------------------------
    Construct a RestaurantOrderManagementSystem object.

    Precondition: None.
    Postcondition: The menu is loaded from file and the system is ready to use.
  -----------------------------------------------------------------------*/

  /***** Entry point for managing the system *****/
  void run();

  /*----------------------------------------------------------------------
    Run the Restaurant Order Management System.

    Precondition: None.
    Postcondition: The system runs, allowing the user to manage menu items and orders.
  -----------------------------------------------------------------------*/
};

#endif // RESTAURANTORDERSYSTEM_H
