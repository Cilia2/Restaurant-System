/*-- RestaurantOrderManagementSystem.cpp-----------------------------------

   This file implements the member functions of the RestaurantOrderManagementSystem class.
-------------------------------------------------------------------------*/

#include "RestaurantOrderManagementSystem.h"
#include <iostream>
using namespace std;

//--- Definition of class constructor
RestaurantOrderManagementSystem::RestaurantOrderManagementSystem() {
    cout << "Loading menu from file..." << endl;
    menu.loadFromFile();
    cout << "Menu loaded successfully!" << endl;
}

//--- Definition of run()
void RestaurantOrderManagementSystem::run() {
    int choice;
    bool running = true;

    cout << "--- Restaurant Order Management System ---" << endl;

    while (running) {
        cout << "\n--- Restaurant Order Management System --- " << endl;
        cout << "1. Display Menu" << endl;
        cout << "2. Add Menu Item" << endl;
        cout << "3. Delete Menu Item" << endl;
        cout << "4. Reset Menu" << endl;
        cout << "5. Add New Order" << endl;
        cout << "6. Process Next Order" << endl;
        cout << "7. Display Orders" << endl;
        cout << "8. Delete Order" << endl;
        cout << "9. Calculate Total Amount of Sold Orders" << endl;
        cout << "10. Save Completed Orders to File" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayMenu();
                break;
            case 2: addMenuItem();
                break;
            case 3: deleteMenuItem();
                break;
            case 4: resetMenu();
                break;
            case 5: addNewOrder();
                break;
            case 6: processNextOrder();
                break;
            case 7: displayOrders();
                break;
            case 8: deleteOrder();
                break;
            case 9: calculateTotalRevenue();
                break;
            case 10: saveCompletedOrdersToFile();
                break;
            case 11:
                cout << "Exiting the system. Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

//--- Definition of displayMenu()
void RestaurantOrderManagementSystem::displayMenu() {
    menu.displayMenu(cout);
}

//--- Definition of addMenuItem()
void RestaurantOrderManagementSystem::addMenuItem() {
    menu.addMenuItem();
    menu.saveToFile();
}

//--- Definition of deleteMenuItem()
void RestaurantOrderManagementSystem::deleteMenuItem() {
    menu.deleteMenuItem();
    menu.saveToFile();
}

//--- Definition of resetMenu()
void RestaurantOrderManagementSystem::resetMenu() {
    menu.resetMenu();
    menu.saveToFile();
}

//--- Definition of addNewOrder()
void RestaurantOrderManagementSystem::addNewOrder() {
    string name;
    cout << "Enter customer name: ";
    cin >> name;

    Order order(name);

    cout << "Enter item IDs (0 to finish): ";
    int itemId;
    while (true) {
        cin >> itemId;
        if (itemId == 0) break;
        order.addItem(itemId, menu);
    }

    queue.addOrder(order);
    cout << "Order added successfully!" << endl;
}

//--- Definition of processNextOrder()
void RestaurantOrderManagementSystem::processNextOrder() {
    if (queue.empty()) {
        cerr << "No orders available!" << endl;
        return;
    }

    Order firstOrder = queue.front();
    firstOrder.setStatus("Completed");
    queue.deleteOrder();
    stack.push(firstOrder);

    cout << "Order for " << firstOrder.getCustomerName()
            << " moved to completed orders." << endl;
}

//--- Definition of displayOrders()
void RestaurantOrderManagementSystem::displayOrders() const {
    cout << "--- Pending Orders ---" << endl;
    cout << queue << endl;
    cout << "--- Completed Orders ---" << endl;
    cout << stack << endl;
}

//--- Definition of deleteOrder()
void RestaurantOrderManagementSystem::deleteOrder() {
    queue.deleteOrder();
}

//--- Definition of calculateTotalRevenue()
void RestaurantOrderManagementSystem::calculateTotalRevenue() const {
    cout << "Total Amount of Sold Orders: $"
            << stack.totalRevenue() << endl;
}

//--- Definition of saveCompletedOrdersToFile()
void RestaurantOrderManagementSystem::saveCompletedOrdersToFile() const {
    stack.saveOrdersToFile();
}
