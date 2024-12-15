/***
 * A Palindrome is a string that reads the same backwards or forwards
 * Simple examples are: 
 * madam
 * bob
 * toot
 * radar
 * 
 * An entire phrase can also be a palindome, for example: 
 *  A Toyota's a toyota
 *  A Santa at NASA
 *  A man, a plan, a cat, a ham, a yak, a hat, a canal-Panama!
 * 
 * For the purposes of this assignment we will only consider alpha characters and omit all other characters. 
 * We will also not be considering case. 
 * So,
 * A Santa at Nasa, will be processed as: 
 * ASANTAATNASA
 * 
 * A common method to solve this problem is to compare the string to its reverse and if the are equal then it must be a palindrome. But we will use a deque. 
 * 
 * I am providing the main driver for you which will automatically run several test cases. 
 * You challenge is to write the following functions: 
 * 
 * 
 * ***/
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string &s){

    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.

    std::stack<char> stk;
    std::queue<char> q;

    // add all the string characters that are alpha to the back of the queue in uppercase
    // push all the string characters that are alpha on the stack

    for (char c : s){
        if(std::isalpha(c)){
            c = std::toupper(c);
            q.push(c);
            stk.push(c);
        }
    }

    char c1 {};
    char c2 {};

    // while the queue is not empty
    //      compare and remove the character at the top of the stack
    //      and the character at the front of the queue
    //      if they are not the same - return false since it can't be a palindrome
    // if you complete the loop then the string must be a palindrome so return true

    while(!q.empty()){
        c1 = q.front();
        q.pop();
        c2 = stk.top();
        stk.pop();
        if (c1 != c2)
            return false;
    }

    return true;
}

int main(){

    std::vector<std::string> test_strings {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana", "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa At NASA", "C++", "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto&s:test_strings){
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;

    return 0;
}