#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"

// These are not class member functions.These are just plain old global c++ function.

//Utility helper functions for Account * class
//=> That class pointer => The poser of dynamic polymorphism
void display (const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts,double amount);
void withdraw(std::vector<Account *> &accounts, double amount);


#endif