/***
 * [Deriving classes from exiting classes]
 * C++ derivation syntax
 * => This is the class that we'll be creating the new class from. This class will have its own member data and methods as we've already learned in this course. 
 * Then we declare the new class derived in this case, followed by a colon then an access specifier and the name of the base class. 
 * If you don't provide an access specifier, private inheritance is used.
 * 
 * class Base {
 *  // Base class members... 
 * };
 * 
 * class Derived : access-specifier Base {
 *  // Derived class members... 
 * };
 * 
 * Access-specifier can be: public, private, or protected
 * 
 * 
 * Types of inheritance in C++
 * public
 *  Most common
 *  Establishes 'is-a' relationship between Derived and Base classes
 * private and protected    => It is often used to implement one class in terms of another. 
 *  Establishes "derived class has a base class" relationship
 *  "Is implemented in terms of" relationship
 *  Different from composition
 * 
 * 
 * => Notice that we're assuming that we already have an existing account class and it's got its own member data and methods, and we want to reuse it. 
 * Now we want to create a savings account class that has much in common with an account class, but it also has some more specialized behavior. We can declare the savings account class, then provide a colon followed by the public access specifier, and finally, the name of the base class.
 * This establishes an "is-a" relationship between savings account and account. 
 * Now savings account inherits everything in the account class, and it's free to implement its own specialized behaviors based on the behaviors it inherited from account. 
 * class Account {
 *  // Account class members... 
 * };
 * 
 * class Savings_Account : public Account {
 *  // Savings_account class members... 
 * };
 * 
 * Savings_account 'is-a' Account
 * 
 * => We assume that we have a no args constructor in the deposit and withdraw methods handle deposit and withdraw funds to an account. We can create account objects on the stack or on the heap via pointer and call these methods as we need.
 * 
 * C++ creating objects
 * 
 * Account account{};
 * Account *p_account = new Account();
 * 
 * account.deposit(1000.0);
 * p_account->withdraw(200.0);
 * 
 * delete p_account;
 * 
 * => We also have a savings account class, so we can create savings account objects. In this case the specialized deposit and withdraw methods of the savings account class will be used. 
 * So as you can see, conceptually inheritance is pretty simple. However, the nuances of inheritance can get very complex. 
 * Savings_Account sav_account {};
 * Savings_Account *p_sav_account = new Savings_Account();
 * 
 * sav_account.deposit(1000.0);
 * p_sav_account->withdraw(200.0);
 * 
 * delete p_sav_account;
 * ***/
#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main(){
    cout << "\n=========Account==================\n";
    Account acc{};
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    cout << endl;

    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

    // Use the Savings Account class
    cout << "\n=========Savings_Account==================\n";
    Savings_Account sav_acc {};     //=> It also an account because we're got inheritance. So everything that was in my parent is in me. And can see that the account part of me is 0 and the account name part of me is "an account". sav_acc {Account: {balance: 0, name: "An account"}, int_rate: 3}.
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);

    cout << endl;

    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->deposit(500.0);
    return 0;
}
/***
 * <Section15_DerivingClassesFromExistingClasses1.png> 
 * acc, it's an account and it has two local variable: balance and name. And it also has access to those two methods deposit and withdraw as well as the constructors and the destructor.
 * have got a savings_account, sav_acc is the name of the object and its type is savings account. This is an account. So it's got an account part inside it. It's going to have a balance, name. It's going to have access to those deposit and withdraw methods and deposit and withdraw are methods for the account class. 
 * But then savings_account class add an interest rate (int_rate) and it's got its own versions of deposit and withdraw. 
 * When we say that a savings account is an account. There's the account part of me. This is wehre we're headed with the next few lectures because we really need to be able to know you know what can I access from these methods. It all depends on access modifiers. And also I need to be able to instantiate or initialize that account part of me. 
 * ****/