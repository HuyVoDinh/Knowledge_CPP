/*****
 * [Smart pointer]
 * Custom deleters
 *  Sometimes when we destroy a smart pointer we need more than to just destroy the object on the heap      => Sometimes when we use pointers to see structures from c frameworks, we have to provide a specialized way of destroying them since in many cases they don't have destructors.
 *  
 *  These are special use-cases
 *  
 *  C++ smart pointers allow you to provide custom deleters     => If custom deleters, can't use make shared or make unique when you create your smart pointer objects since we need to provide our custom deleter and these functions don't support that.
 * 
 *  Lost of way to achieve this
 *      Functions
 *      Lambdas
 *      Others
 * 
 * Custom deleters - function   => will be called automatically when the smart pointer will be deleted. This function will be provided with a raw pointer to managed object that the smart pointer is referencing. Then in this function you do whatever you need to do to relinquish your resources.
 * 
 * void my_deleter(Some_Class *raw_pointer){
 *      //your custom deleter code
 *      delete raw_pointer;
 * }
 * 
 * shared_ptr<Some_Class> ptr {new Some_Class{}, my_deleter};
 * 
 * custom deleter - lambde  => a lambda is an anonymous function that is a function that has no name and can be defined in line right where you expect to use it. 
 * 
 * share_ptr<Test> ptr (new Test{100}, [] (Test *ptr){
 *      cout << "\nUsing my custom deleter\n";
 *      delete ptr;
 * });
 * ****/

#include <iostream>
#include <memory>

class Test{
    private:
        int data;
    public:
        Test() : data{0} {std::cout << "\nTest construcotr (" << data << ")" << std::endl;}
        Test(int data) : data {data} {std::cout << "\nTest construcotr (" << data << ")" << std::endl;}
        int get_data() const {return data;}
        ~Test () {{std::cout << "\nTest construcotr (" << data << ")" << std::endl;}}
};

void my_deleter(Test *ptr){
    std::cout << "\tUsing my custom function deleter\n";
    delete ptr; //=> this gets much more complicated when you've got raw pointers to c structures that are used in c frameworks which they don't have destructors. You've really got to manage that memory yourself. And this is a nice way to do it and still be able to use unique pointers and shared pointers
}

int main(){

    {
        //Using a function
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter}; //>test objects on the heap. We have to use new here to do this. We can't use make_shared. When this pointer is deleted and it has to clean up the memory.
    }

    std::cout << "====================\n";
    {
        //Using a Lambda expression
        std::shared_ptr<Test> ptr2 (new Test{100},
            [] (Test *ptr){
                std::cout << "\tUsing my custom lambda deleter\n";
                delete ptr;
            });
    }
    return 0;
}