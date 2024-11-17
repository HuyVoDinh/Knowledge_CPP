#include "Savings_Account.h"

//-> Those are two parameters in this particular constructor. We want to initialize the account part of us. So we want to invoke our account part constructor. Our parents constructor and that expects just the balance. It doesn't know anything about the interest rate. 
//-> And then once that's initialized, I can come back and take care of the interest rate and initialize that. There is no body to this constructor.
Savings_Account::Savings_Account(double balance, double int_rate)
    : Account(balance), int_rate(int_rate){

    }


//-> Here is no-arg constructor. It expect nothing. The simplest thing to do is just to delegate to overloaded constructor. And what I want to pass into it is 0.0 for the balance and 0.0 for the interest rate. 
//-> We don't have any destructors or copy constructors or anything like that.
Savings_Account::Savings_Account()
    : Savings_Account{0.0,0.0}{

    }

//-> It expects a double, which is the amount to deposit. 
void Savings_Account::deposit(double amount){
    amount = amount + (amount * int_rate/100);
    Account::deposit(amount);       //-> pass in the amount that we wanted to deposit for Account.
    //-> w
}

//->implement the friend overloaded operator. So this returns a ref to an ostream, and we're overloading operator, our insertion operator.std ostream by reference and we'll call it os. And we've got a const savings account ref.
std::ostream &operator<<(std::ostream &os, const Savings_Account &account){
    os << "Savings account balance: " << account.balance << " interest rate: " << account.int_rate;
    return os;
}