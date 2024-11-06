/****
 * [Defining Functions]
 * name
 *  the name of the function
 *  same rules as for variables
 *  should be meaningful
 *  usually a verb or verb phrase
 * 
 * parameter list
 *  the variables passed into the function
 *  their types must be specified
 * 
 * return type
 *  the type of data that is returned from the function
 * 
 * body
 *  the statements that are executed when the function is called 
 *  in curly braces {}
 * 
 *  [Return type] [name] (Parameters)
 *  {   
 *      [Body]
 *  }
 *  int function_name ()
 *  {
 *      statements;
 *      return 0;
 *  }
 * 
 * [Example with 1 parameter]
 * int function_name (int a)
 *  {
 *      statements;
 *      return 0;
 *  }
 * 
 *  Example with multiple parameters
 *  void function_name (int a, std::string b)
 *  {
 *      statements;
 *      return;
 *  }
 * 
 *  A function with no return type and no parameters
 *  void say_hello()
 * {
 *      cout << "Hello" << endl; //=>in this case, there is no return statement required since the function doesn't return anything
 * 
 * }
 * 
 *  int main()
 * {
 *      say_hello(); //Can call function from main or from any other function
 *      return 0;
 * }
 * 
 * We can define as many function as we need in our applications to help modularize program
 * 
 * void say_world()
 * {
 *      cout << " World" << endl;
 *      cout << " Bye from say_world" << endl;
 * }
 * 
 * void say_hello()
 * {
 *      cout << "Hello\n";
 *      say_world();
 *      cout << " Bye from say_hello\n";
 * }
 * 
 * int main()
 * {
 *      say_hello();
 *      cout << " Bye from main\n";
 *      return 0;
 * }
 * 
 * Hello
 * World
 * Bye from say_world
 * Bye from say_hello
 * Bye from main
 * 
 * [Calling functions]
 * 
 * Functions can call other functions
 * Complier must know the function details BEFORE it is called
 * int main()
 * {
 *      say_hello(); // called BEFORE it is defined ERROR
 *      return 0;
 * }
 * 
 * void say_hello ()
 * {
 *      cout << "Hello\n";
 * }
 * ***/

#include <iostream>

using namespace std;

const double pi = 3.14159;

double calc_area_circle(double radius)
{
    return pi *radius* radius;
}

double calc_volume_cylinder(double radius, double height)
{
    return calc_area_circle(radius) * height;
}

void area_circle() {
    double radius{};
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;

    cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

void volumne_cylinder(){
    double radius{};
    double height;
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;

    cout << "\nEnter the radius of the height: ";
    cin >> height;

    cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius,height) << endl;
}

int main()
{
    area_circle();
    volumne_cylinder();
    return 0;
}
