#include "20_Dog.h"

Dog::Dog (const Dog &dog) : name {dog.name}, age {dog.age} {
            cout << "Copy Constructor";
        }
