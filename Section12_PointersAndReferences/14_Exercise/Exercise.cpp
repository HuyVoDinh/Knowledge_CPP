/***
 * [Reverse a std::string using Pointers]
 * Exercise: Reverse a std::string using Pointers

Specification:

Write a C++ function reverse_string that takes a std::string as input and returns a new std::string with the characters in reverse order. The function should use pointers to perform the reversal.

Function Signature:

std::string reverse_string(const std::string& str);
Input:

str: The input string.

Output:

The function should return a new string with the characters of str reversed.

Example:

std::string input = "Hello, World!";
std::string reversed = reverse_string(input);
 
// reversed should be "!dlroW ,olleH"
 * **/

#include <iostream>
#include <string>
using namespace std;

#include <string>

std::string reverse_string(const std::string &str) {
    std::string reversed;
    reversed = str;
    // Write your code below this line 
    for(int i = 0; i < reversed.length(); i++)
        reversed[i] = str[str.length() - 1 - i];
    // Write your code abocve this line

    /****
     *     const char* start = str.c_str();                    // Pointer to the first character
    const char* end = str.c_str() + str.size() - 1;     // Pointer to the last character

    while (end >= start) {
        reversed.push_back(*end);   // Append the character at the end pointer to the reversed string
        end--;
    }
     * **/


    return reversed;
}

int main(){

    std::string input = "Hello, World!";
    std::string reversed = reverse_string(input);
    cout << reversed << endl;
    return 0;
}