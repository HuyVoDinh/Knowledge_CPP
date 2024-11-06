/*****
 * [Dynamic memory allocation]
 * 
 * Allocating storage from the heap at runtime
 * 
 * We often don't know how much storage we need until we need it
 * 
 * We can allocate storage for a variable at run time
 * 
 * Recall C++ arrays
 *  We had to explicitly provide the size and it was fixed
 *  But vectors grow and shrink dynamically
 * 
 * We can use pointers to access newly allocated heap storage
 * 
 * using 'new' to allocate storage
 * 
 * int *int_ptr = nullptr;
 * 
 * int_ptr = new int;                                       // allocate an integer on the heap
 * 
 * cout << int_ptr << endl;                                 // 0x2747f28
 * 
 * cout << *int_ptr << endl;                                // 41188048 - garbage
 * 
 * *int_ptr = 100;
 * 
 * cout << *int_ptr << endl;                                // 100
 * 
 * -----
 * Need to release or deallocate the storage
 * using 'delete' to deallocate storage
 * 
 * int *int_ptr = nullptr;
 * 
 * int_ptr = new int;                                       // allocate an integer on the heap
 * 
 * delete int_ptr;                                          // frees the allocated storage
 * 
 * -------
 * 
 * using new[] to allocate storage for an array
 * using delete[] to deallocate storage for an array
 * 
 * int *array_ptr = nullptr;
 * int size {};
 * 
 * cout << "How big do you want the array?\n";
 * cin >> size
 * 
 * array_ptr = new int[size];                       // allocate array on the heap
 * 
 * delete [] array_ptr;                             // free allocated storage
 * --------
 * ****/

#include <iostream>

using namespace std;

int main(){
     //Have a part of memory called the heap, it's also called the free store. All dynamic allocation happens here.  We can't really do dynamic allocation on the stack. It's already doing dynamic allocation when we push and pop activation records. We can't really decide at runtime how bis those things are going to be. We can to a point but not really. The heap is a free-for-all
     // But need to take care of that heap, and need to release the storage when done

    int *int_ptr = nullptr;
    int_ptr = new int;
    cout << int_ptr << endl;
    delete int_ptr;

    size_t size = 0;
    double *temp_ptr = nullptr;

    cout << "How many temps? ";
    cin >> size;
    //while(true) => terminate called after throwing an instance of 'std::bad_alloc' => There was no more more available
        temp_ptr = new double[size];

    delete [] temp_ptr;

    //temp pointer was on the stack, we allocated, let's say 1-- doubles on the heap. Temp pointer is pointing to the first one.
    //In this case, temp pointer was on the stack because it's local to main.
    // If we do something really silly like, don't know, temp pointer equals null pointer, and we do that before we delete this => we just nulled out this pointer , so address is gone , we just lost our only way to get to that storage and that's called the memory leak 
    // What the delete call dose is it frees up this storage again . Your pointer is still pointing to it, and that's important because  if you try to use that pointer again after you've deleted the storage, you could have really, really unpredictable results
    // But in this case, you don't want to lose your pointer to a dynamically allocated memory because then it's basically orphaned out there, and that's the memory leak 


    cout << endl;
    return 0;
}