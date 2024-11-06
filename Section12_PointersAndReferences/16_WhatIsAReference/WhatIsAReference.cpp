/***
 * [What is a reference?]
 * 
 * An alias for a variable
 * 
 * Must be initialized to a variable when declared
 * 
 * Cannot be null
 * 
 * Once initialized cannot be made to refer to a different variable
 * 
 * Very useful as function parameters
 * 
 * Might be helpful to think of a reference as a constant pointer that is automatically dereferenced
 * 
 * Using references in range-based for loop
 * 

 * ***/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int num = 100;
    int &ref = num;

    cout << num << endl;
    cout << ref << endl;

    num = 200;
    cout << num << endl;
    cout << ref << endl;

    ref = 300;
    cout << num << endl;
    cout << ref << endl;

    vector<string> stooges {"Larry", "Moe", "Curly"};
    
    for(auto str: stooges)
         str = "Funny";              // changes the copy - str is a COPY of the each vector element
    
    for(auto str:stooges)
         cout << str << endl;        // Larry, Moe, Curly   - No change
    
    for(auto &str: stooges)
         str = "Funny";              // changes the copy    - str is a reference to each vector element
    
    for(auto const &str:stooges)     // notice we are using const
         cout << str << endl;        // now the vector elements have changed
    return 0;
}