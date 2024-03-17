#include <iostream>
#include <iomanip>
using namespace std;

/***
 *  How can nest if statements within other if statements
 *  
 *      if (expr1)
 *          if(expr2)
 *              statement1;
 *          else
 *              statement2;
 * 
 * if statements is nested within another
 * Allows testing of multiple conditions
 * else belongs to the closest if
 * 
 * [Example]
 *      if (score > 90)
 *          if(score > 95)
 *              cout << "A+";
 *          else
 *              cout << "A";
 *      else
 *          cout << "Sorry, No A"; 
 * ***/

int main()
{
    // int score = 0;
    // cout << "Enter your score on the exam (0 -100): ";
    // cin >> score;

    // char letter_grade{};
    // if(score >= 0 && score <= 100)
    // {
    //     if(score > 90)
    //         letter_grade = 'A';
    //     else if (score > 80)
    //         letter_grade = 'B';
    //     else if (score > 70)
    //         letter_grade = 'C';
    //     else if (score > 60)
    //         letter_grade = 'D';
    //     else
    //         letter_grade = 'F';

    //     cout << "Your grade is: " << letter_grade << endl;
    //     if(letter_grade = 'F')
    //         cout << "Sorry!, your must repeat the class\n";
    //     else
    //         cout << "Congrats\n";
    // }
    // else
    // {
    //     cout << "Sorry " << score << " is not in range\n";
    // }

    /****
     * [Ex2]
     * [Shipping cost calculator]
     * 
     * Ask the user for package dimension in inches, length, width, height - these should be integers
     * 
     * All dimension must be 10 inches or less or we cannot ship it
     * 
     * Base cost $2.50
     * If package volume is greater than 100 cubic inches there is a 10% surcharge
     * If package volume is greater than 500 cubic inches there is a 25% surcharge
     * **/

    int length, width, height;
    double base_cost = 2.50;

    const int tier1_threshold = 100;
    const int tier2_threshold = 500;

    int max_dimension_length = 10;

    double tier1_surcharge = 0.1;
    double tier2_surcharge = 0.25;

    //All dimension must be 10 inches or less
    int package_volume;

    cout << "Welcome to the package cost calculator\n";
    cout << "Enter length, width, and height of the package separated by spaces: ";
    cin >> length >> width >> height;

    if(length > max_dimension_length || width > max_dimension_length || height > max_dimension_length)
        cout << "Sorry, package rejected - dimension exceeded" << endl;
    else
    {
        double package_cost = 0;
        package_volume = length * width * height;
        package_cost = base_cost;

        if(package_volume > tier2_threshold)
        {
            package_cost += package_cost * tier2_surcharge;
            cout << "Adding tier 2 surcharge" << endl;
        }
        else if(package_volume > tier1_surcharge)
        {
            package_cost += package_cost * tier1_surcharge;
            cout << "Adding tier 2 surcharge" << endl;
        }

        cout << fixed << setprecision(2);
        cout << "The volume of your package is: " << package_volume << endl;
        cout << "Your package will cost $" << package_cost << " to ship\n";
    }
    return 0;
}