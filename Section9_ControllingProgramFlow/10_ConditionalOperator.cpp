#include <iostream>
using namespace std;

/***
 * [Conditional Operator]
 *  (cond_expr) ? expr1 : expr2
 * 
 *      cond_expr evaluates to a boolean expression
 *          If cond_expr is true then the value of expr1 is returned
 *          If cond_expr is false then the value of expr2 is returned
 * 
 * Similar to if-else construct
 * Ternary operator
 * Very useful when used inline
 * Very easy to abuse => This leads to if else if logic that quickly becomes unreadable and difficult to manage
 * 
 * [Example]
 * 
 * int a = 10, b = 20;
 * int score = 92;
 * int result;
 * 
 * result = (a > b) ? a : b;
 * 
 * result = (a < b) ? (b-a) : (a-b);
 * 
 * result = (b != 0) ? (a/b) : 0;
 * 
 * cout << ((score > 90) ? "Excellent" : "Good");
 * ***/

int main()
{
    int num = 0;

    cout << "Enter an integer: ";
    cin >> num;

    cout << num << " " << ((num %2 == 0) ? "is even" : "is old");

    int num1,num2;
    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;

    if(num != num2)
    {
        cout << "Largest: " << ((num1 > num2) ? num1 : num2);
        cout << "Smallest: " << ((num1 > num2) ? num2 : num1);
    }
    else
    {
        cout << "The numbers are the same.\n";
    }
    return 0;
}