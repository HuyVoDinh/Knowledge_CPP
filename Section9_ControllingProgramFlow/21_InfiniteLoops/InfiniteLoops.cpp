#include <iostream>
using namespace std;

/***
 * [Infinite loop]
 * Loops whose condition expression always evaluate to true
 *  Usually this is unintended and a programmer error
 *  Sometimes programmers use infinite loops and include and break statements in the body to control them
 *  Sometimes infinite loops are exactly what we need
 *      + Event loop in an event-driven program
 *      + Operating system
 * 
 * [Example]
 * 
 * for(;;)
 *      cout << "This will print forever\n";
 * 
 * => If omit all three, get just two semicolons. That's an infinite loop. The output statement will be displayed as long as the program is running
 * 
 *  while (true) 
 *      cout << "This will print forever\n";
 * 
 * => It always true, and the output statement will execute over and over again
 * 
 *  do{
 *      cout << "This will print forever\n"; 
 *  } while (true)
 * **/

int main()
{
    return 0;
}