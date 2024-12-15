/****
 * [std::stack]
 * 
 *  List-in First-out (LIFO) data structure
 * 
 *  Implemented as an adapter over other STL container. Can be implemented as a vector, list or deque. 
 * 
 *  All operations occur on one end of the stack (top)
 * 
 *  No iterators are supported
 * 
 *  #include <stack>
 * 
 *  push - insert an element at the top of the stack
 *  pop - remove an element from the top of the stack
 *  top - access the top element of the stack but it doesn't remove it. 
 *  empty - is the stack empty?
 *  size - number of elements in the stack
 * 
 * [std::stack - initialization]
 * 
 *  std::stack<int> s;                      // deque
 *  std::stack<int, std::vector<int>> s1;   // vector
 *  std::stack<int, std::list<int>> s2;     // list
 *  std::stack<int, std::deque<int>> s3;    // deque
 * 
 * [std::stack - common methods]
 * 
 *  std::stack<int> s;
 * -> push on top the stack
 *  s.push(10);             // 10
 *  s.push(20);             // 20 10
 *  s.push(30);             // 30 20 10
 * 
 * std::cout << s.top();    // 30 20 10
 * s.pop();                 // 30 is removed    // 20 10
 *  s.pop();                // 20 is removed    // 10
 * std::cout << s.size();   // 1
 * 
 * ***/

#include <iostream>
#include <stack>
#include <vector>
#include <list>

// This function displays a stack of by repeatedly topping and popping the stack
// Note theat the stack is passed in value so we don't affect the passed in stack.

template <typename T>
void display(std::stack<T> s){
    std::cout << "[ ";
    while(!s.empty()){
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main(){
    std::stack<int> s;                   
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;  
    std::stack<int, std::deque<int>> s3; 

    for(int i : {1,2,3,4,5})
        s.push(i);
    display(s);

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while(!s.empty())
        s.pop();
    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    s.push(10);
    display(s);

    s.top() = 100;
    display(s);
    return 0;
}