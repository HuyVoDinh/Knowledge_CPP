/***
 * [Copy Constructor]
 * When objects are copied C++ must create a new object from existing object
 * 
 * When is a copy of an object made?
 *  passing object by value as a parameter
 *  returning an object from a function by value
 *  constructing one object based on another of the same class
 * 
 * C++ must have a way of accomplishing this so it provides a compiler-defined copy constructor if you don't
 * 
 * 
 * [Pass object by-value]
 * The default mode of passing data in C++ is by value, which means a copy is made.
 * 
 * Player hero {"Hero", 100, 20};
 * 
 * void display_player(Player p){ //p is created and COPY of hero using the copy constructor
 *  // Notice that p is local to the display_player function. Soi when p goes out of scope, the destructor will be called as well.
 *  // use p
 *  // Destructor for p will be called
 * }
 * 
 * display_player(hero);
 * 
 * [Return object by value]
 * Player enemy;
 * 
 * Player create_super_enemy(){
 *  Player an_enemy {"Super Enemy", 1000, 1000};
 *  return an_enemy;        // A Copy of an_enemy is returned
 * //Since we're returning an enemy by value. A copy of the enemy object is made by the copy constructor.
 * }
 * 
 * enemy = create_super_enemy();
 * 
 * [Construct one object based on another]
 * 
 * Player hero {"Hero", 100, 100};
 * Player another_hero {hero};  // A COPY of hero is made
 * 
 * 
 * [Copy Constructor]
 * If you don't provide your own way of copying objects by value then the compiler provides a default way of copying objects
 * 
 * Copies the values of each data member to the new object
 *  default member-wise copy => That means that it'll go through the class attributes and copy them from the source object to the target object
 * 
 * Perfectly fine in many cases
 * 
 * Beware if you have a pointer data member
 *  Pointer will be copied => If you're using raw pointers, then only the pointer will be copied, not the data, that it's pointing to.
 *  Not what it is pointing to
 *  Shallow vs. Deep copy 
 * 
 * [Best practices]
 * Provide a copy constructor when your class has raw pointer members
 * Provide the copy constructor with a const reference parameter
 * Use STL classes as they already provide copy constructors
 * Avoid using raw pointer data member if possible or use smart pointers
 * 
 * [Declaring the Copy Constructor]
 * Type::Type(const Type &source);  => It's a constructor, so it has the same name as the class. In the parameter list, we have a single object passed in of the same type. We pass that object in as a reference and a constant.
 * => Why by reference and constant? First, if we pass it in by value then we have to make a copy of it. That's the whole point of the copy constructor. We would defeat the purpose and end up with never ending recursive calls. And as a constant because the semantics of copying means that we're copying the source, we're not modifying it. So the const prevents any modification to the source object
 * 
 * Player:: Player(const Player &source);
 * 
 * Account::Account(const Account &source);
 * 
 * [Implementing the Copy constructor]
 * Type::Type(const Type &source){
 *      // code or initialization list to copy the object
 * => We do whatever we need to initialize our new object. We have access to source, so we can reference any attributes we want from source. Bur rather than write assignment statements in the constructor body. We can use a constructor initialization list as we've done before.
 * 
 * }
 * 
 * 
 * Notice that we're initializing the newly created object attributes. in the initializer list based on the source object's attributes.
 * Player:Player(const Player &source) : name {source.name}, health {source.health}, xp {source.xp}{
 * => Any code we write in the constructor body will be executed immediately after the new object is initialized.
 * }
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
        std::string get_name() {return name;}
        int get_health() {return health;}
        int get_xp () {return xp;}
        Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
        //Copy constructor
        Player(const Player &source);
        //Destructor => this thing is going to be destroyed because it's going to be very important so that we understand the life cycle of these object
        ~Player() {cout << "Destructor called for: " << name << endl;};
};

Player::Player(std::string name_val, int health_val, int xp_val): name{name_val}, health {0}, xp {0}{
     cout << "Three-args constructor\n";
}

Player::Player(const Player &source) : name {source.name}, health {source.health}, xp {source.xp} // Step 3 - Step 1.3: We're in the copy constructor. We're making a copy of empty, and that copy is going to be called p. Then we just did the initialization. Now it;s going to say copy constructor made copy of None
{
    cout << "Copy constructor - made copy of: " << source.name << endl;
}

void display_player(Player p) //Step 2: We have to make a copy of it. because we're doing pass-by-value or pass-by-copy. P is local to this function. So again, it's a copy of empty and it's on the stack
{
    //Step 4: p has been created. It's a copy of empty
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}
// Step 5: p is going out of scope right now. We;re going to leave this function so that stack frame needs to be cleaned up. So the destructor for p should be called. The destructor for the copy, not the destructor for empty. But the destructor for that p copy => Destructor has been called.

int main(){
    Player empty;
    display_player(empty);//Step 1
    Player frank{"Frank"};
    Player villain {"Villain", 100, 55}; // Step 1.1: villain has been created.

    Player my_new_object {villain}; // Want to copy from villain. This will call the copy constructor. That's the whole idea of making a copy.
    //Step 1.2: This is a constructor. I'm constructing or initializing or instantiating the jargons all the same a my_new_object which is a player. In this case, from villain object that I've already created, that's where the copy comes in.

    display_player(villain); // Step 1.4: Same empty;

    return 0;
}