/***
 * [std::deque (double ended queue)]
 * 
 *  #include <deque> 
 * 
 *  Dynamic size
 *      Handled automatically
 *      Can expand and contract as needed
 *      Elements are NOT stored in contiguous memory
 * 
 *  Direct element access (constant time)
 * 
 *  Rapid insertion and deletion at the front and back (constant time)
 * 
 *  Insertion or removal of elements (linear time)
 * 
 *  All iterators available and may invalidate
 * 
 * [std::deque - initialization and assignment]
 * 
 *  std::deque<int> d {1,2,3,4,5};
 *  std::deque<int> d1 (10, 100);       // ten 100s
 * 
 *  std::deque<std::string> stooges{
 *      std::string{"Larry"},
 *      "Moe",
 *      std::string{"Curly"}
 *  };
 *  d = {2,4,6,8,10};
 * 
 *  <Section20_SequenceContainers-Deque.png> 
 *  The deque's elements are not in contiguous memory. So usually a deque is implemented as a collection of memory blocks, and these memory blocks contain elements that are in a contiguous memory. 
 *  But the blocks themselves are not in contiguous memory. So a good way to think of a deque is as a linked list of vectors. So when we add an element at the front, it adds it if there's space. 
 *  If not, it will allocate a new block, add the element to that block and then link in the block. The same happens when we add an element at the back.
 * 
 * [std::deque - common methods]
 * 
 *  std::deque<int> d {1,2,3,4,5};
 * 
 *  std::cout << d.size();                  // 5
 *  std::cout << d.max_size();              // a very large number
 *  std::cout << d.at(0);                   // 1
 *  std::cout << d[1];                      // 2
 *  std::cout << d.front();                 // 1
 *  std::cout << d.back();                  // 5
 * 
 *  Person p1 {"Larry", 18};
 *  std::deque<Person> d;
 * 
 *  d.push_back(p1);                        // add p1 to the back
 *  d.pop_back();                           // remove p1 from the back
 *  d.push_front(Person{"Larry"}, 18);      
 *  d.pop_front();                          // remove element from the front
 *  d.emplace_back("Larry", 18);            // add to back efficient!!
 *  d.emplace_front("Moe", 24);             // Add to front
 * ***/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

// template function to display any deque
template <typename T>
void display(const std::deque<T> &d){
    std::cout << "[ ";
    for(const auto &elem : d)
        std::cout << elem << " ";
    std::cout << "]\n";
}

void test1(){
    std::cout << "\nTest1=======================================\n";

    std::deque<int> d {1,2,3,4,5};
    display(d);

    d = {2,4,5,6};
    display(d);

    std::deque<int> d1 (10,100);        // ten 100s in the deque
    display(d1);

    d[0] = 100;
    d.at(1) = 200;
    display(d);
}

void test2(){
    //push and pops
    std::cout << "\nTest2=======================================\n";

    std::deque<int> d {0,0,0};
    display(d);

    d.push_back(10);
    d.push_back(2);
    display(d);

    d.push_front(100);
    d.push_front(200);
    display(d);

    std::cout << "Front: " << d.front() << std::endl;
    std::cout << "Back: " << d.back() << std::endl;
    std::cout << "Size: " << d.size() << std::endl;

    d.pop_back();
    d.pop_front();
    display(d);
    
}

void test3(){
    std::cout << "\nTest3=======================================\n";
    //insert all even numbers into the back of a deque and all odd numbers into the front
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    for(const auto &elem:vec){
        if(elem % 2 == 0)
            d.push_back(elem);
        else    
            d.push_front(elem);
    }
    display(d);
}

void test4(){
    std::cout << "\nTest4=======================================\n";
    // push front vs. back ordering

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;   

    for(const auto &elem : vec){
        d.push_front(elem);
    }
    display(d);

    d.clear();

    for(const auto &elem:vec){
        d.push_back(elem);
    }
    display(d);
}

void test5(){
    std::cout << "\nTest5=======================================\n";
    // Same as test4 using std::copy

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);

    d.clear();

    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);
}

int main(){

    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}