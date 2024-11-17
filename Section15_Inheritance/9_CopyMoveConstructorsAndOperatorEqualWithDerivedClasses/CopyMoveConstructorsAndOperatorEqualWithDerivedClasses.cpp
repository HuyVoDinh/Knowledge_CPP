/***
 * [Inheritance]
 * Copy/Move constructors and overloaded operator=
 *  Not inherited from the Base class
 *  You may not need to provide your own
 *      Compiler-provided versions may be just fine
 *  We can explicitly invoke the Base class version from the Derived class => we can explicitly invoke these special constructors and the overloaded assignment operators in our base class from the Derived class if necessary.
 * 
 * 
 * Copy constructor
 * -> If we need to copy a derived object then we must ensure that the base part of that derived object is also copied of that derived object is also copied. If that base class has a copy constructor, then we can explicitly invoke it in our derived copy constructor's initialization list. 
 * This is very similar to what we did with our non-special. The only part that might be confusing is that the base class constructor expects a reference to a base object, but we have a derived object in the derived class. In this case, the derived object is referenced by the variable other. 
 * So we can invoke the base class and pass in other. Remember we have is a inheritance. So a derived is a base. And since a derived is a base, we can pass in a drive to a method that expects a base. In this case, the compiler uses slicing and slices out the base part of the derived object. 
 * Slicing can sometimes cause issues, but in this case, it's fine since. 
 * 
 * 
 * Can invoke Base copy constructor explicitly
 *  Derived object 'other' will be sliced
 * 
 * Derived::Derived (const Derived &other) : Base (other), {Derived initialization list}
 * {
 *      //code
 * }
 * 
 * class Base  {
 *      int value;
 *  public: 
 *      //Same constructors as previous example
 * 
 *      // Construct a new object based on the other object, and we simply copy other.value to this dot value and display a message to the console. 
 *      The compiler provided copy constructor would be perfectly appropriate here. However, for instructional purposes, I'm writing the copy constructor so that we can se exactly what's being called. 
 *      Base(const Base &other) : value{other.value} {
 *          cout << "Base copy constructor\n";
 *      }
 * };
 * 
 * class Derived : public Base{
 *      int doubled_value;
 *  public: 
 *      //Same constructors as previous example
 * 
 *      //Notice that it's derived publicly from base, and it adds an integer attribute name doubled value. The derived class has its own copy constructor that expects a ref to a derived object that will be copied. 
 *      In this case, we're explicitly copying the base part of other by invoking the base class copy constructor in the derived copy constructor's initialization list. 
 *      Notice that we pass the other object, which will be sliced to yield its base part. Once we copy the base part, we can take care of copying doubled_value and then display a message to the console. The move constructor works the same way. 
 *      Derived(const Derived &other) : Base(other), doubled_value {other.doubled_value}{
 *          cout << "Derived copy constructor\n";
 *      }
 * };
 * 
 * 
 * operator=
 * class Base {
 *      int value;
 *  public:
 *      // Same constructors as previous example
 *      In this method, we check for self-assignment and then we assign the right-hand side's values to this object, and we return this object. 
 *      Base &operator=(const Base &rhs){
 *          if(this != &rhs){
 *              value = rhs.value;      // assign
 *          }
 *          return *this;
 *      }
 * };
 * 
 * class Derived : public Base {
 *      int doubled_value;
 *  public: 
 *      //Same constructors as previous example
 * 
 *      //In this method, it's important that we assign the base part of the derived object and then take care of the doubled_value. So after we check for self-assignment, we call our base classes overloaded assignment operator and pass in the right-hand side object that we want to assign. 
 *      This will take care of assigning the base part. Then we simply set doubled_value to the right-hand sides doubled_value to complete the assignment of the derived part. Finally, we just return to this object. 
 *      Note that if we don't explicitly call the base classes overloaded assignment operator, then the base part will not be assigned.
 *      Again, the move assignment works in a similar manner.
 *      Derived &operator=(const Derived &rhs){
 *          if (this != %rhs){
 *              Base::operator=(rhs);                   // assign Base part
 *              doubled_value = rhs.doubled_value;      // assign Derived part
 *          }
 *      }
 * };
 * 
 * Copy/Move constructors and overloaded operator=
 * 
 * Often you do not need to provide your own
 * 
 * If you DO NOT not define them in Derived
 *  then the compiler will create them and automatically and call the base class's version
 * 
 * If you DO provide Derived versions
 *  then YOU must invoke the Base versions explicitly yourself
 * 
 * Be careful with raw pointers and dynamically allocated memory
 *  Especially if Base and Derived each have raw pointers
 *  Provide them with deep copy semantics
 * ***/
#include <iostream>
using namespace std;

