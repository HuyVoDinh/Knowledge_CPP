#include <iostream>
using namespace std;

int main()
{
    /***
     * [Array]
     *      Compound data type or data structure => it's a data type that's made up of other data types
     *          Collection of elements
     *      All elements are of the same type
     *      Each element can be accessed directly
     * Why do we need arrays?
     * Ex: Declare n variables as intergers, give them meaningful names and initialize them to whatever values 
     *      int test_score_1 {0};
     *      int test_score_2 {0};
     *      int test_score_3 {0};
     *      ....
     *      int test_score_n {0};   
     * 
     *  Characteristics => Give you a collection of as many elements as you want and give the entire collection a single name
     *      Fixed size => The size cannot change and Arrays will not grow or shrink on their own while the program is running
     *      Elements are all the same type
     *      Stored contiguously in memory => The memory will be allocated as one chunk
     *      Individual elements can be accessed by their position or index
     *      
     *      First element is at index 0 not at position 1
     *      Last element is at index size-1
     * 
     *      No checking to see if you are out of bounds
     * 
     *      Always initialize arrays
     *      Very efficient
     *      Iteration (looping) is often used to process
     * ***/

    /***
     * [Declaring Arrays]
     *      Element_Type array_name [constant number of elements];
     * **/

    // int test_scores [5];

    // int high_score_per_level [10];
    
    // const int days_in_year {365};
    // double hi_temperatures [days_in_year];

    /***
     * [Initialization Arrays]
     * [Initialization]
     *      Element_Type array_name [constant number of elements] {init list};
     * **/

    int test_scores [5] {100,95,99,73,15};

    int high_score_per_level [10] {3,5}; //init to 3,5 and remaining to 0
    
    const int days_in_year {365};
    double hi_temperatures [days_in_year] {0}; // init all to zero

    int another_array [] {1,2,3,4,5}; //size automatically calculated

}