/***
 * [Shallow vs. Deep Copying]
 * 
 * Consider a class that contains a pointer as a data member
 * Constructor allocates storage dynamically and initializes the pointer
 * Destructor releases the memory allocated by the constructor
 * What happens in the default copy constructor?
 * 
 * [Default copy constructor]
 * 
 * member-wise copy => A shallow copy is the default behavior provided by the compiler generated copy constructor. It basically does member-wise copying of all the object attributes.
 * Each data member is copied from the source object => you end up with the newly created objects and the object being copied both pointing to the same area of storage in the heap.
 * The pointer is copied NOT what it points to (shallow copy)
 * 
 * Problem: when we release the storage in the destructor, the other object still refers to the released storage => When destroyed happens, the object;s destructor releases the memory allocated on the heap as it should. However, the other object is still pointing to this released area and thinks the area is still valid. This could lead t o subtle errors. The best thing that can happen is that the program crashes while in development so that you can fix the error.
 * 
 * [Copy constructor]
 * 
 * class Shallow {
 *  private:
 *      int *data;                                      //POINTER
 *  public: 
 *      Shallow(int d);                                 // Constructor
 *      Shallow(const Shallow &source)                  // Copy
 *  Constructor
 *      ~Shallow();                                     // Destructor
 * }
 * 
 * Shallow::Shallow(int d){
 *      data = new int;
 *          *data = d;
 * }
 * 
 * Shallow::~Shallow(){
 *      delete data;                                    // free storage
 *      cout << "Destructor freeing data" << endl;
 * }
 * 
 * Shallow::Shallow(const Shallow &source) : data(source.data) {
 *      cout << "Copy constructor - shallow" << endl;
 * }
 * 
 * //Shallow copy - only the pointer is copied (member-wise copy) - not what it is pointing to!
 * Problem: source and the newly created object BOTH point to the SAME data area and heap that was allocated for the data.
 * Problem comes into play when we make a copy of a shallow object using the copy constructor that's doing a shallow copy. Suppose we have a function display shallow that expects a shallow object by copy.
 * We make the copy with the copy constructor as usual, but when that local objects goes out of scope its destructor is called, and the destructor releases the storage in the heap thats is pointing
 * => The object that was copied into this function still points to this released storage, but it thinks that the storage is valid.
 * 
 * int main(){
 *      Shallow obj1 {100};                 => Obj1 will be created and an integer will be allocated on the heap and 100 stored in it.
 *      display_shallow(obj1);              => A copy of obj1 will be created inside that function. When function is done, the copy of obj1 will be destroyed. Since obj1 and the copy that was just destroyed pointed to the same memory area. obj1 now points to invalid storage. If we try to access that storage from obj1, our program could crash. Also when the destructor for obj1 eventually gets called. It will try to release memory that's no longer valid and will probably crash.
 *      // obj1's data has been released!
 * 
 *      obj1.set_data_value(1000);
 *      Shallow obj2 {obj1};
 *      cout << "Hello world" << endl;
 *      return 0;
 * }
 * ****/

#include <iostream>
using namespace std;

class Shallow {
    private:
        int *data;  // => Git a raw pointer here to a single integer. 
    public: 
        void set_data_value(int d) {*data = d;}
        int get_data_value() {return *data;}
        //Constructor
        Shallow(int d);
        // Copy constructor
        Shallow(const Shallow &source);
        //Destructor
        ~Shallow();
};

Shallow::Shallow(int d){
    data = new int; // => It allocates storage on the heap dynamically for that one integer. ANd the integer is d. It's being passed in. 2: Allocate the new integer on the heap. Storing 100 into that area.
    *data = d;      // => De-referencing the pointer and storing that integer where data's pointing.
}

Shallow::Shallow(const Shallow &source) : data(source.data){ // in this constructor initialization list, all copying the value in that data variable which is the pointer from source to this, which is the object creating right now so. It's copying the pointer not what it's pointing to
    cout << "Copy constructor - shallow copy\n"; // 5. We've got source. source is what;s being passed in so source in this case is obj1. Made copy of obj1 but didn't copy what it;s pointing to, only copied the data. You can see that the address of that pointer data is exactly the same. That's pointing to the same area in memory.
}

Shallow::~Shallow(){ //8. Get the destructor called, and the destructor deletes data. It freed up this area in memory. So as far as the C+ runtime system is concerned, this is no longer valid memory. And deleted it.
    delete data; 
    cout << "Destructor freeing data\n";
}

void display_shallow(Shallow s){ //6 s has a pointer called data. It's pointing to the same area in memory as obj1. But we didn't make a copy what that data pointer was pointing to. What we would want with a deep copy is for s to be pointing. It's pointing to exactly the same memory location.
    cout << s.get_data_value() << endl; //4: this is just a regular function, not a member function. And going to pass obj1 into it. We're doing that by value. You can see right here there's no pointer, there's no reference. It's just by value, so we need to make a copy.
}
//7. s go out of scope.

int main(){
    Shallow obj1 {100}; // 1: Just doing a regular constructor call.
    display_shallow(obj1); // 3: This is where deep copy is necessary rather than the shallow copy, and I'll do another video after this where we'll do a deep copy
    // 9. obj1 pointing to invalid memory. At this point, this is now gone right because we ware all that's been cleaned off the stack. 
    //10. We has a pointer called data. that's pointing to an area on the heap that has 100 in it because that hasn't changed but that memory is invalid. So now if we try to make a copy of obj1 and call it obj2 again, this calls the copy constructor again. So now we've got two objects pointing to invalid data.
    Shallow obj2 {obj1}; // 11. obj2 pointing to that same invalid data. obj1 and obj2 are pointing to exactly the same memory locations.
    obj2.set_data_value(1000); //12.Setting the data value for obj2 to 1000. I just changed obj1's and obj2's data to 1000 indirectly without even knowing it because they're both pointing to the same area in memory.
    //13. both pointing the the same area in memory. it changed to a 1000. we're pointing to the same area in memory.

    return 0;
}
//14.start freeing up these two objects. They're going out of scope. So need to delete the data for both of them. We're calling both the destructors. That pointer is pointing to invalid data. When we try to delete it, the crash comes in.
// what's going on with your heap memory when you're using raw pointers. 