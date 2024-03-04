#include <iostream>
using namespace std;

int main()
{
    /***
     * |    Operator    |               Meaning                 |
     * |        >       |   greater than                        |
     * |        >=      |   greater than or equal to            |
     * |        <       |   less than                           |
     * |        <=      |   less than or equal to               |
     * |        <=>     |   three-way comparision (C++20)       |
     * 
     * **/

    int num1{}, num2{};

    cout << boolalpha;
    cout << "Enter 2 integers separated by a space: ";
    cin >> num1 >> num2;

    cout << num1 << " > " << num2 << ": " << (num1 > num2) << endl;
    cout << num1 << " >= " << num2 << ": " << (num1 >= num2) << endl;
    cout << num1 << " < " << num2 << ": " << (num1 < num2) << endl;
    cout << num1 << " <= " << num2 << ": " << (num1 <= num2) << endl;

    const int lower {10};
    const int upper {20};

    cout << "Enter an integer that is greater than " << lower << ": ";
    cin >> num1;
    cout << num1 << " > " << lower << ": " << (num1 > lower) << endl;

    cout << "Enter an integer that is less than or equal to " << upper << ": ";
    cin >> num1;
    cout << num1 << " <= " << upper << ": " << (num1 <= upper) << endl;
    return 0;
}