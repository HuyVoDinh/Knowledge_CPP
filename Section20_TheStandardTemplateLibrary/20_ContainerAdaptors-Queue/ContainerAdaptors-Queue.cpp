/***
 * [std::queue]
 * 
 * First-in First-out (FIFO) data structure
 * 
 * Implemented as an adapter over other STL container. Can be implemented as a list or deque
 * Elements are pushed at the back and popped from the front
 * No iterators are supported
 * 
 * #include <queue>
 * 
 * push - insert an element at the back of the queue
 * pop - remove an element from the front of the queue
 * 
 * front - access the element at the front
 * back - access the element at the back
 * 
 * empty - is the queue empty?
 * size - number of elements in the queue
 * 
 * [std::queue - initialization]
 * 
 * std::queue<int> q;                       // deque
 * std::queue<int, std::list<int>> q2;      // list
 * std::queue<int, std::deque<int>> q3;     // deque
 * 
 * [std::queue - common methods]
 * -> When push, add to the back of the queue.
 * std::queue<int> q;
 * q.push(10);                              // 10
 * q.push(20);                              // 20 10
 * q.push(30);                              // 30 20 10
 * 
 * std::cout << q.front();                  // 30 20 10     // 10
 * std::cout << q.back();                   // 30 20 10     // 30
 * q.pop();                                 // 30 20        // remove 10
 * q.pop();                                 // 30           // remove 20
 * std::cout << q.size();                                   // 1
 * ***/
#include <iostream>
#include <queue>


template <typename T>
void display(std::queue<T> q){
    std::cout << "[ ";
    while(!q.empty()){
        T elem = q.front();
        q.pop();
        std::cout << elem << std::endl;
    }
    std::cout << "]" << std::endl;
}

int main(){
    std::queue<int> q;

    for(int i : {1,2,3,4,5})
        q.push(i);
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while(!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);
}