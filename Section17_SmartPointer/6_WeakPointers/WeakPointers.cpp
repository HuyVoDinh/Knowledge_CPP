/***
 * [Smart pointer]
 * weak_ptr
 * 
 * Provides a non-owning "weak" reference
 * 
 * weak_ptr<T> 
 *  Points to an object of type T on the heap
 *  Does not participate in owning relationship
 *  Always created from a shared_ptr
 *  Does NOT increment or decrement reference use count     => Weak pointers don't affect the lifetime of the objects they're pointing to
 *  Used to prevent strong reference cycles which could prevent objects from being deleted.  // => Another use case is when we have a pointer that we use to temporarily reference another object, something like an iterator pointer that traverses a list of nodes. It really doesn't own them, just visits them temporarily.
 * 
 * weak_ptr - circular or cyclic reference
 * => Sometimes when design programs we may have two classes where each class refers to the other. This implies a ont-to-one relationship between the classes, and this will be reflected in the class objects when we instantiate them. 
 * In this case, have two objects A and B, which were instantiated from two different classes. Notice that A has a shared pointer to B, and B has a shared pointer to A. 
 * Problem: When they go out of scope, they'll be destroyed from the stack, but their shared resources on the heap will not be destroyed and will leak memory.  A keeps B alive, and B keeps A alive. This is exactly where the weak pointer comes in.
 * 
 * A refers to B
 * B refers to A
 * Shared strong ownership prevents heap deallocation
 * <Section17_WeakPointers1.png>  
 * 
 * Solution: Make one of the pointers non-owning or 'weak'
 * Now heap storage is deallocated properly
 * 
 * A owns B. Then replace the shared pointer in B with a weak pointer. And now everything works as expected, and we don't leak memory. 
 * <Section17_WeakPointers2.png>
 * ***/

#include <iostream>
#include <memory>

using namespace std;


//got an A referencing a B and a B referencing an A, and got that strong circular reference that we can't break. 
// First of all, class A has a shared pointer to a B. Now since we haven't seen the B yet, need to put this forward declaration. Not sure if we've done that in class before or not. But since the compiler needs to know about a B, we're just simply saying you know what compiler, I've got a class B, I'll declare it later, just assume it's here.
// It's similar to a function prototype in a sense that just tells the compiler don't worry about it.
// Class A has a shared pointer to a B. and set method that just sets that pointer.
// It's got a real simple constructor and destructor that just simply display when they're called,so we can see them actually being called.

// In class B is defined down. And the class B has a shared pointer to an A. So there's that relationship between the two. So when A owns a B and a B onto A, so that;s the problem.
// Set method that sets that A pointer, 
class B;        // forward declaration

class A{
        std::shared_ptr<B> b_ptr;
    public:
        void set_B(std::shared_ptr<B> &b){
            b_ptr = b;
        }
        A() {cout << "A Constructor\n";}
        ~A() {cout << "A Destructor\n";}
};

class B{
        //std::shared_ptr<A> a_ptr;       // make weak to break the strong circular reference
        std::weak_ptr<A> a_ptr;  
    public:
        void set_A(std::shared_ptr<A> &a){
            a_ptr = a;
        }
        B() {cout << "B Constructor\n";}
        ~B() {cout << "B Destructor\n";}
};

int main(){

    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    // Set the b part of a to b, and set the a part of b to a. That's establishing that circular reference.
    // is pointing to an A object on the heap. B pointing to a B object on the heap. A points to B and B points to A. Now this guy has a reference count of 1 or use count of 1. This guy has a used count of 1. 
    // A goes out of scope, and it tries to destroy this piece here. But it notices that something else is referencing it. So it's not 0. So it's not going to destroy it, same things with b. 
    // So what ends up happening is what actually gets destroyed is a and b that are one the stack. The shared pointers, but not the are on the heap. And there's your memory leak
    // Problem is because of this implied shared ownership. 
    a->set_B(b);
    b->set_A(a);
    //When run, Can see constructed a and b but destructors never got called because leaked the memory. 
    // To fix, be going to make shared pointer a weak pointer. That won't affect the reference count. So now when run this. CAn see the a constructor the b constructor then the a and the b destructure being called. Now are no longer leaking memory. 

    return 0;
}