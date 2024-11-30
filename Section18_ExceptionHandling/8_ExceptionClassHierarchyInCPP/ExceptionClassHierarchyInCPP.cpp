/***
 * [The C++ standard library exception class hierarchy]
 * 
 * C++ provides a class hierarchy of exception classes          //=> All of exception classes are ultimately derived from it. std::exception provides a virtual function named what that returns a c-style string with a description of the exception that occurred. We can create subclasses of the exception classes and then implement the what virtual function so that it displays whatever exception message we want. 
 *  std::exception is the base class
 *  all subclasses implement the what() virtual function
 *  we can create our own user-defined exception subclasses
 * 
 * virtual const char *what() const noexcept;
 * 
 * <Section18_ExceptionClassHierarchyInCPP1.png>
 * The classes that are in orange are the C++ 18 additions to the class hierarchy.
 * Notice that the common base class in the center is std exception, and then we have many classes derived from it. 
 * Exceptions that are runtime errors, logic errors, bad allocation errors, out of range errors and many more. 
 * We can create our own-user defined classes that are derived from these exception classes. 
 * This can be very useful in some situations since by being derived publicly from stood exception, our classes are now part of this hierarchy and can be used wherever a stood exception is expected since your class is an exception. 
 * Also thanks to dynamic polymorphism. All you have to do is implement the what virtual function and it will be bound dynamically at runtime. 
 * 
 * [Deriving our class form std::exception]
 * 
 * => Implement that what virtual function and return a c-style string describing the exception. We could provide all sorts of error information, codes, descriptions and so forth, as class attributes and initialize them in the constructor when we create and throw the object.
 * noexcept keyword. This tells the compiler that the method will not throw an exception. So don't throw exceptions from these methods. THe destructor is no except by default. If you do happen to throw an exception from a no throw method, the program will terminate, the exception will not be handled. 
 * 
 * class IllegalBalanceException : public std::exception{
 *  public: 
 *      IllegalBalanceException () noexcept = default;
 *      ~IllegalBalanceException () = default;
 *      virtual const char*what() const noexcept {
 *          return "Illegal balance exception";
 *      }
 * };
 * 
 * [Our modified Account class constructor]
 * 
 *  Account::Account (std::string name, double balance) : name {name}, balance {balance} {
 *      if(balance < 0.0)
 *          throw IllegalBalanceException{};    => If account balance is less than 0. And if it is, we're throwing an illegal balance exception, which is our user-defined exception class derived from std exception. When created our own standalone illegal balance exception class. 
 *  }
 * 
 * [Creating an Account object]
 * => Create a unique pointer and create a checking account object dynamically. Notice that we're creating Moe's account with a negative 100 balance. This is not legal, so we expect that the account constructor will throw an illegal balance exception object.  And that's exactly what we're catching in our catch handler. 
 * In this case, the catch handler fires and we call ex.what, which will display illegal balance exception.
 * try{
 *      std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -100.0);
 *      std::cout << "Use moes_account\n";
 * } catch (const IllegalBalanceException &ex)
 * {
 *      std::cerr << ex.what() << std::endl;
 *      //displays "Illegal balance exception"
 * }
 * ***/