/***
 * [Generic Programming with class templates]
 * 
 * What is a C++ class Template?
 *  Similar to function template, but at the class level        -> But instead of creating a generic function, we'll be creating a generic class. So this implies generic attributes, constructors, destructors, methods and so forth. We didn't say I want a vector, we said I want a vector of a specific type, and that's where the class templates come in. So the class template is generic blueprint that the compiler uses to create specialized classes. That's what metaprogramming is all about.
 *  Allows plugging-in any data type
 *  Compiler generates the appropriate class from the blueprint
 * 
 * 
 *  Let's say we want a class to hold items where the item has a name and an integer
 * 
 *  class Item {
 *      private: 
 *          std::string name;
 *          int value;
 *      public: 
 *          Item(std::string name, int value) : name {name}, value {value} {}
 *          std::string get_name() const (return name;)
 *          int get_value() const {return value;}
 *  };
 * 
 *  But we'd like our Item class to be able to hold any type of data in addition to the string      => We can create a new class, just like we did for item that has a double and a string. 
 *  We can't overload class names                                                                   => But we'd have to name it something other than items since we can't overload class names in the same namespace. 
 *  We don't want to use dynamic polymorphism                                                       => We don't want to create a complex hierarchy with dynamic polymorphism.
 * 
 * template <typename T>
 *  class Item {
 *      private: 
 *          std::string name;
 *          T value;
 *      public: 
 *          Item(std::string name, T value) : name {name}, value {value} {}
 *          std::string get_name() const (return name;)
 *          T get_value() const {return value;}
 *  };
 * 
 *  Item<int> item1 {"Larry", 1};
 *  Item<double> item2 {"House", 1000.0};
 *  Item<std::string> item3 {"Frank", "Boss"};
 *  std::vector<Item<int>> vec;
 * 
 * [Multiple types as template parameters]
 * 
 *  We can have multiple template parameters    => No limit to the number of template parameters you can have. 
 *  An their type can be different
 * 
 * template <typename T1, typename T2> 
 *  struct My_Pair{
 *      T1 first;
 *      T2 second;
 *  };
 * 
 *  My_Pair <std::string, int> p1 {"Frank", 100};
 *  My_Pair <int, double> p2 {123, 13.6};
 *  std::vector <My_PairM<int, double>> vec;
 * 
 * [std::pair]
 * 
 *  #include <utility>
 *  std::pair<std::string, int> p1 {"Frank", 100};
 *  std::cout << p1.first;      // Frank
 *  std::cout << p1.second;     // 100
 * ***/

#include <iostream>
#include <string>
#include <vector>

//Template classes are typically completely contained in header files
// So, we would have the template class in Item.h and no Item.cpp file would be used

template <typename T>
class Item {
    private: 
        std::string name;
        T value;
    public:
        Item(std::string name, T value) : name {name}, value {value}{}
        std::string get_name() const {return name;}
        T get_value() const {return value;}
};

template <typename T1, typename T2>
struct My_Pair{
    T1 first;
    T2 second;
};

int main() {

    Item<int> item1 {"Frank", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2 {"Frank", "Professor"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    Item<Item<std::string>> item3 {"Frank", {"C++", "Professor"}};
    std::cout << item3.get_name() << " " << item3.get_value().get_name() << " " << item3.get_value().get_value() << std::endl;

    std::cout << "\n=====================================\n";
    std::vector<Item<double>> vec {};
    vec.push_back(Item<double> ("Larry", 100.0));
    vec.push_back(Item<double> ("Moe", 200.0));
    vec.push_back(Item<double> ("Curly", 300.0));

    for(const auto &item:vec){
        std::cout << item.get_name() << " " << item.get_value() << std::endl;    
    }
    
    std::cout << "\n=====================================\n";
    My_Pair <std::string, int> p1 {"Frank", 100};
    My_Pair <int, double> p2 {124, 13.6};

    std::cout << p1.first << ", " << p1.second << std::endl;
    std::cout << p2.first << ", " << p2.second << std::endl;
    return 0;
}