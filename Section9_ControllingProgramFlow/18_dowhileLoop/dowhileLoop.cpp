#include <iostream>
using namespace std;

/***
 * do{
 *  statements;
 * } while (expression);
 * 
 * [Example]
 * 
 * int number {};
 * do{
 *  cout << "Enter an integer between 1 and 5: ";
 *  cin >> number;
 * } while(number <= 1 || number >= 5);
 * 
 * **/


int main()
{
    char selection {};
    do {
        cout << "1. Do this.\n";
        cout << "2. Do that.\n";
        cout << "3. Do something else\n";
        cout << "Q. Quit\n";
        if(selection == 1)
            cout << "You chose 1 - doing this\n";
        else if(selection == 2)
            cout << "You chose 2 - doing that\n";
        else if(selection == 3)
            cout << "You chose 3 - doing something elst\n";
        else if(selection == 'Q' || selection == 'q')
            cout << "Goodbye\n";
        else
            cout << "Unknow option - try again.\n";
    } while (selection != 'q' || selection != 'Q');

    return 0;
}