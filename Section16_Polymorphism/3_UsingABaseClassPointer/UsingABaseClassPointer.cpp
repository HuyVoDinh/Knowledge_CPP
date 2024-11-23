/***
 * [Polymorphism]
 * [Using a Base class pointer]
 * 
 *  For dynamic polymorphism we must have:
 *      Inheritance
 *      Base class pointer or Base class reference  // => We must be using a base class pointer or base class reference, and we must declare the methods we want dynamically bound as virtual. 
 *      Virtual functions
 * 
 *  Account *p1 = new Account();
 *  Account *p2 = new Savings();
 *  Account *p3 = new Checking();
 *  Account *p4 = new Trust();
 * 
 *  p1->withdraw(1000);             // Account::withdraw
 *  p2->withdraw(1000);             // Savings::withdraw
 *  p3->withdraw(1000);             // Checking::withdraw
 *  p4->withdraw(1000);             // Trust::withdraw
 * 
 *  Account *array [] = {p1, p2, p3, p4};
 * 
 *  for (auto i = 0; i < 4; ++i)
 *      array[i]->withdraw(1000);
 * 
 *  <Section16_WhatIsPolymorphism2.png> 
 * 
 *  Assume that this class hierarchy is now using dynamic polymorphism. Create 4 pointers to account objects, and initialize each one to a different type of account created on the heap. 
 *  p1 holds the address of an account object, p2 holds the address of a savings account objects, p3 holds the address of a checking account objects, p4 holds the address of a trust account objects.
 *  Now call the withdraw method using the base class pointers, and C++ will figure out which method to bind at runtime based on the type of the object being pointed to by each pointer.
 *  I've declared an array that holds pointers to account objects. These will be the base class pointers. Then initialize the array to hold the four pointers we declared. Then loop through the array and call the withdraw method for each element in the array. 
 *  It doesn't matter how many base class pointers I initialize the array with or what type of accounts they're pointing to, it'll work as expected. 
 *  This also works with other collections such as a vector.  
 *  Be careful when using raw pointers and collections such as vectors. It's better to use smart pointers in this type of example.
 *  
 * ***/

#include <iostream>
#include <vector>

using namespace std;

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video

class Account{
    public:
        virtual void withdraw(int val) {
            cout << "In Account::withdraw\n";
        }
};

class Checking : public Account {
    public:
        void withdraw(int val) {
            cout << "In Checking::withdraw\n";
        }
};

class Savings : public Account {
    public:
        void withdraw(int val) {
            cout << "In Savings::withdraw\n";
        }
};

class Trust : public Account {
    public:
        void withdraw(int val) {
            cout << "In Trust::withdraw\n";
        }
};

int main()
{
    cout << "\n=========Pointers========\n";

    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
   
    p1->withdraw(1000);             
    p2->withdraw(1000);             
    p3->withdraw(1000);             
    p4->withdraw(1000);             

    cout << "\n========Array========\n";
    Account *array [] = {p1,p2,p3,p4};
    for(auto i = 0; i < 4; i++)
        array[i]->withdraw(1000);       //=> dynamically bound and it'll call the correct method

    cout << "\n========Array========\n";
    array[0] = p4;
    for(auto i = 0; i < 4; i++)
        array[i]->withdraw(1000); 
    
    cout << "\n========Vector========\n";
    vector<Account *> accounts {p1,p2,p3,p4};       // Template parameter is a pointer to an account. Just like had an array, have a vector of pointers to accounts. That's base class pointer.
    for(auto acc_ptr : accounts)
        acc_ptr->withdraw(1000);

    cout << "\n========Clean up=======\n";
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}