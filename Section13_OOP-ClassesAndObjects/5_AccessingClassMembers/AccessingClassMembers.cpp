/****
 * [Accessing class members]
 * 
 * Can access
 *  class attributes
 *  class methods
 * 
 * Some class members will not be accessible (more on that later)
 * We need an object to access instance variables
 * 
 * If we have an object (dot operator) => using the dot operator to access class member, we have to de-reference the pointer using the asterisk and then use the dot operator to get the class member we want
 * 
 * Account frank_account;
 * frank_account.balance;
 * frank_account.deposit(1000.00);
 * 
 * If we have a pointer to an object (member of pointer operator)
 *  Dereference the pointer then use the dot operator
 * => In order to access the o
 *  Account *frank_account = new Account();
 * 
 *  (*frank_account).balance;
 *  (*frank_account).deposit(1000.00);
 * 
 * Or use the member of pointer operator (arrow operator)
 * Account *frank_account = new Account();
 * 
 * frank_account->balance;
 * frank_account->deposit(1000.00);
 * ***/

#include <iostream>
#include <string>

using namespace std;

class Player{
    // attributes
public:
    string name = "Player";
    int health = 100;
    int xp = 3;

    // methods
    void talk(string text_to_say) {
        cout << name << " says " << text_to_say << endl;
    }
    bool is_dead();
};

class Account{
    //attributes
public:
    string name = "Account";
    double balance = 0.0;

    //methods
    bool deposit(double bal){
        balance += bal;
        cout << "In doposit\n";
        return true;
    }

    bool withdrawal(double bal){
        balance -= bal;
        cout << "In withdrawal\n";
        return true;
    }
};


int main(){
    Account frank_account;
    frank_account.name = "Frank's account";
    frank_account.balance = 5000.0;

    frank_account.deposit(1000);
    frank_account.withdrawal(500);

    Player frank;

    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");

    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    (*enemy).xp = 15;

    enemy->talk("I'll destroy you");

    return 0;
}