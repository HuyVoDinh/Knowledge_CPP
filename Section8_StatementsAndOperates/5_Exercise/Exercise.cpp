//Using the Assignment Operator
#include <iostream>
using namespace std;

int main()
{
    // Declare num1 as an integer and initialize it to 13.
    int num1 = 13;
    
    // Declare num2 as an integer and initialize it to 0.
    int num2 = 0;
    
    // Assign the value 5 to num1
    num1 = 5;
    
    // Assign the value of num1 to num2
    num2 = num1;

    cout << num1 << " " << num2;
}