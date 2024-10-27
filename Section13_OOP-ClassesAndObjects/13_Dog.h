#ifndef __DOG_H__
#define __DOG_H__
#include <string>
using namespace std;

class Dog{
    private:
        string name;
        int age;
    public:
        Dog(){
            name = "None";
            age = 0;
        }
};

#endif