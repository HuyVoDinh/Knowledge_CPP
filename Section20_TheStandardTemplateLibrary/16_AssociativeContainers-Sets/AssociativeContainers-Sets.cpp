/***
 * [The STL Set containers]
 * 
 *  Associative containers
 *      Collection of stored objects that allow fast retrieval using a key
 *      STL provides Sets and Maps
 *      Usually implemented as a balanced binary tree or hashsets
 *      Most operations are very efficient
 * 
 *  Set
 *      std::set
 *      std::unordered_set
 *      std::multiset
 *      std::unordered_multiset
 * 
 * [std::set]
 * 
 *  #include <set>
 *  Similar to a mathematical set
 *  Ordered by key
 *  No duplicate elements
 *  All iterators available and invalidate when corresponding element deleted
 * 
 * [std::set - initialization and assignment]
 * 
 *  std::set<int> s {1,2,3,4,5};
 *  std::set<std::string> stooges{
 *      std::string {"Larry"},
 *      "Moe",
 *      std::string {"Curly"}
 *  };
 *  s = {2,4,6,8,10};
 * 
 * [std::set - common methods]
 * 
 *  std::set<int> s {4,1,1,3,3,2,5};            // 1 2 3 4 5
 *  std::cout << s.size();                      // 5
 *  std::cout << s.max_size;                    // a very large number
 * 
 *  No concept of front and back
 *  s.insert(7);                                // 1 2 3 4 5 7
 * 
 *  Person p1 {"Larry", 18};
 *  Person p2 {"Moe", 25};
 * 
 *  std::set<Person> stooges;
 * 
 *  stooges.insert (p1);                        // adds p1 to the set
 *  auto result = stooges.insert(p2);           // adds p2 to the set
 * 
 *  uses operator< for ordering!
 *  return a std::pair<iterator, bool> 
 *      first is an iterator to the inserted element or to the duplicate in the set
 *      second is a boolean indicating success or failure
 * 
 * 
 *  std::set<int> s {1,2,3,4,5};
 * 
 *  s.erase(3);                                 // erase the 3 : 1 2 4 5
 * 
 *  auto it = s.find(5);
 *  if(it != s.end())
 *      s.erase(it);                            // erase the 5 : 1 2 4
 * 
 *  int num = s.count(1);                       // 0 or 1
 * 
 *  s.clear();                                  // remove all elemets
 * 
 *  s.empty();                                  // true or false;
 * 
 * [std::multi_set]
 * 
 *  #include <set> 
 *  Sorted by key
 *  Allows duplicate elements
 *  All iterators are available
 * 
 * [std::unordered_set]
 * 
 *  #include <unordered_set>
 *  Elements are unordered
 *  No duplicate elements allowed
 *  Elements cannot be modified
 *      Must be erased and new element inserted
 *  No reverse iterators are allowed
 * 
 * [std::unordered_multiset]
 * 
 *  #include <unordered_set> 
 *  Elements are unordered
 *  Allows duplicate elements
 *  No reverse iterators are allowed
 * ***/

#include <iostream>
#include <set>

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
void display(const std::set<T> &l){
    std::cout << "[ ";
    for(const auto &elem : l)
        std::cout << elem << " ";
    std::cout << "]\n";
}

void test1(){
    // Sets
    std::cout << "\nTest1=======================================\n";
    std::set<int> s1 {1,4,3,5,2};
    display(s1);

    s1 = {1,2,3,1,1,2,2,3,3,4,5};
    display(s1);

    s1.insert(0);
    s1.insert(10);

    display(s1);

    if(s1.count(10))
        std::cout << "10 is in the set\n";
    else 
        std::cout << "10 is NOT in the set\n";

    auto it = s1.find(5);
    if(it != s1.end())
        std::cout << "Found: " << *it << std::endl;

    s1.clear();

    display(s1);
}

void test2(){
    std::cout << "\nTest2=======================================\n";
    std::set<Person> stooges{
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges);                   // Note the order of display! operator< -> it's ordering by age,not ordering by name.Otherwise Curly would be the first one

    stooges.emplace("james", 50);
    display(stooges);

    stooges.emplace("Frank", 50);       // No -- 50 already exists
    display(stooges);

    auto it = stooges.find(Person{"Moe", 2});
    if(it != stooges.end())
        stooges.erase(it);

    display(stooges);

    it = stooges.find(Person("XXXX", 50));  // Will remove James
                                            // uses operator<

    if(it != stooges.end())
        stooges.erase(it);
    display(stooges);
}

void test3(){
    std::cout << "\nTest3=======================================\n";

    std::set<std::string> s {"A", "B", "C"};
    display(s);

    auto result = s.insert("D");
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;

    std::cout << std::endl;

    result = s.insert("A");     // assigned the return value of the insert method. This is a std::pair. std::pair has 2 attributes, first and second. In this case, first is an iterator that's pointing to either the d that we just inserted or the d that's already duplicated in there that didn't allow me to insert.
                                // The second part of the pair. The second attribute is going to have a boolean tru false was the insertion successful. So I've changed this to bool alpha so it displays the true false value. 
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;
}

int main(){
    test3();
    test3();
    test3();
    return 0;
}