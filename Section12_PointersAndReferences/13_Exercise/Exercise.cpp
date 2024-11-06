/***
 * [Reverse an Array using Pointers (Challenging!)]
 * 
 * Exercise: Array Reversal using Pointers

Specification:

Write a C++ function reverse_array that takes an integer array and its size as input and reverses the order of the elements in the array. The function should modify the array in-place.

Function Signature:

void reverse_array(int* arr, int size);
Input:

arr: A pointer to the first element of the integer array.

size: The size of the array.

Output:

The function should modify the array in-place, reversing the order of the elements. You should NOT make a copy of the original array.

Example:

int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]);
 
reverse_array(arr, size);
 
// After the function call, the array should be reversed:
// arr[] = {5, 4, 3, 2, 1}
Constraints:

The array will always have at least one element.

You must perform the reversal in-place, without allocating extra memory.
 * ***/

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void reverse_array(int* arr, int size) {
    //-- Write your code below this line 
    for(int i = 0; i < size/2; i++){
        swap(arr[i], arr[size -1 -i]);
    }
    //-- Write your code above this line

    // int *start = arr;
    // int *end = arr + size - 1;
    // while (start < end) {
    //     // swap elements pointed to by start and end pointers
    //     int temp = *start;
    //     *start = *end;
    //     *end = temp;
        
    //     // Move the pointers towards the center
    //     start++;
    //     end--;
    // }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    reverse_array(arr, size);
    
    // After the function call, the array should be reversed:
    // arr[] = {5, 4, 3, 2, 1}
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}