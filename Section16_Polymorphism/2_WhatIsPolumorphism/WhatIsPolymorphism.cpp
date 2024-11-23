/****
 * [Polymorphism]
 * 
 * What is Polymorphism?
 *  Fundamental part of object-oriented programming.
 * 
 *  Polymorphism    => They simply mean before the program executes. In other words, something the compiler takes care of way before the program runs.
 *      Compile-time/early binding/static binding 
 *      Run-time/late binding/dynamic binding   => all refer to the association of what the programmer wants to do with how to do it but at runtime as the program executes. 
 * 
 *  Runtime polymorphism
 *      Being able to assign different meanings to the same function at run-time
 * 
 *  Allows us to program more abstractly
 *      Think general vs. specific
 *      Let C++ figure out which function to call at run-time. => In C++ the default type of binding is static binding. This makes sense since C++ is all about efficiency and static binding is done before runtime so programs can be as fast as possible. However, sometimes we want to defer decisions until run time.  In C++ we can opt into this behavior by using base class pointers or references and declaring our functions as virtual functions. 
 * 
 *  Not the default in C++, run-time polymorphism is achieved via 
 *      Inheritance
 *      Base class pointers or references
 *      Virtual functions
 * 
 * Type of Polymorphism in C++?
 *  <Section16_WhatIsPolymorphism1.png> 
 * => Comp8ile-time polymorphism includes function overloading and operator overloading. We also have runtime polymorphism. We achieve runtime polymorphism by overriding functions and using inheritance, using virtual functions and then having base class pointers and references. 
 * 
 * An non-polymorphic example - Static Binding
 * 
 *  Account a;
 *  a.withdraw(1000);       // Account::withdraw()
 * 
 *  Savings b;
 *  b.withdraw(1000);       // Savings::withdraw()
 * 
 *  Checking c;
 *  c.withdraw(1000);       // Checking::withdraw()
 * 
 *  Trust d;
 *  d.withdraw(1000);       // Trust::withdraw()
 * 
 *  Account *p = new Trust();
 *  p->withdraw(1000);      // Account::withdraw()
 *                          // should be
 *                          // Trust::withdraw()
 *  <Section16_WhatIsPolymorphism2.png> 
 *  non-polymorphic example that uses static binding. In this case have an account hierarchy using public inheritance. We'll assume that every type of account class has its own version of the withdraw method and each withdraw method is different depending on the type of account. 
 *  Create four objects, one for each type of account and call their withdraw methods. When we call account withdraw method, it will call accounts withdraw. This makes sense since a is an account object. The compiler knows this and binds this method call at compile-time or statically. 
 *  The same applies to objects b c and d. In each case, the compiler is binding the calls to withdraw based on the information that is has about the objects when they were declared in the source code. So b withdrawal calls savings withdraw, c withdraw calls checking withdraw, and d withdraw calls trust withdraw.
 *  At the pointer p, p is a pointer to an account object. So p contains the address of an account object. Create a trust account dynamically on the heap and assign its address to p. p can hold addresses of accounts and trust is an account. Using static binding by default so the compiler doesn't really know that type of account object p is pointing to at runtime. 
 *  All it knows is that p is pointing to an account. So it will call the account withdraw method. This is probably not what we expected. 
 *  It certainly isn't what we wanted since we want the trust object on the heap to use its own version of withdraw. 
 * 
 * An non-polymorphic example - Static Binding
 * 
 *  void display_account(const Account &acc){
 *      acc.display();
 *      // will always use Account::display
 *  } 
 * 
 *  Account a;
 *  display_account(a);
 * 
 *  Saving b;
 *  display_account(b);
 * 
 *  Checking c;
 *  display_account(c);
 * 
 *  Trust d;
 *  display_account(d);
 * 
 *  <Section16_WhatIsPolymorphism2.png>
 *  Display method that displays account information based on the type of account we have. Since all our derived classes are accounts, we can pass any of them into this function, and this function will call the display method for the account object passed in. 
 *  Create 4 objects: a b c and d, one for each type of account and then it calls display account and passes in each of these objects to the function. The behavior you get from the display account function may not be what you expect. But by default C++ is doing exactly what it's supposed to do, static binding. 
 *  When the compiler sees the call to acc.display in the display account function, it will bind the call to accounts display. So accounts display method will be called regardless of what object was passed in, and our display will only display whatever is in the account part of us. 
 *  There is a way for C++ to ask the account object being passed in. And then depending on that, we can have if else statements that call the appropriate display methods. That's bad coding practice, and it also makes us program less abstractly since then we've got to figure out what kind of object we've got and then call its functions. 
 *  THat's where runtime polymorphism comes in. 
 * 
 * A polymorphic example - Dynamic Binding
 * withdraw method is virtual in Account
 *  Account a;
 *  a.withdraw(1000);       // Account::withdraw()
 * 
 *  Savings b;
 *  b.withdraw(1000);       // Savings::withdraw()
 * 
 *  Checking c;
 *  c.withdraw(1000);       // Checking::withdraw()
 * 
 *  Trust d;
 *  d.withdraw(1000);       // Trust::withdraw()
 * 
 *  Account *p = new Trust();
 *  p->withdraw(1000);      // Trust::withdraw()
 * 
 *  <Section16_WhatIsPolymorphism2.png> 
 *  Virtual functions. This allow us to use runtime polymorphism when using base class pointers or references. Since we're not using base class pointers or reference, these example are all statically bound just like before.
 *  In pointer p, when we call the withdraw method of the object pointed to by p, the trust withdraw method will be called. The idea of using virtual functions tells the compiler not to bind the calling compile time but instead defer the binding to runtime. And at runtime, a check will occur to see exactly what p is pointing to and then that object's method will be called.
 *  In this case, the trust withdraw method.  
 * 
 *  void display_account(const Account &acc){
 *      acc.display();
 *      // will always call the display method depending on the object's type at RUN-TIME
 *  }
 *  => Now we have virtual display functions in our account class. So whenever we use a pointer or a reference to a base class, the binding is done at runtime, not at compile time. When pass these objects to the display account function, the binding of acc.display will take place at runtime and call the display method based on the type of object being passed in. 
 *  Now can write functions, methods and data structures that use pointers and references to base class objects, and I know that the correct methods will be called at runtime. 
 * ****/

