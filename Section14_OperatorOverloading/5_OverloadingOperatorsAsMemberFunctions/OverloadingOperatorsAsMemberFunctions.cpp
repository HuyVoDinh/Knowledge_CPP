/***
 * [Operator Overloading]
 * C++ allows to overload operators as member methods or as global non-member function.
 * Unary operators as member methods (++, --, -, !)
 * The the case that we have to return a new object from the method, we'll return the new object by value. 
 * Also notice that unary member methods have an empty parameter list. This is because the object we;re working with is referred to by the this pointer. So can see the prototypes for the unary operators. 
 * If we wanted them to work with our hypothetical number class. Also notice that we can overload both the pre and post decrement and increment operators. C++ simply provides an int that isn't used in the parameters for the post increment. 
 * 
 *  Return Type::OperatorOp();
 * 
 *  Number Number::operator-() const
 *  Number Number::operator++();                // pre-increment
 *  Number Number::operator++(int);             // post-increment
 *  bool Number::operator!()const;  
 * 
 *  Number n1{100};
 *  Number n2 = -n1;                            // n1.operator-()
 *  n2 = ++ n1;                                 // n1.operator++()
 *  n2 = n1++;                                  // n1.operator++(int)
 * 
 * Mystring operator- make lowercase
 * 
 *  Mystring larry1 {"LARRY"};
 *  Mystring larry2;
 *  
 *  larry1.display();                           // LARRY
 *  larry2 = -larry1;                           // larry1.operator-()
 *  larry1.display();                           // LARRY
 *  larry2.display();                           // larry
 * 
 * => It depends on the context of the application and the design.
 * 
 * Mystring operator- make lowercase
 * 
 * => returning a new object that will be the lowercase copy of the existing object. We're overloading the operator minus. We expect no parameters to this method. And it's const method since we don't want to modify the current object. 
 * 
 * We want to create a new object based on it. So the first thing we do is allocate space for an area in memory on the heap where we want to store the lowercase copy of the current object string. Then we use the stood string copy function to copy the string over. 
 * Then we simply loop through the characters in the copy and convert each character to its lowercase equivalent, using the character function to lower in the cc type header file. Once we have the buffer lower case, then we construct a temporary Mystring object using this lowercase string as the initializer. 
 * Finally, we delete the buffer we created in this method so we don't leak memory and we return the newly created lowercase object. We could certainly write more optimized code here, but I wrote this method to show each step explicitly. So that's the general pattern for overloading a unary operator using a member method. 
 * 
 *  Mystring Mystring::operator-() const {
 *      char *buff = new char[std::strlen(len) + 1];
 *      std::strcpy(buff,str);
 *      for(size_t i = 0; i < std::strlen(buff); i++)
 *          buff[i] == std::tolower(buff[i]);
 *      Mystring temp {buff};
 *      delete [buff];
 *      return temp;
 * }
 * 
 * Binary operators as member methods (+, -, ==, != , <, >, etc)
 * 
 * I've named this parameter RHS, which stands for rhs. That way it's very clear that RHS refers to the parameter on the rhs of the operator. And the this pointer points to the object on the lhs of the operator. 
 * Notice the overloaded addition and subtraction operators return the newly created sum or difference objects by value. 
 * Also notice that the equality operators return Boolean values which makes sense since they're comparing things. 
 * 
 * 
 *  ReturnType Type::operatorOp(const Type &rhs);
 *  
 *  Number Number::operator+(const Number &rhs) const;
 *  Number Number::operator-(const Number &rhs) const;
 *  bool Number::operator==(const Number &rhs) const;
 *  bool Number::operator<(const Number &rhs) const;
 * 
 *  Number n1 {100}, n2 {200};
 *  Number n3 = n1 + n2;                        // n1.operator+(n2)
 *  n3 = n1 - n2;                               // n1.operator-(n2)
 *  if (n1 == n2)   ...                         // n1.operator==(n2)
 * 
 * Mystring operator==
 * 
 *  bool Mystring::operator==(const Mystring &rhs) const{
 *      if(std::strcmp(str,rhs.str) == 0)
 *          return true;
 *      else 
 *          return false;
 * }
 * 
 *  if (s1 == s2)       // s1 and s2 are Mystring objects
 * 
 * Mystring operator+ (concatenation)
 * 
 * => Suppose we wanted to overload the binary plus operator for the Mystring class so that it concatenates the strings from the lhs and rhs objects into a new object. 
 * First can create Mystring objects Larry and Moe and Stooges. Then write a statement like Larry + Stooges which will concatenate the string Larry. And the string and stooges to create a new string. Larry is one of the three stooges. 
 * Notice that we can also use c-style strings on the right- hand side. This is because we have a Mystring constructor that can construct Mystring objects from a c-style string. 
 * The only limitation to overloading operators as member functions is that the object on the lhs must be an object of the class you're using. 
 * For example, the last statement in this slide won't compile since the lhs operand is not a my string object. 
 * 
 *  Mystring larry {"Larry"};
 *  Mystring moe{"Moe"};
 *  Mystring stooges {" is one of the three stooges"};
 * 
 *  Mystring result = larry + stooges;          // larry.operator+(stooges);
 *  result = moe + " is also a stooge";         // moe.operator+ ("is also a stooge");
 *  result = "Moe" + stooges;                   // "Moe".operator+(stooges)                 // ERROR
 * 
 * 
 * Mystring operator+ (concatenation)
 * => We allocate a character buffer large enough for both of the strings plus one for the string terminator. Then we allocate this buffer on the heap. 
 * First copy over the left side string with std string copy and then we concatenate the right side string with std string cat. 
 * We create the new object that will contain the concatenated string using the buffer as the initializer. And then finally, we de-allocate the local buffer area so we don't leak memory.  And then, we return the newly created object by value. 
 * Can see that first this looks complicated. But more you do it patterns evolve that are very similar.  
 * 
 *  Mystring Mystring::operator+(const Mystring &rhs) const {
 *      size_t buff_size = std::Strlen(str) + std::Strlen(rhs.str) + 1;
 *      char *buff = new char[buff_size];
 *      std::strcpy(buff,str);
 *      std::strcat(buff, rhs.str);
 *      Mystring temp {buff};
 *      delete [] buff;
 *      return temp;
 * }
 * ***/

//=> We'r e4going to overload the equality  operator that allows us to compare two objects, the negation operator, the unary minus operator, which in our case we're going to make whatever string we want to negate lowercase.
// Finally, the concatenation operator that'll take two string objects and make a bigger string object from it that contains those two strings put together, just like we;ve done before using the regular string class.
// Have Moe + balnk + larry + blank + Curly and this is a c-style string. => It's be pretty flexible. 
#include "Mystring.h"
#include <iostream>
using namespace std;
int main(){

    cout << boolalpha << endl;

    Mystring larry{"Larry"};
    Mystring moe{"Moe"};

    Mystring stooge = larry;
    larry.display();
    moe.display();

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    larry.display();
    Mystring larry2 = -larry;
    return 0;
}