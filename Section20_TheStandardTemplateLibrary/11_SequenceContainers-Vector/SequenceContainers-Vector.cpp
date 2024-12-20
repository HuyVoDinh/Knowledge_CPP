/***
 * [std::vector]
 * 
 * #include <vector>
 * 
 * Dynamic size
 *  handled automatically
 *  Can expand and contract as needed
 *  Elements are stored in contiguous memory as an array
 * 
 * Direct element access (constant time)
 * 
 * Rapid insertion and deletion at the back (constant time)
 * 
 * Insertion or removal of elements (linear time)
 * 
 * All iterators available and may invalidate
 * 
 * push_back: if there's no room and the vector needs to allocate more space, it'll automatically
 * 
 * [std::vector - initialization and assignment]
 * 
 * std::vector<int> vec {1,2,3,4,5};
 * std::vector<int> vec1 (10, 100);     // ten 100s
 * 
 * std::vector<std::string> stooges {
 *  std::string{"Larry"},
 *  "Moe",
 *  std::string{"Curly"}
 * };
 * 
 * vec1 = {2,4,6,8,10};
 * 
 * [std::vector - common methods]
 * 
 *  std::vector<int> vec {1,2,3,4,5};
 * 
 *  std::cout << vec.size();                // 5
 *  std::cout << vec.capacity();            // 5
 *  std::cout << vec.max_size;              // a very large number
 * 
 *  std::cout << vec.at(0);                 // 1
 *  std::cout << vec[1];                    // 2
 * 
 *  std::cout << vec.front();               // 1
 *  std::cout << vec.back();                // 5
 * 
 *  Person p1 {"Larry", 18};
 *  std::vector<Person> vec;
 * 
 *  vec.push_back(p1);                      // add p1 to the back
 *  vec.pop_back();                         // remove p1 from the back
 * 
 *  vec.push_back(Person{"Larry", 18});
 * 
 *  vec.emplace_back("Larry", 18);          // efficient
 * 
 * 
 *  std::vector<int> vec1 {1,2,3,4,5};
 *  std::vector<int> vec2{10,20,30,40,50};
 * 
 *  std::cout << vec1.empty();              // 0 (false)
 *  vec1.swap(vec2);                        // swaps the 2 vector
 * 
 *  std::sort(vec1.begin(), vec1.end());
 * 
 * 
 *  std::vector<int> vec1 {1,2,3,4,5};
 *  std::vector<int> vec2 {10,20,30,40, 50}; 
 * 
 *  auto it = std::find(vec1.begin(), vec1.end(), 3);
 *  vec1.insert(it,10);             // 1,2,19,3,4,5
 * 
 *  it = std::find(vec1.begin(), vec1.end(), 4);
 *  vec::insert(it, vec2.begin(), vec2.end());
 *      // 1, , 10, 3, 10, 20, 30, 40, 50, 4, 5
 * ***/
#include <iostream>
#include <vector>
#include <algorithm>

class Person{
        friend std::ostream &operator<<(std::ostream &os, const Person &p);
        std::string name;
        int age;
    public:
        Person() = default;
        Person(std::string name, int age) : name {name}, age{age} {}
        bool operator==(const Person &rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os << p.name << ": " << p.age;
    return os;
}

// Use for_each and a lambda expression to display vector elements
void display2(const std::vector<int> &vec){
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(), [] (int x) {std::cout << x << " ";});
    std::cout << "]\n";
}

// template function to display any vector
template <typename T>
void display(const std::vector<T> &vec){
    std::cout << "[ ";
    for(const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << "]\n";
}

void test1(){
    std::cout << "\nTest1=======================================\n";

    std::vector<int> vec {1,2,3,4,5};
    display(vec);

    vec= {2,4,5,6};
    display2(vec);

    std::vector<int> vec1 (10,100);         // ten 100s in the vector
    display(vec1);
}

void test2(){
    std::cout << "\nTest2=======================================\n";

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    std::cout << "\nnvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.push_back(6);
    display(vec);
    std::cout << "\nnvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.shrink_to_fit();        // C++11
    display(vec);
    std::cout << "\nnvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.reserve(100);
    display(vec);
    std::cout << "\nnvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl; 
}

void test3(){
    std::cout << "\nTest3=======================================\n";

    std::vector<int> vec {1,2,3,4,5};
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;

    display(vec);
}

void test4(){
    std::cout << "\nTest4=======================================\n";
    std::vector<Person> stooges;

    Person p1 {"Larry", 18};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person{"Moe", 25});
    display(stooges);

    stooges.emplace_back("Curly", 30);
    display(stooges);
}

void test5(){
    std::cout << "\nTest5=======================================\n";

    std::vector<Person> stooges{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };

    display(stooges);
    std::cout << "\nFront: " << stooges.front() << std::endl;
    std::cout << "\nBack: " << stooges.back() << std::endl;

    stooges.pop_back();
    display(stooges);
}

void test6(){
    std::cout << "\nTest6=======================================\n";
    std::vector<int> vec {1,2,3,4,5};
    display(vec);

    vec.clear();
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);
    vec.erase(vec.begin(), vec.begin() +2);
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    // erase all even numbers
    auto it = vec.begin();
    while(it != vec.end()){
        if(*it %2 ==0)
            vec.erase(it);
        else 
            it++;       // only increment if not erased!
    }
    display(vec);
}

void test7(){
    std::cout << "\nTest7=======================================\n";

    std::vector<int> vec1 {1,2,3,4};
    std::vector<int> vec2 {10,20,30,40,50};

    display(vec1);
    display2(vec2);
    std::cout << std::endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

void test8(){
    std::cout << "\nTest8=======================================\n";

    std::vector<int> vec1 {1,21,3,40,21};

    display(vec1);
    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

void test9(){
    std::cout << "\nTest9=======================================\n";
    /***
     * std::back_inserter contruts a back-insert iterator that inserts new elements at the end of the container it applied to. 
     * It's a special output iterator
     * It's awesome!!!! and very efficient
     * There is also a front_inserter we can use with deques and list
     * 
     * ***/

    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2{10,20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    // Copy_if the element is even

    vec1= {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x) {return x%2 ==0;});
    display(vec1);
    display(vec2);
}

void test10(){
    std::cout << "\nTest10=======================================\n";
    // transform over 2 ranges

    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3;

    // 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3), [] (int x, int y){return x*y;});
    display(vec3);
}

// Insert vec2 into vec1 before the 5
void test11(){
    std::cout << "\nTest11=======================================\n";
    std::vector<int> vec1{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()){
        std::cout << "Inserting...\n";
        vec1.insert(it, vec2.begin(), vec2.end());
    } else {
        std::cout << "Sorry, 5 not found\n";
    }
    display(vec1);
}

int main(){

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}