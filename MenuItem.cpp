/*------------------------------------------------------------------------------
    MenuItem.cpp
    This file implements DynamicArrayList member functions.
--------------------------------------------------------------------------------*/

#include "MenuItem.h"
#include <stdexcept>

//--- Definition of class no-arg constructor
MenuItem::MenuItem()
{
    setMenuItem(0, " ", " ", 0);
}

//--- Definition of class with-arg constructor
MenuItem::MenuItem(int id, string name, string description, double price)
{
    setMenuItem(id, name, description, price);
}

//--- Definition of class copy constructor
MenuItem::MenuItem(const MenuItem &other)
{
    //Set MenuItem values to the values of the other MenuItem object
    setMenuItem(other.id, other.name, other.description, other.price);
}

//--- Definition of class operator
MenuItem &MenuItem::operator=(const MenuItem &other)
{
    if (this != &other)
    { // Protect against self-assignment
        id = other.id;
        name = other.name;
        description = other.description;
        price = other.price;
    }
    return *this;
}

//--- Definition of setId()
void MenuItem::setId(int id)
{
    //Check if id is valid
    if (id < 0)
    {
        throw std::invalid_argument("ID cannot be negative");
    }
    this->id = id;
}

//--- Definition of setName()
void MenuItem::setName(string name)
{
    //Check if name is empty
    if (name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
    this->name = name;
}

//--- Definition of setDescription()
void MenuItem::setDescription(string description)
{
    //Check if description is empty
    if (description.empty())
    {
        throw std::invalid_argument("Description cannot be empty");
    }
    this->description = description;
}

//--- Definition of setPrice()
void MenuItem::setPrice(double price)
{
    //Check if price is valid
    if (price < 0)
    {
        throw std::invalid_argument("Price cannot be negative");
    }
    this->price = price;
}

//--- Definition of setMenuItem()
void MenuItem::setMenuItem(int id, const string name, const string description, double price)
{
    setId(id);
    setName(name);
    setDescription(description);
    setPrice(price);
}

//--- Definition of getId()
int MenuItem::getId() const
{
    //Check if id is valid
    if (id <= 0)
    {
        throw std::runtime_error("Invalid ID: ID must be positive");
    }
    return id;
}

//--- Definition of getName()
string MenuItem::getName() const
{
    //Check if name is empty
    if (name.empty())
    {
        throw std::runtime_error("Name is empty");
    }
    return name;
}

//--- Definition of getDescription()
string MenuItem::getDescription() const
{
    //Check if description is empty
    if (description.empty())
    {
        throw std::runtime_error("Description is empty");
    }
    return description;
}

//--- Definition of getPrice()
double MenuItem::getPrice() const
{
    //Check if price is valid
    if (price < 0)
    {
        throw std::runtime_error("Invalid Price: Price cannot be negative");
    }
    return price;
}

//--- Definition of display()
void MenuItem::display(ostream &out) const
{
    out << "ID: " << getId() << endl;
    out << "Name: " << getName() << endl;
    out << "Description: " << getDescription() << endl;
    out << "Price: $" << getPrice() << endl;
}

ostream &operator<<(ostream &out, const MenuItem &menuitem)
{
    menuitem.display(out);
    return out;
}
