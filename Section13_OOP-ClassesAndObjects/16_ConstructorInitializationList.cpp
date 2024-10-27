/***
 * [Constructor Initialization Lists]
 * So far, all data member values have been set in the constructor body => While this works, it technically isn't initialization because by the time the constructor body is executed. These member attributes have already been created. So we're really just assigning values to already created attributes.
 * 
 * Constructor initialization lists
 *  are more efficient => member data values initialized to our values before the constructor body executes. This is much more efficient since it's true initialization
 *  initialization list immediately follows the parameter list
 *  initializes the data members as the object is created
 *  order of initialization is the order of declaration in the class
 * 
 * class Player
 * {
 *  private:
 *      std::string name;
 *      int health;
 *      int xp;
 *  public:
 *      //Overloaded Constructors
 *      Player();
 *      Player(std::string name_val);
 *      Player(std::string name_val, int health_val, int xp_val);
 * }
 * If recall three overloaded constructors, we implemented them using assignment statemented in the constructor body
 * 
 * Player::Player(){
 *      name = "None";          // assignment not initialization
 *      health = 0;
 *      xp = 0;
 * }
 * => WHile this work, it can be inefficient in many cases. For example, by the time that we get to the statement name equals none. The name string object has already been constructed and initialized to an empty string. Sp we're really just assigning a new string to it, in this case, to an existing object. That's very different from initialization. What we really want is to initialize the data members to our data values as they're created. That's what constructor initialization lists allow us to do.
 * 
 * 
 * Better way:
 * Player::Player() : name{"None"}, health{0}, xp{0}{
 * 
 * }
 * => Shows how we could implement the same constructor in a more efficient way. Notice that immediately after the parameter list, we provide a colon followed by a list of initializers. In this case, we're telling the C++ compiler to initialize name to none, health and xp to 0. This happens before the body of the constructor is ever executed. One thing to keep in mind, the order in which the members are initialized is not necessarily the order we provide in the initialization list. The data members will be initialized in the order that they were declared in the class declaration.
 * 
 * Notice how in the constructor, there's no code in the constructor body. We can still write any code we want in the constructor body. But now we can be sure that our data members have been initialized to our own values before any code in the constructor body is executed.
 * ***/

#include <iostream>
#include <string>
using namespace std;

class Player
{
    private:
        std::string name;
        int health;
        int xp;
    public:
        // Overloaded constructors
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
};

// Player::Player(){
//     name = "None";
//     health = 0;
//     xp = 0;
// }

// Player::Player(std::string name_val){
//     name = name_val;
//     health = 0;
//     xp = 0;
// }

// Player::Player(std::string name_val, int health_val, int xp_val){
//     name = name_val;
//     health = health_val;
//     xp = xp_val;
// }

Player::Player()
: name{"None"}, health {0}, xp {0}{
}

Player::Player(std::string name_val)
: name{name_val}, health {0}, xp {0}{
}

Player::Player(std::string name_val, int health_val, int xp_val): name{name_val}, health {0}, xp {0}{
}
int main(){
    //use debug and point at the name every constructor (60,66,72, 80);
    //First in empty variable and step through this. That will call the no args constructor. On line 60, since we're providing no information for initialization.
    // You'll notice that name is set to the empty string. That tells you that that was already initialized. In other words, that string object name its constructor was already called with no information, and we initialized it to an empty string. So line 60 says name equals none. That's really not initializing anything. All it;s doing is assigning None to an already created object name.
    // That's really not what we'd like we'd like to initialize that object name immediately without have to initialize and then assign to it. That can be very inefficient. In the case of a very complex class, you might have to create some sort of a default constructor for it and it's setting a lot of fields, it may be allocating things and then you're just going to deallocate all that stuff and assign to it again.
    // It really doesn't make sense things become very inefficient

    Player empty;
    Player frank{"Frank"};
    Player villain {"Villain", 100, 55};

    // We've just created three string objects and then get rid of basically the string, the empty string they pointed to and replace it with Frank, Villan and None. So really really an inefficient thing to do.
    // => We want to use the initializer lists for the constructors.
    return 0;
}