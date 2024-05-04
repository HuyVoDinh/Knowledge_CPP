/***
 * [Class member access modifiers]
 * Access modifiers to determine what will be hidden in the class and what parts of the program have access to this information
 * In the body of the class, you specify the axis modifier followed by colon. Then everything you declare from that point forward will have that access modifier applied to it
 * 
 * 
 * public, private nad protect
 * 
 * public
 *  accessible everywhere
 * 
 *  Anything we declare after this will be public until we see a different access modifier 
 * 
 *  class Class_name
 *  {
 *  public:
 *      // declarations; 
 *  };
 * 
 * private
 *  accessible only by members or friends of the class
 * 
 *  class Class_name
 *  {
 *  private:
 *      // declarations; 
 *  };
 * 
 * 
 * 
 * protected 
 *  used with inheritance
 * 
 * class Class_name
 *  {
 *  protected:
 *      // declarations; 
 *  };
 * 
 * [Example]
 * 
 * We commonly use public, private and protected all at the same time to tell the compiler what class member should not be available outside the class,
 * and what class members should be part of the public interface of the class
 * 
 * class Player
 * {
 *  private:
 *      // player's name, health and xp are all private . This means that they're only accessible from the other members of this class and from friends of the class
 *      std::string name;
 *      int health;
 *      int xp;
 *  public:
 *      void talk(std::string text_to_say);
 *      bool is_dead();
 * };
 * 
 * int main(){
 *      Player frank;
 *      frank.name = "Frank";               // Compiler error
 *      frank.health = 1000;                // Compiler error
 *      frank.talk("Ready to battle");      // OK
 * 
 *      Player *enemy = new Player();
 *      enemy->xp = 100;                    // Compiler error
 *      enemy->talk("I'll hunt you down");  // OK
 * 
 *      delete enemy;
 * }
 * 
 * class Account
 * {
 *  private:
 *      std::string name;
 *      double balance;
 *  public:
 *      bool withdraw(double amount);
 *      bool deposit(double amount);
 * };
 * 
 * int main(){
 *      Account frank_account;
 *      frank_account.balance = 100000.0;       // Compiler error
 *      frank_account.deposit(10000.0);         // OK
 *      frank_account.name = "Frank's Account"; // Compiler error => If try to directly access the name of the account, get a compiler error for the same reason, the account name is private
 * 
 *      Account *marry_account = new Account();
 *      
 *      marry_account->balance = 1000.0         // Compiler error
 *      mary_account->withdraw(1000.0);         // OK
 * 
 *      delete marry_account;
 * 
 * }
 * ***/

#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        //attributes
        string name {"Player"};
        int health;
        int xp;
    public:
        //method
        void talk(string text_to_say){
            cout << name << " says " << text_to_say << endl;
        }
};

int main(){
    //=> The idea is you want to control that variable via some sort of public method, so they've got to go thorough the public method and then the public method makes sure that the health is within some reasonable range
    Player frank;
    // frank.name = "Frank"; // Error
    // cout << frank.health << endl;       // Error
    frank.talk("Hello there");

    return 0;
}