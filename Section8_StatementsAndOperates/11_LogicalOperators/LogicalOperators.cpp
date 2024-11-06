#include <iostream>
using namespace std;


int main()
{
    /***
     * |    Operator    |       Meaning         |
     * |========================================|
     * |        not     |       negation        |
     * |        !       |                       |
     * |----------------------------------------|
     * |        and     |       logical and     |
     * |        &&      |                       |
     * |----------------------------------------|
     * |        or      |       logical or      |
     * |        ||      |                       |
     * |========================================|
     * 
     * [not (!)]
     * 
     * |    expression  |        not a          |
     * |        a       |         ! a           |
     * |========================================|
     * |       true     |        false          |
     * |       false    |        true           |
     * 
     * * [and (&&)]
     * 
     * |    expression  |     expression        |       a and b     |
     * |        a       |         b             |       a && b      |
     * |============================================================|
     * |       true     |        true           |       true        |
     * |       false    |        true           |       false       |
     * |       true     |        false          |       false       |
     * |       false    |        false          |       false       |
     * 
     * * [or (||)]
     * 
     * |    expression  |     expression        |       a or b      |
     * |        a       |         b             |       a || b      |
     * |============================================================|
     * |       true     |        true           |       true        |
     * |       false    |        true           |       true        |
     * |       true     |        false          |       true        |
     * |       false    |        false          |       false       |
     * 
     * 
     * [Precedence]
     * "not" has higher precedence than "and"
     * "and" has higher precedence than "or"
     * 
     * "not" is a unary operator
     * "and" and "or" are binary operators
     * 
     * [Example]
     * 
     * num1 >= 10 && num1 < 20
     * num1 <= 10 || num1>= 20
     * 
     * !is_raining && temperature > 32.0
     * is_raining || is_snowing
     * temperature > 100 && is_humid || is_raining
     * 
     * [Short-Circuit Evaluation]
     * When evaluating a logical expression C++ stops as soon as the result is known
     * expr1 && expr2 && expr3      => If expr1 is false then there is no way that the entire expression can be true since all the expressions must be true. So why bother evaluating expr2 and expr3 when the compiler already knows that the result will be false
     * expr1 || expr2 || expr3      => If expr1 is true then complier already knows that the entire expression is true and it won't evaluate expression two or expression three. 
     *                              => However if expression 1 is false then the compiler continues evaluating expr2 since it doesn't know the result yet.
     * We use logical operators in depth when we learn about control structures
     * **/

    int num {};
    const int lower {10};
    const int upper {20};

    cout << boolalpha;

    //Determine if an entered integer is between two other integers
    //assume lower < upper;

    cout << "Enter an integer - the bounds are" << lower << " and " << upper << ":";
    cin >> num;

    bool within_bounds{false};

    within_bounds = (num > lower && num < upper);
    cout << num << " is between " << lower << " and " << upper << ": " << within_bounds << endl;

    //Determine if an entered integer is outside two other integers
    //assume lower < upper;
    cout << "Enter an integer - the bounds are " << lower << " and " << upper << ": ";
    cin >> num;

    bool outside_bounds{false};
    outside_bounds = (num < lower || num > upper);
    cout << num << " is outside " << lower << " and " << upper << ": " << outside_bounds << endl;

    //Determine if an entered integer is exactly on the boundary
    //assume lower < upper;
    cout << "Enter an integer - the bounds are " << lower << " and " << upper << ": ";
    cin >> num;

    bool outside_bounds{false};
    outside_bounds = (num == lower || num == upper);
    cout << num << " is exactly " << lower << " or " << upper << ": " << outside_bounds << endl;

    //Determine if you need to wear a coat based on temperature and wind speed
    bool wear_coat {false};
    double temperature {};
    int wind_speed {};

    const int wind_speed_for_coat {25};             //wind over this value requires a coat
    const double temperature_for_coat {45};         //temperature below this value requires a coat

    //Require a coat if either wind is too high OR temperature is too low
    cout << "Enter the current temperature in (F):" ;
    cin >> temperature;
    cout << "Enter windspeed in (mph): ";
    cin >> wind_speed;

    wear_coat = (temperature < temperature_for_coat || wind_speed > wind_speed_for_coat);
    cout << "Do you need to wear a coat using OR? " << wear_coat << endl;

    return 0;
}
