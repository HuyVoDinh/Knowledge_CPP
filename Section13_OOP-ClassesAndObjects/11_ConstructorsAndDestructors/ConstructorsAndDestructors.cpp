/***
 * [Constructors]
 * 
 * Special member method
 * Invoked during object creation
 * Useful for initialization
 * Same name as the class
 * No return type is specified
 * Can be overloaded
 * 
 * class Player
 * {
 *  private:
 *      std::string name;
 *      int health;
 *      int xp;
 *  public:
 *      // Overloaded Constructors
 *      // Constructors have the same name as the class and they don't specify a return type
 *      Player();   // no args constructor and expects no arguments
 *      Player(std::string name);   // expects a single standard string object as an argument
 *      Player(std::string name, int health, int xp);   // expects three arguments: a standard string and two integers that represent health and xp
 * };
 * 
 * class Account
 * {
 *      private:
 *          std::string name;
 *          double balance;
 *      public:
 *      // Constructors
 *          Account();      // no args constructor
 *          Account(std::string name, double balance);      // expects two arguments: a string representing the account name and a double representing the account balance
 *          Account(std::string name);      // expects a string
 *          Account(double balance);        // expects double
 * };
 * 
 * [Destructors]
 * 
 * Special member method
 * Same name as the class proceeded with a tilde(~)
 * Invoked automatically when an object is destroyed
 * No return type and no parameters
 * Only 1 destructor is allowed per class - cannot be overloaded!
 * Useful to release memory, closed files and free any other resources
 * 
 *  * class Player
 * {
 *  private:
 *      std::string name;
 *      int health;
 *      int xp;
 *  public:
 *      // Overloaded Constructors
 *      // Constructors have the same name as the class and they don't specify a return type
 *      Player();   // no args constructor and expects no arguments
 *      Player(std::string name);   // expects a single standard string object as an argument
 *      Player(std::string name, int health, int xp);   // expects three arguments: a standard string and two integers that represent health and xp
 *      // Destructor
 *      ~Player();  // => This destructor will be called automatically when a local object goes out of scope or when we delete a pointer to an object
 * };
 * 
 * int main()
 * {
 *      {
 *          Player slayer;
 *          Player frank {"Frank", 100, 4};
 *          Player hero {"Hero"};
 *          Player villain {"Villain"};
 *          // use the objects
 *          // 4 destructors called
 *      }
 *      Player *enemy = new Player("Enemy", 1000, 0);
 *      delete enemy; //destructor called
 * }
 * 
 * 
 * If provide no constructor and no destructor, C++ will automatically provide a default constructor and a default destructor that are empty
 * ***/

#include <iostream>
#include <string>

using namespace std;

class Player
{
    private:
        string name;
        int health;
        int xp;
    public:
        void set_name(string name_val){
            name = name_val;
        }
        // Overloaded Constructors
        Player(){
            cout << "No args constructor called" << endl;
        }

        Player(string name){
            cout << "String arg constructor called" << endl;
        }

        Player(string name, int health, int xp){
            cout << "Three args constructor called" << endl;
        }

        ~Player(){
            cout << "Destructor called for " << name << endl;
        }
};

int main()
{
    {
        Player slayer;  // Slayer is a player object. It's local to this block. It's going to be created on the stack. slayer is created with no information so what's go8ing to happend here is the no args constructor will be called.
        slayer.set_name("Slayer");
    }
    //The object needs to be destroyed since it's no longer needed. A destructor will be called right before the object is destroyed
    
    
    
    {
        Player frank;   // It's a no args constructor
        frank.set_name("Frank");
        Player hero ("Hero");   // it's a single string
        hero.set_name("Hero");
        Player villain ("Villain", 100,12); // string and the two integers
        villain.set_name("Villain");
    }


    Player *enemy = new Player;
    enemy->set_name("Enemy");

    Player *level_boss = new Player("Level Boss", 1000,300);
    level_boss->set_name("Level boss");

    delete enemy;
    delete level_boss;

    return 0;
}