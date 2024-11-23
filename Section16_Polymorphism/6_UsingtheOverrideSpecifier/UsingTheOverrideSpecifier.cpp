/***
 * [Polymorphism]
 *  The override specifier
 * => What if we inadvertently make a small change to the function signature by mistake? If this happens, then the functions we intended to override doesn't get overwritten at all. Instead it gets redefined, and we know that redefined functions are statically bound, not dynamically bound. 
 * This type of error is really hard to find sometimes since the function signatures look very similar and it may not be easy to spot the difference.  Can add this specifier to the method you're writing in your derived class, and the C++ compiler will ensure that you're indeed overriding and not redefining. 
 * 
 *      We can override Base class virtual functions
 *      The function signature and return must be EXACTLY the same
 *      If they are different then we have redefinition NOT overriding
 *      Redefinition is statically bound
 *      Overriding is dynamically bound
 *      C++11 provides an override specifier to have the compiler ensure overriding
 * 
 * class Base {
 *  public:
 *      virtual void say_hello () const {
 *          cout << "Hello - I'm a Base\n";
 *      }
 * 
 *      virtual ~Base() {}
 * };
 * 
 * class Derived : public Base {
 * public:
 *      virtual void say_hello () {     // Notice I forgot the const - NOT OVERRIDING -> The C++ compiler considers this function redefinition and not overriding. 
 *          cout << "Hello - I'm a Derived\n";
 *      }
 * 
 *      virtual ~Derived() {}
 *  };
 * 
 *  Base: virtual void say_hello() const;
 *  Derived: virtual void say_hello();          -> Will be statically bound, not dynamically bound. This will cause unexpected behavior when we use a base class pointer. 
 * 
 * Base *p1 = new Base();
 * p1->say_hello();             // Hello - I'm a Base
 * 
 * Base *p2 = new Derived();
 * p2->say_hello();             // Hello - I'm a Base
 * 
 * 
 * => P1 is pointing t oa base object, p2 is pointing to a derived object. When call say hello via p1, this will be bound dynamically and it will call bases say hello.
 * However, call say hello via pointer p2, I expect it to display hello I'm a Derived because I expected dynamic binding, but I messed up when created the function by not matching the signature exactly. So the function call is statically bound to base say hello. We can easily prevent this error by using the C++11 override specifier
 *  Not what we expected
 *  say_hello method signatures are different
 *  So Derived redefines say_hello instead of overriding it
 * 
 * 
 * class Base {
 *  public:
 *      virtual void say_hello () const {
 *          cout << "Hello - I'm a Base\n";
 *      }
 * 
 *      virtual ~Base() {}
 * };
 * 
 * class Derived : public Base {
 *  public:
 *      virtual void say_hello () override{     // Produces compiler error. Error: marked override but does not override. 
 *          cout << "Hello - I'm a Derived\n";
 *      }
 * 
 *      virtual ~Derived() {}
 *  };
 * 
 * => In this case, the compiler will produce an error, can add that const to fix the problem. 
 * ***/

#include <iostream>
using namespace std;

class Base {
 public:
     virtual void say_hello () const {
         cout << "Hello - I'm a Base\n";
     }

     virtual ~Base() {}
};

class Derived : public Base {
    public:
     virtual void say_hello () const override {   // Notice forget the const   => So it should have had a const there, but it doesn't. So now as far as the compiler is concerned. This class is redefining the base class function, not overriding it. So it's going to statically bind it rather than dynamically bind it.
        cout << "Hello - I'm a Derived\n";
     }

     virtual ~Derived() {}
 };

 int main() {

    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();

    Derived *p2 = new Derived();    // Derived::say_hello()
    p2->say_hello();

    Base *p3 = new Derived();
    p3->say_hello();        // The problem here is since didn't override instead redefined, this will not be bound dynamically, it'll be bound statically. So as far as the compiler is concerned, I've got a base pointer, so it's going to bind it to base say hello.
                            // => Redefined that function so it's going to be statically bound rather than dynamically bound.
                            // To fix it, just put const. But can also use the override keyword in C++11, which is really handy. You really should do this every time that you're going to overwrite a function in a derived class.
                            // Can put the override specifier at the end of the function prototype. When run will get an error. And the error says  error: 'virtual void Derived::say_hello()' marked 'override', but does not override. 
                            // Put const to fix
    return 0;
 }