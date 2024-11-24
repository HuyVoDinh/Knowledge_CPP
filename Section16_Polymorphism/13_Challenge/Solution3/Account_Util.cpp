#include <iostream>
#include "Account_Util.h"

//Displays Account objects in a vector of Account objects
void display(const std::vector<Account *> & accounts){
    std::cout << "\n========Account========\n";
    for (const auto &acc:accounts)
    {
        std::cout << *acc << std::endl;
    }
}

//Deposits supplied amount to each Account object in the vector
void deposit(std::vector <Account *> &accounts, double amount){
    std::cout << "\n============Depositing to Accounts=========\n";
    for (auto acc:accounts){
        if(acc->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        else 
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;
    }
}

//Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account *> &accounts, double amount){
    std::cout << "\n=========Withdrawing from Accounts=========\n";
    for(auto acc : accounts){
        if(acc->withdraw(amount))
            std::cout << "Withdraw " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed withdrawal of " << amount << " from " << *acc << std::endl;
    }
}

