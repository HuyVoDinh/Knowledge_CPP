#ifndef __DOG_H__
#define __DOG_H__
#include <string>
using namespace std;

class Dog {
private:
    string name;
    int age;
public:

//---- WRITE YOUR CLASS FUNCTIONS BELOW THIS LINE----
    void set_name(string n){
        name = n;
    }
    
    string get_name(){
        return name;
    }
    
    void set_age(int a){
        age = a;
    }
    
    int get_age(){
        return age;
    }

//---- WRITE YOUR CLASS FUNCTIONS ABOVE THIS LINE----
};
#endif 
