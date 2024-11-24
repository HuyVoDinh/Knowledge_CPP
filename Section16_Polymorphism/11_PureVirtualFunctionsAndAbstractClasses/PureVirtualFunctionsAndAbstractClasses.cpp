/***
 * [Polymorphism]
 * Pure virtual functions and abstract classes
 * 
 *  Abstract class
 *      Cannot instantiate objects
 *      These classes are used as base classes in inheritance hierarchies
 *      Often referred to as Abstract Base Classes
 * 
 *  Concrete class
 *      Used to instantiate objects from
 *      All their member functions are defined
 *          Checking Account, Savings Account
 *          Faculty, Staff
 *          Enemy, Level Boss
 * 
 *  Abstract base class
 *      Too generic to create objects from
 *          Shape, Employee, Account, Player
 *      Serves as parent to Derived classes that may have objects   => In order for a class to be an abstract base class, it must contain at least one pure virtual function. 
 *      Contains at least one pure virtual function
 * 
 *  Pure virtual function
 *      Used to make a class abstract
 *      Specified with "=0" in its declaration      // Declared pure virtual functions just like virtual function, add the =0 after the prototype. Typically, pure virtual functions don't have any implementation since it's really up to the derived concrete classes to define this behavior, but it is possible to give them an implementation. Whatever class this function is declared in is now an abstract class amd cannot be instantiated. 
 *          virtual void function () = 0;   // pure virtual function
 *      Typically do not provide implementations
 * 
 *  Pure virtual function
 *      Derived classes MUST override the base class => Pure virtual function makes a class abstract, which means we can't directly instantiate them. We must override the pure virtual functions in the base class in order to be a concrete class.
 *      If the Derived class does not override then the Derived class is also abstract
 *      Used when it doesn't make sense for a base class to have an implementation
 *          But concrete classes must implement it
 *              virtual void draw() = 0;        // Shape        => That not only makes it an abstract class, but it also forces all derive classes to implement the draw method if they want to be concrete classes.
 *              virtual void defend () = 0;     // Player
 * 
 *  <Section16_PureVirtualFunctionsAndAbstractClasses1.png>
 *  The shapes that we would be drawing and manipulation would be lines, circles. squares and probably many others. So we weill have circle objects, line objects, square objects and so forth.
 *  A shape object is just an abstraction that we can use as a base class. If we declare two pure virtual functions draw and rotate in that shape class, then all derived classes must override these methods or they will also be abstract. 
 *  Open_shape and Closed_shape are all abstract classes since their names are italicized and line, circle and square are concrete classes. 
 * 
 *  class Shape {               // Abstract
 *      private:
 *          //attributes common to all shapes
 *      public: 
 *          // => It makes no sense to provide implementations for draw and rotate in the shape class sine we have no idea how to  draw or rotate the abstraction shape.
 *          virtual void draw() = 0;     // pure virtual function
 *          virtual void rotate() = 0;   // pure virtual function
 *          virtual ~Shape();
 *  };
 * 
 *  If this class overrides the draw and rotate virtual functions, then it becomes a concrete class, and we can instantiate circle objects.
 *  class Circle : public Shape {       // Concrete
 *      private: 
 *          //attributes for a circle
 *      public: 
 *          virtual void draw () override {
 *              // code to draw a circle
 *          }
 *          virtual void rotate () override {
 *              // code to rotate a circle
 *          }
 *          virtual ~Circle ();
 *          ...
 *  };
 * 
 *  Abstract Base class
 *      Cannot be instantiated          => Abstract base classes cannot be instantiated directly. If create a shape object shape, the compiler will give us an error.
 *          Shape shape;                //Error
 *          Shape *ptr = new Shape();   //Error -> Also create a shape object dynamically on the heap,  will also get a compiler error.
 *      We can use pointers and references to dynamically refer to concrete classes derived from them   => Notice that ptr is a pointer to a shape, and then create a circle object on the heap and point to it from ptr.  
 *          Shape *ptr = new Circle();  => It work because all concrete classes derived from shape must have overridden the draw and rotate methods. 
 *          ptr->draw();
 *          ptr->rotate();
 * ***/

#include <iostream>
#include <vector>

class Shape {           //Abstract Base class
    private:
        // attributes common to all shapes
    public:
        virtual void draw() = 0;        // pure virtual function
        virtual void rotate () = 0;     // pure virtual function
        virtual ~Shape(){}
};

class Open_Shape : public Shape {   //Abstract class
    public:
        virtual ~Open_Shape() {}
};

class Closed_Shape : public Shape {  //Abstract class
    public: 
        virtual ~Closed_Shape() {}
};

class Line : public Open_Shape {    // Concrete class
    public:
        virtual void draw() override {
            std::cout << "Drawing a line\n";
        }

        virtual void rotate () override{
            std::cout << "Rotating a line\n";
        }
        virtual ~Line() {}
};

class Circle : public Closed_Shape {    //Concrete class
    public:
        virtual void draw() override {
            std::cout << "Drawing a circle\n";
        }

        virtual void rotate() override {
            std::cout << "Rotating a circle\n";
        }
        virtual ~Circle() {}
};

class Square : public Closed_Shape {//Concrete class
    public:
        virtual void draw() override {
            std::cout << "Drawing a square\n";
        }

        virtual void rotate() override {
            std::cout << "Rotating a square\n";
        }
        virtual ~Square() {}
};

int main() {

    // Shape s;         =>It says cannot declare variable s to be of an abstract type shape. And same thing here with this new shape. Not allowed to instantiate shape objects.
    // Shape *p = new Shape();
    // Instantiate open shapes and close shapes we'd also get the same error because they are also abstract class.

    Circle c;
    c.draw();       // This is not coming at it with a base class pointer. This is all being statically bound. We're not using dynamic polymorphism. Real purpose of creating that abstract base class is so we can come at this class hierarchy with base class pointers or references.
    Shape *ptr = new Circle();
    ptr->draw();    // If call the draw and rotate methods through the base class pointer, what's going to happen is we're having dynamic polymorphism. So the function call will be bound at runtime, and call for the circle because that's what I'm pointing to so.
    ptr->rotate();  // The only difference here is that we're using those pure virtual functions to define an interface, if you will, at that base class level. And all our concrete classes must implement those pure virtual functions. And all our concrete classes must implement those pure virtual functions. Otherwise they are abstract themselves.
    
    Shape *p1 = new Circle();
    Shape *p2 = new Line();
    Shape *p3 = new Square();

    std::vector<Shape *> shapes {p1,p2,p3};
    for (const auto p : shapes)
        p->draw();

    delete p1;
    delete p2;
    delete p3;
    return 0;
}