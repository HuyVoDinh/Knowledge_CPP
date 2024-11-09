/***
 * [Operator Overloading]
 * Move assignment operator (=)     //The copy assignment operator that we just overloaded. The move operator that will overload works with r-value references. 
 * 
 * // Think temporary unnamed objects. Don't have to provide a move assignment operator. And if you don't C++ will use the copy constructor by default. But as we said when we talked about the move constructor, move semantics can be much more efficient, and it's not a lot of extra work to provide a move constructor and a move assignment operator
 * 
 * You can choose to overload the move assignment operator
 *  C++ will use the copy assignment operator if necessary
 * 
 *  Mystring s1;                                            // Create Mystring object s1 is an empty string. 
 *  s1 = Mystring {"Frank"};        // move assignment      // Assign the mystring object with the string frank to it. Notice that the mystring object initialized to frank must be constructed. And once it's constructed, it has no name, it's a temporary object. So it's an r-value. That means that when we assign it so s1, the move assignment operator will be called since we're providing an r-value reference. 
 * 
 * If we have raw pointer we should overload the move assignment operator efficiency
 * 
 * Overloading the Move assignment operator
 * 
 * The move assignment operator declaration is very similar to copy assignment. But there are a few differences. First, we use the double ampersand operator in the parameter list to tell the compiler that the rhs object is an r-value. So the rhs value will be an r-value reference. 
 * Second rhs object reference can't be const since we'll be modifying that object when we move the data. SO the declaration for the mystring class returns a mystring object byreference and expects an r-value reference to a mystring object.
 * 
 *  Type &Type::operator=(Type &&rhs);
 *  
 *  Mystring &Mystring::operator=(Mystring &&rhs);
 *  s1 = Mystring {"Joe"};  // move operator = called       // assignment operator will be called because the rhs of the assignment statements are r-values. 
 *  s1 = "Frank";           // move operator = called
 * 
 * 
 * Not deep copying from the rhs object. Instead, stealing the pointer and then nulling out the rhs pointer.
 * 
 * Mystring &Mystring::operator=(Mystring &&rhs){
 *  if (this == &rhs)               // self assignment
 *      return *this;               // return current object
 *  delete [] str;                  //deallocate current storage
 *  str = rhs.str;                  // steal the pointer
 *  rhs.str = nullptr;              // null out the rhs object
 *  return *this;                   // return current object
 * }
 * 
 * Check for self assignment        // Check for self-assignment just before. And if we're self-assigning the nwe return the lhs object and done since there was nothing to do. 
 *  if (this == &rhs)
 *      return *this;               // return current object    
 * Deallocate storage for this->str since we are overwriting it     // Otherwise, de-allocated the storage pointed to by the lhs object since we'll be overriding this, and we don't want a memory leak.  Now the lhs object is ready so let's move the pointer over.
 *  delete [] str;
 * 
 * 
 * Steal the pointer from the rhs object and assign it to this->str     //Copy of a pointer variable, not doing a deep copy here. Then know out the pointer on the rhs object. This step is critical. Finally return the left-side object. 
 *  str = rhs.str;
 * 
 * Null out the rhs pointer
 *  rhs.str = nullptr;
 * 
 * Return the current object by reference to allow chain assignment
 *  return *this;
 * ***/
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    // Mystring a {"Hello"};           // Overloaded constructor                           //Created an object am ut;s using an overloaded constructor that's expecting that character pointer. Just constructing a simple object a that's got that string attribute pointing to hello on the heap. 
    // a = Mystring {"Hola"};          // Overloaded constructor then move assignment      // Want to use assignment . "a" already exists so now this will be assignment not initialization. And what I want to do is construct another mystring object off of the initialization string Hola. At this point, that temporary object has no name, so it's an r-value. If we don't provide any move semantics, then it's going to use a copy constructor or a copy assignment operator to do what it needs to do. If don't have any move assignment operator implemented. You'll see that it's using copy assignment
    // a = "Bonjour";                  // Overloaded constructor then move assignment
    // Created a object and it's on the stack, it's got the str attribute, which is a pointer. And once this object has been constructed that pointer is pointing to the string hello, which is on the heap. It's got that null terminator at the end. This is the situation once we instantiate a.
    // Next we want to assign to a the object that create. That object gets created exactly the same way as we created a. It's using the overloaded constructor. But it doesn't have a name. It's an unnamed temporary object. It's got an str attribute, and it's pointing to Hola, which is on the heap. Now what we want to assign temp to a. But we really don't want to do the overhead of copying because we don't need to. This temporary object will be destroyed soon. So let's just use move assignment so that we can steal that pointer and not have to make any copies of anything or copy anything over. 
    // What are the semantics. The first thing we need to do is de-allocate the space for "Hello" because we're not going to use that. So we're going to get rid of that. and what that's going to do it's going to leave us in this situation where we're no longer pointing to that area. And we want to steal the pointer. So I want to make this pointer a point to Hola. And then once that's done, what I want to do is not delete information ("Hola"). I don't want to de-allocate that because using it. All I want to do is just null out temp pointer.
    // Just null temp pointer out. a object is pointing to "Hola" on the heap. temp is null out. When it gets destroyed by the destructor, it won't destructor, it won't delete anything out there on the heap because it's not pointing to anything on the heap. So it'll destroyed


    //Example 2
    Mystring a {"Hello"};           // a is hello and can see the address string attribute.       
    a = Mystring {"Hola"};          // First construct that temporary object and then call overloaded assignment operator an r-value reference because that's exactly what this is an unnamed object so.First, we're going to create the object using the overloaded constructor. Then allocate the space, copy it over. It's done. Now notice that the move assignment operator gets called. because we have an r-0value reference which is a temporary unnamed object. So display using move assignment, check for self assignment, which we don't have we delete this str. Then going to steal the pointer, and then going to nullify that other pointer.
    // Now the temporary object is being destructed and we do have a null pointer because we nulled it out. So this will print out calling destructor for null pointer. We'll delete the area. 
    a = "Bonjour";             


    Mystring empty;                     // no-args constructor
    Mystring larry("Larry");            // overloaded constructor
    Mystring stooge {larry};            // copy constructor
    Mystring stooges;                   // no0args constructor

    empty = stooge;                     // copy assignment operator

    empty.display();                    // Larry : 5
    larry.display();                    // Larry : 5
    stooge.display();                   // Larry : 5
    empty.display();                    // Larry : 5

    stooges = "Larry, Moe, and Curly";
    stooges.display();                  //Larry, Moe, and Curly : 21

    vector <Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");

    cout << "=======Loop1===============" << endl;
    for (const Mystring &s:stooges_vec)
        s.display();

    cout << "=======Loop2===============" << endl;
    for(Mystring &s:stooges_vec)
        s = "Changed";                  //Copy assignment

    cout << "=======Loop 3===============" << endl;
    for(const Mystring &s : stooges_vec)
        s.display();
    return 0;
}
