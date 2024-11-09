/***
 * [Operator Overloading]
 * stream insertion and extraction operators (<<, >>)
 * 
 * This will allow us to insert and extract our mystring objects to and from streams exactly as we've been doing with all the other built-in types. 
 * Simply insert our own user-defined objects into an output stream. This makes our classes feel and behave more like a built-in C++ type. 
 * 
 *  Mystring larry {"Larry"};
 *  cout << larry << endl;      // Larry
 *  
 *  Player hero {"Hero", 100, 33};
 *  cout << hero << endl;       // {name: Hero, health: 100, xp: 33}
 * 
 * stream insertion and extraction operators (<<, >>)
 * Of course, we can also overload the stream extraction operator so that we can read data from a stream and assign them to our objects
 * 
 *  Mystring larry;
 *  cin >> larry;
 * 
 *  Player hero;
 *  cin >> hero;
 * 
 * Doesn't make sense to implement as member methods    => when we overload an operator as a member method, the left-hand side object must be an object of the class we're overloading. This means that we would have to write Larry on the lhs of the output statement. While this will work, it would be very strange for C++ programmers  to use in this manner since it's not the way we use these operators with other values. 
 *  Left operand must be a user-defined class             
 *  Not the way we normally use these operators
 * 
 * 
 * 
 *  Mystring larry;
 *  larry << cout;          // huh?
 *  larry >> cin;           // huh?
 * 
 *  we're going to overload these operators as non-member functions. 
 * stream insertion operator (<<)
 * This is a non-member function named operator insertion operator that has two arguments. 
 * The first argument is an output stream object by reference. This is typed as std ostream
 * The second parameter is a reference to the mystring object whose data we want to insert in the output stream. 
 * Notice that the reference is constant . Also notice that the function returns an output stream reference. This is important because we want to be able to chain insertion as we normally do.
 * It's important that we use ostream references, and we don't copy the stream. Then comes the easy part, put whatever data you like in whatever format you like on the output stream as usual. 
 * If this function has been declared as a friend function in the Mystream class, then you have access to all the private data members. Otherwise, you have to use the public getter to get the information you need. 
 * Finally, the last step is to return the output stream reference. As you can see it's very simple and very useful too. Let's see how we can overload the stream extraction operator. 
 * 
 * std::ostream *operator<< (std::ostream &os, const Mystring &obj){
 *      os << obj.str;                  // if friend function
 *      // os << obj.get_str();         // if not friend function
 *      return os
 * }
 * Return a reference toi the ostream so we can keep inserting
 * Don't return ostream by value!
 * 
 * stream extraction operator (>>)
 * 
 * => The name of the function is operator, extraction operator. The function has two parameters. 
 * The first is a reference to an input stream whose type is istream. And the second is a reference to the object we want to extract data into. Notice that since we're going to modify this object, we don't want it to be a const. So depending on the data we want to read, we cat get the data from the input stream and either store it locally or store it directly in the object. 
 * In this case, we allocate a large array of characters that  will hold the data we want to construct a mystring object. Then we simply create a temporary mystring object and assign it back to the object that was passed in.
 * This assumes we have copied or moved overloaded assignment operators and they're implemented correctly since we have a raw pointer. 
 * Finally we return the istream reference so that we can change assign. We can do all sorts of error checking and setting and getting the state of the input stream so we have control of the data we're extracting as well as not overrunning the size of the buffer we created.
 * 
 * std::istream &operator>>(std::istream &is, Mystring &obj){
 *      char *buff = new char[1000];
 *      is >> buff;
 *      obj = Mystring {buff};      // If you have copy or move assignment
 *      delete [] buff;
 *      return is;
 * }
 * 
 * 
 * Return a reference to the istream so we can keep inserting
 * Update the object passed in
 * ***/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main(){

    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    return 0;
}