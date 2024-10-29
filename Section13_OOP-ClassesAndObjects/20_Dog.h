#ifndef __DOG_H__
#define __DOG_H__
#include <string>
#include <iostream>

using namespace std;

class Dog{
    private:
        string name;
        int age;
    public:
        Dog(string name, int age) : name{name}, age{age} {}

        //Write your copy constructor below this line
        Dog (const Dog &dog);
        //Write your copy constructor above this line
        string get_name() {return name;}
        void set_name(string n) {name = n;}
        int get_age() {return age;}
        void set_age(int a) {age = a;}
        int get_dog_years() {return age*7;}
        string speak() {return "Woof";}
};
Dog::Dog (const Dog &dog) : name {dog.name}, age {dog.age} {
            cout << "Copy Constructor";
        }

#endif