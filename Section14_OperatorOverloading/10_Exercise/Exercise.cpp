// /***
//  * Operator Overloading the Stream Insertion Operator
// Given the provided Money class,  please add the overloaded stream insertion  << operator so that it displays a Money object on a output stream as follows.

// If the Money object models 1 dollar and 70 cents, the output should be:

// Money amount {1, 70};
// std::cout << amount;
// dollars: 1 cents: 70 ,no '\n' or endl should be added.

// You ONLY need to write the overloaded operator function, our automated tester will create the object and test it.

// This overloaded operator should return a reference to a std::ostream object and should be implemented as a non-member friend function.

// First, add the overloaded friend operator function declaration to the Money class declaration in Money.h

// Second, add the overloaded operator function definition in Money.cpp

// This overloaded operator function should not modify the Money object in any way.
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


//     //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//     //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
    
//     friend std::ostream &operator<<(std::ostream &os, const Money &money);
    
    
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


// std::ostream &operator<<(std::ostream &os, const Money &money) {
//     os << "dollars: " << money.dollars << " cents: " << money.cents;
//     return os;
// }



// //----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


