/***
 * [Polymorphism]
 *  What is using a class as an interface?
 *      An abstract class that has only pure virtual functions
 *      These functions provide a general set of services to the user of the class
 *      Provided as public      => Any class that wants to be a concrete class and support the interface provided by the interface class can override the pure virtual functions and implement these services as needed. 
 *      Each subclass is free to implement these services as needed
 *      Every service (method) must be implemented          => C++ will strictly enforce type information. When overriding the function, prototypes must match exactly. 
 *      The service type information is strictly enforced
 * 
 *  A printable example     => Unlike java, C# and other languages, C++ does not provide a specific keyword or way to create an interface as part of the C++ core language. So in C++, use abstract classes with pure virtual functions to achieve the concept of an interface.
 *      C++ does not provide true interfaces
 *      We use abstract classes and pure virtual functions to achieve it
 *      Suppose we want to be able to provide Printable support for any object we wish without knowing it's implementation at compile time
 *          std::cout << any_object << std::endl;
 *          any_object must conform to the Printable interface
 * 
 *  class Printable {
 *          friend ostream &operator<<(ostream &, const Printable &obj);
 *      public: 
 *          virtual void print(ostream &os) const = 0;
 *          virtual ~Printable() {};
 *  };
 * 
 *  ostream &operator<<(ostream &os, const Printable &obj) {
 *      obj.print(os);
 *      return os;
 *  }
 * 
 *  class Any_Class : public Printable {            // => Ist must be derived from printable, and it must override the pure virtual function print that's in the printable interface. So in this case, any class is derived from printable and it does override the print pure virtual function. 
 *      public: 
 *          // must override Printable::print()
 *          virtual void print(ostream &os) override{
 *              os << "Hi from Any_Class";
 *          }
 *  };
 * 
 * 
 * => First create ptr as a pointer 2 class and create an any class object. Then dereference the pointer to get that object, use it in an output statement. This will call the overloaded insertion operator, which will in turn, call the function print of any class, and this will display "Hi from any class". 
 * Function 1 expects an any class object by reference, and function2 expects a printable object by reference. Both these functions and pass in the object ptr is pointing to, because that object is an instance of any class and because that object is a printable.
 * In both cases, we get the same output. The print function in any class is bound dynamically.
 * 
 *  Any_Class *ptr = new Any_Class();
 *  cout << *ptr << endl;
 * 
 *  void function1 (Any_Class &obj) {
 *      cout << obj << endl;
 *  }
 * 
 *  void function2 (Printable &obj) {
 *      cout << obj << endl;
 *  }
 * 
 *  function1(*ptr);            // Hi from Any_Class
 *  function2(*ptr);            // Hi from Any_Class
 * 
 * => Have a shape class that only has pure virtual functions. So it's an abstract class, and it can also be used as an interface class. If want to be a concrete shape, then must be derived from shape and must override the draw and the rotate pure virtual functions. 
 *  class Shape{
 *      public: 
 *          virtual void draw() = 0;
 *          virtual void rotate() = 0;
 *          virtual ~Shape() {};
 *          ... 
 *  };
 * 
 * => If want a circle to be a concrete class, then must override draw and rotate. 
 *  class Circle : public Shape {
 *      public:
 *          virtual void draw() override {//code};
 *          virtual void rotate() override {//code};
 *          virtual ~Circle() {};
 *          ... 
 *  };
 * 
 * => Intended to be used as interface classes named with a capital I preceding the class name. This makes it easy to know just by the name that the class is intended to be used as an interface. 
 * In this example, shape was renamed to I shape. 
 *  A Shapes example
 *  class I_Shape{
 *      public: 
 *          virtual void draw() = 0;
 *          virtual void rotate() = 0;
 *          virtual ~I_Shape() {};
 *          ... 
 *  };
 * 
 *  class Circle : public I_Shape{
 *      virtual void draw()  override {//code};
 *      virtual void rotate() override {//code};
 *      virtual ~I_Shape() {};
 *      ... 
 *  };
 *  Line and Square class would be similar
 * 
 * 
 * => Use pointers to I_Shape objects to use dynamic polymorphism. Then create a vector of pointers to I_Shape objects, and then create three pointers and initialize them to point to three different types of shapes. In order to call the overridden functions in the concrete classes, we simply loop through the vector and call the functions. 
 * Since must use inheritance and pure virtual functions as interfaces in C++. But there's another difference. 
 *  vector <I_Shape *> shapes;
 *  I_Shape *p1 = new Circle();
 *  I_Shape *p2 = new Line();
 *  I_Shape *p3 = new Square();
 * 
 *  for (auto const &shape : shapes){
 *      shape->rotate();
 *      shape->draw();
 *  }
 *  //delete the pointers
 * ***/

