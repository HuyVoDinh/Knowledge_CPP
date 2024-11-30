/*****
 * For this challenge we want to integrate our own user-defined exception classes into the Account class hierarchy. 
 * 
 * The account classes are provided for you. Also, the IllegalBalanceException.h file contains the declaration for the IllegalBalanceException class. 
 * 
 * What I would like you to do is:  
 * 1. Derive IllegalBalanceException from std::exception and implement the what() method to provide an exception message. 
 *  This exception object should be thrown from the Account class constructor is an account object is created with a negative balance. 
 * 
 * 2. Derive InsufficentFundException from std::exception and implement the what() method to provide an exception message. 
 *  This exception object should be thrown if a withdraw results in a negative balance. 
 *  You should throw this exception object from the Account withdraw method. 
 * *****/

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

using namespace std;

int main(){
    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> larrys_account;
    try{
        larrys_account = std::make_unique<Savings_Account>("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;
    } catch (const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
    }

    try{
        moes_account = std::make_unique<Savings_Account>("Moe", 1000.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(500.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(1000.0);
        std::cout << *moes_account << std::endl;

        larrys_account = std::make_unique<Savings_Account>("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;
    } catch (const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
    } catch (const InsufficientFundsException & ex){
        std::cerr << ex.what() << std::endl;
    }


    std::cout << "Program completed successfully\n";
    return 0;
}