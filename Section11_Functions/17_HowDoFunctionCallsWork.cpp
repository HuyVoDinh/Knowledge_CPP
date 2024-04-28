/***
 * [How do Function Calls Work?]
 * Functions use the 'function call stack' 
 *  Analogous to a stack of books => A stack is analogous to a stack of books or a stack of dishes. if place a book on top of the stack, then you must remove that book before removing any others
 *  LIFO - Last In First Out
 *  push and pop
 * 
 * Stack Frame or Activation Record
 *  Functions must return control to function that called it
 *  Each time a function is called we create we create an new activation record and push it on stack
 *  When a function terminates we pop the activation record and return
 *  Local variables and function parameters are allocated on the stack
 * 
 * Stack size is finite - Stack Overflow
 * 
 * [Memory]
 * It's devided into segments
 * Code area: this is where the code resides
 * Static: An area for static variables or for global variables
 * Heap, free store: pointers and dynamic memory allocation
 * 17_1.png
 * ***/

#include <iostream>

using namespace std;

void func2(int &x, int y, int z){
    x += y + z;
}

int func1(int a, int b){
    int result {};
    result = a + b;
    func2(result, a, b);
    return result;
}

int main(){
    int x = 10;
    int y = 20;
    int z {};
    z = func1(x,y);
    cout << z << endl;
    //17_2.png
    return 0;
}

/***
 * What typically happens when main calls func1 (or any function calls another)?
 * There are other ways to achieve the same results
 * 
 * main:
 *  push space for the return value
 *  push space for the parameters
 *  push the return address
 *  transfer control to func1(imp)
 * func1:
 *  push the address of the previous activation record
 *  push any register values that will need to be restored before returning to the caller
 *  perform the code in func1
 *  restore the register values
 *  restore the previous activation record (move the stack pointer)
 *  store any function result
 *  transfer control to the return address (imp)
 * main:
 *  pop the parameters
 *  pop the return value
 * ***/
