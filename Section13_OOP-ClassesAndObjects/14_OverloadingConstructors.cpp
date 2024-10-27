/***
 * [Overloading Constructors]
 * Classes can have as many constructors as necessary
 * Each must have a unique signature
 * Default constructor is no longer compiler-generated once another constructor is declared => If there's any ambiguity, the compiler won't guess, it will generate a compiler error.
 * 
 * [Constructors and Destructors]
 * Overloaded Constructors
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
 * Obviously, the signatures for these constructors are different so the compiler can tell them apart. We could have more constructors depending on our class design.
 * We don't want garbage data in any of the attributes after they're created
 * Player::Player(){
 *      name = "None";
 *      health = 0;
 *      xp = 0;
 * }
 * 
 * Player::Player(std::string name_val){
 *      name = name_val;
 *      health = 0;
 *      xp = 0;
 * }
 * 
 * Player::Player(std::string name_val, int health_val, int xp_val){
 *      name = name_val;
 *      health = health_val;
 *      xp = xp_val;
 * }
 * 
 * Player empty;                                        // None, 0, 0
 *  
 * Player hero {"Hero"};                                // Hero, 0, 0
 *  
 * Player frank {"Frank", 100, 4};                      //  Frank, 100, 4
 * 
 * Player *enemy = new Player("Enemy", 1000, 0);        // Enemy, 1000, 0
 * delete enemy;
 * ***/