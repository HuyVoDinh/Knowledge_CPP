/***
 * [Relationship between arrays and pointers]
 * 
 * The value of an array name is the address of the first element in the array. If a pointer points to the same type of data, as the array elements then the pointer and the array name are the same as far as C++ is concerned. The only difference is that the array name is not a variable so can change it.
 * But otherwise, all the calculations done to access array elements can be done with array name or the pointer name 
 * 
 * The value of a pointer variable is an address
 * 
 * If the pointer points to the same data type as the array element then the pointer and array name can be used interchangeably (almost)
 * 
 * int scores [] {100,95,89};
 * 
 * cout << scores << endl;                      // 0x61fec8
 * cout << *scores << endl;                     // 100
 * 
 * int *score_ptr = scores;
 * 
 * cout << score_ptr << endl;                   // 0x61fec8
 * cout << *score_ptr << endl                   // 100
 * 
 * cout << score_ptr[0] << endl;                // 100
 * cout << score_ptr[1] << endl;                // 95
 * cout << score_ptr[2] << endl;                // 89
 * 
 * [Example using pointers in expressions]
 * 
 * int scores[] {100, 95, 89};
 * int *score_ptr = scores;
 * 
 * cout << score_ptr << endl;                       // 0x61ff10
 * cout << (score_ptr + 1) << endl;                 // 0x61ff14
 * cout << (score_ptr + 2) << endl;                 // 0x61ff18
 * 
 * cout << *score_ptr << endl;                       // 100
 * cout << *(score_ptr + 1) << endl;                 // 95
 * cout << *(score_ptr + 2) << endl;                 // 89
 * 
 * [Subscript and Offset notation equivalence]
 * 
 *              int array_name [] {1,2,3,4,5};
 *              int *pointer_name = array_name;
 * 
 * |    Subscript Notation      |       Offset Notation         |
 * |    array_name[index]       |   *(array_name + index)       |
 * |    pointer_name[index]     |   *(pointer_name + index)     |
 * ****/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int scores[] {100,96,49};

    cout << "Value of scores: " << scores << endl;

    int*score_ptr(scores);
    cout << "Value of score_ptr: " << score_ptr << endl;

    cout << "\nArray subscript notation\n";
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;

    cout << "\nPointer subscript notation\n";
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;

    cout << "\nArray offset notation\n";
    cout << * scores << endl;
    cout << *(scores + 1)<< endl;
    cout << *(scores + 2)<< endl;

    cout << "\nPointer offset notation\n";
    cout << *(score_ptr + 0) << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;


    return 0;
}