class Base{
    private:
        int value;
    public:
        Base()
        :value{0} {
            cout << "Base no-args constructor\n";
        }

        Base(int x)
        :   value{x}{   //1. integer constructor to be called. We'll set the value to 100, and display int base constructor. We've just constructed this object b. 
            cout <<"int Base constructor\n"; //8. overloaded constructor and pass in x to it. I'm now in base classes constructor, which is going to take care of initializing that base part of me. Display base constructor
        }

        Base (const Base&other)
        :value {other.value}{                       //11. In my base class copy constructor. Pass to 100 but other originally had that doubled value as well. So that got sliced out. And the only piece that we're interested in is the base part of that object. 
            cout << "Base copy constructor\n";      //3. Set this value to the others value, and we just we're going to displace base copy constructor. Now can see that b and b1 are indeed copies of one another, and use the base copy constructor to do that.
        }

        Base &operator=(const Base &rhs){
            cout << "Base operator=" << endl;       //5. Base operator= being called. It's not self-assignment, and simply assigning the right hands value to this value, and returning the object.
            if(this == &rhs){                       //14. At right hand side. Notice that now it just it's a base now. So it just got sliced. That double part os mpt [art pf a base/ So it's sliced out. So now just keep executing, we're going to execute the base operator=, which assigns the right-hand side's value to the left-hand side's value or this in this case since it's a member function. 
                return *this;
            }
            value = rhs.value;
            return *this;
        }

        ~Base(){cout << "Base destructor\n";}
};

class Derived : public Base{    //Explain: Derived class that is derived publicly from base. It gets value from base but we've added double value.
    private: 
        int doubled_value;
    public: 
        Derived():
            Base {}{    
                cout << "Derived no-args constructor\n";
            }

            Derived (int x):    //Explain: Call the overloaded base constructor. Then we take care of initializing our own stuff, which in this case is doubled_value, which we simply initialize it to 2 times.
            Base{x}, doubled_value {x*2} {  //7. overloaded constructor that expects an integer. Now need to construct the base part of me. So invoke base classes,
                cout << "int Derived constructor\n";    //9. It just initialized the base . It initialized double val, and now it;s just going to do a simple display statement.
            }

            Derived (const Derived &other) // Explain:  And then we've got our copy constructor. IOt expects a derived. And call our base classes copy constructor and pass other. Other is a derived. Base expects a base, but since a derived is a base, we can certainly pass other in here
                : Base (other), doubled_value {other.doubled_value}{    //10. Derived copy constructor got called. And then it immediately called our base copy constructor and we passed in other.  Remember, other was or is a derived object.
                    cout << "Derived copy constructor\n";       //12. We set doubled_value. Now our derived copy constructor is done.So can see that the derived copy constructor, and you'll see that the derived copy constructor invoked the base copy constructor. And it passed in that derived object to it, which got sliced. 
            }

            Derived &operator=(const Derived &rhs){
                cout << "Derived operator=\n";      // 13. Display derived operator equals. We're going to check for self-assignment. And now what I want to do is I want to copy the right-hand side to the left hand-side but only the base part. In this case, I want to call my bass classes overloaded operator and pass in right-hand side. Right-hand side is a derived. So it's got a base, and it's got its derived doubled_value. Call base method
                if (this == &rhs)
                    return *this;
                Base::operator=(rhs);   // Explain: We're calling our base classes overloaded assignment operator, and we're passing in the right-hand side. Again, that method in our base class expects a base object -> a ref to a base object. We're passing in a derived. Then once the base is assigned , I take care of assigning the part of the derived that really this method is only concerned about and we return this.
                doubled_value = rhs.doubled_value;  //15. We just assigned the base part. We're going to take care of the doubled_value part of us. 
                return *this;
            }

            ~Derived(){cout << "Derived destructor\n";}
            
};

int main(){
    Base b{100};        //overloaded constructor
    Base b1 {b};        // Copy constructor     //2. We're going to construct b1, which is also a base class object based on b. So we're going to call the copy constructor.
    b = b1;             //Copy assignment       //4. b already exists.  So this is not a constructor, this is copy assignment. 

    Derived d {100};    //overloaded constructor            
    Derived d1 {d};     // Copy constructor     
    d = d1;             //Copy assignment  
    // Now obviously these values are going to be the same because we just assigned them, and they both have a base part and a derived part. Now they're going to go out of scope, so we need to unwind and then destroy these objects. So the destructor will be called in the reverse order of the constructors. S o the first destructor that will be called is the one for d1 and we'll execute and you can see that the derived destructor executes followed by the base destructor. Then the same thing will happen with the next object. 
    // The derived constructors and copy constructors work.
}