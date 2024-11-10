/***
 * [Operator overloading]
 * ------------------------
 * Overload the following operators in the provided Mystring class. 
 * 
 * To gain experience overloading operators, you should do this challenge twice. 
 * First, overload the operators using member functions and then in another project overload the same operators again using non-member functions. 
 * 
 * Please do it once using member methods and then again using non-member function. 
 * 
 * Here is a list of some of the operators that you can overload for this class:
 * 
 *  -   -> unary minus. Returns the lowercase version of the object's string. -s1
 *  ==  -> returns true if the two strings are equal. (s1 == s2)
 *  !=  -> returns true if the two strings are not equal (s1 != s2)
 *  <   -> return true if the lhs string is lexically less then the rhs string (s1 < s2)
 *  >   -> return true if the lhs string is lexically greater than the rhs string (s1 > s2)
 *  +   -> concatenate the rhs. Returns an object that concatenates the lhs and rhs (s1 + s2)
 *  +=  -> concatenate the rhs string to the lhs string and store the result in lhs object (s1 += s2); equivalent to s1 = s1 + s2
 *  *   -> repeat - results in a string that is copied n times. s2 * 3
 *                      ex) s2 = "abc" 
 *                          s1 = s2 * 3
 *                          s1 will result in "abcabcabc"
 * 
 *  *=  -> repeat the string on the lhs n times and store the result back in the lhs object
 *                          s1 = "abc" 
 *                          s1 *= 4         s1 = s1 will result in "abcabcabcabc"
 * 
 * If you wish to overload the ++ and -- operators remember that they have pre and post versions. 
 * 
 * The semantics should be as follows (this shows the member method version): 
 * 
 * Mystring &operator++(){  // pre-increment
 *  // do what ever you want increment do to - maybe make all characters uppercase?
 *  return *this;
 * }
 * 
 * //Note that post-increment returns a Mystring by value not by reference
 * Mystring operator++(int){    //post-increment        // got operator ++ with an int. That int is not used It's not even named it's just a placeholder. And the compiler is using that behind the scenes to be able to tell the difference between these two prototypes if you will because otherwise it'd be exactly the same and it wouldn't know which one to call
 *  Mystring temp(*this);       // make a copy          // we need to make a copy of what we've got now.
 *  operator++();               // call pre-increment - make sure you call pre-increment!       // Then call operator++. Notice that this doesn't have an int in there. So we're calling pre-increment. If you call post increment, you end up with a recursive loop and never going to get out . What we're doing is we're incrementing, we're doing a  pre-increment, and then we're returning this temporary object that we saved which is the old copy. That' exactly what the whole idea with post increment means.
 *  return temp;                // return the old value
 * }
 * 
 * Have fun! Think of some other operators that might be useful!
 * Don't worry if they all don't make sense -- this is an exercise about learning how to overload operators.
 * 
 * Hints:
 * 1. take advantage of the std::strcmp function for the equality operators!
 * 2. the += and *= operators should return a Mystring &
 * 3. rather than duplicate code in the += and *= functions, use the + and * operators which you have already overloaded!
 * ****/
#include <iostream>
#include "Mystring.h"

using namespace std;
int main(){
    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};

    cout << (a == b) << endl;       // true
    cout << (a != b) << endl;       // false

    b = "george";
    cout << (a == b) << endl;       // false
    cout << (a != b) << endl;       // true
    cout << (a < b)  << endl;       // true
    cout << (a > b) << endl;       // false

    Mystring s1 {"FRANK"};
    s1 = -s1;
    cout << s1 << endl;       // frank
    s1 = s1 + "*****";
    cout << s1 << endl;       // frank*****

    s1 += "-----";
    cout << s1 << endl;       // frank*****-----

    Mystring s2 {"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;       // 123451234512345

    Mystring s3 {"abcdef"};
    s3 *= 5;
    cout << s3 << endl;       // abcdefabcdefabcdefabcdefabcdefabcdef

    Mystring repeat_string;
    int repeat_times;
    cout << "Enter a string to repeat: " << endl;
    cin >> repeat_string;
    cout << "how many times would you like it repreated?";
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "The resulting string is: " << repeat_string << endl;

    cout << (repeat_string * 12) << endl;
    repeat_string = "RepeatMe";
    cout << (repeat_string + repeat_string + repeat_string) << endl;

    repeat_string += (repeat_string * 3);
    cout << repeat_string << endl; 

    Mystring s = "Frank";
    ++s;
    cout << s << endl;       // FRANK

    s = -s;
    cout << s << endl ;      // frank

    Mystring result;
    result = ++s;
    cout << s << endl;      // FRANK
    cout << result << endl; // FRANK

    s = "Frank";
    s++;
    cout << s << endl;

    s = -s;
    cout << s << endl;      // frank
    result = s++;
    cout << s << endl;      // FRANK
    cout << result << endl; // frank
}