/***
 * In this exercise you will create a program that will be used to reformat a name so that it can be read more easily.

The string variable unformatted_full_name is comprised of two substrings; first_name and last_name in that order. Each substring begins with a capital letter.

Begin by declaring and initializing the string variable first_name from the string variable unformatted_full_name remembering that when initializing from another string, the first integer within the curly brackets represents the starting index of the substring you wish to copy and the second integer represents the length of the substring.

Next, declare and initialize the string variable last_name by using the assignment operator = and the string function substr on the string variable unformatted_full_name.

Next, declare and initialize the string variable formatted_full_name. This should be done through the use of the concatenation operator + by concatenating the string variables first_name and last_name in that order, and then assigning the concatenated string to formatted_full_name using the assignment operator =.

Now the string variable formatted_full_name contains the string "StephenHawking". We see that the string is no more formatted than the original string variable unformatted_full_name and that is because the addition operator + does not add whitespace between strings when concatenating them.

Fortunately, we can use the string function insert on the string variable formatted_full_name to insert a whitespace between the substrings such that formatted_full_name will then contain the string "Stephen Hawking".
 * ***/


#include <iostream>
#include <string>
using namespace std;

void cpp_strings() {
    
    string unformatted_full_name {"StephenHawking"};
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    int pos = 0;
    for(int i = unformatted_full_name.length() - 1 ; i >= 0; i--)
        if(isupper(unformatted_full_name.at(i)))
        {
            pos = i;
            break;
        }
    string first_name = unformatted_full_name.substr(0,pos);
    string last_name = unformatted_full_name.substr(pos,unformatted_full_name.length());
    string formatted_full_name = first_name + last_name;
    formatted_full_name = formatted_full_name.insert(pos, " ");
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << formatted_full_name;
}

int main()
{
    cpp_strings();
    return 0;
}