/***
 * [Inline Functions]
 *  //Need to create an activation record , push it on the stack deal with parameters, pop off the activation record when the function terminates and deal with the return addresses  and return values
 *   
 * Functions calls have a certain amount of overhead
 * You saw what happens on the call stack
 * Sometimes we have simple functions
 * 
 * We can suggest to the compiler to compile them 'inline'
 *  avoid function call overhead
 *  generate inline assembly code // Inline code is basically inline assembly code that avoids the function call overhead
 *  faster // if inline a function many times, then you're duplicating function code in many places and it could lead to larger binaries
 *  could cause code bloat
 * 
 * Compilers optimization are very sophisticated
 *  will likely inline even without your suggestion
 * 
 * [Example]
 * inline int add_numbers(int a, int b){
 *  return a + b;
 * }
 * 
 * int main(){
 *  int result = 0;
 *  result = add_numbers(100,200);
 *  return 0;
 * }
 * ***/