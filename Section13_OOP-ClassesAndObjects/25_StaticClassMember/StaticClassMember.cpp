/***
 * [Static Class Members]
 * Class data members can be declared as static
 *  A single data member that belongs to the class, not the objects => When declare class data members as static, we telling c++ compiler that these data members belong to the class, not to any specific object.. So they're extreme useful to create class-wide information.
 *  Useful to store class-wide information
 *=> Example we wanted to know how many player objects we have active in our application at any point in time. We could create a global variable and the increment and decrement it in the code whenever we create an object or delete an object. This is really hard to do though since we really can't be sure when constructors are called and when the structures are being called.
  So a better solution is to create a static variable that's part of the player class and then we can manipulate that variable directly within the player class. and then whenever we need to know how many player objects there are we can simply ask the player class. We don't even need any objects. In fact, if the player count is 0 this means that there are no active player objects at all.
 *  
 * Class functions can be declared as static
 *  Independent of any objects
 *  Can be called using the class name
 * 
 * [Player class-static member]             
 * class Player {
 *  private: static int num_players;            // => We need to add a static data member to the class. We can do this very easily by adding a private static int name num_players. We'll initialize this to 0 a little bit later since we can't initialize it.
 *  public: static int get_num_players();       // => We also would need to declare a static class function that returns an integer. It'll return the static integer we just declared. A
 * };
 * 
 * [Player class- initialize the static data]
 * int Player::num_players = 0; //=> This is where we want to initialize the static integer num_players to 0. Notice that the syntax might look a litter strange. This is where define that variable and assign it to 0 in this case. This must happen exactly once and it typically happens in the .cpp file for the class.
 * 
 * [Player class - implement static method]
 * 
 * int Player::get_num_players(){       // Since this function is static, it only has access to static data members. It does not have access to non-static class data members. In this function, simply return num_players.
 *      return num_players;
 * }
 * => We need to increment and decrement the number of players whenever we create and destroy objects.
 * [Player class - update the constructor]
 * The best place to increment the player count is in the constructor. In this case, we simply increment num_players by 1. Be careful though if you have many overloaded constructors since you might have in increment num_players in more than one place. Anywhere you create an object.
 * Player::Player (std::string name_val, int health_val, int xp_val) : name {name_val}, health {health_val}, xp {xp_val} {
 *      ++num_players;
 * }
 * 
 * [Player class - Destructor]
 * our original player class didn't have a destructor. It used the compiler provided default destructor since it was all we needed. However, now we need to define our own destructor and decrement the number of players count when the object is destroyed. 
 * 
 * Player::~Player(){
 *      --num_players;
 * }
 * 
 * [main.cpp]
 * void display_active_players(){
 *      cout << "Active players: " << Player::get_num_players() << endl;        //
 * }
 * 
 * int main(){
 *      display_active_players();       // The first statement is display_active_players and it will display 0
 *      Player obj1 {"Frank"};          // As we add and remove player objects, we'call display active players. And it will display the current number of active player objects
 *      display_active_players();
 * }
 * ***/

