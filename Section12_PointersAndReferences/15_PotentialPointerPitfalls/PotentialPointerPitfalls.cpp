/***
 * [Potential Pointer Pitfalls]
 * 
 * Uninitialized pointers
 * Dangling Pointers
 * Not checking if new failed to allocate memory
 * Leaking memory
 * 
 * 
 * [Uninitialized pointers]
 * Uninitialized pointers contain garbage, which means they could point anywhere.
 * If we try to access or modify the data there're pointing to, we could run into some major problems
 * The pointer might be pointing to a very important area in memory, and we could wipe it out.
 * 
 * Modern operating systems today are pretty good at protecting critical areas of system memory, but you could still trash an area  important to your program that could cause your program to crash
 * Worst-case scenario is that the program continues to work as expected for a long time since the memory access isn't used 
 * Then an update to your program later on changes everything, and all of a sudden the program is crashing
 * 
 * You think it's because of the new change, but it's actually a bug that's been in the code for a long time 
 * 
 * In the old days of computing it wasn't uncommon to corrupt data on storage devices by using uninitialized pointers 
 * 
 * int *int_ptr;                    // pointing anywhere
 * *int_ptr = 100;                  // Hopefully a crash
 * 
 * 
 * [Dangling pointer]
 * 
 * Pointer that is pointing to released memory 
 *  For example, 2 pointers point to the same data
 *  1 pointer releases the data with delete
 *  The other pointer accesses the release data
 * 
 * Pointer that points to memory that is invalid
 *  We saw this when we returned a pointer to a function local variable
 * 
 * [Not checking if new failed]
 * 
 * If new fails an exception is thrown
 * We can use exception handling to catch exceptions
 * Dereferencing a null pointer will cause your program to crash
 * 
 * [Leaking memory]
 * 
 * Forgetting to release allocated memory with delete
 * If you lose your pointer to the storage allocated on the heap you have not way to get to that storage again
 * The memory is orphaned or leaked
 * One of the most common pointer problems
 * ***/