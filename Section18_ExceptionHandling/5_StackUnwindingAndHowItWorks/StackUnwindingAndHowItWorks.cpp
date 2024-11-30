/***
 * [Stack unwinding]
 * If an exception is thrown but not caught in the current scope
 * C++ tries to find a handler for the exception by unwinding the stack     => Suppose we have a function and it throws an exception. If the function doesn't handled its own exception , then the function terminates and it's removed from the call stack. 
 *                                                                          Then C++ looks at the call stack to determine the function that's now at the top since that function must have called the function that just terminated. 
 * 
 *  Function in which the exception was not caught terminates and is removed from the call stack
 * 
 *  If a try block was used to then catch blocks are checked for a match        => If one is found, it fires, and we keep processing. 
 * 
 *  If no try block was used or the catch handler doesn't match stack unwinding occurs again        => If there is no try block or there is a try block but it doesn't have a catch handler that matches,  then the function is removed from the call stack and the process repeats. The is called stack unwinding.
 * 
 *  If the stack is unwound back to main an no catch handler handles the exception the program terminates       => If get to the main function and the exception isn't handled there either, then the program terminates since the exception was not handled. Remember, what happens when a function is removed or pooped from the stack all of its local variables are destroyed. This means that for local objects their destructors are called. If we have to free memory with delete, then these statements may not execute at all, and we will leak memory. This makes it critical that you implement classes that require resources as RAII classes. 
 * ***/

#include <iostream>
using namespace std;

void func_a();
void func_b();
void func_c();

void func_a(){
    std::cout << "Starting func_a\n";
    func_b();
    std::cout << "Ending func_a\n";
}

void func_b(){
    std::cout << "Starting func_b\n";
    try{
        func_c();
    } catch (int &ex) // Example 3
    {
        std::cout << "Caught error in func_b\n";
    }
    std::cout << "Ending func_b\n";
}

void func_c(){
    std::cout << "Starting func_c\n";
    throw 100; // Example 2
    std::cout << "Ending func_c\n";
}

int main(){
    cout << "Starting main\n";
    try{
        func_a();
    } catch (int &ex){  //Example 2
        std::cout << "Caught error in main.\n";
    }
    cout << "Finishing main\n";


    return 0;
}

/***
 * <Section18_StackUnwindingAndHowItWorks1.cpp> => This is normal flow, no exception handling and no exception and no problems at all.
 * All this happens in the stack. All the function calls happen on the stack. 
 * got main on the stack. So main is activated on the stack. Print out starting main, and then call function a.
 * Function a gets pushed on the stack and displays starting function a. Then it calls function b
 * Function b gets pushed on the stack and displays starting function b. It calls function c. 
 * Function c is put on the stack, so can see it's real nice orderly process of function calling. It displays starting function c then displays ending function c. It's popped off the stack.
 * B completes not, and says ending function b and it's popped off the stack, 
 * A saying ending function a. It's popped off the stack, 
 * Finally end up printing finishing main. So each function announces itself and then it says I'm done. 
 * ***/

/***
 * Example 2
 * print out starting main. Then going to try function a. Function a could throw an exception. Call function a, and it prints out starting function a. And it calls function b. 
 * Function b begins displays. Starting function b, it calls function c, which displays starting function c. 
 * Now it throws an exception. This function is now done because it's not catching its own exception. So ending function c will not execute. Will never see this function complete normally because it's being pulled off the stack right now. 
 * We go back to whoever called function c, which was function b. Then gets popped off the stack, This won't execute either. Go back to a. 
 * Because a called b, it doesn't have a catch handler. This won't execute either. Now we finally get back to the main, the main does have a catch handler. This will fire, and our program will finish normally. 
 * But what's happened on the stack is real different. Notice these three functions got ripped off the stack immediately. All its local variables were destroyed, destructors were called if any So you've got to be real careful with your objects here. Make sure that their destructors are correct because they just got called, and they didn't get called as you expected them to be called. 
 * 
 * ***/

/***
 * Example 3
 * Trying function a. Function a could throw an exception or anything called by function a could throw an exception as well. 
 * Calling function a. It says starting function a and it calls function b. 
 * Function b displays starting function b, and it tries to execute function c. So what's going to happen here is function c executes, and it throws an exception. 
 * This is not execute, function c is now gone. Function b is handling the exception. function b print caught error in func_b and ending func_b. 
 * Then function a will all execute normally. Finally finish off our main -> THis is stack unwinding.
 * ***/