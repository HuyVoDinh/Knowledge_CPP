#include "Money.h"

Money::Money(int dollars, int cents) : dollars{dollars}, cents{cents} {}

Money::Money(int total) : dollars {total/100}, cents{total%100}  {}
   

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----


Money operator+(const Money &lhs, const Money &rhs){
    int total = (lhs.dollars + rhs.dollars) *100;
    total += lhs.cents + rhs.cents;
    return Money{total};
}

//----WRITE YOUR METHOD DEFINITIONS ABOVE THIS LINE----


