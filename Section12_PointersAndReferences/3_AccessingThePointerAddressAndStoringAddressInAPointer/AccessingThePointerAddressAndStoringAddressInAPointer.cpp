/***
 * [Accessing Pointer Address?]
 * 
 * & the address operator
 * 
 * Variables are stored in unique addresses
 * Unary operator
 * Evaluates to the address of its operand
 *  Operand cannot be a constant or expression that evaluates to temp values
 * 
 * int num = 10;
 * 
 * cout << "Value of num is: " << num << endl;                  // 10
 * cout << "sizeof of num is: " << sizeof(num) << endl;         // 4
 * cout << "Address of num is: " << &num << endl;               //0x61ff1c
 * 
 * [Example]
 * 
 * int *p;
 * 
 * cout << "Value of p is: " << p << endl;                      //0x61ff1c  - garbage
 * cout << "Address of p is: " << &p << endl;                   // 0x61ff18
 * cout << "sizeof of p is: " << sizeof(p) << endl;             // 4
 * p = nullptr;                                                 // set p to point nowhere
 * cout << "value of p is: " << p << endl;                      // 0
 * 
 * [sizeof a pointer variable]
 * 
 * Don't confuse the size of a pointer and the size of what it points to
 * All pointers in a program have the same size
 * They may be pointing to very large or very small types
 * 
 *          int *p1 = nullptr;
 *          double *p2 = nullptr;
 *          unsigned long long *p3 = nullptr;
 *          vector<string> *p4 = nullptr;
 *          string *p5 = nullptr;
 * 
 * [Storing an Address in Pointer Variable?]
 * 
 * Typed pointers
 * 
 * The compiler will make sure that the address stored in a pointer variable is of the correct type
 * 
 * int score = 10;
 * double high_temp = 100.7;
 * 
 * int *score_ptr = nullptr;
 * score_ptr = &score;              // OK   => the compiler is fine with that since score pointer holds addresses of integers and scores an integer
 * score_ptr = &high_temp;          // Compiler Error   => The compiler will get a compiler error. score pointer holds addresses of integers but it store the address of a double, both addresses are four bytes long, so the issue isn't the size won't fit, the issue is that there's a type conflict
 * 
 * [& the address operator]
 * 
 * Pointers are variables so they can change
 * Pointers can be null
 * Pointers can be uninitialized
 * 
 * double high_temp = 100.7;
 * double low_temp = 37.1;
 * 
 * double *temp_ptr;
 * 
 * temp_ptr = &high_temp;           //points to high_temp
 * temp_ptr = &low_temp;            // now points to low_temp
 * 
 * temp_ptr = nullptr;
 *  ***/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int num = 10;
    cout << "Value of num is: " << num << endl;
    cout << "sizeof of num is: " <<  sizeof(num) << endl;
    cout << "Address of num is: " << &num << endl;

    int *p;
    cout << "Value of p is: " << p << endl;
    cout << "sizeof of p is: " <<  sizeof(p) << endl;
    cout << "Address of p is: " << &p << endl;

    p = nullptr;
    cout << "\nValue of p is: " << p << endl;

    int *p1 = nullptr;
    double *p2 = nullptr;
    unsigned long long *p3 = nullptr;
    vector<string> *p4 = nullptr;
    string *p5 = nullptr;

    cout << "\nsizeof p1 is: " << sizeof(p1) << endl;
    cout << "\nsizeof p2 is: " << sizeof(p2) << endl;
    cout << "\nsizeof p3 is: " << sizeof(p3) << endl;
    cout << "\nsizeof p4 is: " << sizeof(p4) << endl;
    cout << "\nsizeof p5 is: " << sizeof(p5) << endl;
    // 4 => Because need is 4 bytes to represent any address on my machine, may be 8 on your machine



    int score = 10;
    double high_temp = 100.7;

    int *score_ptr = nullptr;

    score_ptr = &score;
    cout << "Value of score is: " << score << endl;             // value
    cout << "Address of score is: " << &score << endl;          // address
    cout << "Value of score+ptr is: "  << score_ptr << endl;    // address
    
    //score_ptr = &high_temp;                                   // Compiler error
}