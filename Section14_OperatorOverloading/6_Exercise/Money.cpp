/***
 * Operator Overloading as Member Functions
Given the provided Money class,  please add the overloaded equality operators == and !=

These overloaded operators should return a bool and should be implemented as member functions.

Given 2 Money objects, consider them to be equal if both the dollars and cents attributes are the same for both objects.

First, add the overloaded operator function declarations to the Money class declaration in Money.h

Second, add the overloaded operator function definitions in Money.cpp
 * ***/

#include "Money.h"

Money::Money(int dollars, int cents) : dollars{dollars}, cents{cents} {}

Money::Money(int total) : dollars {total/100}, cents{total%100}  {}
   

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----

bool Money::operator==(const Money &rhs){
    if(dollars == rhs.dollars && cents == rhs.cents)
        return true;
    return false;
}

bool Money::operator!=(const Money &rhs){
    if(dollars != rhs.dollars && cents != rhs.cents)
        return true;
    return false;
}


//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


