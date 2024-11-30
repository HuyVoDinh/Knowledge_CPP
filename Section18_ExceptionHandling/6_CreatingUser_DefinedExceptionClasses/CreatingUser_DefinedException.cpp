/***
 * [User-defined exceptions]
 * We can create exception classes and throw instances of those classes
 * 
 *  Best practice:
 *      throw an object not a primitive type
 *      throw an object by value
 *      catch an object by reference (or const reference)
 * 
 * [Creating exception classes]
 * 
 * class DivideByZeroException{
 * };
 * 
 * class NegativeValueException {
 * };
 * 
 * [throwing user-defined exception classes]
 * 
 *  double calculate_mpg(int miles, int gallons){
 *      if (gallons == 0)
 *          throw DivideByZeroException();
 *      if (miles < 0 || gallons < 0)
 *          throwNegativeValueException();
 * 
 *      return static_cast<double>(miles)/gallons;
 *  }
 * 
 * => The function may or may not throw an exception. If it does not, then we simply assign the result of the function to miles per gallon, display it, transfer control all the may to the bottom, and display buy, and done. 
 * If calculate miles per gallon does throw an exception. It could throw a divide by 0 exception or a negative value exception. So create two catch handlers, one for each exception type, and write exception handling code in the catch blocks . 
 * If an exception is thrown then one of these catch handlers will handle it. Notice how we're catching the exceptions by const ref. If we had provided attributes or methods in the exception classes, we would access them. 
 * As before, if don't handle a particular exception type then C++ will terminate this function and proceed up the call stack looking for a handler until it finds one or the program terminates. 
 *  try {
 *      miles_per_gallon = calculate_mpg(milles, gallons);
 *      std::cout << miles_per_gallon << std::endl;
 *  }
 *  catch (const DivideByZeroException &ex){
 *      std::cerr << "You can't divide by zero\n";
 *  }
 *  catch (const NegativeValueException &ex){
 *      std::cerr << "Negative values aren't allowed\n";
 *  }
 * 
 *  std::cout << "Bye\n";
 * ***/

#include <iostream>

class DivideByZeroException{};
class NegativeValueException {};

double calculate_mpg(int miles, int gallons){
    if (gallons == 0)
        throw DivideByZeroException();
    if (miles < 0 || gallons < 0)
        throw NegativeValueException();

    return static_cast<double>(miles)/gallons;
}

int main(){
    int miles {};
    int gallons {};
    double miles_per_gallon{};

    std::cout << "Enter the miles driven: ";
    std::cin >> miles;
    std::cout << "Enter the gallons used: ";
    std::cin >> gallons;

    try{
        miles_per_gallon = calculate_mpg(miles,gallons);
        std::cout << "Result " << miles_per_gallon << std::endl;
    }
    catch (const DivideByZeroException &ex){
        std::cerr << "Sorry, you can't divide by zero\n";
    }
    catch (const NegativeValueException &ex){
        std::cerr << "Sorry, one of your parameters is negative\n";
    }
    std::cout << "Bye\n";
    return 0;
}