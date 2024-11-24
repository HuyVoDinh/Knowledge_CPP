/***
 * [Polymorphism]
 * Using Base class references
 *  We can also use Base class references with dynamic polymorphism
 *  Useful when we pass objects to functions that expect a Base class reference
 * 
 *  Account a;
 *  Account &ref = a;           // => Create a reference ref that's a reference to an account, that's the base class reference, and we initialize ref to a. 
 *  ref.withdraw(1000);         // Account::withdraw        //=> If call the withdraw method using the ref reference, we're calling the accounts withdraw method, but the binding is dynamic. 
 * 
 *  Trust t;
 *  Account &ref1 = t;          // => Create ref1 as a reference to an account object. That's the base class reference, and we initialize ref one to t. 
 *  ref1.withdraw(1000);        // Trust::withdraw          //=> If call the withdraw method using the reference ref1, call the trust withdraw method. This method was bound dynamically. 
 * 
 * 
 * => Functions expecting base class references allow us to think in the general again and not have to worry about details.
 *  void do_withdraw(Account &account, double amount) {
 *      account.withdraw(amount);
 *  }
 * 
 *  Account a;
 *  do_withdraw(a, 1000);       // Account::withdraw
 * 
 *  Trust t;
 *  do_withdraw(t, 1000);       // Trust::withdraw
 * ****/

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

void do_withdraw(Account &account, double amount){
    account.withdraw(amount);
}

int main()
{
    Account a;
    Account &ref = a;
    ref.withdraw(1000);                 // In Account::withdraw
    //ref is referring to an account. Can see vptr, that's your virtual pointer. So this tells you that there is dynamic polymorphism going on.

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);                // In Trust::withdraw   // When call ref1's withdraw , method call will be bound dynamically because it'll realize that ref1 is currently referring to a trust account. So it'll bind it to trusts withdrawal because they're all virtual methods.
    //In ref1 while it is a reference to a base class, it's actually referring to a trust account. The trust account has the account part of it.


    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1, 1000);              // In Account::withdraw     // In this case, the account that was passed in is a reference to account. That's base class reference. That it's actually referring to an account object.
    do_withdraw(a2, 1000);              // In Savings::withdraw     // Can see  that account while it is still a reference to the base class, it is currently referring to a savings account. Can see that the savings account has the account part within it. So when execute this. we're doing account withdraw, trusts withdraw, and then we're saying account savings, checking and trust withdraw. So can see that use a base class reference, you still get the polymorphic behavior and writing functions like these that expect references to base class objects is really handy to do, and it saves you from thinking in detail again.
    do_withdraw(a3, 1000);              // In Checking::withdraw
    do_withdraw(a4, 1000);              // In Trust::withdraw

   return 0;
}