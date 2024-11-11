/***
 * [Inheritance]
 * 
 * What is it and why is it used?
 * 
 *  Provides a method for creating new classes from existing classes
 *  
 *  The new class contains the data and behaviors of the existing class
 * 
 *  Allow for reuse of existing classes     => reusing behaviors that have been tested and have already been used in existing applications. But it wouldn't be very useful if I only inherited data and behaviors and that's it. But with inheritance, we can modify the behaviors however we'd like to make our newly created classes unique. So the new class is based on an existing class, but we can tweak it so that it does exactly what we want it to do. And we can do this without modifying the source code of the original class we're reusing. This is important since that class has already been tested and it's probably being reused by other applications.  So we really don't want to modify it at all. 
 *                                              Of course, inheritance must make sense. We don't want to reuse a class employee and create a new class planet that contains the data and behaviors of an employee. 
 * 
 *  Allow us to focus on the common attributes among a set of classes
 * 
 *  Allows new classes to modify behaviors of existing classes to make it unique
 *      Without actually modifying the original class
 * 
 * Related classes
 * => In many applications, when you're designing your solution, you can identify classes in your application that are related to one another. Sometimes the relationship is clear, and other times the relationship might be less clear. 
 * => Related classes are all around us when we develop software. Sometimes it makes sense to extract out common elements of related classes and model them on their own so we can reuse them. 
 * 
 *  Player, Enemy, Level Boss, Hero, Super Player, etc. 
 *  Account, Savings Account, Checking Account, Trust Account, etc. 
 *  Shape, Line, Oval, Circle, Square,  etc. 
 *  Person, Employee, Student, Faculty, Staff, Administrator, etc. 
 * 
 * 
 * Account
 * 
 *  Account
 *      balance, deposit, withdraw,... 
 *  Savings Account
 *      balance, deposit, withdraw, interest rate,... 
 *  Checking Account
 *      balance, deposit, withdraw, minimum balance, per check fee,... 
 *  Trust Account
 *      balance, deposit, withdraw, interest rate,...
 * 
 * Accounts - without inheritance - code duplication
 * => And implement them all totally independent from one another.
 * 
 *  class Account {
 *      // balance, deposit, withdraw,... 
 *  };
 * 
 *  class Savings_Account {
 *      // balance, deposit, withdraw, interest rate,... 
 *  };
 * 
 *  class Checking_Account {
 *      // balance, deposit, withdraw, minimum balance, per check fee,... 
 *  };
 * 
 *  class Trust_Account {
 *      // balance, deposit, withdraw, interest rate,... 
 *  };
 * 
 * Account - with inheritance - code reuse
 * => We can use inheritance to create a new class savings account based on the account class. So the savings account will inherit balance and the implementations of withdrawal and deposit provided by the account class. 
 * 
 *  class Account {
 *      // balance, deposit, withdraw,... 
 *  };
 * 
 *  class Savings_Account : public Account{
 *      // interest rate, specialized withdraw... 
 *  };
 * 
 *  class Checking_Account : public Account{
 *      // minimum balance, per check fee, specialized withdraw... 
 *  };
 * 
 *  class Trust_Account : public Account{
 *      // interest rate, specialized withdraw... 
 *  };
 * ****/