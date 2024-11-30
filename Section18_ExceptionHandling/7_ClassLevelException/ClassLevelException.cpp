/***
 * [Class level exception]
 * Exceptions can also be thrown from within a class: 
 *  
 *  Method:
 *      These work the same way as they do for functions as we've seen
 * 
 *  Constructor:
 *      Constructors may fail
 *      COnstructors do not return any value
 *      Throw an exception in the constructor if you cannot initialize an object
 * 
 *  Destructor
 *      Do NOT throw exceptions from your destructor => The destructor tis marked in C++ as no except by default, which means that it does not throw exceptions. If a destructor is called as a result of an exception being thrown elsewhere and then the destructor throws an exception, then there's a problem since the original catch block will never be reached. The only time a destructor might throw an exception is if it handles it itself, and that's a very unlikely use case. 
 * 
 * 
 * => In this case, assuming that we've created our own illegal balance exception class. 
 *  Account::Account(std::string name, double balance) : name {name}, balance {balance} {
 *      if (balance < 0.0)
 *          throw IllegalBalanceException{};
 *  }
 * 
 *  try{
 *      std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
 *      // use moes_account
 *  } catch (const IllegalBalanceException &ex){
 *      std::cerr << "Couldn't create account\n";
 *  }
 * ***/

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"

using namespace std;

int main(){

    try{
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    } catch (const IllegalBalanceException &ex){    // => If it doesn't throw an exception, then simply de-reference Moe's account and print it out to stand it out.
        std::cerr << "Couldn't create account - negative balance\n";
    }
    std::cout << "Program completed successfully\n";

    return 0;
}