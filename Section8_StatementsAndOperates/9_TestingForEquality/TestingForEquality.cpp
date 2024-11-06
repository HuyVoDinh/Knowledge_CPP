#include <iostream>
using namespace std;

int main()
{
    /***
     * [Testing for Equality]
     * 
     * The == and != operators
     *  Compares the values of 2 expressions
     *  Evaluates to a Boolean (True or False, 1 or 0)
     *  Commonly used in control flow statements
     *  
     *      expr1 == expr2
     *      expr1 != expr2
     *      100 == 200
     *      num1 != num2
     * 
     * [Example == and != operators]
     * 
     *      bool result {false};
     *      result = (100 == 50+50);
     *      result = (num1 != num2);
     *      cout << (num1 == num2) << endl          // 0 or 1
     *      cout << std::boolalpha;
     *      cout << (num1 == num2) << endl;         // true or false
     *      cout << std::noboolalpha;
     *      
     * ***/

    bool equal_result {false};
    bool not_equal_result {false};
    
    int num1{},num2{};

    cout << boolalpha;                  // will display true/false instead of 1/0 for booleans

    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2;
    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);
    cout << "Comparision result (equals): " << equal_result << endl;
    cout << "Comparision result (not equals): " << not_equal_result << endl;

    char char1{}, char2{};
    cout << "Enter two characters separated by a space: ";
    cin >> char1 >> char2;
    equal_result = (char1 == char2);
    not_equal_result = (char1 != char2);
    cout << "Comparision result (equals): " << equal_result << endl;
    cout << "Comparision result (not equals): " << not_equal_result << endl;

    double double1{}, double2{};
    cout << "Enter two doubles separated by a space: ";             //Example 12.0 and 11.999999999999999999999999999999999999
    cin >> double1 >> double2;
    equal_result = (double1 == double2);
    not_equal_result = (double1 != double2);
    cout << "Comparision result (equals): " << equal_result << endl;
    cout << "Comparision result (not equals): " << not_equal_result << endl;

    cout << "Enter an integer and a double separated by a space: ";
    cin >> num1 >> double1;
    equal_result = (num1 == double1);
    not_equal_result = (num1 != double1);
    cout << "Comparision result (equals): " << equal_result << endl;
    cout << "Comparision result (not equals): " << not_equal_result << endl;
    return 0;
}