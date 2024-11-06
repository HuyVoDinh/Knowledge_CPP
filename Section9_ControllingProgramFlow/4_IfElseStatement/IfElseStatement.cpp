#include<iostream>
using namespace std;

/****
 * [If else statement]
 *  if (expr)
 *      statement1;
 *  else
 *      statement2;
 * 
 * If the expression is true then execute statement1
 * If the expression is false then execute statement2
 * 
 *  Ex:
 *      if (num > 10)
 *          ++num;
 *      else
 *          num = 10;
 * ****/




int main()
{
    int num = 0;
    const int target = 10;
    
    cout << "Enter a number and I'll compare it to " << target << ": ";
    cin >> num;

    if(num >= target)
    {
        cout << num << " is greater than or equal to " << target << endl;
        int diff = num - target;
        cout << num << " is " <<  diff << " greater than " << target << endl;
    }
    else
    {
        cout << num << " is less than or equal to " << target << endl;
        int diff = target - num;
        cout << num << " is " <<  diff << " less than " << target << endl;
    }
    return 0;
}