/***
 * In this exercise you will write a switch  statement that displays the name of the day of the week given the day code.

You may use the integer variable named day_code   whose value we will change to automatically to test your code.
You do NOT need to declare this variable.

Given the following day codes, your program should display the day of the week using a cout  statement. No '\n ' or endl  should be used.

Day Code        Display
--------        ------------------------
   0            Sunday
   1            Monday
   2            Tuesday
   3            Wednesday
   4            Thursday
   5            Friday
   6            Saturday
 other          Error - illegal day code
 * 
 * ***/

#include <iostream>
using namespace std;

void display_day(int day_code) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    switch (day_code)
    {
    case 0:
        cout << "Sunday";
        break;
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    
    default:
        cout << "Error - illegal day code";
        break;
    }
    
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

int main()
{
    return 0;
}