#include <iostream>
using namespace std;

int main()
{
    /**
     * [Mixed type Expression]
     * C++ operations occur on same type operands
     * If operands are of different types, C++ will convert one
     * Important! Since it could affect calculation results
     * C++ will attempt to automatically convert types (coercion). If it can't a compiler error will occur
     * 
     * [Conversions]
     * Higher vs. Lower types are based on the size of the values the type can hold -> The lower types are those type that can hold smaller values and higher types can hold larger values. We can typically convert from a lower type to a larger type automatically since the lower types value will fir into the higher types value
     *  long double, double, float, unsigned long, long unsigned int, int
     *  short and char types are always converted to int
     * 
     * Type Coercion: Conversion of one operand to another data type
     * 
     * Promotion: conversion to a higher type
     *  Used in mathematical expressions
     * 
     * Demotion: conversion to a lower type
     *  Used with assignment to lower type
     * 
     * [Examples]
     * 
     *      lower op higher              the lower is promoted to a higher
     *        2   *    5.2
     *        2 is promoted to 2.0
     * 
     *      lower = higher              the higher is demoted to a lower
     *      int num {0};
     *      num = 100.2;
     * 
     * [Explicit type castling - static_cast<type>]
     *  int total_amount {100};
     *  int total_number {8};
     *  double average {0.0};
     *  
     *  average = total_amount / total_number;
     *  cout << average << endl;                                        //12
     * 
     *  average  static_cast<double> {total_amount} / total_number;
     *  cout << average << endl;                                        // 12.5
     * 
     * ***/

    /***
     * Ask the user to enter 3 integers
     * Calculate the sum of the integers then calculate the average of the integers
     * 
     * Display the 3 integers entered the sum of the 3 integers and the average of the 3 integers
     * 
     * ***/
    int total{};
    int num1 {}, num2 {}, num3 {};
    const int count {3};

    cout << "Enter 3 integers separated by spaces: ";
    cin >> num1 >> num2 >> num3;

    total = num1 + num2 + num3;

    double average {0.0};

    average = static_cast<double>(total)/ count;
    average = (double)total / count;

    cout << "The 3 numbers were: " << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "The sum of the numbers is: " << total << endl;
    cout << "The average of the numbers is: " << average << endl;

    return 0;
}