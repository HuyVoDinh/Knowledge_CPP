/***
 * [Operator Overloading]
 * 
 * Unary operators as global functions (++, --, -, !)
 * => Using non-member or global functions. Since these are not member functions, we no longer have a this pointer referring to the object on the left-hand side. So since we very often need access to private attributes in the objects, you see these non-member functions declared as friend functions of the class in many applications. 
 * This isn't absolutely necessary since we can still use getter methods to access attribute values. But as I said, you often see them implemented as friends. I'm going to declare these overloaded operator methods as friends when we head over to the IDE. 
 * So in the case of unary operators, a single object is in the parameter list. And in the case of a binary operator, two objects are in the parameter list. 
 * 
 * 
 *  ReturnType operatorOp(Type &obj);
 * 
 *  Number operator-(const Number &obj);
 *  Number operator++(Number &obj);                     // pre-increment
 *  Number operator++(Number &obj, int);                // post-increment
 *  bool operator!(const Number &obj);
 * 
 *  Number n1 {100};
 *  Number n2 = -n1;                                    // operator-(n1)
 *  n2 = ++n1;                                          // operator++(n1)
 *  n2 = n1++;                                          // operator++(n1,int)
 * 
 * Mystring oeprator - make lowercase
 * => So let's overload the unary minus operator to make a string lowercase as we did in the previous video. We want to provide the same functionality we did before, and our use of the unary minus operator would look the same.
 * 
 *  Mystring larry1 {"LARRY"};
 *  Mystring larry2;
 * 
 *  larry1.display();                                   // LARRY
 *  larry2 = -larry1;                                   // operator-(larry1)
 *  
 *  larry1.display();                                   // LARRY
 *  larry2.display();                                   // larry
 * 
 * Mystring operator-
 * Often declared as friend functions in the class declaration
 * => Assuming that this function has been declared as a friend to the mystring class since I'm directly accessing the private attribute str. Notice first that this in not a member function, It's a regular c++ global function The3 function returns a Mystring object by value, and it's named operator minus, and it expects a single parameter. 
 * In this case, obj is a Mystring object reference. Now the code is essentially the same as it was in the member version except that the string data is in obj.str rather than in this str. 
 * We allocate storage on the heap, copy the object's string  data, loop through and make the copied string all lowercase.  Then we create a new Mystring object using the lowercase string as the initializer, de-allocate the temporary storage and  return the newly created object. 
 * Of course, you can't have both the member and non-member versions of this overloaded operator at the same time or the compiler wouldn't know which one to use. You can onlye have one or the other. 
 * 
 *  Mystring operator-(const Mystring &obj){
 *      char* buff = new char[std::strlen(obj.str) + 1]
 *      std::Strcpy(buff, obj.str);
 *      for (size_t i = 0; i < std::strlen(buff); i++)
 *          buff[i] = std::tolower(buff[i]);
 *      Mystring temp {buff};
 *      delete [] buff;
 *      return temp;
 *  }
 * 
 * Binary operators as global functions (+, -, ==, !=, <, >, etc.)
 * => You probably already figured out that overloading binary operators as global functions is basically the same except that now we have two arguments required by the function. The first argument is the left-hand side object and the second is the right-hand side object. 
 * => Notice that they all have two parameters in the parameter list. I've named the first LHS for left-hand side and the second RHS for right-hand side. Then at the bottom of the slide, you can see how these operators can be used and the functions that c++ will call when it uses them. 
 * 
 * 
 *  ReturnType operatorOp(const Type &lhs, const Type &rhs);
 * 
 *  Number operator+(const Number &lhs, const Number &rhs);
 *  Number operator-(const Number &lhs, const Number &rhs);
 *  bool operator==(const Number &lhs, const Number &rhs);
 *  bool operator<(const Number &lhs, const Number &rhs);
 * 
 *  Number n1{100}, n2{200};
 *  Number n3 = n1 + n2;                    // operator+(n1,n2)
 *  n3 = n1 - n2;                           // operator-(n1,n2)
 *  if (n1 == n2)                           // operator==(n1,n2)
 * 
 * Mystring operator ==
 * 
 * => Overload the equality operator as a non-member function. Again, I'm accessing a private attribute str in the Mystring class. So I', assuming this function is a friend of the Mystring class. The code is almost the same as it was for the member version except that now I have an LHS object instead of the this pointer. 
 * So we compare the left-hand side string to the right-hand side string using string compare as we did before. 
 * 
 *  bool operator==(const Mystring &lhs, const Mystring &rhs){
 *      if (std::strcmp (lhs.str, rhs.str) == 0)
 *          return true;
 *      else 
 *          return false;
 *  }
 * 
 * If declared as a friend of Mystring can access private str attribute
 * Otherwise we must use getter methods
 * 
 * Mystring operator+(concatenation)
 *  => Overload the binary + operator so that we can use it. to concatenate two Mystring objects. We create larry, moe and stooges as Mystring objects as we did previously. Now when we use the plus operator, notice the methods that the compiler is calling in the comments. 
 * Also notice that each is called with two arguments as we expect. Finally, remember that with the member version, the left-side argument had to be an object of the class type. With non-member functions, this isn't hte case. Either one or both arguments can be of Mystring type. 
 * However, if you have two string literals that won't work. C++ assumes primitive pointer and not objects.
 * 
 *  Mystring larry{"Larry"};
 *  Mystring moe{"Moe"};
 *  Mystring stooges {" is one of the three stooges"};
 *  Mystring result = larry + stooges;                      // operator+(larry, stooges);
 *  result = moe + " us also a stooge";                     // operator+(moe, " is also a stooge");
 *  result = "Moe" + stooges;                               // OK with non-member functions
 * 
 * 
 * => The function operator plus returns a Mystring object by value. It also expects two Mystring objects left-hand side and right-hand side. Notice that they're both constant references since we don't want to modify them. The code now is exactly as it was for the member version expect that whenever I need the left-hand side object I use LHS instead of the his pointer. 
 * Both the member and non-member versions achieve the desired result. But remember, you can only use one at a time.
 * 
 *  Mystring operator+(const Mystring &lhs, const Mystring &rhs){
 *      size_t buff_size = std:: strlen(lhs.str) + std::len(rhs.str) + 1;
 *      char *buff = new char[buff_size];
 *      std::Strcpy(buff, lhs.str);
 *      stdLLstrcat(buff, rhs.str);
 *      Mystring temp {buff};
 *      delete [] buff;
 *      return temp;
 *  }
 * ****/

#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main(){
    Mystring larry {"Larry"};
    larry.display();

    larry = -larry;
    larry.display();

    cout << boolalpha << endl;
    Mystring moe {"Moe"};
    Mystring stooge = larry;

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    // Mystring stooges = larry + "Moe";
    Mystring stooges = "Larry" + moe;
    stooges.display();

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();

    Mystring three_stooges = moe + " " +  larry + " " + "Curly";
    three_stooges.display();

    return 0;
}


