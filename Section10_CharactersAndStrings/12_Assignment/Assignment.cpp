/***
 * In this assignment, you will display a Letter Pyramid given a string of characters. This assignment will allow you to practice using loops, nested loops, and std::stringn this assignment, you will display a Letter Pyramid given a string of characters. This assignment will allow you to practice using loops, nested loops, and std::string
 * 
 * 
 * Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

It's much easier to understand the Letter Pyramid given examples.

If the user enters the string "ABC", then your program should display:

  A                                                                                                                    
 ABA                                                                                                                   
ABCBA 


If the user enters the string, "12345", then your program should display:

 

    1                                                                                                                  
   121                                                                                                                 
  12321                                                                                                                
 1234321                                                                                                               
123454321
 

If the user enters 'ABCDEFG', then your program should display:

 

      A                                                                                                                
     ABA                                                                                                               
    ABCBA                                                                                                              
   ABCDCBA                                                                                                             
  ABCDEDCBA                                                                                                            
 ABCDEFEDCBA                                                                                                           
ABCDEFGFEDCBA
If the user enters 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', then your program should display:

                         A
                        ABA
                       ABCBA
                      ABCDCBA
                     ABCDEDCBA
                    ABCDEFEDCBA
                   ABCDEFGFEDCBA
                  ABCDEFGHGFEDCBA
                 ABCDEFGHIHGFEDCBA
                ABCDEFGHIJIHGFEDCBA
               ABCDEFGHIJKJIHGFEDCBA
              ABCDEFGHIJKLKJIHGFEDCBA
             ABCDEFGHIJKLMLKJIHGFEDCBA
            ABCDEFGHIJKLMNMLKJIHGFEDCBA
           ABCDEFGHIJKLMNONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
   ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
  ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
 ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA
If the user enters "C++isFun!", then your program should display:

 

        C                                                                                                              
       C+C                                                                                                             
      C+++C                                                                                                            
     C++i++C                                                                                                           
    C++isi++C                                                                                                          
   C++isFsi++C                                                                                                         
  C++isFuFsi++C                                                                                                        
 C++isFunuFsi++C                                                                                                       
C++isFun!nuFsi++C


Think about the problem before you begin and break it down into steps.

This can be a very challenging problem to solve!

*****  Don't forget to paste your code solution when you submit.******

*****  Also, submit it so your peers can see it and possibly comment. ******

Have fun!

Questions for this assignment
Which C++ loop(s) did you use and why?

How did you handle displaying the leading spaces in each row of the pyramid?

Now that you completed the assignment, how might approach the problem differently if you had to solve it again?
 * **/


#include <iostream>
using namespace std;
int main()
{
    string Letter_Pyramid;
    cin >> Letter_Pyramid;
    int size = Letter_Pyramid.length() - 1;
    

    for(size_t i = 0; i <= size; i++)
    {
        int pos = 0;
        for(size_t j = 0; j < 2*size + 1; j++)
        {
            if(j >= size - i &&  j <= i + size){
                 if(j < size)
                 {
                    cout << Letter_Pyramid.at(pos);
                    pos++;
                 }
                 else {
                    cout << Letter_Pyramid.at(pos);
                    if(pos > 0)
                        pos--;
                 }
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


/****
 * [Solution]
 * Which C++ loop(s) did you use and why?

How did you handle displaying the leading spaces in each row of the pyramid?

Now that you completed the assignment, how might approach the problem differently if you had to solve it again?

Please see the solution at the end of this text.

The idea when solving this problem is first to break up the problem up into subproblems.

Get the input from the user and store it in a std::string variable
Loop for each letter in the string entered by the user
    Determine how many blank spaces must be displayed before the current row and display them
    Determine how many letters must be displayed before the current character and display them
    Display the current character
    Display the remaining characters in reverse order
    Complete the row with a new line


There are many, many ways to solve this problem. My solution is considering that the std::string .length() and .at() methods use size_t as the type for the return value and parameter.

You can also use int instead of size_t for this problem, but you will get compiler warnings about int and size_t compatibility issues.

I look forward to seeing your solutions!

Please share so others can see the work. 

Here is a sample solution:

// Letter Pyramid
// Written by Frank J. Mitropoulos

#include <iostream>
#include <string>


int main()
{
    std::string letters{};

    std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(std::cin, letters);

    size_t num_letters = letters.length();

    int position {0};

    // for each letter in the string
    for (char c: letters) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            std::cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j=0; j < position; j++) {
            std::cout << letters.at(j);
        }

        // Display the current 'center' character
        std::cout << c;

        // Display the remaining characters in reverse order
        for (int j=position-1; j >=0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            std::cout << letters.at(k);
        }

        std::cout << std::endl; // Don't forget the end line
        ++position;
    }

    return 0;
}
 * 
 * **/