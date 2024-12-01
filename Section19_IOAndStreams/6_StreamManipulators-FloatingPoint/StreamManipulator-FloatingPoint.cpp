/****
 * [Formatting floating point types]
 * 
 * Default when displaying floating point values is: 
 *  setprecision - number of digits displayed (6)
 *  fixed - not fixed to a specific number of digits after the decimal point
 *  noshowpoint - trailing zeroes are not displayed
 *  nouppercase - when displaying in scientific notation
 *  noshowpos - no '+' is displayed for positive numbers
 * 
 * These manipulators affect all further output to the stream
 * 
 * [Formatting floating point types - precision]
 * double num {1234.5678};
 * 
 * std::cout << num << std::endl;
 * 
 * //Will display
 * 1234.56      //Notice precision is 6 and rounding
 * 
 * double num {123456789.987654321};
 * std::cout << num << std::endl;
 * 
 * //Will display
 * 1.23457e+008         //Notice precision is 6     => If display this number, C++ will try to do it with 6 significant digits, but this won't work since it will display 123456, and the number displayed wouldn't be accurate. So in t his case, the number displayed using scientific notation. And notice 1.23457 has got the digits of precision that's the default. 
 * 
 * 
 * double num {123456789.987654321};
 * std::cout << std::setprecision(9);
 * std::cout << num << std::endl;
 * 
 * //Will display
 * 1234567890           // Note that rounding occurs 
 * 
 * 
 * [Formatting floating point types - fixed]
 * 
 * double num {123456789.987654321};
 * 
 * std::cout << std::fixed;
 * std::cout << num >> std::endl;
 * 
 * // Will display precision 6 from the decimal
 * 123456789.9887654
 * 
 * 
 * double num {123456789.987654321};
 * 
 * std::cout << std::Setprecision(3) << std::fixed;
 * std::cout << num << std::endl;
 * 
 * //Will display precision 3 from the decimal
 * 123456789.988
 * 
 * [Formatting floating point types - scientific]
 * 
 * double num {123456789.987654321};
 * 
 * std::cout << std::setprecision(3) << std::scientific;
 * std::cout << num << std::endl;
 * 
 * //Will display precision 3
 * 1.23e+008
 * 
 * 
 * [Formatting floating point types - scientific uppercase]
 * 
 * double num {123456789.987654321};
 * 
 * std::cout << std::setprecision(3) << std::scientific << std::uppercase;
 * std::cout << num << std::endl;
 * 
 * //Will display precision 3
 * 1.23E+008        // Note the capital 'E'
 * 
 * 
 * [Formatting floating point types - displaying the positive sign]
 * 
 * double num {123456789.987654321};
 * 
 * std::cout << std::setprecision(3) << fixed << std::showpos;
 * std::cout << num << std::endl;
 * 
 * //Will display precision 3
 * +123456789.988       // Note the leading '+'
 * 
 * [Formatting floating point types - trailing zeroes]
 * 
 * double num {12.34};
 * 
 * std::cout << num << std::endl;       //12.34
 * std::cout << std::showpoint;
 * std::cout << num << std::endl;       //12.3400
 * 
 * //Will display precision 3
 * 12.34                // Note no trailing zeroes (default)
 * 12.3400              // Note trailing zeroes up to precision
 * 
 * 
 * [Returning to general settings]
 * 
 *  unsetf
 *      std::cout.unsetf(std::ios::scientific | std::ios:fixed);
 *  or
 *      std::cout << std::resetiosflags(std::ios::floatfield);
 * 
 *  Refer to the docs for other set/reset flags
 * ***/

#include <iostream>
#include <iomanip>

int main(){

    double num1 {123456789.987654321};
    double num2 {1234.5678};
    double num3 {1234.0};

    //using default settings
    std::cout << "--Defaults------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Note how since we can't display in precision 2 scientific notation is used
    std::cout << std::setprecision(2);
    std::cout << "--Precision 2------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Using precision 5
    std::cout << std::setprecision(5);
    std::cout << "--Precision 5------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Using precision 9
    std::cout << std::setprecision(9);
    std::cout << "--Precision 9------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Using precision 3 and fixed
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << "--Precision 3 - fixed------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Using precision 3, fixed and scientific notation
    //Note precision is after the decimal
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << "--Precision 3 - scientific------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Same but display capital 'E' in scientific
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << "--Precision 3 - scientific - uppercase------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Show '+' symbol for positive
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << "--Precision 3 - fixed - showpos------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);

    //Show trailing zeroes up to precision 10
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << "--Precision 3 - showpoint------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    //Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showpoint);

    std::cout << "--Back to defaults------------------------\n";
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    return 0;
}