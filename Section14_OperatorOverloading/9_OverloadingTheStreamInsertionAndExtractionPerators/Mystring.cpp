#include <iostream>
#include "Mystring.h"
#include <cstring>

// No-args constructor

Mystring::Mystring() : str{nullptr}
{                      // => providing no construction information. So the no args constructor gets called. You can see it expects nothing. And what we're doing here is we're creating an object called a and let's just put a right here. It has in it a pointer called str. now if we create an empty object, we could simply set that pointer to null pointer, and we're done with it. I don't want to do that. I want to set an empty string to an empty string that looks like that. In other words, a single character with the null terminator in it rather than a null pointer that just makes it easier later if we ever display or pint out an empty string. It'll be fine. We don't have to check for null pointers later.
    str = new char[1]; // we're going to allocate space for one character. Notice the brackets they're important here because we're going to delete characters in that manner as well. So I'm going to allocate one character. Remember, all this is happening on the heap. "a object str" is happening on the stack.  And going to assign that address to str, so str in pointing the heap.
    *str = '\0';       // Then what I'm doing is de-referencing the pointer and putting that terminator in the heap. That's my empty string. If you try to display this, it will just display nothing. So that's my no args constructor.
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr}
{ // Mystring a {"Hello"};  //Overloaded constructor here that expects a c-style string
    if (s == nullptr)
    { // Checking if by any chance somebody sent a null pointer. If they did, I', just going to create an empty string. I'm just going to double check that just to be safe. We're going to create that a object. It's got an attribute called str that's the only attribute it has actually.  and what we're going to do is we're going to allocate
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1]; // This many characters on the heap. Going to figure out what the length of "Hello" and add 1 to it because need an extra character for that terminator. I'm going to allocate 6 characters on the heap.
        std::strcpy(str, s);                // Copy s to str. At this point it's going to copy hello and put the null terminator. Those are my six characters and I'm going to pointing from stack  to heap (a (str[])) -> [Hello\0]
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr}
{                                                // Mystring a {"Hello"};   //We've got an existing object and I want to copy it and construct a new object from it. This is not an assignment, it's a construction.
    str = new char[std::strlen(source.str) + 1]; // Mystring b {a}; => copy constructor being called. gets called if you pass an object by value to  a function lost of different places. this pointer refer to the object that creating. source refer to a object.
                                                 // creating object, setting str. It doesn't even have a name yet. But let's just call it by this pointer because it;s being pointed to by that pointer. And what I want to do is I want to copy that hello and I want to do a deep copy. I don't want to share this. I want to allocate 6 characters on the heap. THese are uname. Then used std::string copy to copy the source string to the string, a deep copy.  Those are my six characters and I'm going to pointing from stack  to heap (a (str[])) -> [Hello\0]
    std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring()
{ // This responsible for de-allocating the memory that you allocate. So I've allocated some memory in the constructors. I've got to be sure to de-allocate it in the destructor
    delete[] str;
}

// Example 2
//  Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// Example 2
//  Move constructor
Mystring::Mystring(Mystring &&source) : str(source.str)
{
    source.str = nullptr;
    std::cout << "Move constructor used\n";
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Equality
// bool Mystring::operator==(const Mystring &rhs) const
// {
//     // want to compare those two strings. The string in this and the string and right-hand side.

//     return (std::strcmp(str, rhs.str) == 0); // return, and the new can call std string compare, which is a c-string function that compares two c-strings is which we've got. So str in one of them and rhs dot str is the other one. And if that returns 0, we'll return the value
// }

// Make lowercase
// We're returning Mystring object by value. It's part of the Mystring class. There's my scope resolution operator, and it's operator minus nothing in the parameter list because it's a unary operator. And it's const because we don't want to change our current object again.
// Mystring Mystring::operator-() const
// {
//     // Remember we need to make a copy of whatever is in the current object, make that lover case, and then create a new object form it. I need to allocate space to create that copy so that I can make lowercase. I don't want to change the object because I can't . It's a const method.
//     // Let's create a temporary area and memory called buff, and we'll create a new array of characters there. And how big is that going to be. It's going to be as big as t he length of the string in str + 1. For example, If it's frank, I'm going to get bach 5, allocate 1. This is a brand new pointer to an area on the heap that I just allocated. It's local to this function.
//     // When we're finished with function, we need to get rid of that and de-allocate it.
//     char *buff = new char[std::strlen(str) + 1];
//     // At this point I need to copy the string that's in str to buff.
//     std::strcpy(buff, str);
//     // Copy that string. So what we can do now is we can just simply loop through
//     for (size_t i = 0; i < std::strlen(buff); i++)
//         buff[i] = std::tolower(buff[i]); // contains a copy of that original string and then we just made it lowercase.
//     // Create a new object, the temporary object right on the stack here base on that information.
//     Mystring temp{buff};
//     // This is one of the benefits of using smart pointers.
//     //  Need to de-allocate that space. Otherwise I'll leak that memory
//     delete[] buff;
//     return temp;
// }

// Concatenate
// Going to create a new string from it. So by value, it's a Mystring method. We'll call it operator plus. And it expects something on the right-hand side, which is Mystring by reference. And it's const method as well.
// Mystring Mystring::operator+(const Mystring &rhs) const
// {
//     // Need to allocate an area in memory for characters.And how big is this going to be. THis need to be since we're concatenating, it has to be the length of this string plus the length of the right-hand side string plus 1.
//     char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
//     // That allocates the storage on the heap that I need. At this point, I need to copy the first string and then concatenate the second string to it so I can build the bigger string from it. So we'll say std string copy in to buff from the left-hand side string which is str.
//     std::strcpy(buff, str);
//     // Then we'll do a std string cat to concatenate again into buff from the right-hand side str.
//     std::strcat(buff, rhs.str);
//     // So what we've done now is we've just copied one string and concatenated the other.  At this point, we've got the information we need in buff to create that new temporary object that I'm going to return.  Same thing we did up here.
//     // So we built a object and call it temp, and we'll build it with the buff information
//     Mystring temp{buff};
//     delete[] buff;
//     return temp;
// }

// Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

// Length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char *Mystring::get_str() const { return str; }

// This is regular function, it's not a member function
// Equality

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);     //See the difference between this one and the member function. 
}

