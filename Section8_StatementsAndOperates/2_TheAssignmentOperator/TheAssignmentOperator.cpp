#include <iostream>
using namespace std;


int main()
{
    /***
 * [Assignment Operator (=)]
 *      lhs = rhs   //left hand side = right hand side
 * rhs is an expression that is evaluated to a value
 * The value of the rhs is stored to the lhs
 * 
 * The value of the rhs must by type compatible with the lhs
 * Tha lhs must be assignable. It can't be a literal or const
 * 
 * Assignment expression is evaluated to what was just assigned 
 * More than one variable can be assigned in a single statement
 * ***/
    int num1{10}; //initialization
    int num2{20}; //initialization

    num1 = 100; // lhs = rhs
    num1 = num2; // lhs = rhs
    num1 = num2 = 100; // lhs <----- rhs => num1 = (num2 = 100)  => num1 = 100

    cout << "num1 is " << num1 << endl;
    cout << "num2 is " << num2 << endl;
}