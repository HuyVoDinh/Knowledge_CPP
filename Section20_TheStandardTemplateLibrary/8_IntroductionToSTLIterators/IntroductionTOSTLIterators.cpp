/***
 * [Iterators]      => Iterators allow us to process sequence of elements from these containers without worrying or even needing to know about how the container is implemented behind the scenes. Iterators are implemented as template classes, so we create iterator objects and use them to iterate through our containers. 
 *                  The syntax we use with iterators will remind you of pointers. We can use the dereference operator, the increment and decrement operators and so forth. This was done intentionally. C++ programmers are comfortable with the pointer syntax, and it's very easy to learn how to use iterators without having to learn some other arbitrary syntax. 
 *                  Most of the stl containers can be traversed with iterators. There are a few exceptions such as a stack and a queue. 
 *  Allows abstracting an arbitrary container as a sequence of elements
 *  They are objects that work like pointers by design
 *  Most container classes can be traversed with iterators
 * 
 * [Declaring iterators]
 *  Iterators must be declared based on the container type they will iterate over
 *  
 *  container_type::iterator_type iterator_name;
 * 
 *  std::vector<int>::iterator it1;
 *  std::list<std::string>::iterator it2;
 *  std::map<std::string, std::string>::iterator it3;
 *  std::set<char>::iterator it4;
 * 
 * [iterator begin and end methods]
 *  std::vector<int> vec{1, 2, 3};
 * 
 * vec.begin(): first element
 * vec.end(): location after last element
 * 
 * [Initializing iterators]
 * 
 *  std::vector<int> vec{1, 2, 3};
 *  std::vector<int>::iterator it = vec.begin();
 * 
 *  or
 * 
 *  auto it = vec.begin();
 * 
 * [Operations with iterators (it)]
 * 
 * |            Operation                       |       Description             |   Type of Iterator
 * |    ++it                                    |   Pre-increment               |   All
 * |    it++                                    |   Post-increment              |   All
 * |    it = it1                                |   Assignment                  |   All
 * |    *it                                     |   Dereference                 |   Input and Output
 * |    it->                                    |   Arrow operator              |   Input and Output
 * |    it == it1                               |   Comparison for equality     |   Input
 * |    it != it1                               |   Comparison for inequality   |   Input
 * |    --it                                    |   Pre-decrement               |   Bidirectional
 * |    it--                                    |   Post-decrement              |   Bidirectional
 * |it + i. it+=i, it - i, it - = i             |   Increment and decrement     |   Random Access
 * |it < it1, it <= it1, it > it1, it >= it1    |   Comparison                  |   Random Access
 * 
 * 
 * [Using iterators - std::vector]
 *  std::vector<int> vec {1, 2, 3};
 *  std::vector<int>::iterator it = vec.begin();
 * 
 *  while (it != vec.end()){
 *      std::cout << *it << " ";        // the iterator is pointing to by dereferencing the iterator,
 *      ++it;                           // move to the next element by incrementing the iterator. 
 *  }
 *  // 1 2 3
 * //=> Why not just use a range-based for loop or a counter controlled for loop? That a range based for loop is converted to an iterator-based loop behind the scenes by the compiler. But the real answer is that in the case of a vector, we could do it a lot of different ways. 
 *  => But other containers don't allow us to randomly access elements like a vector does. So for those containers, iterators are necessary. 
 * 
 *  std::vector<int> vec{1, 2, 3};
 *  for(auto it = vec.begin(); it != vec.end(); it++){
 *      std::cout << *it << " ";
 *  }
 *  // 1 2 3
 * 
 * [Reverse iterators]
 *  Works in reverse
 *  Last element is the first and first is the last
 *  ++ moves backward, -- moves forward
 * 
 *  std::vector<int> vec {1, 2, 3};
 *  std::vector<int>::reverse_iterator it = vec.begin();        // The last element is the first and the first is the last. 
 *  while (it != vec.end()){                                    // When we increment the iterator, we move backwards through the container in reverse. When decrement the iterator, we move forward. We then declare it as a reverse iterator and initialize it to vec.begin. 
 *                                                                      since it's a reverse iterator, it will be pointing to the last element in the list, not the first.
 *                                                              // In addition to the reverse iterator, there's a few variants that are const iterators, that are read-only iterators.
 *      std::cout << *it << " ";
 *      ++it;
 *  }
 *  // 3 2 1
 * 
 * [Other iterators]
 * 
 *  begin() and end()
 *      iterator
 * 
 *  cbegin() and cend()
 *      const_iterator
 * 
 *  rbegin() and rend()
 *      reverse_iterator
 * 
 *  crbegin() and crend()
 *      const_reverse_iterator
 * ****/

 #include <iostream>
 #include <vector>
 #include <set>
 #include <map>
 #include <list>

 //display any vector of integers using range-based for loop
 void display(const std::vector<int> &vec){
    std::cout << "[ ";
    for (auto const &i : vec){
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
 }

 void test1(){
    std::cout << "\n================================\n";
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.begin();        // point to 1
    std::cout << *it << std::endl;

    it++;                           // point to 2
    std::cout << *it << std::endl;

    it += 2;                           // point to 4
    std::cout << *it << std::endl;

    it -= 2;                           // point to 2
    std::cout << *it << std::endl;

    it = nums1.end()-1;                           // point to 5
    std::cout << *it << std::endl;

}

void test2(){
    std::cout << "\n================================\n";
    // display all vector elements using an iterator

    std::vector<int> nums1 {1,2,3,4,5};

    std::vector<int>::iterator it = nums1.begin();
    while(it != nums1.end()){
        std::cout << *it << std::endl;
        it++;
    }

    // change all vector elements to 0
    it = nums1.begin();
    while(it != nums1.end()){
        *it = 0;
        it++;
    }

    display(nums1);
}

void test3(){
    //using a const_iterator
    std::cout << "\n================================\n";
    std::vector<int> nums1 {1,2,3,4,5};

    std::vector<int>::const_iterator it1 = nums1.begin();
    // auto it1 = nums1.cbegin();       // these lines equivalent

    while (it1 != nums1.end()){
        std::cout << *it1 << std::endl;
        it1++;
    }

    // compiler error when we try to change element 
    it1 = nums1.begin();
    while(it1 != nums1.end()){
        // *it1 = 0;        // compiler error - read only because const_iterator
        it1++;
    }
}

void test4(){
    // more iterators
    // using a reverse iterator
    std::vector<int> vec {1, 2, 3, 4};
    auto it1 = vec.rbegin();                // reverse iterator over vector of ints starts at 4
    while (it1 != vec.rend()){
        std::cout << *it1 << std::endl;
        it1++;
    }

    // const reverse iterator over a list
    std::list<std::string> name {"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin();              // iterator over list of strings point to Curly
    std::cout << *it2 << std::endl;
    it2++;      // point to Moe
    std::cout << *it2 << std::endl;

    // iterator over a map
    std::map<std::string, std::string> favorites{
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };

    auto it3 = favorites.begin();           // iterator over map of string, string pairs
    while (it3 != favorites.end()){
        std::cout << it3->first << ": " << it3->second << std::endl;
        it3++;
    }
}

void test5(){
    // iterate over a subset of a container
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;

    while (start != finish){
        std::cout << *start << std::endl;
        start++;
    }
}


int main(){

    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}