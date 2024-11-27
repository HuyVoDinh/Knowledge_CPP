/****
 * [Exception handling]
 * 
 * Basics concepts
 * 
 *  Exception handling      => exception in C++ should be used only for synchronous code, not asynchronous code.
 *      dealing with extraordinary situations
 *      indicates that an extraordinary situation has been detected or has occurred
 *      program can deal with the extraordinary situations in a suitable manner.alignas => In some case, we'll be able to recover and continue. But in other cases, maybe the only alternative is to terminate the program. But in this case, can control how we terminate the program. 
 * 
 *  What causes exceptions?
 *      insufficient resources          => Maybe we're out of memory or we have no external storage left, and we need that to continue. Another cause is missing resources. Suppose we need to open and read a file, but that file doesn't exist/ If this file is critical to our program, then we have to decide how we're going to continue if it's even possible. 
 *      missing resources
 *      invalid operations
 *      range violations
 *      underflows and overflows
 *      illegal data and many others
 * 
 *  Exception safe
 *      when your code handles exception
 * 
 * 
 * Terminology
 * 
 *  Exception
 *      An object or primitive type that signals that an error has occurred
 * 
 *  Throwing an exception (raising an exception)
 *      your code detects that an error has occurred or will occur
 *      the place where the error occurred may not know how to handle the error
 *      code can throw an exception describing the error to another part of the program that knows how to handle the error
 *      //Example I want to allocate some memory dynamically, but there isn't enough memory available. The part of our code that allocates the memory would throw an exception since it couldn't allocate any more memory, but it doesn't know what to do. Then in some other part of our program, we can catch this exception and maybe we can clear out some buffers or caches and then release some memory and then try to allocate it again.
 * 
 * 
 *  Catching an exception (handle the exception)
 *      code that handles the exception
 *      may or may not cause the program to terminate
 * 
 * 
 * [C++ syntax]
 * 
 *  throw
 *      throws an exception
 *      followed by an argument
 * 
 *  try {code that may throw an exception}
 *      you place code that may throw an exception in a try block
 *      if the code throws an exception is handled by a catch handler
 *      if no catch handler exists the program terminates
 * 
 *  catch (Exception ex) {code to handle the exception}
 *      code that handle the exception
 *      can have multiple can handlers
 *      may or may not cause the program to terminate
 * 
 * [Divide by zero example]
 * 
 *  What happens if total is zero?
 *      crash, overflow?
 *      it depends?
 *          double average {};      
 *          average = sum / total?          //=> Does the program crash and get an underfined result. The result of a division by 0 depends on the types of the arguments in the division operation. 
 * 
 * 
 *          double average {};
 *          if (total == 0)
 *              // what to do?              // We don't know what are we doing if total = 0
 *          else 
 *              average = sum / total;
 * 
 * 
 *          double average {};
 *          try {                           // try block
 *              if (total == 0)
 *                  throw 0;                // throw the exception
 *              average = sum / total;      // won't execute if total == 0
 *              //use average here
 *          }
 *          catch (int &ex) {               // exception handler
 *              std::cerr << "can't devide by zero\n";
 *          }
 *          std::cout << "program continues\n";
 * ****/

#include <iostream>

// int main(){

//     int miles {};
//     int gallons {};
//     double miles_per_gallon {};

//     std::cout << "Enter the miles: ";
//     std::cin >> miles;
//     std::cout << "Enter the gallons: ";
//     std::cin >> gallons;

//     if(gallons != 0){
//     // miles_per_gallon = miles / gallons;                          // => crash
//     miles_per_gallon = static_cast<double>(miles) / gallons;        // => result is "inf". If miles = 0, gallons = 0 -> result = nan
//     std::cout << "Result: " << miles_per_gallon << std::endl;
//     } else {
//         std::cerr << "Sorry, can't devide by zero\n";
//     }
//     std::cout << "Bye\n";
//     return 0;

//     return 0;
// }

int main(){

    int miles {};
    int gallons {};
    double miles_per_gallon {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    try {
            if(gallons != 0){
                throw 0;            //=> if do throw this exception, this piece of code here is not executed at all. It's totally skipped.
            }
            // => If gallons is not equal to 0, then our code executes as normal. 
        // miles_per_gallon = miles / gallons;                          // => crash
        miles_per_gallon = static_cast<double>(miles) / gallons;        // => result is "inf". If miles = 0, gallons = 0 -> result = nan
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int &ex){             // C++ system is looking for that exception that was just thrown. If don't catch it, then the program will terminate.
        std::cerr << "Sorry, can't devide by zero\n";
    }
    //=> The program will not crash
    // => If else is not typically the way that we do exception handling. We do the exception handling when a function throws an exception, and that function has no idea what to do with it and catch that exception somewhere else.
    std::cout << "Bye\n";
    return 0;

    return 0;
}