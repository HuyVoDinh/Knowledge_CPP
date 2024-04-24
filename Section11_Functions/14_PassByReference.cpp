/***
 * [Pass by Reference]
 * Sometimes we want to be able to change the actual parameter from within the function body
 * 
 * In order to achieve this we need the location or address of the actual parameter
 * 
 * We saw how this is the effect with array, but what about other variable types?
 * 
 * We can use reference parameters to tell the compiler to pass in a reference to the actual parameter
 * 
 * The formal parameter will now be an alias for the actual parameter
 * 
 * [Example]
 * void scale_number(int &num);                 // prototype
 * 
 * int main() {
 *      int number = 1000;
 *      scale_number(number);                   // call
 *      cout << number << endl;                 // 100
 *      return 0;
 * }
 * 
 * void scale_number(int &num){                 // definition
 *  if(num > 100)
 *      num = 100;
 * }
 * 
 * [Example]
 * 
 * void swap(int &a, int &b);
 * 
 * int main(){
 *      int x{10}, y{20};
 *      cout << x << " " << y << endl;      // 10 20
 *      swap(x,y);
 *      cout << x << " " << y << endl;      // 20 10
 *      return 0;
 * }
 * 
 * void swap(int &a, int &b)
 * {
 *      int temp = a;
 *      a = b;
 *      b = temp;
 * }
 * 
 * [vector example - pass by value]
 * void print(std::vector<int> &v);
 * void print2( const std::vector<int> &v);
 * 
 * int main(){
 *      std::vector<int> data {1,2,3,4,5};
 *      print(data);
 *      return 0;
 * }
 * 
 * void print(std::vector<int> &v){
 *      for(auto num : v)
 *          cout << num << endl;
 * }
 * void print(const std::vector<int> &v){
 *      v.at(0) = 200;                          // error
 *      for(auto num : v)
 *          cout << num << endl;
 * }
 * ***/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vector(const vector<string> &v);         // const

void pass_by_ref1(int &num){
    num = 1000;
}
void pass_by_ref2(string &s){
    s = "Changed";
}
void pass_by_ref3(vector<string> &v){
    v.clear();
}
void print_vector(const vector<string> &v){
    for(auto s:v){
        cout << s << endl;
    }
    cout << endl;
}

int main()
{
    int num = 10;
    int another_num = 20;

    cout << "num before calling pass_by_ref1: " << num << endl;
    pass_by_ref1(num);
    cout << "num after calling pass_by_ref1: " << num << endl;

    cout << "another_num before calling pass_by_ref1: " << another_num << endl;
    pass_by_ref1(another_num);
    cout << "another_num after calling pass_by_ref1: " << another_num << endl;

    string name = "Frank";
    cout << "name before calling pass_by_ref1: " << name << endl;
    pass_by_ref2(name);
    cout << "name after calling pass_by_ref1: " << name << endl;

    vector<string> stoogers {"Larry" , "Moe", "Curly"};
    cout << "\ntooges before calling pass_by_value3: ";
    print_vector(stoogers);
    pass_by_ref3(stoogers);
    cout << "\ntooges after calling pass_by_value3: ";
    print_vector(stoogers); 
}