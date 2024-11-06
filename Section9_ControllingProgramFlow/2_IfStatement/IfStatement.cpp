#include <iostream>
using namespace std;

/***
 * [if statement]
 *      if (expr)
 *          statement;
 * 
 * If the expression is true then execute the statement
 * 
 * If the expression is false then skip the statement
 *  
 *      if (num > 10)
 *          ++num;
 * If you want to execute more than one statement if the condition is true that's where block statements come in
 * A block statement is a sequence of statements inside a block which is made up of opening and closing curly brackets
 *      if(num > 10) {
 *          ++num;
 *          cout << "This too";
 *      }
 * 
 * [Block statement]
 * {
 *      //variable declarations        
 *      statement1;
 *      statement2;
 *      .......
 * }
 * 
 * Create a block of code by including more than one statement in code block {}
 * Blocks can also contain variable declarations
 * These variables are visible only within the block - local scope => Variables declared in a block are only visible to statements that are also in the same block
 * ***/

int main()
{
    int num = 0;
    const int min = 10;
    const int max = 100;

    cout << "Enter a number between " << min << " and " << max << ": " <<  endl;
    cin >> num;

    if(num >= min)
    {
        cout << num << " is greater than or equal to " << min << endl;

        int diff = num - min;
        cout << num << " is less than or equal to " << max << endl;
    }

    if (num <= max)
    {
        cout << num << " is less than or equal to " << max << endl;

        //diff = max - num; => diff was not declared in the scope. Because diff was declared in other block
        int diff = max - num;
        cout << num << " is less than or equal to " << max << endl;
    }

    if(num >= min && num <= max)
    {
        cout << num << " is in range " << endl;
        cout << "This means statement 1 and 2 must also display!" << endl;
    }

    if(num == min || num == max)
    {
        cout << num << " is right on a boundary" << endl;
        cout << "This means all 4 statements display" << endl;
    }
    return 0;
}