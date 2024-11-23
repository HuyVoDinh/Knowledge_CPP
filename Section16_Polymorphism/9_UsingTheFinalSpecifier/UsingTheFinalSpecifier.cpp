/***
 * [Polymorphism]
 *  The final specifier         => At class level, the final specifier prevents a class from being derived from or subclassed. Sometimes frameworks have final classes that can't be subclassed. In some cases, this is done for better compiler optimization. Other times, it may be done to ensure that objects are copied safely without slicing. When used at the method or function level, the final specifier prevents the method from being overridden in derived classes. 
 *                                  This also be done for better compiler optimization. 
 *      C++11 provides the final specifier
 *          When used at the class level
 *          Prevents a class from being derived from
 * 
 *      When used at the method level
 *          Prevents virtual method from being overridden in derived classes
 * 
 *  final class
 *  => We simply add the final specifier after the class name when we declare it. In the first example, my class cannot be derived from. And in the second example, derived cannot be derived from. If you try to drive a class from these classes, the compiler will generate a compiler error. 
 * 
 *  class My_class final{
 *      ... 
 *  };
 * 
 *  class Derived final : public Base {
 *      ...
 *  };
 * 
 * 
 * => In this case, we have a simple class hierarchy with three classes: a, b, c. The base class a declares the function do something as virtual. Class b is derived form a and it overrides do something but it also marks it as final. So do something can no longer be overridden further down in the hierarchy. Notice that if class c tries to override do something, the compiler generates an error. 
 *  class A{
 *      public: 
 *          virtual void do_something();
 *  };
 * 
 *  class B : class A {
 *      virtual void do_something() final;      // prevent further overriding
 *  };
 * 
 *  class C : public B {
 *      virtual void do_something();            // COMPILER ERROR - Can't override
 *  };
 * ***/