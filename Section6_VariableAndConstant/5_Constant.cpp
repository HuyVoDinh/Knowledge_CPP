#include <iostream>
using namespace std;

int main()
{
    /***
     * Constant cannot change value
     * **/

    /***
     * [Literal constants]
     * 
     * Declared constants
     *      const keyword
     * Constant expression
     *      constexpr keyword
     * Enumerated constants
     *      enum keyword
     * Defined constants
     *      #define
     * 
     * Example: 
     *      const double pi {3.1415};
     *      const int months_in_year {12};
     *      pi = 2.5; // Compiler error
     * 
     * Constants declared using the const keyword
     *      #define pi 3.1415
     * **/


    /***
     * Frank's Carpet Cleaning Service
     * Charges $30 per room
     * Sales tax rate is 6%
     * Estimates are valid for 30 days
     * 
     * Prompt the user for the number of rooms they would like cleaned and provide an estimate such as:
     * 
     * Estimate for carpet cleaning service:
     * Number of rooms: 2
     * Price per room: $30
     * Cost: $60
     * Tax: $3.6
     * ====================
     * Total estimate: $63.6
     * This estimate is valid for 30 days
     * 
     * Pseudocode: is like an English-like or your own natural spoken language like representation of the algorithm or the steps necessary to solve problem
     * 
     *  Prompt the user to enter the number of rooms
     *  Display number of rooms
     *  Display price per room
     * 
     *  Display cost: (number of rooms * price per room)
     *  Display tax: number of rooms * price per room * tax rate
     *  Display total estimate: (number of rooms * price per room) * (number of rooms * price per room * tax rate)
     *  Display estimate expiration time
     * 
     * **/

    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "\nHow many rooms would you like cleaned?";

    int number_of_rooms {0};
    cin >> number_of_rooms;

    const double price_per_room {30.0};
    const double sales_tax {0.06};
    const int estimate_expriy {30};

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;
    cout << "Price per room: $" << price_per_room << endl;
    cout << "Cost: $" << price_per_room *number_of_rooms << endl;
    cout << "Tax: $" << price_per_room * number_of_rooms * sales_tax << endl;
    cout << "===================================\n";
    cout << "Total estimate: $" << (price_per_room * number_of_rooms) + (price_per_room * number_of_rooms * sales_tax) << endl;
    cout << "This estimate is valid for " << estimate_expriy << " days\n";

    cout << endl;
    return 0;
}