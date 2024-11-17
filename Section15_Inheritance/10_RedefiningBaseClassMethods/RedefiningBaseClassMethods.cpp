/***
 * [Inheritance]
 * Using and redefining Base class methods
 * -> One of the most powerful features of inheritance is that base class member functions are available to the derived class. A derived class can directly invoke base class methods. A derived class can also override or redefine base class methods. 
 * This concept will provide us with a large amount of power when we use polymorphic functions. In order to redefine or override a method, you simply provide a method in the derived class with same name and signature as a method in the base class. 
 * 
 *  Derived class can directly invoke Base class methods
 *  Derived class can override or redefine Base class methods
 *  Very powerful in the context of polymorphism
 * 
 * Using and redefining Base class methods
 * -> Suppose we have an account class and it has a deposit method that simply increments a balance by an amount. 
 * class Account{
 *  public:
 *      void deposit(double amount) {balance += amount;}
 * };
 * 
 * -> Savings account class, it also needs a deposit method, but its behavior will be slightly different in some way. We can override the account classes deposit method in the savings account class by providing a specialized implementation using the same method signature. Now when the savings account objects deposit fund, this  specialized method will be invoked. 
 * But since the accounts deposit method does some of the work that we want to do in the savings account deposit method, we don't have to duplicate code, we can simply call the accounts deposit method from within the savings accounts deposit method. We must prefix the method call with the account class so the compiler knows that we're calling the deposit method in the account class
 * class Savings_Account : public Account{
 *  public: 
 *      void deposit(double amount) {       //Redefine Base class method
 *          amount += some_interest;
 *          Account::deposit(amount);       // Invoke call Base class method
 *      }
 * };
 * 
 * 
 * Static binding of method class
 * -> By default, C++ does static binding of method calls. All that means is that the compiler determines which methods are called based on what it sees at compile time. Static binding is supper efficient and that's why it's the default in C++. 
 * So if the compiler sees that a b is declared as a base object and we call b.deposit, then the compiler will call the base classes deposit. The same is true for a derived object. If d is a derived object and c.deposit is called, this results in a call to the derived classes deposit method. 
 * While this is very efficient and fine in most cases, there are times when we'd like the binding to take place at runtime. 
 *  Binding of which method to use is done at compile time
 *      Default binding for C++ is static
 *      Derived class objects will use Derived::deposit
 *      But, we can explicitly invoke Base::Deposit from Derived::deposit
 *      OK, but limited - much more powerful approach is dynamic binding 
 * 
 * -> In the first example, b.deposit will call the base classes deposit method because b is a base object.
 * Base b;
 * b.deposit(1000);                 // Base::deposit
 * 
 * ->  And d.deposit we'll call the derived classes deposit method since d is a type of derived.
 * Derived d;
 * d.deposit(1000);                 // Derived::deposit
 * 
 * -> Have a pointer ptr to a base object but we create a derived object on the heap and assign it to the pointer. This is perfectly valid since the derived is a base. But now if we call the deposit method through the pointer, the compiler will call the base classes deposit method because it sees that pointer is a pointer to a base class. 
 * But perhaps it would make more sense to call the derives deposit method. In this example since the actual object pointed to is a derived object. 
 * Base *ptr = new Derived();
 * ptr->deposit(1000);              //Base::deposit???
 * ***/
#include <iostream>
#include "Savings_Account.h"

using namespace std;

int main(){
    cout << "\n============Account class========\n";
    Account a1 {1000.0};
    cout << a1 << endl;     //Account balance: 1000;

    a1.deposit(500.0);      
    cout << a1 << endl;     //Account balance: 1500

    a1.withdraw(1000);
    cout << a1 << endl;     //Account balance: 500

    a1.withdraw(5000.0);
    cout << a1 << endl;     //Account balance: 500
    
    cout << "\n============Savings Account class=========\n";
    Savings_Account s1 {1000,5.0};
    cout << s1 << endl;     // Savings Account balance: 1000, interest rate: 5

    s1.deposit(1000);
    cout << s1 << endl;     // Savings Account balance: 2050, interest rate: 5

    s1.withdraw(2000);
    cout << s1 << endl;     // Savings Account balance: 50, interest rate: 5

    s1.withdraw(1000);
    cout << s1 << endl;     // Savings Account balance: 50, interest rate: 5
    return 0;
}