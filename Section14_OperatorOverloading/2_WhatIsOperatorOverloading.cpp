/***
 * [Operator Overloading]
 * 
 * What is Operator Overloading?
 * 
 * Using traditional operators such as +, =, *, etc. with user-defined types
 * 
 * Allows user define types to behave similar to built-in types
 * 
 * Can make code more readable and writable
 * 
 * Not done automatically (expect for the assignment operator)
 * They must be explicitly defined
 * 
 * All the other operators that can be overloaded must be explicitly defined by the programmer
 * 
 * Suppose we have a Number class that models any number
 * 
 * Using function:
 *  Number result = multiply(add(a,b), divide(c,d));
 * Using member methods:  
 *  Number result = (a.add(b)).multiply(c.divide(d));
 * 
 * Are these statements very unreadable and very difficult to write? Maybe it depends on your perspective, but the point is that we're adding dividing and multiplying and we're been using these operator to do that. Why can't we use them now?
 * => C++ doesn't know what to do with our user-defined types. In most cases, it makes no sense to add or multiply or subtract your objects. 
 * For example, what does it mean to subtract two player objects in a game or multiply two account objects? It's totally dependent on what you want to do. 
 * In many case, it doesn't make sense to overload certain operators for your classes. In those case don't do it. Only do it if it makes sense
 * In this example, I would argue that it does make sense since the users of the number class would know the meaning and how to use those operators we would overload. 
 * 
 * 
 * Suppose we have a Number class that models any number
 * 
 * Using overloaded operators       //user-defined number class. Looks and feels and behaves like the build-in c+ types. Operator overloading is syntactic sugar. Behind the scenes, we're still calling methods or functions
 *  Number result = (a+b)*(c/d);
 * 
 * What operators can be overloaded?
 *  The majority of C++'s operators can be overloaded
 *  The following operators cannot be overload. We can't overload the scope resolution operator, the conditional operator, the pointer to member operator, the dot operator and the sizeof operator. Just because an operator can be overloaded doesn't mean you should.  Don't overload it unless it makes sense and makes your code. more usable, more readable and more writable. 
 *  
 *  |   Operator    |
 *  |       ::      |
 *  |       :?      |
 *  |       .*      |
 *  |       .       |
 *  |       sizeof  |
 * 
 * 
 * Some basic rules:    => So as always, there are some basic rules that must be followed when you're overloading operators. 
 *  Precedence and Associativity cannot be changed          => First the precedence and associativity of the operator that you're overloading cannot be change. This makes perfect sense since c+ programmers are already familiar with the precedence and associativity of its operators. 
 *  'arity' cannot be changed (i.e) can't make the division operator unary      => So if an operator is a binary operator which means that it's applied to two arguments, then this can't be changed. C++ does now allow you to change the way that the current operators work with the built-in types.
 *  Can't overload operators for primitive type (e.g. int, double, etc)
 *  Can't create new operators              => C++ does it all you create new operators that are not currently used by c++. 
 *  [], (), ->, and the assignment operator (=) must be declared as member methods
 *  Other operators can be declared as member methods or global functions           => And finally, c++ allows you to overloaded operators using global functions or member methods. However, there are several operators that must be implemented as member methods as you can see. Notice that the assignment operator must be implemented as a member method. 
 * 
 * Some examples
 *  Left column shows examples of using operators with the built-in types. For example, we can use plus and equals for addition of integers, doubles and logs and assignment. We also use the insertion operator with many built-in types so that we can easily insert values into streams
 *  Right column using operators on user-defined types. The first is std::string. Can use the plus operator to concatenate strings, and we can compare strings using less than, greater than less than or equal to and so forth. We want to be able to overload some operators to concatenate Mystring compare them, assign them and so forth. 
 *  Last example is the player class. Does it make sense to overload operators for the player class? Maybe, It depends on what we;'re trying to achieve. For example, suppose we want to compare two player objects p1 and p2. We might only care about their health attribute, and this would do just that. 
 *  What about comparing two player objects with the equality operator, are we comparing names, health, xp, all of those attributes or just some of them. That's one of the issues with overloading operators. We can make the operator mean anything we want.  So we want to make sure that when we do overload operators it makes sense and the users of the class know about it.
 *  Finally, it would make sense to overload the stream insertion operator so that we can insert player objects into a stream. 
 * 
 * int                                      std::string 
 *  a = b + c                                   s1 = s2 + s3
 *  a < b                                       s1 < s2
 *  std::cout << a                              std::cout << s1
 * 
 * double                                   Mystring
 *  a = b + c                                   s1 = s2 + s3
 *  a < b                                       s1 < s2
 *  std::cout << a                              s1 == s2
 *                                              std::cout << s1
 * 
 * long                                     Player
 *  a = b + c                                   p1 < p2
 *  a < b                                       p1 == p2
 *  std::cout << a                              std::cout << p1
 * 
 * Mystring class declaration
 * 
 * class Mystring{
 *      private:
 *          char *str;      // C-style string           chose to include a raw pointer because it will allow us more practice with our copy and move constructors, and we'll also have to think about copy and move assignment when we overload the assignment operator. 
 *      public: 
 *          Mystring();
 *          Mystring(const char *s);
 *          Mystring(const Mystring &source);
 *          ~Mystring();
 *          void display() const;
 *          int get_length() const;
 *          const char *get_str() const;
 * };
 * ***/

#include <iostream>
#include "2_Mystring.h"

using namespace std;

int main(){
    Mystring empty;                     // no-args constructor      //Creating empty which is just an empty mystring object is going to call a no args constructor. 
    Mystring larry("Larry");            // overloaded constructor   //Creating larry, which again is a MyString object and going to initialize it to that string Larry using an overloaded constructor. 
    Mystring stooge {larry};            // copy constructor         //Got another Mystring called stooge.  and initializing with Larry. So there we have a copy constructor call

    empty.display();                                                //Doing is calling the display method for each one onf those objects which is going to display emplty string, larry and Larry again since we copied it 
    stooge.display();

    return 0;
}