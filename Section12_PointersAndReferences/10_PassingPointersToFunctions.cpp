/***
 * [Passing Pointers To Functions]
 * Pass-by-reference with pointer parameters
 * 
 * We can use pointers and the dereference operator to achieve pass-by-reference
 * 
 * The function parameter is a pointer
 * 
 * The actual parameter can be a pointer or address of a variable
 * 
 * Pass-by-reference with pointers - defining the function
 * 
 * 
 * ***/

#include <iostream>

using namespace std;

 void double_data(int *int_ptr);
 
 void double_data(int *int_ptr){
      *int_ptr *= 2;
 }
 
 int main(){
      int value {10};
      int *int_ptr = nullptr;
 
      cout << "Value: " << value << endl;           // 10
      double_data(&value);
      cout << "Value: " << value << endl; 

      int_ptr = &value;
      double_data(int_ptr);
      cout << "Value: " << value << endl; 
 }
