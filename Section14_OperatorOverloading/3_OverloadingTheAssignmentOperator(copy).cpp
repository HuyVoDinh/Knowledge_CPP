/***
 * [Operator Overloading]
 * 
 * Copy assignment operator (=)     
 * 
 * C++ Provides a default assignment operator used for assigning one object to another
 * 
 *  Mystring s1 {"Frank"};
 *  Mystring s2 = s1;           // NOT assignment
 *                              // same as Mystring s1 {s1};        // Initialization is done by constructors when create new objects. The statement mystring s1 = s1 is not an assignment statement, it's an initialization statement because s2 hasn't been created yet. C++ allows us to use the assignment operator but this assignment is really equivalent to mystring s2 = s1. It will invoke the copy constructor. 
 * 
 *  s2 = s1;                    // assignment                       // This is assignment since s2 has already been created and initialized previous to the statement. So an assignment occurs when an object has already been initialized and you want to assign another object to it. C++ provides a default way of assigning one object to another. Anf if you don't provide your own overloaded assignment operator, then C++ will provide a compiler generated one for you. This is very similar to what it did with the default copy constructor. 
 * 
 * Default is member-wise assignment (shallow copy)     //The behavior for the default assignment is member-wise assignment, which means shallow copying. If your class doesn't have raw pointers, then the default assignment operator will probably be just fine. 
 *  If we have raw pointer data member we must deep copy
 * 
 * Overloading the copy assignment operator (deep copy)
 * 
 * First, the assignment operator must be overloaded as a member function, so we can provide a method prototype that has the general pattern shown in the top declaration. We then simply replace type with the name of our class. 
 * Notice that the name of the method is operator equal. The keyword operator followed by the operator that we wish to overload. 
 * So for the mystring class, the overloaded assignment operator method returns a reference to a mystring object. This is important since we want to avoid extra copies if we return by value.  And we also want to allow chain assignments such as p1 = p2 = p3. 
 * 
 * Type &Type::operator = (const Type &rhs);
 * Mystring &Mystring::operator = const( Mystring &rhs);
 * s2 = s1;                                                 // We write this
 * s2.operator=(s1);                                        // operator= method is called
 * 
 * 
 * The object on the left-hand side of an assignment statement is referred to by the this pointer. 
 * The object on the right-hand side is being passed into the method. 
 * Since we're assigning the rhs object to lhs object, we must make a deep copy of the rhs object's attributes and copy them over to the lhs object. 
 * The lhs object or this object will be overwritten. So we need to de-allocate anything it refers to on the heap. Then we have to allocate space in the lhs object for the rhs object's data, and then we finally copy the data over to the left side from the right side.  
 * Mystring &Mystring::operator=(const Mystring &rhs){
 *  if (this == &rhs)
 *      return *this;
 *  delete[]str;
 *  str = new char[std::strlen(rhs.str)+1];
 *  std::strcpy(str,rhs.str);
 * 
 *  return *this;
 * }
 * 
 * Overloading the copy assignment operator - steps for deep copy
 * 
 * The first thing we want to do is check to se if we're doing self-assignment. For example, p1 =p1 or assign p1 to itself. We can easily check for that by checking the address of the lhs object which is in the pointer this and comparing it to the address of the rhs object. 
 * If they're the same, then we really don't want to do anything and we just return de-reference this, which is the lhs object. 
 * Check for self assignment
 *  if (this == &rhs)       // p1 = p1;
 *      return *this         // return current object
 * 
 * If we don't have self-assignment, then we need to de-allocate storage for this string since it's pointing to a string on the heap. We need to-deallocate the storage. Otherwise when we copy the new data over, we'll orphan this memory and end up with a memory leak.
 * Deallocate storage for this->str since we are overwriting it
 *      delete [] str;
 * 
 * Allocate storage for the deep copy
 * 
 * The lhs object is ready to be assigned from the data from the rhs object, but we haven't yet allocated storage on the heap for the deep copy. So we need to allocate enough storage on the heap, that's the size of the string in the right object+1 since we need the space for the string terminator. 
 *  str = new char[std::strlen(rhs.str) + 1];
 * 
 * We can perform the copy by copying over one character at a time until we see the null character. But since we're using a c-style string, we can simply call the string library method stood string copy, which copies the string from the rhs object to the lhs object. All we have to do now is return the lhs object so we can support chain assignment.
 * If your class has multiple raw pointer, then don't forget to deep copy each of them. 
 * Perform the copy
 *  std::strcpy(str, rhs.str);
 * 
 * Return the current by reference to allow chain assignment
 *  return *this;
 * // s1 = s2 =s3;
 * ***/
