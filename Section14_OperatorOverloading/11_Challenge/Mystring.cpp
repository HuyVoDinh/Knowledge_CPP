#include <iostream>
#include "Mystring.h"
#include <cstring>



// No-args constructor

Mystring::Mystring() : str{nullptr}
{                     
    str = new char[1];
    *str = '\0';       
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);               
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr}
{                                               
    str = new char[std::strlen(source.str) + 1]; 
                                                 
    std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring()
{ 
    delete[] str;
}

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

//Solution 1
// Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

// Length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char *Mystring::get_str() const { return str; }

std::ostream &operator<<(std::ostream &os, const Mystring &rhs){
    os << rhs.str;
    return os;
}
std::istream &operator>>(std::istream &in, Mystring &rhs){
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete[]buff;
    return in;
}

// //Equality
// bool Mystring::operator==(const Mystring &rhs) const{
//     return (std::strcmp(str,rhs.str)==0);
// }

// // Not equality
// bool Mystring::operator!=(const Mystring &rhs) const{
//     return !(std::strcmp(str,rhs.str)==0);
// }

// //Less than
// bool Mystring::operator< (const Mystring &rhs) const{
//     return (std::strcmp(str,rhs.str)<0);
// }

// // Greater than
// bool Mystring::operator>(const Mystring &rhs) const{
//     return (std::strcmp(str,rhs.str)>0);
// }

// // Make lowercase
// Mystring Mystring::operator-() const{
//     char *buff = new char[std::strlen(str)+1];
//     std::strcpy(buff,str);
//     for(size_t i = 0; i < std::strlen(buff); i++)
//         buff[i] = std::tolower(buff[i]);
//     Mystring temp {buff};
//     delete [] buff;
//     return temp;
// }

// // Concatentate
// Mystring Mystring::operator+(const Mystring &rhs) const{
//     char *buff = new char[std::strlen(str) + std::strlen(rhs.str)+1];
//     std::strcpy(buff,str);
//     std::strcat(buff, rhs.str);
//     Mystring temp {buff};
//     delete [] buff;
//     return temp;
// }

// // Concat and assign
// Mystring &Mystring::operator+=(const Mystring &rhs){
//     *this = *this + rhs;
//     return *this;
// }

// //repeat
// Mystring Mystring::operator*(int n) const{
//     Mystring temp;
//     for (int i = 0; i <= n; i++)
//         temp = temp + *this;
//     return temp;

//     // size_t buff_size = std::strlen(str) * n + 1;
//     // char * buff = new char[buff_size];
//     // strcpy(buff, "");
//     // for(int i = 0; i <= n; i++)
//     //     strcat(buff, str);
//     // Mystring temp {buff};
//     // delete [] buff;
//     // return temp;
// }

// // repeat and assign
// Mystring &Mystring::operator*=(int n){
//     *this = *this * n;
//     return *this;
// }

// // Pre-increment - make the string upper case
// Mystring &Mystring::operator++() {  // pre-increment
//     for (size_t i = 0; i < std::strlen(str); i++)
//         str[i] = std::toupper(str[i]);
//     return *this;
// }

// // Post-increment - make the string upper-case
// Mystring Mystring::operator++(int){     // post-increment
//     Mystring temp (*this) ;    // make a copy
//     operator++();               // call pre-increment - make sure you call preincrement!
//     return temp;                // return the old value
// }

//Solution 2

// No-args constructor
//Equality
bool operator==(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str)==0);
}

// Not equality
bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(std::strcmp(lhs.str,rhs.str)==0);
}

//Less than
bool operator< (const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str,rhs.str)<0);
}

// Greater than
bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str,rhs.str)>0);
}

// Make lowercase
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str)+1];
    std::strcpy(buff,obj.str);
    for(size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Concatentate
Mystring operator+(const Mystring &lhs,const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str)+1];
    std::strcpy(buff,lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Concat and assign
Mystring &operator+=(Mystring &lhs,const Mystring &rhs){
    lhs = lhs + rhs;
    return lhs;
}

//repeat
Mystring operator*(Mystring &lhs,int n){
    Mystring temp;
    for (int i = 0; i <= n; i++)
        temp = temp + lhs;
    return temp;
}

// repeat and assign
Mystring &operator*=(Mystring &lhs,int n){
    lhs = lhs * n;
    return lhs;
}

// Pre-increment - make the string upper case
Mystring &operator++(Mystring &obj) {  // pre-increment
    for (size_t i = 0; i < std::strlen(obj.str); i++)
        obj.str[i] = std::toupper(obj.str[i]);
    return obj;
}

// Post-increment - make the string upper-case
Mystring operator++(Mystring &obj,int){     // post-increment
    Mystring temp (obj) ;    // make a copy
    operator++(obj);               // call pre-increment - make sure you call preincrement!
    return temp;                // return the old value
}