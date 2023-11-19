#include <iostream>
using namespace std;

int main()
{
    /***
     * What is variable
     * A variable is an abstraction for a memory location
     * Variables have data type and value
     * Variable must be declared before they are used
     * A variables value may change
     * **/
    
    /***
     * [Declaring variable]
     * 
     * VariableType VariableName;
     * ***/
    int age;
    double rate;
    string name;

    /***
     * [Rule for naming c++ variable]
     * 
     * Can contain letter, numbers, and underscores
     * Must begin with a letter or underscore and cannot begin with a number
     * Cannot use C++ reversed keywords
     * Cannot redeclare a name in the same scope
     * C++ is case sensitive
     *      Example: The name, age in uppercase is considered different from the name, age and lowercase
     * 
     * Legal     | Illegal
     * Age       | int
     * age       | $age
     * _age      | 2014_age
     * My_age    | My age
     * your_age  | Age+1
     * INT       | cout
     * Int       | return
     * 
     * [Naming Variables - Style]
     * 
     * Be consistent with your naming conventions
     *      MyVariableName vs. my_variable_name
     *      avoid beginning names with underscores
     * Use meaningful names
     *      not too long and not too short
     * Never use variables before initializing them
     * Declare variables close to when you need them in your code
     * 
     * int age;     uninitialized
     * int age = 21;    C-like initialization
     * int age (21);    Constructor initialization
     * int age {21};    C++11 list initialization syntax
     * ***/

    int number {21};
    cout << number;
}