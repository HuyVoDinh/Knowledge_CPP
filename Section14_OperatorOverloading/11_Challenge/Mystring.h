#ifndef _MYSTRING_H__
#define _MYSTRING_H__
#include <iostream>
class Mystring{

    //Solution 2
    friend Mystring operator-(const Mystring &obj);                     // make lowercase
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);  // concatenate
    friend bool operator== (const Mystring &lhs, const Mystring &rhs) ;    // equals
    friend bool operator!= (const Mystring &lhs, const Mystring &rhs) ;    // not equals
    friend bool operator< (const Mystring &lhs, const Mystring &rhs) ;     // less then
    friend bool operator> (const Mystring &lhs, const Mystring &rhs) ;     // greater than
    friend Mystring &operator+=( Mystring &lhs, const Mystring &rhs);      // s1 += s2; concat and assign
    friend Mystring operator*(Mystring &lhs, int n) ;                // s1 = s2 * 3; repeat s2 n times
    friend Mystring &operator*=( Mystring &lhs, int n);                    //s1 *= 3; s1 = s1 * 3;
    friend Mystring &operator++(Mystring &obj);                         // pre-increment ++s1;
    friend Mystring operator++(Mystring &obj,int);                       // post-increment s1++; 

    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs); 
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);  
    private:
         char *str;      // C-style string //pointer to a char[] that holds a C-style string  
     public: 
         Mystring();                            //No-args constructor
         Mystring(const char *s);               //Overloaded constructor
         Mystring(const Mystring &source);      //Copy constructor
         Mystring(Mystring &&source);           // Move constructor
         ~Mystring();                           //Destructor

        Mystring &operator=(const Mystring &rhs);   //Copy assignment    
        Mystring &operator = (Mystring &&rhs);      //Move assignment

         void display() const;
         int get_length() const;                //getters
         const char *get_str() const;
        
        //Solution 1
        // Overloaded operator member methods
        // Mystring operator-() const;                     // make lowercase
        // Mystring operator+(const Mystring &rhs) const;  // concatenate
        // bool operator== (const Mystring &rhs) const;    // equals
        // bool operator!= (const Mystring &rhs) const;    // not equals
        // bool operator< (const Mystring &rhs) const;     // less then
        // bool operator> (const Mystring &rhs) const;     // greater than
        // Mystring &operator+=(const Mystring &rhs);      // s1 += s2; concat and assign
        // Mystring operator*(int n) const;                // s1 = s2 * 3; repeat s2 n times
        // Mystring &operator*=(int n);                    //s1 *= 3; s1 = s1 * 3;
        // Mystring &operator++();                         // pre-increment ++s1;
        // Mystring operator++(int);                       // post-increment s1++; 
};

#endif