#include <iostream>
#include <vector>
#include "3_Mystring.h"

using namespace std;

int main(){
    //Example 1
    Mystring a {"Hello"};               //overloaded constructor            //Instantiating my object "a". It's a mystring object, and I'm initializing it to Hello. It'll have an str attribute, which is a pointer, Hello will be allocated on the heap. Remember, there's a null character there at the end. So this is really six characters big, and atr attribute will be pointing to it. So that's the condition that I'll be in after the construction of the a object.
    Mystring b;                         // no-args constructor              // WHen we create the b object, It'll have an str attribute. In this case, It pointing to an empty stream. The empty string consists of a single character with the null character in it.
    b = a;                              // copy assignment
                                        // b.operator=(a)                   /*** In this case, this is assignment because b already exists, b has been instantiated. First, we want to be sure that we're not assigning to ourselves b = b or a = a. Then what we'll do is we really want b to contain that Hello. 
                                                                            // But we don't want this situation like we had with a shallow copy. We want to create a copy of that hello string on the heap. So in order to do t hat, there's a couple of things I need to do. First of all, I need to de-allocate the "empty" on the heap and this could be a lot bigger than just an empty string. This could be a very large string. So I want to allocate that. Then I want to allocate space for 6 characters because I'm copying hello as h-e-l-l-o and the null terminator.
                                                                            // I want to copy hello + over. Empty on the heap is gone. That's been de-allocated so we don't leak memory.
    b = "This is a test";               // b.operator=("This is a test");   // Being also an assignment because we're assigning something to b and b already exists. In this case, It's a little bit different because we don't have an operator equal that expects a character pointer. So what we need to do is we need to construct a temporary object using the overloaded constructor and then assign that temporary object to b and then that will eventually be destroyed the temporary object will. 

    //Example2
    Mystring a {"Hello"};       //Constructing or instantiating that a object. I'm providing some initialization information. Going to call the overloaded constructor. There is the call to the overloaded constructor that expects a character pointer just like we expect, it's not null. So we're gonna skip the if part. Whatever the string that was being passed in by plus 1 for the null terminator. And the just copying it over. Finished, str attribute is pointing to the string hello.
    Mystring b;                 // b object call no-args constructor since we;re not providing any information. And when we get back, we expect b's string attribute to be an empty string. Being an empty string. There you can see the no args constructor. It;s simply create one character and putting the null terminator. 
    b = a;                      // a is hello and b is empty. Now is the assignment. Operator equal to be called,. We're going to check for self-assignment. Not -> skip->. Next delete the lhs object's string on the heap. And going to copy the rhs is hello and the lhs now is just pointing to garbage because we've deleted that, so it's invalid memory. Next replace that with an area that creating on the heap that's going to store the string that. From addresses, they are indeed two unique areas in memory. and returning the object by reference
                        
                        
                        
    b = "This is a test";       //And then once that object is created, we'll assign it over. So that temporary object is going to be assigned over. Calling overloaded constructor, which is going to create a temporary object. And now that temporary object will be assigned. So you can see the assignment operator being called now. Then get rid of the temporary object. That's the destructor being called


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
    return;
}
