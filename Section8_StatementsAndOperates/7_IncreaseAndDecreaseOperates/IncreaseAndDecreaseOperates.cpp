#include <iostream>
using namespace std;

int main()
{
    /**
     * Increment operator ++
     * Decrement operator --
     * 
     * Increments or decrements its operand by 1
     * Can be used with integers, floating point types and pointers
     * 
     * Prefix ++num => before its operand
     * Postfix num++
     * 
     * Don't overuse this operator
     * ALERT!! Never use it twice for the same variable in the same statement
     *  => Because the behavior is undefined. You really don't know what you're going to get
     * **/

    int counter {10};
    int result {0};

    //Example 1 simple increment
    cout << "Counter: " << counter << endl;

    counter = counter + 1;
    cout << "Counter: " << counter << endl;

    counter++;
    cout << "Counter: " << counter << endl;

    ++counter;
    cout << "Counter: " << counter << endl;

    /***
     * Example 2 - preincrement
     * **/

    counter = 10;
    result = 0;

    cout << "Counter: " << counter << endl;

    result = ++ counter; //Note the pre increment
    //Counter will be incremented before it's used
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;

    /***
     * Example 3 - post-increment
     * **/

    counter = 10;
    result = 0;

    cout << "Counter: " << counter << endl;

    result = counter++; //Note the post increment
    //Counter will be incremented after it's used
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;

    //Example 4
    counter = 10;
    result = 0;

    cout << "Counter: " << counter << endl;

    result = ++ counter + 10;

    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;

    //Example 5
    counter = 10;
    result = 0;

    cout << "Counter: " << counter << endl;

    result = counter++ + 10;

    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;

    return 0;
}