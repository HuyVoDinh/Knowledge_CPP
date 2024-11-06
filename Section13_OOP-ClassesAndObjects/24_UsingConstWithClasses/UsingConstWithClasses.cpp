/***
 * [Using const with classes]
 * Pass arguments to class member methods as const
 * We can also create const objects
 * What happens if we call member functions on const objects?
 * const-correctness
 * 
 * [Creating a const object]
 * villain is a const object so it's attributes cannot change
 * => We can't change any of its attributes, that's the whole idea with it being const.
 * const Player villain {"Villain", 100, 55};
 * 
 * [Using const with classes]
 * What happens when we call member methods on a const object?
 * 
 * const Player villain {"Villain", 100, 55};
 * villain.set_name("Nice guy");                    // Error    => Obviously, this can't be allowed since the object is declared as const. And in fact, this produces a compiler error. The compiler complains that you're passing a const object as this to a method that could change it.
 * 
 * std::cout << villain.get_name() << std::endl;    // Error    => Not modifying the const object. simply getting a copy of its name for display. This won't compile either. in fact you get the same error that you get when you called set name.
 * => The compiler assumes that the get name function could potentially change the object, so it gives an error
 * 
 * Solution: Since we would like to call the getter methods and other methods that are public that don't modify the object. 
 * 
 * const Player villain {"Villain", 100, 55};
 * void display_player_name(const Player &p) {
 *      cout << p.get_name() << endl;
 * }
 * display_player_name(villain);                // Error
 * => We have a display_player_name function that expects a reference to a const object. And get a compiler error. 
 * The problem is that when we call p.get_name() in the display_player_name function. This pointer isn't expecting a const object, so get name could potentially change the object. The compiler is being very careful not to allow a const object to lose its constness.
 * 
 * 
 * Solution: Need to tell the compiler that specific methods will not modify the object. And all we have to do is put the const modifier before the semicolon and the method prototype. Now the compiler will not only allow this method to be called on const objects, it will also produce a compiler error if you try to modify any of the object attributes in the method. This idea of class methods having const qualifiers is part of what;s referred to as const correctness. Const correctness can get pretty complicated. 
 * class Player {
 *  private:
 *      ...
 *  public: 
 *      std::string get_name() const;
 *      // Error if code in get_name modifies this object.
 * };
 * => get_name works just fine, but the call to set_name is still not allowed since set name is not a const function.
 * const Player villain {"Villain", 100, 55};
 * villain.set_name("Nice guy");                    // Error
 * std::cout << villain.get_name() << std:endl     //OK
 * ***/

#include <string>
#include <iostream>

using namespace std;

class Player{
    private:
        std::string name;
        int health;
        int xp;
    public:
        std::string get_name() const{//add const to fix. We want to tell the compiler this method get_name is not modifying the object at all.
            // xp = 100;    //  error: assignment of member 'Player::xp' in read-only object. Error - changing something at a read-only object. This is const correctness. it can get pretty complicated. when you're passing things all over the place as const here, non-const here and so forth. But the rule of thumb is all your getters should be const. Basically, any method that you have in your class that doesn't modify the object should be const.
            return name;
        }

        void set_name(std::string name_val){\
            name = name_val;
        }

        void set_xp(int xpPlayer){
            xp = xpPlayer;
        }
        
        int get_xp(){
            return xp;
        }
        //Overloaded Constructors
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
};

Player::Player() : Player {"None", 0, 0} {

}

Player::Player(std::string name_val) : Player{name, 0,0}{

}

Player::Player(std::string name_val, int health_val, int xp_val) : name {name_val}, health{health_val}, xp {xp_val}{

}

void display_player_name(const Player &p){ // it expects p, which is a reference to a const player object. doing is getting that player object;s name and displaying it.
    cout << p.get_name() << endl;// error: passing 'const Player' as 'this' argument discards qualifiers [-fpermissive]. When call p.getname() as far as p.get_name() is concerned, that's const. It can't change it but there's no way to guarantee that
}

int main(){
    const Player villain {"Villain", 100, 55};
    //villain.set_xp(1000); //passing 'const Player' as 'this' argument discards qualifiers [-fpermissive]. Can't change any of villain
    //villain.set_name("Super Villain");
    //cout << villain.get_name() << endl; //error: passing 'const Player' as 'this' argument discards qualifiers [-fpermissive]. That sould work and you really think about it. Because it's not changing the object, it's simply returning that string and display it. But it won't work. It's going to give an error.
    Player hero {"Hero", 100, 15};
    // cout << hero.get_name() << endl; // work well because hero is not const. So the compiler doesn're really care if you change hero in that method or not.
    display_player_name(villain);      
    display_player_name(hero);          
    return 0;
}