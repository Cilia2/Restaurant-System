#ifndef MENU_H
#define MENU_H

#include "DynamicArrayList.h"
#include <fstream>
#include <iostream>

using namespace std;

class Menu
{
private:
    DynamicArrayList items; // Dynamic array to manage menu items

public:
    
    /***** Class constructor *****/
    Menu();
/*------------------------------------------------------------------------------
        Initializes an empty menu

        Precondition: None
        Postcondition: A Menu object is created with an empty dynamic 
                       array of menu items
--------------------------------------------------------------------------------*/
    
    void loadFromFile();   
/*------------------------------------------------------------------------------
        Load menu items from file

        Precondition: The file containing the menu items must exist 
                      and be in a valid format to load
        Postcondition: The menu items are loaded from the file 
                       into the DynamicArrayList (stored in the items attribute)
--------------------------------------------------------------------------------*/
    
    void saveToFile() const;
/*------------------------------------------------------------------------------
        Save menu items to file

        Precondition: The items attribute contains valid menu items
        Postcondition: The current menu items are saved to a file in a specified format
--------------------------------------------------------------------------------*/

    void addMenuItem();  
/*------------------------------------------------------------------------------
        Add a new menu item to the menu

        Precondition: The menu item to be added must be valid and properly constructed
        Postcondition: A new menu item is added to the items array.
--------------------------------------------------------------------------------*/
    
    void deleteMenuItem(); 
/*------------------------------------------------------------------------------
        Delete a menu item from the menu

        Precondition: A valid menu item index must be provided.
        Postcondition: The menu item at the specified index is removed from the items array.
--------------------------------------------------------------------------------*/
    
    void resetMenu();
/*------------------------------------------------------------------------------
        Reset the entire menu

        Precondition: None
        Postcondition: All menu items are removed from the items array, 
                       effectively resetting the menu.
--------------------------------------------------------------------------------*/
    
    MenuItem *getItems() const;
/*------------------------------------------------------------------------------
        Get the array of menu items

        Precondition: None
        Postcondition: Returns a pointer to the array of menu items, 
                       allowing access to the current menu items
--------------------------------------------------------------------------------*/
    
    MenuItem menuFindById(int index) const;
/*------------------------------------------------------------------------------
        Find a menu item by its ID

        Precondition: The index must be a valid index in the array of menu items
        Postcondition: Returns the MenuItem at the specified index.
--------------------------------------------------------------------------------*/
    
    bool isEmpty() const;
/*------------------------------------------------------------------------------
        Check if the menu is empty

        Precondition: None
        Postcondition: Returns true if the menu has no items and false otherwise
--------------------------------------------------------------------------------*/
    
    void displayMenu(ostream &out) const; 
/*------------------------------------------------------------------------------
        Display all menu items

        Precondition: None
        Postcondition: Displays the menu items to the provided output stream
--------------------------------------------------------------------------------*/
    
};
ostream &operator<<(ostream &out, const Menu &menu);
#endif // MENU_H
