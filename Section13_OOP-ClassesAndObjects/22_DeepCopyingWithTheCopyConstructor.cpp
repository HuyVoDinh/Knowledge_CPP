/****
 * [User-provided copy constructor]
 * Create a copy of the pointed-to data => It copy the data pointed to by the pointer.
 * Each copy will have a pointer to unique storage in the heap => have to allocated storage the copied data and then perform the copy. Each object will have a pointer to unique storage in the heap and both areas will contain the same data.
 * Deep copy when you have a raw pointer as a class data member
 * 
 * [Copy Constructor]
 * class Deep {
 *      private:
 *          int *data;                      // POINTER => raw c++ pointer that points to a single integer
 *      public:
 *          Deep (int d);                   // Constructor => This class has a constructor that expects an integer a copy constructor and a destructor as before.
 *          Deep (const Deep &source);      // Copy Constructor
 *          ~Deep();                        //Destructor
 * };
 * 
 * Deep::Deep(int d){
 *      data = new int;                     //allocate storage => The constructor allocates storages for the integer and then stores the passed in integer d into where that data pointer is pointing. Since we allocated the storage dynamically
 *      *data = d;
 * }
 * 
 * Deep::~Deep(){
 *      delete data;                        // free storage => It frees the data that was allocated by the constructor
 *      cout << "Destructor freeing data" << endl;
 * }
 * 
 * Deep::Deep(const Deep &source){
 *      data = new int;                     // allocate storage
 *      *data = *source.data;
 *      cout << "Copy constructor - deep" << endl;
 * }
 * 
 * Deep copy - create new storage and copy values. => Don't simply copy the pointer. Instead, we allocate storage for the copy of what we're pointing to and then copy the data itself over. Creating a new integer and then we're copying what the source data pointer is pointing to which is an integer into our newly created area on the heap.
 * We have an exact unique copy of the original heap storage in each object.
 * 
 * Deep copy constructor - delegating constructor
 * => Since we can also delegate object construction from a copy constructor to another constructor within the same class
 * Notice that we're delegating to the constructor that expects an integer and the integer we're passing in is the one pointed to by data. Now we've made a deep copy of that data pointer.
 * Both source and the newly created object each have an exact unique copy of the original heap storage.
 * Deep::Deep(const Deep &source) : Deep {*source.data}{
 *      cout << "Copy constructor - deep" << endl;
 * }
 * 
 * Delegate to Deep (int) and pass in the int (*source.data) source is pointing to.
 * 
 * Deep-a simple method that expects a copy
 * void display_deep(Deep s){
 *      cout << s.get_data_value() << endl;
 * }
 * When s goes out of scope the destructor is called and releases data.  
 * No problem: since the storage being releases is unique to s.
 * 
 * int main(){
 *      Deep obj1 {100};
 *      display_deep(obj1);
 * 
 *      obj1.set_data_value(1000);
 *      Deep obj2 {obj1};
 * 
 *      return 0;
 * }
 * There won't be any crashes and no problems because the copy constructor is doing a deep copy and we're responsibly handling memory.
 * ***/

#include <iostream>

using namespace std;

class Deep {
    private:
        int *data;
    public:
        void set_data_value(int d) {*data = d;}
        int get_data_value() {return *data;}
        //Constructor
        Deep(int d);
        //Copy constructor
        Deep(const Deep&source);
        //Destructor
        ~Deep();
};

Deep::Deep (int d){
    data = new int;         // Creating integer on the heap and storing the 100 into it.// 7. Creating storage and we're copying that data into it.
    *data = d;
}

Deep::Deep(const Deep &source) : Deep {*source.data}{       // 6. The copy constructor is going to delegate construction to our regular constructor. That just expects a single integer.. 13. We're going to delegate construction to our regular constructor. The data gets written over
    cout << "Copy constructor - deep copy\n";               // 8. Comeback to copy constructor and display message.
}

Deep::~Deep(){  
    delete data;//10. Destructor is being called. and be going to free up s object. It just freed the data
    cout << "Destructor freeing data\n";
}

void display_deep(Deep s){  //5. Call display_deep. This is regular function, not a member function. Passing in a deep obj into it by value. So we need to make a copy of it. When s will be a copy of obj1. In order to get the copy, we need to execute the copy constructor.
    cout << s.get_data_value() << endl; //9. display message. That integer contains 100. We've got two different areas in the heap. So each one of these is pointing to a unique area. This is really what deep copy is all about because what's going to happen in a second. When finish this function, we need to clean up s. It's going out of scope So the destructor for s is going to get called and it's going to free up this area in memory. It not messing with obj1's area.
}

int main(){
    Deep obj1 {100};            //1. Create obj1. This is a regular simple instantiation with the constructor. 3. Obj1 got a pointer called data and it's pointing to an integer on the heap, that's 100/
    display_deep(obj1);         //4. obj1 at this point has been created. 
    //11. Obj1 still pointing to valid data. At this point, this has been taken off the stack. It's all been cleaned up.

    Deep obj2 {obj1};// 12.  Making obj2 a copy of obj1. We expect the copy constructor to be called.
    //14. obj1 and obj2 contain a 100. The addresses completely  different memory addresses for that 100.S
    obj2.set_data_value(1000);//15. So in other words, obj1 has copy of a 100 in its own area. and obj2 has a copy of 1000 in its own area

    return 0;
}
//16. Free up obj1, obj2 and program completes with no crashes at all