/***
 * [Struct vs Classes]
 * In addition to define a class we can declare a struct 
 * struct comes from the C programming languages    
 * Essentially the same as a class expect   => everything can do with classes, can do with structs.
 *  members are public by default / member of a class are private by default. 
 * 
 * [class]
 * class Person {               // default, class members are private. So if we create a p object that's a person and try to access name or call get_name
 *      std::string name;
 *      std::string get_name();
 * };
 * 
 * Person p;                    // So if we create a p object that's a person and try to access name or call get_name, the compiler will give us a compiler error saying that we don't have access to those prite elements.
 * p.name = "Frank";            // compiler error - private
 * std::cout << p.get_name();   // compiler error - private
 * 
 * [struct]
 * 
 * struct Person{
 *      std::string name;
 *      std::string get_name();         
 * };
 * 
 * Person p;                    // Create the person object p and try to access its attribute or member function, the compiler is ok with it. That's because the default access for a struct is public. 
 * p.name = "Frank";            // OK - public
 * std::cout << p.get_name();   // Ok - public
 * 
 * [Some general guidelines]
 * struct
 *  Use struct for passive object with public access
 *  Don't declare methods in struct
 * 
 * class
 *  Use class for active objects with private access        // if your objects are active or they have complex behavior, then you should use a class and implement getter and setters and member methods as needed. 
 *  Implement getter/setters as needed
 *  Implement member methods as needed
 * 
 * => Don't use a struct and then make everything private in the struct so it behaves like a class, just use a class instead. 
 * ***/