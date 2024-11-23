/***
 * [Polymorphism]
 * Virtual Destructors
 *  Problems can happen when we destroy polymorphic objects
 *  If a derived class is destroyed by deleting its storage via the base class pointer and the class a non-virtual destructor. Then the behavior is undefined in the C++ standard. 
 *  Derived objects must be destroyed in the correct order starting at the correct destructor.
 * 
 *  Solution/Rule: 
 *      If a class has virtual functions
 *      ALWAYS provide a public virtual destructor
 *      If base class destructor is virtual then all derived class destructors are also virtual
 * 
 * 
 *  class Account {
 *      public: 
 *          virtual void withdraw (double amount);
 *          virtual ~Account();
 *          ... 
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
        virtual ~Account() {
            cout << "Account::destructor\n";
        }
};

class Checking : public Account {
    public:
        virtual void withdraw(int val) {
            cout << "In Checking::withdraw\n";
        }
        virtual ~Checking() {
            cout << "Checking::destructor\n";
        }
};

class Savings : public Account {
    public:
        virtual void withdraw(int val) {
            cout << "In Savings::withdraw\n";
        }
        virtual ~Savings() {
            cout << "Savings::destructor\n";
        }
};

class Trust : public Account {
    public:
        virtual void withdraw(int val) {
            cout << "In Trust::withdraw\n";
        }
        virtual ~Trust() {
            cout << "Trust::destructor\n";
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

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    // If these are not virtual destructors yet, they're just plain old destructors. The warning are about the leading object of polymorphic class type account, which has non-virtual destructor might cause undefined behavior. It sounds pretty ominous, and it's a potentially serious warning actually. All the compiler knows is that we've got pointers to account objects.So it really doesn't know which destructor to call. This is undefined in the C++ standard. If run, when calling the delete, we're getting account, destructor account. The base class destructor is being called. That is problem, p1 is an account (OK) but p2 points to a savings account, p3 is a checking, p4 is trust. SO there could be a lot of memory leaks going on. Those destructors maybe are closing files and writing buffers out, and none of that stuff is being called. So potentially, we could have a serious problem. 
    // To fix it, need to provide virtual destructors. Now we get no error. deleting p1, which calls the account destructor as before. when delete p2 (savings), the savings destructor is being called followed by the base class destructor.  SO if we're freeing memory in those destructors, if we're closing files, writing buffers, taking care of resources. p3 is doing the checking destructor followed by the account destructor and then following the trust destructor and the account destructor for p4. Remember, we're only going one deep here in the inheritance hierarchy. If you're going 5 6 10 deep, then you're got a lot of destructor that weren't called. They will be called now.  They'll take care of memory, take care of resources and so forth.
    // Rule: If got a class and it's got a virtual function, give it a virtual destructor as well.
    // You can't have virtual constructors. They're not allowed, and they really don't make any sense at all.
    return 0;
}