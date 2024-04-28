/***
 * [Recursive Functions]
 * A recursive function is a function that calls itself
 *  Either directly or indirectly through another function // if we end up with two or more activation records on the stack for the same function, then we have recursion
 * 
 * Recursive problem solving
 *  Base case
 *  Divide the rest of problem into subproblem and do recursive call
 * 
 * There are many problems that lend themselves to recursive solutions
 * 
 * Mathematic - factorial, Fibonacci, fractals,...
 * 
 * Searching and sorting - binary search, search tress,... 
 * 
 * [Example - Factorial]
 *          0 != 1
 *          n != n *(n-1);
 * Base case:
 *  factorial(0) = 1
 * Recursive case:
 *  factorial(n)= n * factorial(n-1)
 * 
 * unsigned long long factorial (unsigned long long n){
 *      if (n == 0)
 *          return 1;
 *      return n* factorial(n-1);
 * }
 * 
 * int main(){
 *      cout << factorial(8) << endl;
 *      return 0;
 * }
 * 
 * [Example - Fibonacci]
 *          Fib(0) = 0 
 *          Fib(1) = 1
 *          Fib(n) = Fib(n-1) + Fib(n-2)
 * 
 * Base case:
 *  Fib(0) = 0
 *  Fib(1) = 1
 * Recursive case:
 *  Fib(n) = Fib(n-1) + Fib(n-2)
 * 
 * unsigned long long fibonacci(unsigned long long n){
 *      if(n <= 1)
 *          return;
 *      return fibonacci(n-1) + fibonacci(n-2);
 * }
 * 
 * int main(){
 *      cout << fibonacci(30) << endl; 
 *      return 0;
 * }
 * 
 * [Important notes]
 * If recursion doesn't eventually stop you will have infinite recursion
 * Recursion can be resource intensive
 * Remember the base case(s)
 *  It terminates the recursion
 * 
 * Only use recursive solutions when it makes sense
 * 
 * Anything that can be done recursively can be done iteratively
 * ***/

#include <iostream>

using namespace std;
unsigned long long fibonacci(unsigned long long n);

unsigned long
 long fibonacci(unsigned long long n){
    if(n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    cout << fibonacci(5) << endl;
    cout << fibonacci(30) << endl;
    cout << fibonacci(40) << endl;
}