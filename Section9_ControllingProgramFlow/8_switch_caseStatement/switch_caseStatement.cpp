#include <iostream>
using namespace std;

/***
 * [The switch statement]
 *  switch (integer_control_expr)                   
 *      case expression_1: statement_1; break;
 *      case expression_2: statement_2; break;
 *      .....
 *      case expression_n: statement_n; break;
 *      default: statement_default; 
 *  
 *  The control expression must evaluate to an integer type
 *  The case expressions must be constant expressions that evaluate to integer or integers literals
 *  Once a match occurs all following case sections are executes UNTIL a break is reached the switch complete
 *  Best practice - provide break statement for each case
 *  Best practice - default is optional, but should be handled
 * [Example]
 *  switch (selection) 
 *  {
 *      case '1': cout << "1 selected"; break;
 *      case '2': cout << "2 selected"; break;
 *      case '3':
 *      case '4': cout << "3 or 4 selected"; break;
 *      default: cout << "1, 2, 3, 4 NOT selected";
 *  }
 * 
 * ***/


int main()
{
    /***
     * Ask the user what grade they expect on an exam and tell them what they need to score to get it
     * ***/

    // char letter_grade;

    // cout << "Enter the letter grade you expect on the exam: ";
    // cin >> letter_grade;

    // switch (letter_grade)
    // {
    // case 'a':
    // case 'A':
    //     cout << "You need a 90 or above, study hard!" << endl;
    //     break;
    // case 'b':
    // case 'B':
    //     cout << "You need a 80-89 for a B, go study!" << endl;
    //     break;
    // case 'c':
    // case 'C':
    //     cout << "You need a 70-79 for an average grade" << endl;
    //     break;
    // case 'd':
    // case 'D':
    //     cout << "Hmm, you should strive for a better grade. All you need is 60-69" << endl;
    //     break;
    // case 'f':
    // case 'F':
    //     {
    //         char confirm;
    //         cout << "Are you sure (Y/N)?";
    //         cin >> confirm;
    //         if(confirm == 'y' || confirm == 'Y')
    //             cout << "OK, I guess you didn't study..." << endl;
    //         else if (confirm == 'n' || confirm == 'N')
    //             cout << "Good - go study!" << endl;
    //         else
    //             cout << "Illegal choice" << endl;
    //         break;
    //     }
    // default:
    //     cout << "Sorry, not a valid grade" << endl;
    //     break;
    // }


    /***
     * Switch with enumeration
     * ***/

    enum Direction {left,right,up, down};

    Direction heading (left);

    switch (heading)
    {
    case left:
        cout << "Going left" << endl;
        break;
    case right:
        cout << "Going right" << endl;
        break;
    default:
        cout << "OK\n";
        break;
    }

    cout << endl;
    return 0;
}