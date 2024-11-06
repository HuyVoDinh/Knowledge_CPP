/***
 * [Friends of a class]
 * Friends class have always been a controversial topic in C++. The controversy is about encapsulation. And whether friends violate encapsulation or enhance it.  
 * 
 * Friend 
 *  A function or another class that has access to private class member
 *  And that function of or class is NOT a member of the class it is accessing
 * 
 * => Can be standalone functions or member methods of another class. In the case of another class, the entire class will have access to the private information of the class granting friendship. Friends have unfettered access to both public and private data member of a class but they're not members of the class.
 * 
 * Function 
 *  Can be regular non-member functions 
 *  Can be member methods of another class
 * 
 * Class
 *  Another class can have access to private class members. 
 * 
 * Friendship must be granted NOT taken
 *  Declared explicitly in the class that is granting friendship
 *  Declared in the function prototype with the keyword friend
 * 
 * Friendship is not symmetric
 *  Must be explicitly granted
 *      If A is a friend of B
 *      B is not a friend of A
 * 
 * Friendship is not transitive
 *  Must be explicitly granted
 *      If A is a friend of B AND
 *      B is a friend of C
 *      then A is NOT a friend of C
 * 
 * Friendship is not inherited.
 * [non-member function]
 * class Player{
 *      friend void display_player(Player &p);      //=> Declaring a standalone non-member function as a friend of the player class. Notice that the player class grants the friendship by declaring the function prototype preceded by the friend keyword. Now the display player function has access to everything in the player class. 
 *      std::string name;
 *      int health;
 *      int xpl
 *  public: 
 *      ... 
 * };
 * 
 * void display_player(Player &p){
 *      cout << p.name << std::endl;
 *      cout << p.health << std::endl;
 *      cout << p.xp << std::endl;
 * }
 * 
 * display_player may also change private data members. don't have to go thorough public getter or setters to display the player information or set information. Can directly access the private class attribute. 
 * In fact, we can change them as well if we wanted to since the object is passed by reference an in this case non-const. 
 * 
 * [Member function of another class]
 * class Player{
 *      friend void Other_class::display_player(Player &p);      //=> we're declaring the display player method of the other class as a friend. That method will now have access to everything in the player class
 *      std::string name;
 *      int health;
 *      int xpl
 *  public: 
 *      ... 
 * };
 * 
 * class Other_class{
 *      ... 
 *  public: 
 *      void display_player(Player &p){         // Notice that it is indeed a member of the other class. But can use the player class-s private attributes directly within it. 
 *          cout << p.name << std::endl;
 *          cout << p.health << std::endl;
 *          cout << p.xp << std::endl;
 *      }
 * };
 * 
 * [Another class as a friend]
 * class Player {
 *      friend class Other_class;               // Declare the class other class as a friend of player. So all the methods in the Other_class will have access to the player classes private attributes. 
 *      std::string name;
 *      int health;
 *      int xp;
 *  public:
 *      ... 
 * };
 * 
 * Friendship can bypass function call overhead associated with getters and setters and other class methods and allow direct access to private attributes. Sometimes we have classes that use other classes and writing code using getters and setters becomes long tedious and sometimes give you overhead. 
 * However, that shouldn't be the only reason for granting friendship. Friendships should be granted only when it makes sense in the design of your system and then only the minimal necessary friendship should be granted
 * ***/