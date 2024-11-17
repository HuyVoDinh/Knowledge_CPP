/***
 * [Multiple Inheritance]
 * <Section15_MultipleInheritance1.png>
 * -> the class diagram shows an example of multiple inheritance. In this case the class, department chair is derived from both faculty and administrator classes.
 * So if we use public inheritance, then a department chair is a faculty member and a department chair is also an administrator. 
 * 
 * A derived class inherits from two or more
 *  Base classes at the same time       -> Multiple inheritance occurs when a derived class inherits from two or more base classes at the same time. 
 * 
 * The Base classes may belong to unrelated class hierarchies  
 * 
 * A department chair
 *  Is-A Faculty and
 *  Is-A Administrator 
 * 
 * C++ Syntax
 * class Department_Chair : public Faculty, public Administrator{
 *      ... 
 * };
 * 
 * Beyond the scope of this course  
 * Some compelling use-cases
 * Easily misused
 * Can be very complex
 * -> Multiple inheritance is beyond the scope of this course, and it can be very, very complex in practice. There are some compelling use cases for multiple inheritance. However, in many cases we can refactor our design so that the multiple inheritance can be avoided, and many times we end up with a better design.
 * This isn't because there's anything wrong with multiple inheritance. The problem with multiple inheritance is that because it can be so complex, many developers don't fully understand it , and, therefore, may misused it. 
 * 
 * ***/