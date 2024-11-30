/***
 * [Smart Pointer]
 * shared_ptr
 * 
 * Provides shared ownership of heap objects
 * 
 * shared_ptr<T> 
 *  Points to an object of type T on the heap
 *  It is not unique - there can many shared_ptr pointing to the same object on the heap. => So we can have one heap object referenced by multiple shared pointers that manage it.
 *  Establishes shared ownership relationship
 *  CAN be assigned and copied
 *  CAN be moved
 *  Doesn't support managing arrays by default      => We can have multiple shared pointers all referencing the same heap object, so how do we know when that object needs to be destroyed. There are different ways that this can be accomplished. THe most common technique is to use reference counting. Every time we instantiate a shared pointer object and have it point or reference to the heap object, we increment the counter. The counter simply has the number of shared pointers referencing that heap object. When the reference count becomes 0, then we know nothing is referring to the heap object, and it can be safely destroyed. 
 *  When the use count is zero, the managed object ton the heap is destroyed.
 * 
 * share_ptr - creating, initializing and using
 * 
 * {//in this case, since we only have one shared pointer referencing the integer on the heap, when p1 goes out of scope, the integer will be de-al;located from the heap.
 *      std:share_ptr<int> p1 {new int {100}};
 *      std::cout << *p1 << std::endl;      // 100
 * 
 *      *p1 = 200;
 *      std::cout << *p1 << std::endl;      // 200
 * }//automatically deleted
 * 
 * shared_ptr - some other useful methods
 * 
 * {
 *      //use_count - the number of shared_ptr objects managing the heap object
 *      std::shared_ptr<int> p1 {new int {100}};
 *      std::cout << p1.use_count() << std::endl;           //1
 * 
 *      std::shared_ptr<int> p2 {p1};                       //shared ownership
 *      std::cout << p1.use_count() << std::endl;           //2
 * 
 *      p1.reset();     //decrement the use_count; p1 is null out  => because reset p1 doesn't mean that de-allocate the integer on the heap. we can't in this case because p2 is still referring to it. 
 *      std::cout << p1.use_count() << std::endl;           //0
 *      std::cout << p2.use_count() << std::endl;           //1
 * }//automatically deleted
 * 
 * shared_ptr - user defined classes
 * shared_pointers also allow us to point to user-defined types. Declare account as the template argument in the shared pointer declaration. 
 * {
 *      std::shared_ptr<Account> p1 {new Account {"Larry"}};
 *      std::cout << *p1 << std::endl;      //display account
 * 
 *      p1->deposit(1000);
 *      p1->withdraw(500);
 * }//automatically deleted
 * 
 * shared_ptr - vectors and move
 * 
 * {
 *      std::vector<std::shared_ptr<int>> vec;
 *      std::shared_ptr<int> ptr {new int {100}};
 *      vec.push_back(ptr);         // OK - copy IS allowed     //shared_pointer can be copied, assigned and moved.
 *      std::cout << ptr.use_count() << std::endl;      //2
 * }//automatically deleted
 * 
 * shared_ptr - make_shared(C++11)
 * The make shared function returns a shared pointer of the specified type and it allows us to pass initialization values into the constructor for the managed object. 
 * This is the preferred way to create shared pointers. Not only do we not have to use the new keyword, but the compiler will generate much more efficient code since remember, the compiler has to generate a data structure that holds information about the reference count, the raw pointer, the actual heap object and other data as well.
 * So this creates all of this in one shot when the pointer is initialized.
 * {
 *      std::shared_ptr<int> p1 = std::make_shared<int>(100);   // use_count: 1
 *      std::shared_ptr<int> p2 {p1};                           // use_count: 2
 *      // the same integer on the heap and its use count will be 2
 *      std::shared_ptr<int> p3;                                
 *      p3 = p1;                                                // use_count: 3
 *      //The third pointer p3 is initalized as empty. So it doesn't point to any share object yet, but it is initialized, it's null. So there's no chance that we can haver an uninitialized or a wild pointer when we use smart pointers. Then we assign p1 to p3. Now p1 also refers to the shared integer, and our use count increases to 3.
 *      //All three pointers now go out of scope, which shared pointer is responsible for cleaning up the heap storage? It's the last one that references it. In this case, it will be p1 since p2 and p3 will be destroyed before p1, but the point is that you don't have to worry about it. 
 * }//automatically deleted
 * 
 * Use std::make_shared - it's more efficient!
 * All 3 pointers point to the SAME object on the heap!
 * When the use_count becomes 0 the heap object is deallocated
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

void func(std::shared_ptr<Test> p){
    std::cout << "Use count: " << p.use_count() << std::endl;
}

int main(){

    //use_count - the number of shared_ptr objects
    //managing the heap object

    std::shared_ptr<int> p1 {new int {100}};
    std::cout << "Use count: " << p1.use_count() << std::endl;       // 1

    std::shared_ptr<int> p2 {p1};       //shared ownwership     // p1 and p2 are both referring to that same storage. They both have a reference count of 2. p1 and p2 are managing that same area in memory. They have co-ownership
    std::cout << "Use count: " << p1.use_count() << std::endl;       // 2

    p1.reset();     //decrement the use_count; p1 is nulled out     
    std::cout << "Use count: " << p1.use_count() << std::endl;       // 0       // p1 point nowhere. So be going to have that set to null pointer
    std::cout << "Use count: " << p2.use_count() << std::endl;       // 1       // p2's reference count will go down by 1 because now p2 is only shared pointer that owns that memory.


    std::cout << "\n======================================\n";
    std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
    func(ptr);
    std::cout << "Use count: " << ptr.use_count() << std::endl;
    {
        std::shared_ptr<Test> ptr1 = ptr;
        std::cout << "Use count: " << ptr.use_count() << std::endl;
        {
            std::shared_ptr<Test> ptr2 = ptr;
            std::cout << "Use count: " << ptr.use_count() << std::endl;
            ptr.reset();
            // ptr will be nulled out, which means that will become null, and then the reference count for the other two pointers ptr1 and ptr2 will go down to 2 since now there's one less shared pointer.
        }
        //Now it's not referring to any managed object.
        std::cout << "Use count: " << ptr.use_count() << std::endl;
    }
    
    std::cout << "\n======================================\n";
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 1000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Trust_Account>("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Trust_Account>("Curly", 6000);

    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);

    for(const auto & acc : accounts){
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl;
    }
    return 0;
}