#include <iostream>
using namespace std;

/***
 * Using dollars and cents
 * 
 * Write a program that asks the user to enter the following:
 * An integer representing the number of cents
 * 
 * You may assume that the number of cents entered is greater than or equal to zero
 * 
 * The program should then display how to provide that change to the user
 * 
 * In the US
 * 1 dollar is 100 cents
 * 1 quarter is 25 cents
 * 1 dime is 10 cents
 * 1 nicked is 5 cents 
 * 1 penny is 1 cent
 * ***/

int main()
{
    const int dollar_value = 100;
    const int quarter_value = 25;
    const int dime_value = 10;
    const int nickel_value = 5;
    int change_amount = 0;
    
    //Solution 1 - not using the modulo operator

    cout << "Enter an amount in cents: ";
    cin >> change_amount;

    int balance = 0, dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    dollars = change_amount / dollar_value;
    balance = change_amount - (dollars * dollar_value);

    quarters = balance / quarter_value;
    balance -= quarters * quarter_value;

    dimes = balance / dime_value;
    balance -= dimes * dime_value;

    nickels = balance / nickel_value;
    balance -= nickels * nickel_value;

    pennies = balance;

    //Solution 2 - Using the modulo operator    

    balance = 0, dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    dollars = change_amount / quarter_value;
    balance= change_amount % dollar_value;

    quarters = balance / quarter_value;
    balance %= quarter_value;

    dimes = balance / dime_value;
    balance %= dime_value;

    nickels = balance / nickel_value;
    balance %= nickel_value;

    pennies = balance;

    cout << "You can provide this change as follows: " << endl;
    cout << "Dollars: " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;
}
