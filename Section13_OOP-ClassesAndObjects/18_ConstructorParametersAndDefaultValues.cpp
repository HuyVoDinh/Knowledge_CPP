/***
 * [Default Constructor Parameters]
 * Can often simplify our code and reduce the number of overloaded constructors by providing default constructor parameters
 * Same rules apply as we learned with non-member functions
 * 
 * class Player
 * {
 *      private:
 *          std::string name;
 *          int health;
 *          int xp;
 *      public:
 *          // Constructor with default parameter values
 *          Player(std::string name_val = "None", int health_val = 0, int xp_val = 0); 
 *          //We can't always have default parameters in class design, but many times you can.
 * };
 * 
 * Player::Player(std::string name_val, int health_val, int xp_val) : name {name_val}, health {health_val}
 * 
 * Player empty;                                    // None, 0, 0
 * Player frank {"Frank"};                          // Frank, 0, 0
 * Player villain {"Villain", 100, 55};             // Villain, 100, 55
 * Player hero {"Hero", 100};                       // Hero, 100, 0
 * ***/

#include <string>
#include <iostream>
using namespace std;

class Player
{
    private:
        std::string name;
        int health;
        int xp;
    public:
        Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
        // Player () {}; it doesn't know what to do, it could call this default constructor or it could call this overloaded constructor with the three default parameters. It's not going to guess, it's just going to give you a compiler error => Error call of overloaded player is ambiguous       
};

//This constructor was which is our three arg constructor that matches the signature. These default parameters will automatically be supplied by the compiler when twe need them.
// It'll definitely simplify your code
// Can't always use these. Somme times it really doesn't make sense to provide default parameter values. You really want you know the user to explicitly provide all of them.
// But sometimes you can. And when you can, they come real handy
Player::Player(std::string name_val, int health_val, int xp_val): name{name_val}, health {0}, xp {0}{
     cout << "Three-args constructor\n";
}

int main(){
    Player empty;
    Player frank{"Frank"};
    Player villain {"Villain", 100, 55};

    return 0;
}