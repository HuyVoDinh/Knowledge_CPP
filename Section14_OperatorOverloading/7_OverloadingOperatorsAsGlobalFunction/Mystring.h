#ifndef _MYSTRING_H__
#define _MYSTRING_H__

class Mystring{
    //Implement three overloaded operators: The equality operator, the unary minus operator, which makes the string lowercase and the plus operator, which concatenates two strings. 
    // And this time, we're going to implement them as non-member functions or global c++ function.
    // First thing we're going to di is we're going to make them friends. We don't have to make them friends. But it's going to be a lot easier to write the code because they don't have to call those getters all the time. 
    // So we can do that right in the class. Remember, the class has to grant friendship. So we'll write the function prototypes here, and we'll  start them off with friend. And we'll do the first one. The first one is returns a Boolean. The operator is the equality operator. And remember now since this is not a member function, we need two parameters.
    //This is a binary operator. The first one will be const Mystring ref LHS for left-hand side and const Mystring ref right-hand side. So that's one function prototype.
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-( const Mystring &rhs);   // This will return a MyString object by value the operator, we're overloading is the minus operator, the unary minus. And it expects single Mystring ref. And we could call this obj.  We can call this anything we like. 
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);    // It returns a Mystring object by value again, and this is the concatenation operator. So it's going to be the plus operator, and it's a binary operator. So we're got const Mystring ref left-hand side and const Mystring ref right-hand side. 
    // It doesn't really matter where you put these friend declarations in doesn't matter if you put them in the private area, the public area. Unless I have any typos that looks pretty good. Now what we'll do is we'll go to the Mystring cpp and implement those. We can really implement them anywhere. But since they really add to the interface of the class, it's common practice to implement them right in here in the .cpp file. 
     private:
         char *str;      // C-style string //pointer to a char[] that holds a C-style string          chose to include a raw pointer because it will allow us more practice with our copy and move constructors, and we'll also have to think about copy and move assignment when we overload the assignment operator.
         //We're implementing a string behind the scenes as s pointer crit to a character is basically the way a c-style string works. We could have done this a lot of different ways. I chose to do it this way. That way can play around with raw pointers a little bit more. The copy constructor, understand the move constructor, which we'll do soon and understand the assignment operators. 
     public: 
         Mystring();                            //No-args constructor
         Mystring(const char *s);               //Overloaded constructor
         Mystring(const Mystring &source);      //Copy constructor
         Mystring(Mystring &&source);           // Move constructor
         ~Mystring();                           //Destructor

        Mystring &operator=(const Mystring &rhs);   //Copy assignment       // We're overloading the equal operator or the assignment operator. The lhs is the current object, the rhs is what we're assigning. And we want this guy const because we really don't want to mess with it. It's not our object, so I don't want to mess with it at all. This is not construction, this is assignment.
        Mystring &operator = (Mystring &&rhs);      //Move assignment

        // Let's do the operator minus first. It's going to be the operator. We're overloading is operator followed by the operator we want, which is minus in this case.  And what are we going to be passing into this, nothing. That's a unary operator. 
        //So we're already got what we need into the left side of the dot. It's important to understand that when we're overloading operators as member methods unary operators take no parameters, binary operators take one parameter because this is already a parameter on the left side.
        // And want this to be const. This will mean, make lower case version of the string. 
        //Mystring operator-() const;                 //make lowercase
        // Let's do the concatenation operator. This is a binary operator. So we need one parameter in this parameter list, and that parameter will be const Mystring reference, and we'll call it right-hand side. Important that it's const because we really don't want to mess with that.
        //Mystring operator+(const Mystring &rhs) const;   // concatenate
        // The equality operator. It will return a Boolean, a true false value. And it will be operator, two equal sign. It's binary. So it's going to expect a const Mystring reference, right-hand side and we want this to be a const method as well. And add const because to change anything.
        //bool operator==(const Mystring &rhs) const;       


         void display() const;
         int get_length() const;                //getters
         const char *get_str() const;
};

#endif