/***
 * [Implementing Member Methods]
 * Very similar to how we implemented functions
 * 
 * Member methods have access to member attributes
 *  So you don't need to pass them as arguments
 * 
 * Can be implemented inside the class declaration
 *  Implicitly inline => Ok for small and relatively simple methods
 * 
 * Can be implemented outside the class declaration
 *  Need to use Class_name::method_name => Ok for more complex methods outside of the class declaration
 * 
 * Can separate specification from implementation
 *  .h file for the class declaration
 *  .cpp file for the class implementation
 * 
 * 
 * Inside the class declaration
 * 
 * class Account{
 *  private:
 *      double balance;
 *  public:
 *      void set_balance(double bal){
 *          balance = bal;
 *      }
 *      double get_balance(){
 *          return balance;
 *      }
 * };
 * 
 * Outside the class declaration
 * 
 * class Account{
 *  private:
 *      double balance;
 *  public:
 *      void set_balance(double bal);
 *      double get_balance();
 * };
 * 
 *  void Account:set_balance(double bal){
 *      balance = bal;
 *  }
 *  double Account::get_balance(){
 *      return balance;
 *  }
 * 
 * 
 * [Separating Specification from Implementation]
 * Account.h
 * 
 * class Account{
 *  private:
 *      double balance;
 *  public:
 *      void set_balance(double bal);
 *      double get_balance();
 * };
 * 
 * [Include Guards]
 * An include guard is just a series of pre-processor directives that guarantees the file will only be that guarantees the file will only be included once
 * The way it works is we wrap up our entire class declaration in this include guard The first line is pound if not defined. This checks to see if the preprocessor has a symbol named.
 * The simple name can be anything you want,  but best practice is to use some soft of combination of the file name in uppercase with in uppercase with preceding and ending underscores
 * Any name is fine as long as it's unique in the program. If the preprocessor has that name defined then it skips the entire file and goes to the pound end if at the end
 * In other words, it doesn't process the file since it's already seen it because the symbol has been defined. If the symbol has not been defined, then the symbol is set  and the file is processed as usual.
 * It's not very elegant compared to more modern programming languages
 * 
 * 
 * 
 * #ifndef _ACCOUNT_H_
 * #define _ACCOUNT_H_
 * 
 *      // Account class declaration
 * class Account{
 *  private:
 *      double balance;
 *  public:
 *      void set_balance(double bal);
 *      double get_balance();
 * };
 * #endif
 * 
 * -----------
 * 
 * Account.h - #pragma once
 * => Many compilers also support the pound pragma once compiler directive. The effect of this directive is the same as t he include guard while many compounders support this directive, some don't.
 * So check your compiler documentation to be sure. Now we can provide the implementation for tha account class in a separate file name account.cpp
 * 
 * #pragma once
 *      // Account class declaration
 * class Account{
 *  private:
 *      double balance;
 *  public:
 *      void set_balance(double bal);
 *      double get_balance();
 * };
 * 
 * => Notice that include account.h and it's in double quotes. Up to this point, our includes have used angle brackets with no extensions. There's an important difference between the two forms of include.
 * Include with angle brackets as in include iostream is used to include system header files and the compiler knows where these are located.
 * Includes with double quotes tell the compiler to include header files that are local to this project, the compiler also knows where those are 
 * Notice that this file implements the two methods declared in the account.h header file
 * Account class is complete, the specification is in account.h and the implementation is in account.cpp
 * 
 * Account.cpp
 * 
 * #include "Account.h"
 * 
 * void Account::set_balance(double bal){
 *      balance = bal;
 * }
 * 
 * double Account::Get_balance(){
 *      return balance;
 * }
 * 
 * 
 * main.cpp
 * 
 * =>include iostream as well as account.h It's important that you always include .h files, never include .cpp files
 * 
 * #include <iostream>
 * #include <Account.h>
 * 
 * int main(){
 * 
 *      Account frank_account;
 *      frank_account.set_balance(1000.0);
 *      double bal = frank_account.get_balance();
 * 
 *      std::cout << bal << std::endl;
 *      return 0;
 * 
 * }
 * ****/

#include <iostream>
#include <string>
#include "8_Account.cpp"

using namespace std;




int main(){
    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);

    if(frank_account.deposit(200.0))
        cout << "Deposit OK\n";
    else
        cout << "Deposit not allowed\n";

    if(frank_account.withdraw(500.0))
        cout << "Withdrawal OK\n";
    else
        cout << "Not sufficient funds\n";

    if(frank_account.withdraw(1500.0))
        cout << "Withdrawal OK\n";
    else
        cout << "Not sufficient funds\n";

    return 0;
}