#include <iostream>
#include <memory>

class Base{
    public:
        void say_hello() const{
            std::cout << "Hello - I'm a Base class object\n";
        }
};

class Derived : public Base {
    public:
        void say_hello() const{
            std::cout << "Hello - I'm a Derived class object\n";
        }
};

void greeting(const Base &obj){
    std::cout << "Greetings";
    obj.say_hello();
}

int main(){
    // The idea would be that if I have a derived object and I pass it into this function, I'd say greetings and then hello - I'm a derived class object, that's not what happens because we're doing static binding.
    Base b;
    b.say_hello();
    // There is no virtual, we haven't really talked about virtual yet, but you'll see the word virtual in here when we buy into dynamic polymorphism. So the compiler sees this class hierarchy. It doesn't see anything virtual so there's not going to be any dynamic polymorphism here. It knows that is needs to bind everything statically.
    // And also, we're not coming at this with a base pointer.

    Derived d;
    d.say_hello();
    // Compiler knows that d is a type of derived. Its type is derived. So in this case, it's going to bind this method. 

    // There's no pointers and no virtual methods, everything is static. So if we run this, what expect is we expect this say hello to say hi I'm a base class object.

    greeting(b);
    greeting(d);
    // Derived is a base. That's what inheritance hierarchy is doing for me. So what I expect here would be for the b to say greetings hello I'm a base and the d to say greetings hello I'm a derived, but that's not what happens because we've got static binding going on.
    // There's the output greetings, hello I'm a base in b and d. Because We're not using dynamic polymorphism. And as far as the compiler is concerned, obj is a reference to a base. Then that will always bind to Base::say_hello(). The same thing happens when we've got a base.

    Base *ptr = new Derived();
    //This really says that ptr can hold the address of any base object. Derived is a base object. A derived is a base that's what the inheritance is telling me.
    // Derived object, creating on the heap. No attributes or anything, but this guy is pointing. Because this is a base. So that's valid.
    // <Section16_WhatIsPolymorphism3.png>
    // The problem comes in now when try to call ptr say_hello. 
    ptr->say_hello();
    // We've got no dynamic polymorphism, no polymorphic functions. So what's going to happen is the compiler sees ptr is a pointer to a base. It's going to bind this to base hello. Base::say_hello(). So we'll always bind that to base say hello. And again this is probably not what we want.
    // We want dynamic polymorphism to figure out what I'm pointing to at runtime and call that appropriately.
    // In pointer, calling say hello through the pointer.  Even though I'm pointing to a derived object the compiler doesn't care. This is not being deferred to runtime so the compiler is binding it right now at compile time. You don't have to use raw pointers for this. We haven't talked about smart pointers yet but we will.
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();
    // And suppose I include memory that's where the smart pointers live. I could say something like a std::unique pointer, and we can have a unique pointer to a base, and we can call this ptr1, and then we could call make unique, which creates that pointer and the pointer is a derived this time.
    // If run this, you can see that even with smart pointer, there's a regular pointer, there's a smart pointer, they're both being statically
    
    // free or delete that pointer.
    delete ptr;
    return 0;
}