/***
 * [Declaring a class] 
 * 
 * Can supply the declarations that define the structure and behavior of our class
 * 
 * class Class_name{
 *  // declarations;
 * };
 * 
 * [Example]
 * class Player
 * {
 *      // attributes
 *      std::string name;
 *      int health;
 *      int xp;
 * 
 *      // methods
 *      void talk(std::String text_to_say);
 *      bool is_dead();
 * };
 * 
 * //Creating object
 * 
 * Player frank;
 * Player hero;
 * 
 * Player *enemy = new Player();
 * delete enemy;
 * 
 * =-----------------
 * 
 * class Account
 * {
 *      //attributes
 *      std::string name;
 *      double balance;
 *  
 *      //methods
 *      bool withdraw(double amount);
 *      bool deposit (double amount);
 * };
 * 
 * //Creating objects
 * 
 * Account frank_account;
 * Account jim_account;
 * 
 * Account *mary_account = new Account();
 * delete mary_account;
 * 
 * Account accounts[] {frank_account, jim_account};
 * 
 * std::vector<Account> accounts1 {frank_account};
 * accounts1.push_back(jim_account);
 * ***/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    // attributes
    string name = "Player";
    int health = 100;
    int xp = 3;

    // methods
    void talk(string);
    bool is_dead();
};

class Account{
    //attributes
    string name = "Account";
    double balance = 0.0;

    //methods
    bool deposit(double);
    bool withdrawal(double);
};


int main(){
    Account frank_account;
    Account hero_account;

    Player frank;
    Player hero;

    Player players[] {frank, hero};

    vector <Player> player_vec {frank};
    player_vec.push_back(hero);

    Player *enemy = nullptr;
    enemy = new Player;


    delete enemy;

    return 0;
}