/*------------------------------------------------------------------------------
MenuItem.h 
 
        This header file defines the data type MenuItem for processing menu items.
        Basic operations are:
        Default constructor -- Initializes object with default values if not already initialized else initializes it with the given value
        Copy constructor -- Initializes object by copying another MenuItem object
        setId: To set the ID of the menu item
        setName: To set the name of the menu item
        setDescription: To set the description of the menu item
        setPrice: To set the price of the menu item
        getId: To get the ID of the menu item
        getName: To get the name of the menu item
        getDescription: To get the description of the menu item
        getPrice: To get the price of the menu item
        setMenuItem: To set all attributes of the menu item
        display: To display the attributes of the menu item
        <<:  Output operators

--------------------------------------------------------------------------------*/

#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class MenuItem
{
    /********** Data Members **********/
private:
    int id;
    string name;
    string description;
    double price;

    /******** Function Members ********/
    /***** Class constructors *****/
public:
    MenuItem();
    MenuItem(int, string, string, double);
    MenuItem(const MenuItem &);
    void setId(int);
    void setName(string);
    void setDescription(string);
    void setPrice(double);
    void setMenuItem(int, string, string, double);
    int getId() const;
    string getName() const;
    string getDescription() const;
    double getPrice() const;
    MenuItem &operator=(const MenuItem &other);

    void display(ostream &) const;
}; // end of class declaration

ostream &operator<<(ostream &, const MenuItem &);

#endif
