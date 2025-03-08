#ifndef DYNAMIC_ARRAY_LIST_H
#define DYNAMIC_ARRAY_LIST_H

#include <iostream>
#include <stdexcept> //included for handling errors
#include "MenuItem.h"
using namespace std;
typedef MenuItem ElementType;

class DynamicArrayList
{

public:
    /******** Function Members ********/
    
  /***** Class constructor *****/
  DynamicArrayList(int maxSize = 1024);
   /*---------------------------------------------------------------------------
        Construct a ArrayList object.

        Precondition:  maxSize is a positive integer with default value 1024.
        Postcondition: An empty ArrayList object is constructed; myCapacity ==
                       maxSize (default value 1024); myArray points to a dynamic
                       array with myCapacity as its capacity; and mySize is 0.
  ------------------------------------------------------------------------------*/
  
  /***** Class destructor *****/
  ~DynamicArrayList();
  /*----------------------------------------------------------------------------
        Destroys a ArrayList object.

        Precondition:  The life of a ArrayList object is over.
        Postcondition: The memory dynamically allocated by the constructor
                       for the array pointed to by myArray has been returned to 
                       the heap.
  ------------------------------------------------------------------------------*/
  
  
  /***** Copy constructor *****/
  DynamicArrayList(const DynamicArrayList &origArrayList);
   /*---------------------------------------------------------------------------
        Construct a copy of a List object.

        Precondition:  A copy of origArrayList is needed; origArrayList is a const
                       reference parameter.
        Postcondition: A copy of origArrayList has been constructed.
  ------------------------------------------------------------------------------*/
  
  /***** Assignment operator *****/
  const DynamicArrayList &operator=(const DynamicArrayList &rightHandSide);
  /*----------------------------------------------------------------------------
        Assign a copy of a ArrayList object to the current object.

        Precondition: none
        Postcondition: A copy of rightHandSide has been assigned to this
                       object. A const reference to this ArrayList is returned.
  ------------------------------------------------------------------------------*/
  
  /***** empty operation *****/
  bool empty() const;
  /*----------------------------------------------------------------------------
        Check if a ArrayList is empty.
   
        Precondition: None
        Postcondition: true is returned if the ArrayList is empty, false if not.
  .-----------------------------------------------------------------------------*/
  
  /***** Mathematical operation *****/
  double getTotalPrice() const;
  /*----------------------------------------------------------------------------
        Get the total price of the array.

        Precondition: None
        Postcondition: return the total price of the array.
  .-----------------------------------------------------------------------------*/
  
  /***** insert *****/
  void insert(ElementType item, int pos);
  /*----------------------------------------------------------------------------
        Insert a value into the ArrayList at a given position.

        Precondition: item is the value to be inserted; there is room in
                      the array (mySize < CAPACITY); and the position satisfies
                      o <= pos <= mySize.
        Postcondition: item has been inserted into the ArrayList at the position
                       determined by pos (provided there is room and pos is a 
                       legal position).
--------------------------------------------------------------------------------*/
  
  /***** insert at end *****/
  void insertatend(ElementType item);
  /*----------------------------------------------------------------------------
        Insert a value into the ArrayList at the end.
   
        Precondition: item is the value to be inserted; there is room in
                      the array (mySize < CAPACITY); and the position satisfies
                      o <= pos <= mySize.
        Postcondition: item has been inserted into the ArrayList at the end.
  ------------------------------------------------------------------------------*/

  /***** erase *****/
  void erase(int pos);
   /*---------------------------------------------------------------------------
        Remove a value from the ArrayList at a given position.
    
        Precondition: The ArrayList is not empty and the position satisfies
                      o <= pos < mySize.
        Postcondition: element at the position determined by pos has been
                       removed (provided pos is a legal position).
  ------------------------------------------------------------------------------*/
  
  /***** clear *****/
  void clear();
  /*----------------------------------------------------------------------------
        Remove all value from the ArrayList at a given position.
   
        Precondition: The ArrayList is not empty .
        Postcondition: element at all the position has been
                       removed.
  ------------------------------------------------------------------------------*/

  /***** output *****/
  void display(ostream &out) const;
  /*----------------------------------------------------------------------------
        Display the ArrayList.

        Precondition: The ostream out is open.
        Postcondition: The ArrayList represented by this ArrayList object has been
                       inserted into out.
  ------------------------------------------------------------------------------*/
  
  /***** size *****/
  int getSize() const;
  /*----------------------------------------------------------------------------
        Get the size of the ArrayList.

        Precondition: The ArrayList object has been properly initialized.
        Postcondition: The method returns the current number of elements stored 
                       in the ArrayList as an integer.
                       The ArrayList remains unchanged.
  ------------------------------------------------------------------------------*/

  /***** get menu items *****/
  MenuItem *getItems() const;
  /*----------------------------------------------------------------------------
        Get all items in the menu.

        Precondition: The menu object has been properly initialized and contains a 
                      valid collection of MenuItem objects.
        Postcondition: A pointer to the array of MenuItem objects is returned.
                       The menu remains unchanged.
--------------------------------------------------------------------------------*/
  
  /***** get an item by index *****/
  MenuItem getItem(int i) const;
  /*----------------------------------------------------------------------------
        Retrieve the menu item at the specified index.

        Precondition: The menu object has been properly initialized. 
                      The index i must be within the valid range of the menu items 
                      (0 <= i < total number of items).
        Postcondition: The MenuItem at index i is returned. 
                       The menu remains unchanged. 
--------------------------------------------------------------------------------*/
  
  /***** get an item by id *****/
  MenuItem findById(int id) const;
  /*----------------------------------------------------------------------------
        Find and return the menu item with the specified ID.

        Precondition: The menu object has been properly initialized.
                      The id must correspond to a valid MenuItem in the menu. 
        Postcondition: The MenuItem with the specified ID is returned if found. 
                       If no such item exists, the error is handled. 
                       The menu remains unchanged.
--------------------------------------------------------------------------------*/


private:
  /******** Data Members ********/
  int mySize;           // current size of ArrayList
  int myCapacity;       // capacity of array
  ElementType *myArray; // pointer to dynamic array

};  //--- end of ArrayList class

ostream &operator<<(ostream &out, const DynamicArrayList &list);

#endif
