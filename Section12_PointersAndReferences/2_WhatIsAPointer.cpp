/***
 * [What is a pointer]
 * 
 * A variable 
 *  whose value is an address 
 * 
 * What can be at that address
 *  another variable
 *  a function
 * 
 * Pointer point to variables or functions?
 * 
 * If x is an integer variable and its value is 10 then can declare a pointer that points to it
 * 
 * To use the data that the pointer is pointing to you must know its type
 * 
 * Can't I just use the variable or function itself?
 * 
 * => Yes, but not always
 * 
 * Inside functions, pointers can be used to access data that are defined outside the function. Those variables may not be in scope so you can't access them by their name
 * 
 * Pointers can be used to operate on arrays very efficiently
 * 
 * We can allocate memory dynamically on the heap or free store
 *  This memory doesn't even have a variable name
 *  The only way to get to it is via a pointer
 * 
 * With OO. pointers are how polymorphism works!
 * 
 * Can access specific addresses in memory
 *  useful in embedded and systems applications
 * 
 * [Declaring Pointers]
 * 
 *              variable_type *pointer_name;
 * 
 *              int *int_ptr;
 *              double *double_ptr;
 *              char *char_ptr;
 *              string *string_ptr;
 * 
 * Initializing pointer variables to 'point nowhere'
 * 
 *              variable_type *pointer_name {null_ptr};
 * 
 *              int *int_ptr {};
 *              double *double_ptr {nullptr};
 *              char *char_ptr {nullptr};
 *              string *string_ptr {nullptr};
 * 
 * => If don't initialize a pointer variable, it will have garbage data.
 * In this case, that garbage data represents an address since that's what a pointer contains.
 * So can think of an uninitialized pointer as pointing anywhere. So if use it we could be accessing memory that we have no business messing around with.
 * We don't even know what that memory is initializing pointer variables is just like initializing non-pointer variables
 * 
 * In these examples, we're initializing the pointer variables to zero. that's what null pointer represents this means that we're initializing the pointers to point nowhere
 * We can also initialize pointers to actually point to a variable
 * 
 * [Declaring Pointers]
 * 
 * Initializing pointer variables to 'point nowhere'
 * 
 *  Always initialize pointers
 *  Uninitialized pointers contain garbage data and can 'point anywhere'
 *  Initializing to zero or nullptr (C++ 11) represents address zero
 *      Implies that the pointer is 'pointing nowhere'
 *  If you don't initialize a pointer to point to a variable or function the you should initialize it to nullptr to 'make it null'
 * ***/

