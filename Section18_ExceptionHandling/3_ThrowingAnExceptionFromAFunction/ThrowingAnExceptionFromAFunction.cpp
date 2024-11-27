/***
 * [Exception Handling]
 * 
 * Throwing an exception from a function
 * What do we return if total is zero?
 * 
 *  double calculate_avg(int sum. int total) {
 *      return static_case<double>(sum) / total;
 *  }
 * 
 * Throwing an exception if we can't complete successfully
 * // Could throw anything and C++ allows us to throw just about any type. 
 *  double calculate_avg(int sum, int total){
 *      if (total == 0)
 *          throw 0;        // if throw the exception, the division will not happen, and the function will terminate. Now C++ will try to find an exception handler to catch that integer that the function threw. But if an exception handler exists, it must be in one of the functions on the call stack that called this function.
 *      return static_cast<double>(sum) / total;
 *  }
 * 
 * Catching an exception thrown from a function
 * 
 *  double average {};
 *  try{
 *      average = calculate_avg(sum, total);
 *      std::cout << average << std::endl;
 *  } catch (int *ex){
 *      std::cerr << "You can't devide by zero\n";
 *  }
 *  std::cout << "Bye\n";
 * ***/
#include <iostream>
using namespace std;

double calculate_mpg(int miles, int gallons){
    if (gallons == 0)
        throw 0;        // It's going to throw this exception. That exception is not being caught anywhere. If not catch exception, it is going to terminate abnormally.
    return static_cast<double>(miles)/gallons;
}

int main(){

    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    try {
    miles_per_gallon = calculate_mpg(miles, gallons);      
    std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int &ex){
        std::cerr << "Sorry, can't devide by zero\n";
    }
    std::cout << "Bye\n";
    return 0;
}