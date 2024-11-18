#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"

using namespace std;

int main(){
    cout.precision(2);
    cout << fixed;

    //Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    //Savings
    vector<Savings_Account> sav_account;
    sav_account.push_back(Savings_Account {});
    sav_account.push_back(Savings_Account {"Superman"});
    sav_account.push_back(Savings_Account {"Batman", 2000});
    sav_account.push_back(Savings_Account {"Wonderwoman", 5000, 5.0});

    display(sav_account);
    deposit(sav_account,2000);
    withdraw(sav_account,2000);

    return 0;
}