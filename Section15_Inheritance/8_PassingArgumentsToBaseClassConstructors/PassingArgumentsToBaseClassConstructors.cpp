/***
 * [Inheritance]
 * 
 * Passing arguments to base class constructors
 * 
 * The Base part of a Derived class must be initialized first   => then we know that some base class constructor must be invoked to do that initialization. 
 * 
 * How can we control exactly which Base class constructor is used during initialization?
 * => We can determine which base constructor to be used based on the arguments that we want to pass to it from the derived class. 
 * 
 * We can invoke the whichever Base class constructor we wish in the initialization list of the Derived class
 * 
 * Passing arguments to base class constructors
 * -> This case, we're passing the integer x to our base class constructor when it's invoked. 
 * Can have initializers for the derived classes attributes as needed. Finally, have the code in the body
 * But remember, this code executes after both the base and Derived parts of the Derived object have been initialized. 
 * If we don't explicitly invoke the base overloaded constructor. Then the no args constructor will be invoked automatically since remember the base part must be initialized. 
 * class Base{
 *  public:
 *      Base();
 *      Base(int);
 *      ...
 * };
 * 
 * Derived::Derived(int x) : Base(x), {optional initializers for Derived}{
 *      //code
 * }
 * 
 * Constructors and class initialization
 * class Base{
 *      int value;
 *  public: 
 *      Base () : value{0}{
 *          cout << "Base no-args constructor\n"; 
 *      }
 *      
 *      Base (int x) : value {x} {
 *          cout << "int Base constructor\n";
 *      }
 * };
 * 
 * class Derived : public Base {
 *      int doubled_value;
 *  public: 
 *      Derived () : Base {}, doubled_value {0} {       //=> It explicitly invokes the base no args constructor and then initializes its own doubled_value attribute. Finally, it displays drive no args constructor.
 *          cout << "Derived no-args constructor\n";
 *      }
 * 
 *      Derived (int x) : Base {x}, doubled_value {x*2} {   // => overloaded constructor that expects an integer parameter. This constructor also invokes the base class overloaded in constructor in its initializer list. And then it initializes its own doubled_value attribute to 2 times x. Finally, it displays int derived constructor. Note that we could have implemented the overloaded constructors as delegating constructors. 
 *          cout << "int Derived constructor\n";
 *      }
 * };
 * 
 * -> First, let's create a simple base object with no parameters. In this case, the base no args constructor is called. 
 * In this second example, we're creating a base object and providing an integer initialization argument. 
 * This will invoke the overloaded int base constructor as we would expect. 
 * In the third example, creating a derived object with no parameters. This will invoke the Derived no args constructor which, in turn, will invoke the base no args constructor from its initialization list. Once the base part is initialized, then the rest of the Derived no args constructor executes. 
 * The last example, creating a derived object with an integer initialization argument. So the derived int derived constructor is invoked, and then we explicitly invoke the int base constructor from it. The first int base constructor executes and then the int derived constructor. Of course, all these objects will be destroyed by the destructors when they go out of scope. We have complete control as to which base class constructors to invoke from our derived class constructors. 
 *                                              Output
 * Base base;                       Base no-args constructor
 * 
 * Base base {100};                 int Base constructor
 * 
 * Derived derived;                 Base no-args constructor
 *                                  Derived no-args constructor
 * 
 * Derived derived {100};           int Base constructor
 *                                  int Derived constructor
 * ***/

#include <iostream>

using namespace std;

class Base{
    private:
        int value;
    public:
        Base() : value{0} {cout << "Base no-args constructor\n";}
        Base(int x) : value{x} {cout << "Base (int) overloaded constructor\n";}
        ~Base() {cout << "Base destructor\n";}
};

class Derived : public Base{
    private:
        int doubled_value;
    public:
        Derived() : Base{}, doubled_value {0} {cout << "Derived no-args constructor\n";}
        Derived (int x) : Base{x}, doubled_value {x*2} {cout << "Derived (int) overloaded constructor\n";}
        ~Derived () {cout << "Derived destructor\n";}
};

int main(){
    //-> I've got no initialization information. So I expect no args derived constructor be called. In this case, I'm explicitly invoking my base class constructor also the no args constructor. Before attributes are initialized, doubled_value is my attribute in derived class. Before attributes were initialized before the body of the derived constructor is initialized, the base part of me will be initialized. Then the base no args constructor is called it'll set that value in the base to 0. It'll display base no args constructor.
    //-> Then initialize doubled_value to 0 and that will indeed be 0. The value in the bases as well as the doubled_value that just got initialized to 0 in the initializer list. Then display derived no args constructor and  object is constructed. So when it goes out of scope, the destructors will be called in the reverse order. Then we come up to here and execute our base destructor. We'll display that as well.
    Derived d;
    //Creating a d object which is a derived object, and we're using a 1000 as initializer. Derived (int x) constructor invoked because it expects. That's the overloaded integer constructor. Before we initialize our own variables, before we do anything in the body of the constructor, our base needs to be initialized.  So in this case, I'm explicitly invoking base class constructor with the variable x that was passed into me. So Base(int x) will be invoked. The value will be set to x, a 1000 and then  display the message, then I come back to my derived overloaded constructor and finish off here. doubled_value was initialized to 2000. And just about to display this . 
    Derived d2 {1000};
    return 0;
}