#include <iostream>
using namespace std;

int main()
{
    /***
     * What is variable
     * A variable is an abstraction for a memory location
     * Variables have data type and value
     * Variable must be declared before they are used
     * A variables value may change
     * **/
    
    /***
     * [Declaring variable]
     * 
     * VariableType VariableName;
     * ***/
    int age;
    double rate;
    string name;

    /***
     * [Rule for naming c++ variable]
     * 
     * Can contain letter, numbers, and underscores
     * Must begin with a letter or underscore and cannot begin with a number
     * Cannot use C++ reversed keywords
     * Cannot redeclare a name in the same scope
     * C++ is case sensitive
     *      Example: The name, age in uppercase is considered different from the name, age and lowercase
     * 
     * Legal     | Illegal
     * Age       | int
     * age       | $age
     * _age      | 2014_age
     * My_age    | My age
     * your_age  | Age+1
     * INT       | cout
     * Int       | return
     * 
     * [Naming Variables - Style]
     * 
     * Be consistent with your naming conventions
     *      MyVariableName vs. my_variable_name
     *      avoid beginning names with underscores
     * Use meaningful names
     *      not too long and not too short
     * Never use variables before initializing them
     * Declare variables close to when you need them in your code
     * 
     * int age;     uninitialized
     * int age = 21;    C-like initialization
     * int age (21);    Constructor initialization
     * int age {21};    C++11 list initialization syntax
     * ***/

    int room_width {0};
    int room_length {0};

    cout << "Enter the width of the room: ";
    cin >> room_width;

    cout << "Enter the length of the room: ";
    cin >> room_length;

    cout << "The area of the room is: " << room_width * room_length << " square feet.\n";


    /***
     * [Exercise]
     * Declaring and Initializing Variables
In this exercise you will write code that creates a profile for a new employee at a company. 

You must declare a total of THREE variables, each of a different type, to represent the employee's name, age, and hourly_wage. 

age  should be an int 
hourly_wage  should be a double , and
name  should be a string 

You must initialize the hourly_wage to 23.50. In order to set the values for name and age you must use cin and the extraction operator >> to allow the employee to enter their name and age in that order separated by a single space. 

You do not have to provide any output statements. Our testing code will automatically supply the name  and age values to test your code.
     * 

     void employee_profile() {
    
    //----WRITE YOUR CODE BELOW THIS LINE----
    int age;
    double hourly_wage {23.50};
    string name;
    
    cin >> name >> age; 
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << name << " " << age << " " << hourly_wage;
}
     * ***/


}