/***
 * [std::list and std::forward_list]
 * 
 *  Sequence containers
 * 
 *  Non-contiguous in memory
 * 
 *  No direct access to elements
 * 
 *  Very efficient for inserting and deleting elements once an element is found
 * 
 * [std::list]
 * 
 *  #include <list>
 * 
 *  Dynamic size
 *      Lists of elements
 *      list is bidirectional (doubly-linked)
 * 
 *  Direct element access is NOT provided
 * 
 *  Rapid insertion and deletion of elements anywhere in the container (constant time)
 * 
 *  All iterators available and invalidate when corresponding element is deleted
 * 
 * <Section20_SequenceContainers-ListAndForwardList1.png>       // same linked list
 * 
 * [std::list - initialization and assignment]
 * 
 *  std::list<int> l {1,2,3,4,5};
 *  std::list<int> ll (10,100); // ten 100s
 * 
 *  std::list<std::string> stooges{
 *      std::string{"Larry"},
 *      "Moe",
 *      std::string{"Curly"}
 *  };
 * 
 *  l = {2,4,6,8,10}; 
 * 
 * [std::list - common methods]
 * => Lists do not allow direct access to elements so we can't use the subscript operator or the at method. 
 * The list also provides front and back methods that return references to the element at the front and the element at the back of the list. 
 *  std::list<int> l {1,2,3,4,5};
 *  
 *  std::cout << l.size();              // 5
 *  std::cout << l.max_size();          // a very large number
 * 
 *  std::cout << l.front();             // 1
 *  std::cout << l.back();              // 5
 * 
 * [std::list - common methods]
 * 
 *  Person p1 {"Larry", 18};
 *  std::list<Person> l;
 * 
 *  l.push_back(p1);                    // add p1 to the back
 *  l.pop_back();                       // remove p1 from the back
 * 
 *  l.push_front(Person{"Larry", 18});
 *  l.pop_front();                      // remove element from the front
 * 
 *  l.emplace_back("Larry", 18);        // add to back efficient
 *  l.emplace_front("Moe", 24);         // add to front
 * 
 * [std::list - methods that use iterators]
 * 
 *  std::list<int> l {1,2,3,4,5};
 *  auto it = std::find(l.begin(), l.end(), 3);
 * 
 *  l.insert(it, 10);           // 1 2 10 3 4 5
 *  l.erase(it);                // erases the 3, 1 2 10 4 5
 *  l.resize(2);                // 1 2
 *  l.resize(5);                // 1 2 0 0 0
 * 
 * [std::list - common methods]
 * 
 *  // traversing the list (bi-directional)
 * 
 *  std::list<int> l {1,2,3,4,5};
 *  auto it = std::find(l.begin(), l.end(), 3);
 * 
 *  std::cout << *it;               // 3
 *  it++;
 *  std::cout << *it;               // 4
 *  it--;
 *  std::cout << *it;               // 3
 * 
 * [std::forward_list]
 * The forward list acts as a singly linked list, so the list can only be traversed in one direction. 
 *  #include <forward_list> 
 * 
 *  Dynamic size
 *      Lists of elements
 *      list uni-directional (singly-linked)
 *      Less overhead than a std::List 
 * 
 *  Direct element access is NOT provided
 * 
 *  Rapid insertion and deletion of elements anywhere in the container (constant time)
 * 
 *  Reverse iterators not available. Iterators invalidate when corresponding element is deleted. => Similar to the list, the forward list allows for rapid insertion and deletion of elements once we have an iterator to one of the elements. Also the forward list does not support direct element access. As'we'll see in a moment, the forward list has no concept of back, only front. It doesn't make much sense to get to the back of a list and then not be able to traverse backwards, so it's not available. 
 *          => Obviously, reverse iterators make no sense either so they're not supported. 
 * 
 * [std::forward_list - common methods]
 * 
 *  std::forward_list<int> l {1,2,3,4,5};
 * 
 *  std::cout << l.size();              // Not available
 *  std::cout << l.max_size;            // a very large number
 * 
 *  std::cout << l.front();             // 1
 *  std::cout << l.back();              // Not available
 * 
 *  Person p1 {"Larry", 18};
 *  std::forward_list<Person> l;
 * 
 *  l.push_front(p1);                   // add p1 to the front
 *  l.pop_front();                      // remove p1 from the front
 * 
 *  l.emplace_front("Moe", 24);         // add to front
 * 
 * [std::forward_list - methods that use iterators]
 * 
 *  std::forward_list<int> l {1,2,3,4,5};
 *  auto it = std::find(l.begin(), l.end(), 3);
 * 
 *  l.insert_after(it, 10);             // 1 2 3 10 4 5
 *  l.emplace_after(it, 100);           // 1 2 3 100 10 4 5
 * 
 *  l.erase_after(it);                  // erases the 100, 1 2 3 10 4 5
 * 
 *  l.resize(2);                        // 1 2
 *  
 *  l.resize(5);                        // 1 2 0 0 0
 * ****/
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>         // for std::advance

class Person{
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    public:
        Person() : name {"Unknown"}, age{0} {}
        Person(std::string name, int age) : name {name}, age{age}{}
        bool operator<(const Person &rhs) const {
            return this->age < rhs.age;
        }
        bool operator==(const Person &rhs) const{
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os << p.name << ": " << p.age;
    return os;
}

template <typename T>
void display(const std::list<T> &l){
    std::cout << "[ ";
    for(const auto &elem : l)
        std::cout << elem << " ";
    std::cout << "]\n";
}

void test1(){
    std::cout << "\nTest1=======================================\n";

    std::list<int> l1 {1,2,3,4,5};
    display(l1);

    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);

    std::list<int> l4 (10,100);
    display(l4);
}

void test2(){
    std::cout << "\nTest2=======================================\n";
    
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    std::cout << "Size: " << l.size() << std::endl;

    std::cout << "Front: " << l.front() << std::endl;
    std::cout << "Back: " << l.back() << std::endl;

    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
}

void test3(){
    std::cout << "\nTest3=======================================\n";
    
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    l.resize(5);
    display(l);

    l.resize(10);
    display(l);

    std::list<Person> persons;
    persons.resize(5);                      // uses the Person default constructor
    display(persons);
}

void test4(){
    std::cout << "\nTest4=======================================\n";
    
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    auto it = std::find(l.begin(), l.end(), 5);
    if(it != l.end()){
        l.insert(it, 100);
    }
    display(l);

    std::list<int> l2 {1000,2000,3000};
    l.insert(it, l2.begin(), l2.end());
    display(l);

    std::advance(it, -4);       // point to the 100
    std::cout << *it << std::endl;

    l.erase(it);                // remove the 100 - iterator becomes invalid
    display(l);
}

void test5(){
    std::cout << "\nTest5=======================================\n";
    
    std::list<Person> stooges{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };

    display(stooges);
    std::string name;
    int age{};
    std::cout << "\nEnter the name of the next stooges: ";
    getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;

    stooges.emplace_back(name,age);
    display(stooges);

    // Insert Frank before Moe
    auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if(it != stooges.end())
        stooges.emplace(it, "Frank", 18);
    display(stooges);
}

int main(){

    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}