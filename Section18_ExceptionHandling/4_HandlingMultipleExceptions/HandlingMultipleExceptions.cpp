/***
 * Throwing multiple exceptions from a function
 * What if a function can fail in several ways
 *  gallons is zero
 *  miles or gallons is negative        => it would also produce incorrect results if either miles or gallon is negative
 * 
 *  double calculate_mpg(int miles, int gallons){'
 *      return static_case<double>(miles) / gallons;
 *  }
 * 
 * Throw different type exceptions for each condition
 *  
 *  double calculate_mpg(int miles, int gallons){
 *      if(gallons == 0)
 *          throw 0;
 *      if (miles < 0 || gallons < 0)
 *          throw std::string {"Negative value error"};
 * 
 *      return static_case<double>(miles) / gallons;
 *  }
 * 
 * Catching an exception thrown from a function
 * 
 * => If an exception is thrown, then one of these catch handlers will handle it. If don't handle a particular exception. Then C++ will terminate this function and proceed up the call stack looking for a handler until it finds one or the program terminates.
 *  double miles_per_gallon {};
 *  try {
 *      miles_per_gallon = calculate_mpg(miles, gallons);
 *      std::cout << miles_per_gallon << std::endl;
 *  }
 *  catch (int &ex) {
 *      std::cerr << "You can't devide by zero\n";
 *  }
 *  catch (std::string &ex) {
 *      std::cerr << ex << std::endl;
 *  }
 * 
 * Catching any type of exception
 * => It's also possible to have a catch-all handler. This catch handler will fire no matter what type of exception is thrown. Of this is used, it's common to place it as the last of your catch blocks since it really servers to catch anything that wasn't handled before. 
 * 
 *  catch (int &ex){
 *  }
 *  catch (std::String &ex){
 *  }
 *  catch (...){
 *      std::cerr << "Unknown exception\n";
 *  }
 * 
 *  std::cout << "Bye\n";
 * ***/
#include <iostream>
#include <string>
using namespace std;

double calculate_mpg(int miles, int gallons){
    if (gallons == 0)
        throw 0;        // It's going to throw this exception. That exception is not being caught anywhere. If not catch exception, it is going to terminate abnormally.
    if (miles < 0 || gallons < 0)
        throw std::string {"Negative value error"};
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
        std::cerr << "Tried to devide by zero\n";
    } catch (std::string &ex){
        std::cerr << ex << std::endl;
    } catch (...){
        
    }
    std::cout << "Bye\n";
    return 0;
}