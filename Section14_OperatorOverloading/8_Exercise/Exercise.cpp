// /***
//  * Operator Overloading as Non-member Functions
// Given the provided Money class,  please add the overloaded  + operator so that it will add two Money objects together and return a Money object representing their sum.

// This overloaded operator should return a Money object and should be implemented as a non-member friend function.

// First, add the overloaded operator function declaration to the Money class declaration in Money.h

// Second, add the overloaded operator function definition in Money.cpp
//  * ***/

// //Answer
// Money.h
// -------
// #ifndef _MONEY_MONEY_H
// #define _MONEY_MONEY_H


// #include <iostream>

// class Money {
//     int dollars;
//     int cents;
// public:
//     Money(int dollars, int cents);
//     Money(int total);
//     int get_dollars() const {return dollars;}
//     int get_cents() const {return cents; }
    

//     //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//     //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
//     friend Money operator+(const Money &lhs, const Money &rhs);
    
    
//     //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
//     //----DO NOT MODIFY THE CODE BELOW THIS LINE----
// };


// #endif //_MONEY_MONEY_H


// Money.cpp
// ---------
// #include "Money.h"

// Money::Money(int dollars, int cents) : dollars{dollars}, cents{cents} {}

// Money::Money(int total) : dollars {total/100}, cents{total%100}  {}
   

// //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
// //----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----

// Money operator+(const Money &lhs, const Money &rhs) {
//     int total = (lhs.dollars + rhs.dollars) * 100;
//     total += lhs.cents + rhs.cents;
//     return Money{total};
// }


// //----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


