/***
 * [Constructors and Destructors]
 * 
 * Constructors and class initialization
 * 
 * A derived class inherits from its Base class => This makes sense since the derived class might use base class information during its own initialization. So since constructors are responsible for object initialization, when a derived object is created, first the base class constructor executes, and then the drive constructor executes. 
 * 
 * The Base part of the Derived class MUST be initialized BEFORE the Derived class is initialized
 * 
 * When a Derived object is created
 *  Base class constructor executes then
 *  Derived class constructor executes
 * 
 * 
 * -> This is example we have a base class that has a no args constructor that simply displays base constructor. 
 * And we have a derived class that inherits publicly from base. THe drive class also has a no args constructor, and it displays derived constructor. 
 * Let's create a base class object and a derived class object and see how the constructors are called. 
 * class Base{
 *  public:
 *      Base(){cout << "Base constructor\n";}
 * };
 * 
 * class Derived : public Base {
 *  public Derived () {cout << "Derived constructor\n";}
 * };
 * 
 * -> Create a base object from the base class. In this case, there is no inheritance involved so we expect the base class constructor to be invoked and that's exactly what happens. 
 * Now if we create a derived class object, this is where things change. In this case, we have inheritance since the derived class is a base class. 
 * So c++ initializes the base part of the derived object first. You can see on the rhs of the slide that the base constructor is invoked first and then the derived constructor is invoked. 
 *                                  Output
 * Base base;               Base constructor
 * 
 * Derived derived;         Base constructor
 *                          Derived constructor
 * 
 * 
 * Destructor
 * 
 * Class destructors are invoked in the reverse order as constructors
 * 
 * The Derived part of the Derived class MUST be destroyed BEFORE the Base class destructor is invoked
 * 
 * When a Derived object is destroyed.
 *  Derived class destructor executes then
 *  Base class destructor executes
 *  Each destructor should free resources allocated in it's own constructors
 * 
 * class Base{
 *  public:
 *      Base(){cout << "Base constructor\n";}
 *      ~Base() {cout << "Base destructor\n";}
 * };
 * 
 * class Derived : public Base {
 *  public:
 *      Derived () {cout << "Derived constructor\n";}
 *      ~Derived () {cout << "Derived destructor\n";}
 * };
 * 
 *                                  Output
 * Base base;               Base constructor
 *                          Base destructor
 * 
 * Derived derived;         Base constructor
 *                          Derived constructor
 *                          Derived destructor
 *                          Base destructor
 * -> First, the base constructor is invoked and then the base destructor is invoked amd the object is destroyed
 * First the derived object must be initialized, and we know that the base part must be initialized before the derived part.
 * So can see that the base constructor is invoked and then the derived constructor is invoked. 
 * When the object is destroyed the opposite happens. First, the derived destructor is invoked, and then the base destructor is invoked. 
 * This order of construction and destruction occurs in the same. manner whether you have two classes or ten classes in the hierarchy. 
 * 
 * 
 * A derived class does NOT inherit
 *  Base class constructors
 *  Base class destructor
 *  Base class overloaded assignment operators
 *  Base class friend functions
 * 
 * However, the derived class constructors, destructor, and overloaded assignment operators can invoke the base-class version.
 * 
 * C++11 allows explicit inheritance of base'non-special' constructors with
 *  using Base::Base; anywhere in the derived class declaration => Sometime can see a using base scope operator base directive in the body of a derived class. For example, default copy and move constructors are not included. Each inherited constructor has the same access specifier as its corresponding base class constructor. If you provide an overloaded constructor in the derived class, then the base class overloaded constructor is not inherited. A base class's constructor default arguments are not inherited. 
 *  Lots of rules involved, often better to define constructors yourself.       => The using statement can be useful and save a bit of typing, but prefer not to use this feature and write out the constructors need in Derived classes and invoked the base class constructors as need.  It isn't that much more typing and it's very clear to programmers that come after you to modify your code exactly what you're doing. 
 * ****/

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
    // comment derived int constructor and uncomment using Base. That will do is it will allow us to inherit the non-special constructors from my base class. And this is a non-special constructor.You can think of the special constructors as a default, as a copy constructor that kind of thing. So now this will be inherited. 
    //=> Derived d {1000} will matches. So Base (int) will be call. That has a problem, because it's not going to deal with the double value
    //=> This time it compiled because it inheriting base(int x). So it's available in Derive, so it does match that integer. So going to initialize the base part of me to a 1000, but look at the state of d. Base is correct a 1000, but double_value never got initialized because simply inherited that. 
    //=> That's one of the issues with using automatically inheriting your non-special constructors. It'll take care of initializing the base part of you, but it won't take care of initializing the derived part of you.  So you really should do that yourself
    using Base::Base;
    private:
        int doubled_value;
    public:
        Derived() : doubled_value {0} {cout << "Derived no-args constructor\n";}
        Derived (int x) : doubled_value {x*2} {cout << "Derived (int) overloaded constructor\n";}
        ~Derived () {cout << "Derived destructor\n";}
};

int main(){
    Base a;
    Base b{100};
    Derived c;      // If Derived don't have constructor, it's going to call the base class constructor. It almost really just skipped own default constructor in the derived class. It's just not doing anything because it's compiler provided in base class. 
                    // If Derived have constructor, The base constructor gets called because before I start executing anything in this derived constructor, the base part of me must be initialized. So you can see when I select step here now I've invoked that base class default constructor. It's going to set value to 0, and say  base no args constructor. Then come back down Derived constructor, which sets doubled_value to 0 and then display that message
                        //Then destructor get called. First the destructor for the derived gets called, and then the destructor for the base gets called.  So the destructors happen in the order opposite from the constructors. 

    Derived d{100}; // If Derived have non arg constructor but don't have int constructor. It'll compiler error say that no matching function call. So basically, it can't find that constructor because it's not there.
                    //Otherwise, first overloaded constructor that expects an integer. the base part of me needs to be initialized. THe compiler is not going to guess as to which one of these to call. So it's simply going to call the no args version and set that value to 0. can see the no args version of the constructor is being called. It's set to value to 0.. Then the derived constructor gets called and finished off by initializing its double value to two times x. 
                        // And the state of this d object, you can see that the base is indeed 0 because that constructor took care of it and the double value is two thousand. . We probably wanted the value to be one 1000, not 0. But we didn't do that because we really don't know how to call these constructors yet. 
                        // Then obviously the destructors get called. 
    return 0;
}