// Make lowercase
Mystring operator-(const Mystring &rhs)
{
        char *buff = new char[std::strlen(rhs.str) + 1];
    std::strcpy(buff, rhs.str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}
Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
        char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// overloaded insertion operator
//Instead, ostream reference, the operator we're overloading is the insertion operator. And we've got the same two parameters that we had before. We've got an ostream reference. We did and a const Mystring class by reference right-hand side. 
// So we can simply say right-hand sides str. If this wasn't a friend, we could use the get str method. Then return that output stream. 
std::ostream &operator<<(std::ostream &os, const Mystring &rhs){
    os << rhs.str;
    return os;
}

//overloaded extraction operator
// It's a stood istream reference. The operator we're overloading is the extraction operator, and we also have two parameters. 
// The first one is a std istream reference. And we've got the mystring ref right-hand side. This one can't be const because we're going to read into it or change it. So now we're going to get a string from the input stream. We need to store that somewhere. 
// Let's create a pretty big zie buffer. We'll do this dynamically on the heap. We'll just store a 1000 characters. That should give us plenty of room. We could certainly do this in different ways so that we don't overrun this buffer. But let's just do it like this because it's a simple example to understand.
// Now we get whatever's in the input stream and store it in buffer. 
// We've got the buffer, it's got the data we have, we want and what we want to do is we want to update this right-hand side objects string based on this data.
// Say RHS equals mystring and initialize it with buff. Depending on whether you've got copy assignment or move assignment, that's what's going to happen here, we've got both.
// So this is going to use move assignment which is supper-efficient we're just going to steal that pointer. When we're done, we make sure that we delete this temporary storage that we created in buff. And we return the input stream. Remember, this is going to return it by reference.
std::istream &operator>>(std::istream &in, Mystring &rhs){
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete[]buff;
    return in;
}