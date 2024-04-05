#include<iostream>
#include <cstring>  //for c-style string function
#include <cctype>   // for character-based functions

using namespace std;

int main()
{
    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    char temp[50] {};

    cout << first_name; //Will likely display garbage

    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Please enter your last name: ";
    cin >> last_name;

    cout << "Hello, " << first_name << "your first name has " << strlen(first_name) << " characters\n";
    cout << "And your last name, " << last_name << " has " << strlen(last_name) << " characters\n";

    strcpy(full_name, first_name);              // copy first_name to full name
    strcat(full_name, " ");                     // concatenate full_name and a space
    strcat(full_name, last_name);               // concatenate last_name  to full name
    cout << "Your full name is: " << full_name << endl;

    cout << "Enter your full name: "; 
    cin >> full_name; // DDD SSS
    cout << "Your full name is?: " << full_name << endl; // => DDD
    // => That's the normal behavior for that extraction operator, that;s whitespace so it stops

    cout << "Enter your full name: ";
    cin.getline(full_name,50);
    cout << "Your full name is?: " << full_name << endl;

    strcpy(temp, full_name);
    if(strcmp(temp,full_name) == 0)
    {
        cout << temp << " and " << full_name << " are the same.\n";
    }
    else
    {
        cout << temp << " and " << full_name << " are different.\n";
    }

    for(size_t i = 0; i < strlen(full_name); i++)
    {
        if(isalpha(full_name[i]))
            full_name[i] = toupper(full_name[i]);
    }
    cout << "Your full name is: " << full_name <<endl;
    if(strcmp(temp,full_name) == 0)
    {
        cout << temp << " and " << full_name << " are the same.\n";
    }
    else
    {
        cout << temp << " and " << full_name << " are different.\n";
    }

    cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name) << endl;
    // => It returns less than 0 if the first string lexically comes before the second string or return greater than 0 if the first string lexically after the second string
    cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp) << endl;

    return 0;
}