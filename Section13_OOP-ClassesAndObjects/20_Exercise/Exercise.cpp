/***
 * Add a Copy constructor to an Existing class
 * 
 * Given the Dog class defined in Dog.h, add a Copy constructor.
 * 
 * The copy constructor should copy the attributes from one object to another.
 * Also, please display, "Copy Constructor" to cout in the body of your copy constructor
 * Do not follow the output statement with '\n' or endl
 * 
 * The copy constructor should allow us to create Dog objects as follows:
 * 
 * Dog spot {"Spot", 5};        // Overloaded constructor
 * Dog twin {spot};             // Copy constructor, twin will be a copy of spot
 * ****/
#include<iostream>
#include "Dog.h"
using namespace std;

int main()
{
    Dog spot {"Spot", 5}; 
    Dog twin {spot};
}