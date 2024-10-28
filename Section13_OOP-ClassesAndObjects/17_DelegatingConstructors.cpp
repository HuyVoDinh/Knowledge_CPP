/***
 * Delegating Constructors
 * Often the code for constructors is very similar
 * 
 * Duplicated code can lead to errors
 * 
 * C++ allows delegating constructors
 *  code for one constructor can call another in the initialization list => can now call another constructor of the same class in the initialization list of constructor.
 *  avoids duplicating code
 * 
 * class Player
 * {
 *      private:
 *          std::string name;
 *          int health;
 *          int xp;
 *      public:
 *          // Overloaded COnstructors
 *          Player();
 *          Player(std::string name_val);
 *          Player(std::string name_val, int health_val, int xp_val);
 * };
 * 
 * //Here's the code for the overloaded constructors using initialization lists => The only differences are the values used for initialization
 * Player::Player()
 * : name{"None"}, health {0}, xp {0}{
 * }
 * 
 * Player::Player(std::string name_val)
 * : name{name_val}, health {0}, xp {0}{
 * }

 * Player::Player(std::string name_val, int health_val, int xp_val): name{name_val}, health {0}, xp {0}{
 * }
 * 
 * 
 * The first constructor is the three argument constructor and we use a constructor initialization list as we did previously.
 * When we define the no args constructor, instead of writing another very similar initialization list, we simply call the three args constructor with the initialization data we need.
 * We call the constructor by providing the constructor name, which is the same name as the class followed by the arguments to the constructor.
 * 
 * 
 * Player::Player(std::string name_val, int health_val, int xp_val): name{name_val}, health {0}, xp {0}{
 * }
 * 
 * No args constructor is the delegating constructor since it delegates object initialization to another constructor.
 * Player::Player() : Player{"None", 0, 0}{
 * }
 * 
 * Delegate to the three arg constructor and provide name_val 0 and 0 as arguments.
 * Player::Player(std::string name_val) : Player {name_val, 0, 0}{
 * }
 * Can't call the other constructors from the body in the delegating constructors. Also  can't delegate to another constructor and provide initialization values to class member.
 * 
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
        // Overloaded constructors
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
};

Player::Player(std::string name_val, int health_val, int xp_val): name{name_val}, health {0}, xp {0}{
     cout << "Three-args constructor\n";
}

Player::Player() : Player{"None", 0, 0}{
    cout << "No-args constructor\n";
}

Player::Player(std::string name_val) : Player {name_val, 0, 0}{
    cout << "One-args constructor\n";
}


int main(){
    Player empty;
    Player frank{"Frank"};
    Player villain {"Villain", 100, 55};

    // We've just created three string objects and then get rid of basically the string, the empty string they pointed to and replace it with Frank, Villan and None. So really really an inefficient thing to do.
    // => We want to use the initializer lists for the constructors.
    return 0;
}