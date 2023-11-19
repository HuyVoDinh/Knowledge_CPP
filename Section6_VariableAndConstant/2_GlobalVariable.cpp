#include <iostream>
using namespace std;

    /***
     * [Global variable]
     * 
     * Sometimes you see variables declared outside of any function. These variables are called global variables.
     * They can be accessed from any part of program -> They can potentially be changed from any part of the program
     * Unlike local variable, global variable are automatically initialized to zero
     * ***/

int age {18}; //Global variable
int main()
{
    int age {16}; // local variable

    /***
     * If have both global variable and local variable. And two variable named age
     * When compiler, it find local variable, it will not use local variable
     * ***/

    cout << age << endl;

    return 0;
}