#include <iostream>

class I_Printer{
    friend std::ostream &operator<<(std::ostream &os, const I_Printer &obj);
    public: 
        virtual void print (std::ostream &os) const = 0;
};

std::ostream &operator <<(std::ostream &os, const I_Printer &obj){  // => this function gets called with a printable or an I_Printable. It'll coming at it with a base class reference. It is going to use dynamic polymorphism to match the appropriate one.
    obj.print(os);
    return os;
}

//Example 1
// class Account {
//         // friend std::ostream &operator<<(std::ostream &os, const Account &acc);
//     public:
//         virtual void withdraw(double amount){
//             std::cout << "In Account::withdraw\n";
//         }
//         virtual ~Account() {};
// };

//Example 2
class Account : public I_Printer{
        // friend std::ostream &operator<<(std::ostream &os, const Account &acc);
    public:
        virtual void withdraw(double amount){
            std::cout << "In Account::withdraw\n";
        }
        virtual void print(std::ostream &os) const override {
            os << "Account display\n";
        }
        virtual ~Account() {};
};

// std::ostream &operator<<(std::ostream &os, const Account &acc){
//     os << "Account display\n";
//     return os;
// }


class Checking : public Account{
        // friend std::ostream &operator<<(std::ostream &os, const Checking &acc);
    public:
        virtual void withdraw(double amount){
            std::cout << "In Checking::withdraw\n";
        }
        //Example 2:
        virtual void print(std::ostream &os) const override {
            os << "Account display\n";
        }
        virtual ~Checking() {};
};

// std::ostream &operator<<(std::ostream &os, const Checking &acc){
//     os << "Checking display\n";
//     return os;
// }

class Savings : public Account{
        // friend std::ostream &operator<<(std::ostream &os, const Savings &acc);
    public:
        virtual void withdraw(double amount){
            std::cout << "In Savings::withdraw\n";
        }
        //Example 2:
        virtual void print(std::ostream &os) const override {
            os << "Account display\n";
        }
        virtual ~Savings() {};
};

// std::ostream &operator<<(std::ostream &os, const Savings &acc){
//     os << "Savings display\n";
//     return os;
// }

class Trust : public Account{
        // friend std::ostream &operator<<(std::ostream &os, const Trust &acc);
    public:
        virtual void withdraw(double amount){
            std::cout << "In Trust::withdraw\n";
        }
        //Example 2:
        virtual void print(std::ostream &os) const override {
            os << "Account display\n";
        }
        virtual ~Trust() {};
};

// std::ostream &operator<<(std::ostream &os, const Trust &acc){
//     os << "Trust display\n";
//     return os;
// }

//This is different from just regular inheritance from a base class. In this case, I can use this printable across hierarchies
void print (const I_Printer &obj){
    std::cout << obj << std::endl;
}

class Dog : public I_Printer{
    public:
    virtual void print(std::ostream &os) const override {
            os << "Woof woof\n";
        }
};

int main(){
    //=>The only virtual function we've got are withdraw. That's the only virtual function we have. We have no virtual function that's going to allow us to work with any kind of account object in the context of this operator here, and it's really clunky to do so because of the syntax
    // We could certainly add some kind of print function to this account class and it's inherited all the way down and make it virtual.
//Example 1 with friend function
//     Account *p1 = new Account();
//     std::cout << *p1 << std::endl;

//     Account *p2 = new Checking();
//     std::cout << *p2 << std::endl;

//     Account a;
//     std::cout << a << std::endl;

//     Checking c;
//     std::cout << c << std::endl;
// // 
//     Savings s;
//     std::cout << s << std::endl;
// // 
//     Trust t;
//     std::cout << t << std::endl;


//Example 2: Without friend function, using interface
    Dog *dog = new Dog();
    std::cout << *dog << std::endl;
    
    Account *p1 = new Account();
    std::cout << *p1 << std::endl;

    Account *p2 = new Checking();
    std::cout << *p2 << std::endl;
    return 0;
}