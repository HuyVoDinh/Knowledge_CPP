/****
 * [Scope Rules]
 * 
 * C++ users scope rules to determine where an identifier can be used
 * C++ uses static or lexical scoping
 * Local or block scope
 * Global scope
 * 
 * [Local or block scope]
 * Identifiers declared in a block {}
 * Function parameters have block scope
 * Only visible within the block {} where declared
 * Function local variables are only active while the function executing
 * Local variables are NOT preserved between function calls
 * With nested blocks inner blocks can 'see' but outer blocks cannot 'see' in
 * 
 * [Static local variables]
 * Declared with static qualifier => variable whose lifetime is the lifetime of the program but it's only visible to the statements in the function body. These
 *      static int value = 10;
 * Value IS preserved between function calls
 * Only initialized the first time the function is called
 * 
 * [Global scope]
 * Identifier declared outside any function or class
 * Visible to all parts of the program after the global identifier has been declared
 * Global constants are OK
 * Best practice - don't use global variables
 * ***/

#include <iostream>

using namespace std;

void local_example();
void global_example();
void static_local_example();

int num = 300;  //global variable - declared outside any class or function

void global_example(){
    cout << "\nGlobal num is: " << num  <<  "in global_example - start" << endl;
    num *= 2;
    cout << "Global num is: " << num << " in global_example - end\n";
}

void local_example(int x){
    int num = 1000;
    cout << "\nLocal num is: " << num  <<  "in local_example - start" << endl;
    num = x;
    cout << "Local num is: " << num << " in local_example - end\n";
    //num1 in main is not within scope - so it can't be used here
}

void static_local_example(){
    static int num = 5000;          //local to static_local_example static - retains it value between calls
    cout << "\nLocal static num is: " << num << " in static_local_example - start" << endl;
    num += 1000;
    cout << "Local static num is: " << num << " in static_local_example - end\n";

}

int main(){
    int num = 100;                  //Local to main
    int num1 = 500;                 //Local to main

    cout << "Local num is: " << num << " in main" << endl;

    {//creates a new level of scope
        int num = 200;
        cout << "Local num is: " << num <<" in inner block in main\n";
        cout << "Inner block in main can see out - num1 is: " << num1 << endl;// The rule that look inside block first , if don't see, it look out to its outer scope
    }

    cout << "Local num is: " << num << " in main" << endl; 

    local_example(10);
    local_example(20);

    global_example();
    global_example();
}