#include <iostream>
#include "Mystring.h"
#include <cstring>

//No-args constructor

Mystring::Mystring() : str{nullptr} {   // => providing no construction information. So the no args constructor gets called. You can see it expects nothing. And what we're doing here is we're creating an object called a and let's just put a right here. It has in it a pointer called str. now if we create an empty object, we could simply set that pointer to null pointer, and we're done with it. I don't want to do that. I want to set an empty string to an empty string that looks like that. In other words, a single character with the null terminator in it rather than a null pointer that just makes it easier later if we ever display or pint out an empty string. It'll be fine. We don't have to check for null pointers later.
    str = new char[1];                  // we're going to allocate space for one character. Notice the brackets they're important here because we're going to delete characters in that manner as well. So I'm going to allocate one character. Remember, all this is happening on the heap. "a object str" is happening on the stack.  And going to assign that address to str, so str in pointing the heap.
    *str = '\0';                        //Then what I'm doing is de-referencing the pointer and putting that terminator in the heap. That's my empty string. If you try to display this, it will just display nothing. So that's my no args constructor. 
}

//Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr} {  // Mystring a {"Hello"};  //Overloaded constructor here that expects a c-style string
    if (s==nullptr){                                //Checking if by any chance somebody sent a null pointer. If they did, I', just going to create an empty string. I'm just going to double check that just to be safe. We're going to create that a object. It's got an attribute called str that's the only attribute it has actually.  and what we're going to do is we're going to allocate
        str = new char[1];
        *str = '\0';
    } else {
        str = new char [std::strlen(s) + 1];        //This many characters on the heap. Going to figure out what the length of "Hello" and add 1 to it because need an extra character for that terminator. I'm going to allocate 6 characters on the heap.
        std::strcpy(str,s);                         // Copy s to str. At this point it's going to copy hello and put the null terminator. Those are my six characters and I'm going to pointing from stack  to heap (a (str[])) -> [Hello\0]
    }
}

//Copy constructor
Mystring::Mystring(const Mystring&source) : str{nullptr}{   //Mystring a {"Hello"};   //We've got an existing object and I want to copy it and construct a new object from it. This is not an assignment, it's a construction. 
    str = new char[std::strlen(source.str) + 1];            // Mystring b {a}; => copy constructor being called. gets called if you pass an object by value to  a function lost of different places. this pointer refer to the object that creating. source refer to a object. 
                                                            // creating object, setting str. It doesn't even have a name yet. But let's just call it by this pointer because it;s being pointed to by that pointer. And what I want to do is I want to copy that hello and I want to do a deep copy. I don't want to share this. I want to allocate 6 characters on the heap. THese are uname. Then used std::string copy to copy the source string to the string, a deep copy.  Those are my six characters and I'm going to pointing from stack  to heap (a (str[])) -> [Hello\0]
    std::strcpy(str, source.str);       
}

//Destructor
Mystring::~Mystring(){  //This responsible for de-allocating the memory that you allocate. So I've allocated some memory in the constructors. I've got to be sure to de-allocate it in the destructor
    delete [] str;
}

//Example 2
// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    std::cout << "Copy assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}



//Example 2
// Move constructor
Mystring::Mystring(Mystring &&source) : str(source.str){
    source.str = nullptr;
    std::cout << "Move constructor used\n";
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout << "Using move assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

//Length getter
int Mystring::get_length() const {return std::strlen(str);}

//string getter
const char*Mystring::get_str() const {return str;}