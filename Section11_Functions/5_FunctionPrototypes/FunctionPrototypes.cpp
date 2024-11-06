/***
 * [Function Prototypes]
 * 
 * The compiler must 'know' about a function before it is used
 *  Defined functions before calling them
 *      OK for small programs
 *      Not a practical solution for larger programs 
 *  
 *  Use function prototypes
 *      Tells the compiler what it needs to know without a full function definition
 *      Also called forward declarations
 *      Also used in our own header files (.h) - more about this later => We split our programs up into multiple files
 * 
 * [Example]
 * 
 * int function_name(); // prototype
 * 
 * int function_name()
 * {
 *      statements;
 *      return 0;
 * }
 * 
 * int function_name(int);  // prototype
 *                          // or
 * int function_name(int a);// prototype
 * 
 * [Calling a function]
 * 
 * void say_hello();
 * 
 * void say_hello() {
 *      cout << "Hello\n";
 * }
 * 
 * 
 * void say_hello();
 * 
 * int main() {
 *      say_hello();            // OK
 *      say_hello(100);         //Error
 *      cout << say_hello();    //Error
 *                              // No return value
 *      return 0;
 * }
 * 
 * ***/

#include <iostream>

using namespace std;

const double pi = 3.14159;

//Function prototypes
double calc_area_circle(double);
double calc_volume_cylinder(double radius, double height);
void area_circle();
void volume_cylinder();

int main()
{
    area_circle();
    volume_cylinder();
    return 0;
}

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

void volume_cylinder(){
    double radius{};
    double height;
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;

    cout << "\nEnter the radius of the height: ";
    cin >> height;

    cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius,height) << endl;
}