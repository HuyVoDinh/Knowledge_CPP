/***
 * [What is a function]
 * 
 *  C++ programs
 *      C++ Standard Libraries (functions and classes)
 *      Third-party libraries (functions and classes)
 *      Our own functions and classes
 * 
 *  Functions allow the modularization of a program
 *      Separate code into logical self-contained units
 *      These units can be reused
 * 
 * int main(){  
 * 
 * // read input                                                                            read_input(){
 *  statement1;                                                                                 statement1;
 *  statement2;                                                                                 statement2;
 *  statement3;                                     int main() {                                statement3;
 *  statement4;                                                                                 statement4;    
 *                                                      // read input                       }
 * // process input                                     read_input();
 *  statement5;                                                                             process_input(){
 *  statement6;                             =>          // process input            =>          statement5;
 *  statement7;                                         process_input();                        statement6;
 *  statement8;                                                                                 statement7;
 *                                                                                              statement8;
 * // provide output                                    //provide output                    }
 *  statement9;                                         provide_output();
 *  statement10;                                                                            provide_output(){
 *  statement11;                                    }                                           statement9;
 *  statement12;                                                                                statement10;
 *                                                                                              statement11;
 * return 0;                                                                                    statement12;
 * }                                                                                        }
 * 
 * Write your code to the function specification
 * Understand what the function does
 * Understand what information the function needs
 * Understand what the function returns
 * Understand any errors the function may produce
 * Understand any performance constraints
 * 
 * Don't worry about HOW the function works internally
 *  Unless you are the one writing the function
 * 
 * Example <cmath>
 * 
 * Common mathematical calculations
 * Global functions called as:
 *  function_name(argument);
 *  function_name(argument1, argument2, ...);
 * 
 * cout << sqrt(400.0) << endl;
 *  double result;
 *  result = pow(2.0, 3.0);
 * 
 * 
 * [User-defined functions]
 * 
 * We can define our own functions
 * Return zero if any of the arguments are negative
 * https://en.cppreference.com/w/
 * https://cplusplus.com/reference/
 * Here is a preview
 * 
 * int add_numbers(int a, int b)
 * {
 *      if(a < 0 || b < 0)
 *          return 0;
 *      return a+b;
 * }
 * 
 * cout << add_numbers(20, 40);
 * ***/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double num;

    cout << "Enter a number (double): ";
    cin >> num;

    cout << "The sqrt of " << num << " is " << sqrt(num) <<endl;
    cout << "The cubed root of " << num << " is " << cbrt(num) << endl;

    cout << "The sine of " << num << " is " << sin(num) << endl;
    cout << "The cosine of " << num << " is " << cos(num) << endl;

    cout << "The ceil of " << num << " is " << ceil(num) << endl;
    cout << "The floor of " << num << " is " << floor(num) << endl;
    cout << "The round of " << num << " is " << round(num) << endl;

    double power {};
    cout << "\nEnter a power to raise " << num << " to: ";
    cin >> power;
    cout << num << " raised to the " << power << " power is: " << pow(num, power) << endl;


    cout << "\nRANDOM\n";

    int random_number {};
    size_t count = 10;
    int min = 1;
    int max = 6;

    //seed the random number generator. If dont seed the generator, will get the same sequence random numbers every run

    cout << "RAND_MAX on my system is: " << RAND_MAX << endl; 
    srand(time(nullptr));

    for(size_t i = 1; i < count; i++){
        random_number = rand() % max + min;
        cout << random_number << endl;
    }
}