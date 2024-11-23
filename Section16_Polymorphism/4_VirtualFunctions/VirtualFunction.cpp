/***
 * [Polymorphism]
 *  Virtual functions
 *      Redefined functions are bound statically        => If don't use the virtual keyword with these functions, then they're statically bound at compile time as we've already seen. 
 *      Overridden functions are bound dynamically
 *      Virtual functions are overridden
 *      Allow us to treat all objects generally as objects of the Base class
 *      
 *  [Declaring virtual functions]
 *      Declare the function you want to override as virtual in the Base class
 *      Virtual functions are virtual all the way down the hierarchy from this point
 *      Dynamic polymorphism only via Account class pointer or reference
 *  class Account{
 *      public:
 *          virtual void withdraw (double amount);      => add virtual keyword, it can be overridden in derived classes and it will be bound dynamically at runtime when use a base class pointer or reference. Once declare a function as virtual, then that function is virtual all the way down the class hierarchy from this point forward. 
 *  };
 * 
 *  Declaring virtual functions
 *      Override the function in the Derived classes
 *      Function signature and return type must match EXACTLY
 *      Virtual keyword not required but is best practice
 *      if you don't provide an overridden version it is inherited from it's base class
 * 
 * => The derived withdraw function will be implicitly virtual, so don't have to use the virtual keyword again, but it's best practice to do so. It's important to understand that in order to override a base classes function, the function's signature and return type must match exactly. 
 *  If you don't match it exactly, the compiler will treat it as a redefinition and statically bind it. 
 *  Remember, virtual functions are dynamically bound only when we call them via a base class pointer or reference. Otherwise, they're statically bound. 
 *  class Checking : public Account {
 *      public: 
 *          virtual void withdraw (double amount);
 *  };
 * ***/

#include <iostream>
using namespace std;
//This class uses dynamic polymorphism for the withdraw method
class Account{
    public:
        virtual void withdraw(int val) {
            cout << "In Account::withdraw\n";
        }
};

class Checking : public Account {
    public:
        virtual void withdraw(int val) {
            cout << "In Checking::withdraw\n";
        }
};

class Savings : public Account {
    public:
        virtual void withdraw(int val) {
            cout << "In Savings::withdraw\n";
        }
};

class Trust : public Account {
    public:
        virtual void withdraw(int val) {
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
    // If don't use virtual, those are the withdraw methods executing. Executing account withdraw for all four of them because we're using static binding. Let's make this polymorphic. Go to our base class, and we look at the functions that we want our derived classes to be able to override. And those are the ones that we want to make virtual.
    // But typically you would have several in a base class. In this case, this is the one, withdraw. So all you need to do is put virtual in front. Whenever I come at any derived object via a base class pointer or a base class reference, it'll be dynamically bound. 

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}