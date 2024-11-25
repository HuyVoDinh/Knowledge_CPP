/***
 * [Smart Pointer]
 * unique_ptr
 * 
 * Simple smart pointer - very efficient! => it can be a drop in replacement in many cases for your typical pointer use case where you allocate storage use it and then free in the same block.
 * 
 * unique_ptr<T>    => A unique pointer declaration uses a template parameter which is the type of the object that the smart pointer will manage on the heap. 
 *  Points to an object of type T on the heap
 *  It is unique - there can only be one unique_ptr<T> pointing to the object on the heap
 *  Owns what it points to
 *  Cannot be assigned or copied
 *  CAN be moved        => So they're great for placing in standard template library containers such as vectors. And since the ownership is unique, you're guaranteed that when the pointer goes out of scope, the object that it points to will automatically be cleaned up from the heap. 
 *  When the pointer is destroyed, what it points to is automatically destroyed
 * 
 * unique_ptr - creating, initializing and using
 * 
 * {
 *      std::unique_ptr<int> p1 {new int {100}};        //create on the heap and
 *      std::cout << *p1 << std::endl;      //100
 *      *p1 = 200;
 *      std::cout << *p1 << std::endl;      //200
 * }//automatically deleted         => when p1 goes out of scope, the int on the heap will be de-allocated. Don't need to call delete with the smart pointer. Now as far as using the pointer, the syntax is pretty much like using a raw pointer. 
 *                                      It's also possible to create a raw pointer variable and then initialize the unique pointer variable using that raw pointer. But it's not good practice to do since you're referring to an object on the heap from a smart pointer and from a raw pointer, not something you typically want. 
 * 
 * unique-ptr - some other useful methods
 * 
 * {
 *      std::unique_ptr<int> p1 {new int {100}};
 *      std::cout << p1.get() << std::endl; //0x564388
 * 
 *      p1.reset();     // p1 is now nullptr
 *      if(p1)
 *          std::cout << *p1 << std::endl;      //won't execute
 * }// automatically deleted
 * 
 * unique-ptr - user defined classes
 * {
 *      std::unique_ptr<Account> p1 {new Account {"Larry"}};            //=> It will manage an account object on the heap.
 *      std::cout << *p1 << std::endl;      //display account
 * 
 *      p1->deposit(1000);
 *      p1->withdraw(500);
 * }// automatically deleted
 * 
 * unique-ptr - vectors and move        => Unique pointer can't be copied or assigned
 * {
 *      std::vector<std::unique_ptr<int>> vec;
 *      std::unique_ptr<int> ptr {new int{100}};
 * 
 *      vec.push_back(ptr);         // Error - copy not allowed => because that implies a copy of the object. 
 *      vec.push_back(std::move(ptr));      // can use move semantics to move the pointer. The vector now owns the pointer, and ptr will be set to null pointers.
 * }// automatically deleted
 * 
 * unique_ptr - make_unique(C++14)  => This function returns a unique pointer of the specified type, and it allows us to pass initialization values into the constructor for the manager object.
 * 
 * {
 *      std::unique_ptr<int> p1 = make_unique<int>(100);        => don't use the new keyword
 *      std::unique_ptr<Account> p2 =  make_unique<Account>("Curly",5000);      => don't use the new keyword
 *      auto p3 = make_unique<Player>("Hero", 100, 100);
 * }// automatically deleted
 * ***/

#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

class Test{
    private:
        int data;
    public:
        Test() : data {0} {std::cout << "Test constructor(" << data<< ")" << std::endl;}
        Test(int data) : data {data} {std::cout << "Test constructor(" << data<< ")" << std::endl;}
        int get_data() const {return data;}
        ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl;}
};

using namespace std;

int main() {
    // Test *t1  = new Test{1000};     //If don't delete it, it's going to leak memory. Test constructor called but the destructor was never called.

    // delete t1;

    std::unique_ptr<Test> t1 {new Test {1000}};     //THere's no delete t1 necessary. Destructor will be called automatically
    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);        //make unique function can make any kind of unique pointer.
    // -> Now we have two unique pointers, both on the stack, both will be constructed and they go out of scope, the heap memory that they point to will be destroyed automatically. So we don't have to call delete. 

    std::unique_ptr<Test> t3;
    //t3 = t1;        // the error, use of the delete function. It's a long-winded error basically telling you that operator. It's kind of telling you that operator equal has been deleted. You don't have access to it. It won't let you because you're not allowed to copy or assign unique pointers.
    t3 = std::move(t1);
    if(!t1)
        std::cout << "t1 is nullptr\n";     //t1 is nullptr because when move the ownership from t1 to t3, t3 now owns that object. T1 is now null. It can't own the object because we're not sharing ownership.
    
    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;
    //create some accounts and they'll on the heap because we've got pointers to them.
    accounts.push_back(make_unique<Checking_Account>("James", 1000));
    accounts.push_back(make_unique<Savings_Account>("Billy", 4000,5.2));
    accounts.push_back(make_unique<Trust_Account>("James", 5000,4.5));

    // for(auto &acc : accounts)        //=> when try to compile this,going to get an error. And the problem is this is doing copy. We're copying each of those unique_pointers that's in the account vector. But we can't we're not allowed to copy unique pointers.So we have to do this by reference. And it's even better if we do it by const reference.
    for(const auto &acc : accounts)     
        std::cout << *acc << std::endl;
    // notice that we didn't do a single delete. Memories being cleared up automatically for us. If we really wanted to see those destructors called, we can go into our account classes and just change destructor from the default instructor to actually just put some code in destructor
    return 0;
}