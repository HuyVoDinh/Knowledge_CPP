/***
 * Inheritance - Bark Dog, Bark!
Coding Challenge: Bark Dog, Bark!

Problem Statement

The Animal base class has been provided for you in the Animal.h header file. This class contains two pure virtual methods:

get_noise(): Returns a string representing the noise that the animal makes.

get_num_legs(): Returns an integer representing the number of legs the animal has.

Additionally, the Animal class contains a constructor that accepts the name and age of the animal, as well as methods to retrieve these properties:

Animal(): A constructor that accepts a string for the name and an integer for the age.

get_name(): Returns the name of the animal.

get_age(): Returns the age of the animal.

Your task is to implement a Dog class that inherits from Animal. The Dog class should have a Dog.h file that contains the Dog class declaration, and a Dog.cpp file for the Dog class implementation.

You need to override the get_noise() and get_num_legs() methods, and provide a constructor for Dog that takes in a name and an age:

get_noise(): Should return the string "Woof".

get_num_legs(): Should return the integer 4.

Dog(): This is the constructor that should accept a string for the name and an integer for the age. It should pass these values to the base class (Animal) constructor.

Input Format

There is no input for this task.

Constraints

The Dog class must inherit from the Animal class, override the required methods, and correctly implement its constructor.

How will I test your Code?

Your program should pass the following tests:

   

     Dog dog{"Spot", 5};
     std::string noise = dog.get_noise(); // Woof
     int legs = dog.get_num_legs();       // 4
     int age = dog.get_age();             // 5
     std::string name = dog.get_name();   // Spot
Your program should also pass the following tests that use a pointer to Dog and a Base class pointer:



    Dog *dog_ptr = new Dog{"Spot", 5};         
    std::string noise = dog_ptr->get_noise();  // Woof
    int legs = dog_ptr->get_num_legs();        // 4
    int age = dog_ptr->get_age();              // 5
    std::string name = dog_ptr->get_name();    // Spot


   

    Animal *animal_ptr = new Dog{"Spot", 5};
    std::string noise = animal_ptr->get_noise();  // Woof
    int legs = animal_ptr->get_num_legs();        // 4
    int age = animal_ptr->get_age();              // 5
    std::string name = animal_ptr->get_name();    // Spot
}


 * 
 * ***/

#include "Dog.h"

// Implement the appropriate Dog class methods below this inline

std::string Dog::get_noise(){
    return "Woof";
}
int Dog::get_num_legs(){
    return 4;
}
// Implement the appropriate Dog class methods above this inline