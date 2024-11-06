#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /****
     * [Vectors]
     * Suppose we want to store test scores for my school
     * 
     * I have no way of knowing how many students will register next year
     * Options:
     *      I can always set the fixed size of the array to a size large enough. because make it too big and waste space
     *      Pick a size that you are not likely to exceed and use static arrays
     *      Use a dynamic array such as vector
     * 
     * What is a vector?
     *  Container in the C++ Standard Template Library
     *  An array that can grow and shrink in size at execution time
     *  Provides similar semantics and syntax as arrays
     *  Very efficient
     *  Can provide bounds checking
     *  Can use lots of cool functions like sort, reverse, find, and mor
     * 
     *  [Declaring]
     *  #include <vector>
     * ***/
    // vector <char> vowels (5);

    vector <int> test_score (10);
    //Can use a constructor initialization syntax which provides information inside parentheses. This tells the compiler that you want 5 characters
    //In the second example, we declare a vector named test_scores of 10 integers.
    //Unlike arrays, these ten integer will be automatically set to 0
    vector <char> vowels {'a','e','i','o','u'};
    //We can also use initializer lists as we did with arrays to initialize vector elements

    /***
     * [Vector - Characteristics]
     * Vectors are an object-oriented container defined in the standard template library
     * Dynamic size => They can grow and shrink as needed at runtime
     * Elements are all the same type
     * Stored contiguously in memory
     * Individual elements can be accessed by their position or index
     * 
     * First element is at index 0 => They won't contain garbage
     * Last element is at index size - 1
     * 
     * [] - no checking to see if you are out of bounds
     * Provides many useful function that do bounds check
     * 
     * Elements initialized to zero
     * Very efficient
     * Iteration (looping) is often used to precess
     * ***/

}