/***
 * [this pointer]
 * 
 * this is a reserved keyword => that contains the address of the current object
 * 
 * Contains the address of the object - so it's a pointer to the object
 * 
 * Can only be used in class scope  => it's a pointer to the object that's currently being used by the class member methods. The this keyword can only be used within the cope of the class
 * 
 * All member access is done via the this pointer => C++ allows to use member names directly. And behind the scenes, it's actually using this pointer.
 * 
 * Can be used by the programmer
 *  To access data member and methods
 *  To determine if two objects are the same
 *  Can be dereferenced (*this) to yield the current object
 * 
 * void Account::set_balance(double bal){
 *      balance = bal;  // this-> balance is implied
 * }
 * // Notice that the name of the parameter is bal and the code in the body of the method is balance = bal, which assigns the value of the parameter bal to the class data member balance. We don't have to write this arrow balance but that's exactly what the compiler is doing for us behind the scenes.alignas
 * 
 * To disambiguate identifier use
 * 
 * void Account::set_balance(double balance){
 *      balance = balance;      // which balance ? the parameter
 * }
 * // Suppose that the name of the parameter was balance. Now in the method body, the assignment statement balance = balance would use the parameter balance for both of those identifiers instead of the data member balance. That's because of scope rules.
 * Now this statement would not accomplish what we wanted to do. So in order to refer to the data member balance, we need to explicitly use this arrow balance. 
 * void Account::set_balance (double balance){
 *      this->balance = balance;            // Unambiguous
 * }
 * 
 * To determine object identity
 * Sometimes its useful to know if two objects are the same object
 * => Suppose we have a compare balance method in the account class that compares the balance of one object with another. If we're comparing the same objects by comparing this and the address of other. If they're the same, then we're dealing with the same object
 * It wouldn't make much difference in our code since we're simply comparing balances but if our compare logic is involved or computationally expensive, then a quick check to see if the objects are the same could help performance. We'll use the this pointer again the the operator overloading section. 
 * int Account::compare_balance (const Account &other){
 *      if(this == &other)
 *          std::cout << "The same objects " << std::endl;
 * }
 * 
 * frank_account.compare_balance(frank_account);
 * We'll use the this pointer again when we overload the assignment operator
 * ****/