#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /***
     * [for Loop]
     *  for(initialization; condition; increment)
     *  {
     *      statement(s);
     *  }
     * 
     *  Firstly, initialization expression is executed exactly once before any iteration occurs
     *  Then the condition is checked, If it's true, the body of the loop is executed
     *  Then the iteration expression is executed, check the condition again and repeat
     *  When the conditions evaluates defaults, the loop is the terminated and continue processing the statements to follow the loop
     * 
     * [Example]
     *  int i = 0;
     *  for(int i = 0; i < 5; i ++) =>>++i and i++ is mean the same thing here since the increment happens on its own and it's not in another expression
     *      cout << i << endl;
     *  i = 100; => //ERROR i only visible in the loop
     * 
     * 
     * some other details
     *  The basic for loop is very clear and concise
     *  Since the for loop's expressions are all optional, it is possible to have
     *      no initialization
     *      no test
     *      no increment
     * 
     *      for(;;)
     *      {
     *          cout << "Endless loop" << endl;
     *      }
     * ***/


    for(int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }

    for(int i = 0; i < 10; i+=2)
    {
        cout << i << endl;
    }

    vector<int> nums = {10,20,30,40,50};
    for(int i = 0; i < nums.size();i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}