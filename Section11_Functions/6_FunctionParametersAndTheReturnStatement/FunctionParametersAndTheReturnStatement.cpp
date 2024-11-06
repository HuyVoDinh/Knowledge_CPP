/***
 * [Function Parameters]
 * 
 * When we call a function we can pass in data to that function
 * In the function call they are called arguments
 * In the function definition they are called parameters
 * They must match in number, order, and in type
 * 
 * [Example]
 * int add_numbers(int, int);               // prototype
 * 
 * int main() {
 *      int result  = 0;
 *      result = add_number(100,200);       // call
 *      return 0;
 * }
 * 
 * int add_numbers(int a, int b){           // definition
 *      return a + b;
 * }
 * 
 * ---
 * void say_hello(std::string name){
 *      cout << "Hello " << name << endl;
 * }
 * 
 * say_hello("Frank");                      // pass c-style string to string
 * 
 * std::string my_dog {"Buster"};
 * say_hello(my_dog);
 * 
 * [Pass-by-value]
 * 
 * When you pass data into a function it is passed-by-value
 * A copy of the data is passed to the function
 * Whatever changes you make to the parameter in the function does NOT affect the argument that was passed in
 * 
 * Formal vs. Actual parameters
 *      Formal parameters - the parameters defined in the function header 
 *      Actual parameters - the parameter used in the function call, the arguments
 * 
 * [Example]
 * 
 * void param_test(int formal)  {           // formal is a copy of actual
 *      cout << formal << endl;             // 50
 *      formal = 100;                       // only changes the local copy
 *      cout << formal << endl;             // 100
 * }  
 * 
 * int main()
 * {
 *      int actual {50};
 *      cout << actual << endl;             // 50;
 *      param_test(actual);                 // pass in 50 to param_test
 *      cout << actual << endl;             // 50 - did not change
 *      return 0;
 * }
 * 
 * [Function Return Statement]
 * 
 * If a function returns a value then it must use a return statement that returns a value
 * if a function does not return a value (void) then the return statement is optional
 * return statement can occur anywhere in the body of the function
 * return statement immediately exits the function
 * Can have multiple return statements in a function
 *      Avoid many return statements in a function
 * 
 * The return value is the result of the function call
 * 
 * ***/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_value1(int num);
void pass_by_value2(string s);
void pass_by_value3(vector<string> v);
void print_vector(vector<string> v);

void pass_by_value1(int num){
    num = 100;
}
void pass_by_value2(string s){
    s = "Changed";
}
void pass_by_value3(vector<string> v){
    v.clear();                              //delete all vector elements
}
void print_vector(vector<string> v){
    for(auto s : v)
        cout << s << " ";
    cout << endl;
}

int main()
{
    int num = 10;
    int another_num = 20;

    cout << "Num before calling pass_by_value1: " << num << endl;
    pass_by_value1(num);
    cout << "Num after calling pass_by_value1: " << num << endl;

    cout << "another_num before calling pass_by_value1: " << another_num << endl;
    pass_by_value1(another_num);
    cout << "another_num after calling pass_by_value1: " << another_num << endl;

    string name = "Frank";
    cout << "name before calling pass_by_value1: " << name << endl;
    pass_by_value2(name);
    cout << "name after calling pass_by_value1: " << name << endl;

    vector<string> stoogers {"Larry" , "Moe", "Curly"};
    cout << "\ntooges before calling pass_by_value3: ";
    print_vector(stoogers);
    pass_by_value3(stoogers);
    cout << "\ntooges after calling pass_by_value3: ";
    print_vector(stoogers); 
}
