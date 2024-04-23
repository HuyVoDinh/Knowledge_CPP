/***
 * [Passing Arrays To Functions]
 * We can pass an array to a function by providing square brackets in the formal parameter description
 *      void print_array (int numbers []);
 * 
 * The array elements are NOT copied
 * Since the array name evaluates to the location of the array in memory - this address is what is copied
 * So the function has no idea how many elements are in the array since all it knows is the location of the first element (the name of the array)
 * 
 * [Example]
 * 
 * void print_array(int numbers []);
 * int main(){
 *  int my_numbers[] {1, 2, 3, 4, 5};
 *  print_array(my_numbers);
 *  return 0;
 * }
 * 
 * void print_array(int numbers[])
 * {
 *      // Doesn't know how many elements are in the array?
 *      // We need to pass in the size!!!
 * }
 * 
 * [Example]
 * void print_array(int numbers [], size_t size);
 * 
 *  * int main(){
 *  int my_numbers[] {1, 2, 3, 4, 5};
 *  print_array(my_numbers);
 *  return 0;
 * }
 * 
 * void print_array(int numbers[], size_t size){
 *      for (size_t i = 0; i < size; i++){
 *          cout << number[i] << endl;
 *      }
 * }
 * 
 *  [Example]
 * 
 * Since we are passing the location of the array
 *      The function can modify the actual array!
 * 
 * void zero_array (int numbers [], size_t size){
 *      for (size_t i = 0; i < size; i++){
 *          numbers[i] = 0;
 *      }
 * }
 * 
 * int main(){
 *      int my_numbers[] {1,2,3,4,5};
 *      zero_array(my_numbers, 5);          // my_number is now zeroes
 *      print_array(my_numbers, 5);         // 0 0 0 0 0 
 *  return -;
 * }
 * 
 * [const parameters]
 * We can tell the compiler that function parameters are const (read-only)
 * This could be useful in the print_array function since it should NOT modify the array
 * 
 * void print_array(const int numbers[], size_t size){
 *      for(size_t i = 0; i < size; i++){
 *          cout << number[i] << endl;
 *      }
 *      numbers[i] = 0;             // any attempt to modify the array
 *                                  // will result in a compiler error
 * }
 * **/

#include <iostream>

using namespace std;

void print_array(int arr[], size_t size);
void set_array(int arr[], size_t size, int value);

void print_array(int arr[], size_t size){
    for(size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;   
}

//set each array element to value
void set_array(int arr[], size_t size, int value){
    for(size_t i = 0; i < size; i++)
        arr[i] = value;
}

int main(){
    int my_scores [] {100,98,75,85,35,86};

    print_array(my_scores, 5);
    set_array(my_scores, 5 , 100);
    print_array(my_scores, 5);

    return 0;
}