/***
 * [Overloading Functions]
 * We can have functions that have different parameter lists that have the same name 
 * => Example may have many ways to display information to the screen depending on what i want to display. So rather than having many functions with different names such as display char, int. We can have a single name display, and then implement a version of the function for each type of parameter. Then we just let the compiler figure out which function to use based on the function call arguments and the defined function parameters
 * 
 * Abstraction mechanism since we can just think 'print' for example
 * 
 * A type of polymorphism
 *  We can have the same name work with different data types to execute similar behavior
 *  The compiler must be able to tell the functions apart based on the parameter lists and argument supplied
 * 
 * [Example]
 * int add_numbers(int, int);
 * double add_number(double, double);
 * 
 * int main(){
 *      cout << add_numbers(10, 20) << endl;
 *      cout << add_number(10.0, 20.0) << endl;
 * return 0;
 * }
 * 
 * [Example]
 * void display(int n);
 * void display(double d);
 * void display(std::string s);
 * void display(std::string s, std::string t);
 * void display(std::vector<int> v);
 * void display(std::vector<std::string> v);
 * 
 * [Overloading Functions]
 * Return type is not considered
 * int get_value();
 * double get_value();
 * 
 * // Error
 * 
 * cout << get_value() << endl; Compile don't know which function called => Error
 * 
 * **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

void print(int num){
    cout << "Printing int: " << num << endl;
}
void print(double num){
    cout << "Printing double: " << num << endl;
}
void print(string s){
    cout << "Printing string: " << s << endl;
}
void print(string s , string t){
    cout << "Printing 2 string: " << s << " and " << t << endl;
}
void print(vector<string> v){
    cout << "Printing vector of strings: ";
    for(auto s : v)
        cout << s + " ";
    cout << endl;
}

int main()
{
    print(100);
    print('A');
    print(123.5);
    print(123.3f);
    print("C-style string");        // C-style string is  converted to a C++ string
    string s = "C++ string";
    print(s);

    vector<string> three_stooges {"Larry", "Moe", "Curly"};
    print(three_stooges);

    return 0;
}