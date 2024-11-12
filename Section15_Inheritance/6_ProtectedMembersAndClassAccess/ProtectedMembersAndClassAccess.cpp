/***
 * [Protected Members and CLass Access]
 * The protected class member modifier
 * class Base{
 *  protected:
 *      //protected Base class members...
 * };
 * 
 * Accessible from the Base class itself
 * Accessible from classes Derived from Base
 * Not accessible by object of Base or Derived
 * 
 * The protected class member modifier
 * 
 * class Base {
 *  public: 
 *      int a;      // public Base class members... 
 *  protected: 
 *      int b;      // protected Base class members... 
 *  private: 
 *      int c;      // private Base class member... 
 * };
 * 
 * Access with public inheritance
 * 
 * Base Class                                   Access in Derived Class
 * public: a                public                  public: a
 * protected: b          inheritance                protected: b
 * private : c                                      c: no access
 * => Each type individually since the access depends on the type of inheritance involved. 
 * Public class members are inherited and they're also public in the derived class. 
 * Protected class member are inherited, and they're also protected in the derived class. 
 * private class members are also inherited, however, the derived class does not have access to them. Protected class member will be accessible by all derived classes. 
 * Any attempt to access base class private class members from the derived class will result in a compiler error. Somethins marked as private in the base class implies that developer of the base class doesn't want to grant access to those class members.
 * 
 * Base Class                                   Access in Derived Class
 * public: a             protected                  protected: a
 * protected: b          inheritance                protected: b
 * private : c                                      c: no access
 * => This is not a inheritance. 
 * The public-based class members are protected in the derived class. 
 * Protected base class members are protected in the derived class. 
 * Private-based class members are not accessible from the derived class.
 * 
 * Base Class                                   Access in Derived Class
 * public: a               private                  private: a
 * protected: b          inheritance                private: b
 * private : c                                      c: no access
 * => private inheritance is not a inheritance. 
 * the base class public and protected class members are private in the derived class, and the private class members are not accessible form derived class. 
 * 
 * ***/

#include <iostream>
using namespace std;

class Base{
    // Note friends of Base have access to all
    public:
        int a {0};     
        void display() {
            std::cout << a << ", " << b << ", " << c << endl;
        }
    protected:
        int b {0};
    private:
        int c {0};
};

class Derived : public Base{
    // Note friends of Derived have access to only what Derived has access to

    // a will be public     => a is public in parent so it's public in Derived
    // b will be protected  => b is protected in parent so it's protected in Derived
    // c will not be accessible      => C is  private in parent, Inherit in but it is not accessible. 
    public:
        void access_base_members(){
            a = 100;    // OK
            b = 200;    // OK | It's protected in parent, so it's protected. This is a member function. It's got access to it.
            //c = 300;    // It's not accessible, compiler error. If you need to access c or modify c, you can't do it directly from derived. You'll have to go thorough some getter function or setter function provided in the base class, but we'll talk about that later. So let's compile this now, and we expect to get a compiler error => C is not accessible.
        }
};

    int main(){
        cout << "====Base member access from base objects====\n";
        Base base;
        base.a = 100; // OK
        //base.b = 200; // Compiler error
        //base.c = 300; // Compile error because as far as the compiler is concerned, the protected and private access modifiers really are the same when it comes to objects. So this object base has no business messing with b or c because they're protected and the other one is private. 
                            // One says b is protected and the other one should say c is private. 

        cout << "====Base member access from derived objects====\n";
        Derived d;
        d.a = 100;  //OK       // a is public so that to work.
        //d.b = 200;  //Error      // b and c protected and not accessible. Don't have access to protected data, and I certainly don't have access to something that;s not accessible.
        //d.c = 300;  //Error
        return 0;
    }