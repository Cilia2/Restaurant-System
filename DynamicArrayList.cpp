/*------------------------------------------------------------------------------
    DynamicArrayList.cpp
    This file implements DynamicArrayList member functions.
--------------------------------------------------------------------------------*/

#include "DynamicArrayList.h"
#include <cassert>
#include <new>
#include <stdexcept>
using namespace std;

//--- Definition of class constructor
DynamicArrayList::DynamicArrayList(int maxSize)
{
    mySize = 0;
    myCapacity = maxSize;
    myArray = new (nothrow) ElementType[maxSize];
    assert(myArray != 0);
}

//--- Definition of class destructor
DynamicArrayList::~DynamicArrayList()
{
    delete[] myArray;
}

//--- Definition of copy constructor
DynamicArrayList::DynamicArrayList(const DynamicArrayList &origArrayList)
{
    mySize = origArrayList.mySize;
    myCapacity = origArrayList.myCapacity;
    //--- Get new array for copy
    myArray = new (nothrow) ElementType[myCapacity];

    if (myArray != 0) // check if memory available
        //--- Copy origList's elements into this new array
        for (int i = 0; i < mySize; i++)
            myArray[i] = origArrayList.myArray[i];
    else
    {
        cerr << "*** Inadequate memory to allocate storage for Arraylist ***\n";
        exit(1);
    }
}

//--- Definition of assignment operator
const DynamicArrayList &DynamicArrayList::operator=(const DynamicArrayList &rightHandSide)
{
    if (this != &rightHandSide) // check that not self-assignment
    {
        //-- Allocate a new array if necessary
        if (myCapacity != rightHandSide.myCapacity)
        {
            delete[] myArray;
            myCapacity = rightHandSide.myCapacity;
            myArray = new (nothrow) ElementType[myCapacity];

            if (myArray == 0) // check if memory available
            {
                cerr << "*Inadequate memory to allocate stack ***\n";
                exit(1);
            }
        }
        //--- Copy rightHandSide's Arraylist elements into this new array
        mySize = rightHandSide.mySize;
        for (int i = 0; i < mySize; i++)
            myArray[i] = rightHandSide.myArray[i];
    }
    return *this;
}

//--- Definition of empty()
bool DynamicArrayList::empty() const
{
    return mySize == 0;
}

//--- Definition of display()
void DynamicArrayList::display(ostream &out) const
{
    if (empty()) {
        out << "DynamicArrayList is empty.\n";
    }
    out << "DynamicArrayList:\n";
    for (int i = 0; i < mySize; i++)
        out << myArray[i] << "  ";
}

//--- Definition of insert()
void DynamicArrayList::insert(ElementType item, int pos)
{
    if (mySize == myCapacity)
    {
        cerr << "*** No space for list element -- terminating "
                "execution ***\n";
        exit(1);
    }
    if (pos < 0 || pos > mySize)
    {
        cerr << "*** Illegal location to insert -- " << pos
             << ".  List unchanged. ***\n";
        return;
    }

    // First shift array elements right to make room for item

    for (int i = mySize; i > pos; i--)
        myArray[i] = myArray[i - 1];

    // Now insert item at position pos and increase list size
    myArray[pos] = item;
    mySize++;
}

//--- Definition of insertAtEnd()
void DynamicArrayList::insertatend(ElementType item)
{
    //insert item at the end of the array (mySize)
    insert(item, mySize);
}

//--- Definition of erase()
void DynamicArrayList::erase(int pos)
{

    if (mySize == 0)
    {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize)
    {
        cerr << "Illegal location to delete -- " << pos
             << ".  List unchanged. ***\n";
        return;
    }

    // Shift array elements left to close the gap
    for (int i = pos; i < mySize; i++)
        myArray[i] = myArray[i + 1];

    // Decrease Array   list size
    mySize--;
}

//--- Definition of clear()
void DynamicArrayList::clear()
{
    //Loop through the elements of the array
    for (int i = 0; i < mySize; i++)
    {
        erase(i); //erase every element by index using the erase method
    }
    
    mySize = 0;  // set array size to 0
    myCapacity = 10; // set array capacity to default value 10
    delete[] myArray; //delete the array
    myArray = new (nothrow) ElementType[myCapacity]; 
    // make a new array that takes myCapacity (10) as its capacity
}

//--- Definition of getSize()
int DynamicArrayList::getSize() const
{
    return mySize;
}

//--- Definition of getItems()
MenuItem *DynamicArrayList::getItems() const
{
    //allocate memory for a new array of MenuItem objects
    //this new array will have the same size as myArray
    MenuItem *temp = new MenuItem[mySize];
    //Loop through each element in myArray
    for (int i = 0; i < mySize; i++)
    {
        //Copy each element from the original myArray to the new array temp
        temp[i] = myArray[i];
    }
    //Return the pointer to the new array temp
    return temp;
}

//--- Definition of getItem()
MenuItem DynamicArrayList::getItem(int i) const
{
    return myArray[i];
}

//--- Definition of getTotalPrice()
double DynamicArrayList::getTotalPrice() const
{
    //initialize the place holder for the calculated value of the price
    double totalPrice = 0.0;
    //Loop through the array to get elements
    for (int i = 0; i < mySize; i++)
    {
        //Get price of each element and add it to totalPrice
        totalPrice += myArray[i].getPrice();
    }
    //return the total price obtained
    return totalPrice;
}

//--- Definition of findById()
MenuItem DynamicArrayList::findById(int id) const {
    //Loop through the array to get elements
    for (int i = 0; i < mySize; i++) {
        //If id given is found
        if (myArray[i].getId() == id) {
            return myArray[i]; // Return pointer to the found MenuItem
        }
    }
    //Handle error if id is not found
    throw std::invalid_argument("Error: Item with the given ID not found");
}

ostream &operator<<(ostream &out, const DynamicArrayList &list)
{
    list.display(out);
    return out;
}
