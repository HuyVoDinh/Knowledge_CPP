#include <iostream>
using namespace std;

int main()
{
    /***
     * [Accessing array elements]
     * 
     *      array_name [element_index]
     *          test_scores [1]
     * ****/

    int test_scores[5] {100,51,26,83,65};

    cin >> test_scores [0];
    cin >> test_scores [1];
    cin >> test_scores [2];
    cin >> test_scores [3];
    cin >> test_scores [4];

    cout << "First score at in dex 0: " << test_scores [0] << endl;
    cout << "Second score at in dex 1: " << test_scores [1] << endl;
    cout << "Third score at in dex 2: " << test_scores [2] << endl;
    cout << "Fourth score at in dex 3: " << test_scores [3] << endl;
    cout << "Fifth score at in dex 4: " << test_scores [4] << endl;

    /***
     * [Arrays]
     *  How does it work?
     *      The name of the array represent the location of the first element in the array (index 0)
     *      The [index] represents the offset from the beginning of the array
     *      C++ simply performs a calculation to find the correct element
     *      Remember - no bounds checking! => So be careful, if you have an array of five integers and you ask the compiler for the integer at the tenth index, it will glady do the calculation and give you whatever happens to be at that location. It's your responsibility to be sure that you're within the bounds of the array
     * ***/

    char vowels[] {'a','e','i','o','u'};
    cout << "\nThe first vowel is: " << vowels[0] << endl;
    cout << "The last vowel is: " << vowels[4] << endl;

    //What would happen if trying to read from the console and I want to store whatever character i read into vowels sub 5-
    // cin >> vowels[5]; => out of bounds
    //=> Obviously, I'm going to read a character and store it in a location that's not part of the array

    double hi_temps [] {90.1,73.2,75.2,73.4};
    cout << "\nThe first high temperature is: " << hi_temps[0] << endl;

    hi_temps[0] = 100.7; //set the first element in hi_temps to 100.7
                        // we'll talk about assignment statement in an upcoming section

    cout << "The first high temperature is now: " << hi_temps[0] << endl;


    int test_scores [5];

    //What happening here is I'm getting an array of five integers => the junk => put a couple of curly braces there in the initializer => will initialize everything to 0
    cout << "First score at in dex 0: " << test_scores [0] << endl;
    cout << "Second score at in dex 1: " << test_scores [1] << endl;
    cout << "Third score at in dex 2: " << test_scores [2] << endl;
    cout << "Fourth score at in dex 3: " << test_scores [3] << endl;
    cout << "Fifth score at in dex 4: " << test_scores [4] << endl;

    cout << "\nEnter 5 test scores: ";
    cin >> test_scores [0];
    cin >> test_scores [1];
    cin >> test_scores [2];
    cin >> test_scores [3];
    cin >> test_scores [4];

    cout << "\nThe updated array is: " << endl;
    cout << "First score at in dex 0: " << test_scores [0] << endl;
    cout << "Second score at in dex 1: " << test_scores [1] << endl;
    cout << "Third score at in dex 2: " << test_scores [2] << endl;
    cout << "Fourth score at in dex 3: " << test_scores [3] << endl;
    cout << "Fifth score at in dex 4: " << test_scores [4] << endl;


    cout << "\nNotice what tha value of the array name is: " << test_scores << endl;
    //You get some hexadecimal number -> That number is the memory address or the storage location where the array is located
    return 0;
}