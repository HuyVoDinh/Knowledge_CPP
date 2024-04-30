/****
 * [Passing pointers to a function]
 * We dont have tyo use const at all. In this case, have a pointer just as we've been using up to this point. We can change the data the pointer is pointing to, and we can change the pointer itself and make it point somewhere else
 * 
 * 
 * const and Pointers
 * 
 * There are several ways to qualify pointers using const => The const qualifier gives us more fine-grained control of what we allow to be changed
 *  Pointers to constants
 *  Constant pointers 
 *  Constant pointers to constants
 * 
 * [Pointers to constants]
 * 
 * The data pointed to by the pointers is constant and cannot be changed
 * 
 * The pointer itself can change and point somewhere else
 * 
 * int high_score = 100;
 * int low_score = 65;
 * 
 * const int score_ptr = &high_score;
 * 
 * *score_ptr = 86;         // ERROR
 * score_ptr = &low_score;  // OK
 * ==> We're free to assign another address to the pointer and have it point somewhere else as we do in the last assignment statement
 * 
 * =========
 *  * The data pointed to by the pointers is constant and can be changed
 * 
 * The pointer itself cannot change and point somewhere else
 * 
 * int high_score = 100;
 * int low_score = 65;
 * 
 * int *const score_ptr = &high_score;
 * 
 * *score_ptr = 86;         // OK
 * score_ptr = &low_score;  // ERROR
 * 
 * 
 * =========
 * The data pointed to by the pointers is constant and cannot be changed
 * 
 * The pointer itself cannot change and point somewhere else
 * 
 * int high_score = 100;
 * int low_score = 65;
 * 
 * const int *const score_ptr = &high_score;
 * 
 * *score_ptr = 86;         // ERROR
 * score_ptr = &low_score;  // ERROR
 * ***/

