#include <iostream>
using namespace std;

int main()
{
    /***
     * [Arithmetic operators]
     *      +   addition
     *      -   subtraction
     *      *   multiplication
     *      /   division
     *      %   modulo or remainder (works only with integers)
     * 
     *      +, -, * and / operators and overloaded to work with multiple types such as int, double, etc
     *      % only for integer types
     * ***/
    
    int num1 {200};
    int num2 {100};

    cout << num1 << " + " << num2 << " = " << num1+num2 << endl;

    int result {0};

    result = num1 + num2;
    cout << num1 << " + " << num2 << " = " << result << endl;

    result = num1 - num2;
    cout << num1 << " - " << num2 << " = " << result << endl;

    result = num1 * num2;
    cout << num1 << " * " << num2 << " = " << result << endl;

    result = num1 / num2;
    cout << num1 << " / " << num2 << " = " << result << endl;

    result = num1 % num2;
    cout << num1 << " % " << num2 << " = " << result << endl;

    num1 = 10;
    num2 = 3;

    result = num1 % num2;
    cout << num1 << " % " << num2 << " = " << result << endl;  

    /***
     *  the precedents or the order in which this stuff happens is the same precedents you probably learned in grade school
     * PEMDAS
     * P is parentheses
     * E is exponents
     * D is division
     * A is addition
     * S is subtraction
     * **/
    result = num1*10+num2; 
    
    cout << 5/10 << endl;

    cout << 5.0 / 10.0 << endl;// result is 0.5 because using double type
    //Can use cast to tell the compiler this to be a double instead of an integer even though it looks like an integer there
 
    return 0;
}