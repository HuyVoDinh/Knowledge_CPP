#ifndef _MYSTRING_H__
#define _MYSTRING_H__

class Mystring{
     private:
         char *str;      // C-style string //pointer to a char[] that holds a C-style string          chose to include a raw pointer because it will allow us more practice with our copy and move constructors, and we'll also have to think about copy and move assignment when we overload the assignment operator.
         //We're implementing a string behind the scenes as s pointer crit to a character is basically the way a c-style string works. We could have done this a lot of different ways. I chose to do it this way. That way can play around with raw pointers a little bit more. The copy constructor, understand the move constructor, which we'll do soon and understand the assignment operators. 
     public: 
         Mystring();                            //No-args constructor
         Mystring(const char *s);               //Overloaded constructor
         Mystring(const Mystring &source);      //Copy constructor
         ~Mystring();                           //Destructor

        Mystring &operator=(const Mystring &rhs);   //Copy assignment       // We're overloading the equal operator or the assignment operator. The lhs is the current object, the rhs is what we're assigning. And we want this guy const because we really don't want to mess with it. It's not our object, so I don't want to mess with it at all. This is not construction, this is assignment.

         void display() const;
         int get_length() const;                //getters
         const char *get_str() const;
};

#endif