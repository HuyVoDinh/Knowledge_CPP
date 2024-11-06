/***
 * [Move Constructor]
 * C++ 11 is most pervasive features was probably move semantics. Whether an expression is an l-value an r-value. But a useful rule of thumb is that when you can refer to an object by name or you can follow a pointer to get to an object then that object is addressable and it's an L-value and R-value are everything else. But in the context of move semantics r-values refer to temporary objects that are created by the compiler and objects returned from methods
 * 
 * Sometimes when we execute code the compiler creates unnamed temporary values
 * 
 * int total {0};
 * total = 100 + 200;
 * 
 *  100 + 200 is evaluated and 300 stored in an unnamed temp value
 *  the 300 is then stored in the variable total        => the R-value is then assigned to the L-value total.
 *  then the temp value is discarded
 * 
 * The same happens with objects as well =>However, with objects there can be a great amount of overhead if copy constructors are called over and over making copies of these temporary objects. And when we have raw pointers and we have to do deep copies then the overhead is even greater. This is where move semantics and the move constructor comes into the picture. R-value objects are the objects that move semantics addresses
 * 
 * [When is it useful?]
 * Sometimes copy constructors are called many times automatically due to the copy semantics of C++. => Copy constructors are called whenever the compiler needs to make a copy of an object. 
 * 
 * Copy constructors doing deep copying can have a significant performance bottleneck => If class contains a raw pointer, then we must implement deep copy. However, this can be computationally expensive since we have to allocate space for the copy and then copy the data over. 
 * 
 * C++11 introduced move semantics and the move constructor 
 * 
 * Move constructor moves an object rather than copy it => C++ move the object rather than copies it, this can be extremely efficient
 * 
 * Optional but recommended when you have a raw pointer => Move constructors are optional. If don't provide them, then the copy constructors will be called. But it's a good idea to use move constructors for efficiency.
 * 
 * Copy elision - C++ may optimize copying away completely (RVO - Return Value Optimization) => In fact sometimes you may not even see the copy constructors being called. If you experience this, it;s probably due to something called copy illusion. Copy illusion is a compiler optimization technique that eliminates unnecessary copying. 
 * Compilers are really smart with their optimization now. And one of the common techniques is called return value optimization, that's when the compiler generates code that doesn't create a copy every return value from a function making the code much more efficient. 
 * 
 * [r-value references]
 * Used in moving semantics and perfect forwarding => R-value references are references to R-values. In the context of move semantics, think of R-value references as references to those temporary objects that we were talking about. L-value references are declared using a single ampersand like we've done, but r-value references are declared using two ampersands. 
 * 
 * Move semantics is all about r-value references
 * 
 * Used by move constructor and move assignment operator to efficiently move an object rather than copy it
 * 
 * R-value reference operator (&&)
 * => Difference between an L-values reference and an R-values reference.
 * 
 * int x {100}                      => declare x as an integer and initialize it to a 100. x is an L-value, it's addressable, and it's got a name
 *  int &l_ref = x;                 // l-value reference    => create r_ref as a reference to x. And since x is an L-value, this is an L-values reference. We can use I ref to refer to x. Nothing new, this is stuff we've seen already. 
 *  l_ref = 10;                     // change x to 10
 * 
 *  int &&r_ref = 200;              // r-value ref          => r_ref is declared as an R-value ref to an integer with a double ampersand operator and set it to refer to 200. Since 200 is an R-value this make ref an R-value reference
 *  r_ref = 300;                    // change r_ref to 300  => assign 300 to r_ref which stores 300 into the R-value of where ref refers to. In other words, we just change that temporary variable. 
 * 
 *  int &&x_ref = x;                // Compiler error       => Notice that if try to assign an L-value to an R-value reference, get a compiler error which makes perfect sense. 
 * 
 * [l-value reference parameters]
 * L-value references in the context of function parameters. 
 * 
 * int x {100};                     // x is an l-value                                      => have an integer x, we initialize it to 100. 
 * 
 * void func(int &num);             // A                                                    => It expects an L-value reference, as denoted by the single ampersand. So it wants an L-value 
 * 
 * func(x);                         // calls A - x is an l-value                            => If call func and pass in x, x is an L-value and num will be the reference to an L-value. 
 * func(200);                       // Error - 200 is an r-value                            => 200 is not an L-value, it's an R-value and the compiler will generate an error.
 * 
 * error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
 * 
 * [r-value reference parameters]
 * R-value references in the context of function parameters
 * 
 * int x {100};                     // x is an l-value                  => defined x to be an integer and initialized it to 100. 
 * 
 * void func(int &&num);            // B                                => Declare func as a function that expects an R-value reference, and denote that with the double ampersands. So it wants an R-value.
 * 
 * func(200);                       // calls B - 200 is an r-value      => call func and pass in 200, it's ok. Now num will be a reference to an R-value
 * func(x);                         // ERROR - x is an l-value          => x is not an R-value, it's an L-value. So the compiler generates the error.
 * 
 * error: cannot bind rvalue reference oif type 'int&&' to lvalue of type 'int'
 * 
 * [l-value and r-value reference parameters]
 * We can overload these functions and have both of them in code at the same time since they have unique signatures. And the compiler will call the correct function depending on whether the parameter is an L-value or and R-value. We're going to take advantage of this when we define the move constructor.
 * 
 * int x {100};                     // x is an l-value
 * 
 * void func(int &num);             // A
 * void func(int &&num);            // B
 * 
 * func(x);                         // calls A - x is an l-value
 * func(200);                       // calls B - 200 is an r-value
 * 
 * [Example - move class]
 * 
 * class Move {
 *  private:
 *      int *data;                                  // raw pointer
 *  public:
 *      void set_data_value(int d) {*data = d;}
 *      int get_data_value() {return *data;}
 *      Move (int d);                               // Constructor
 *      Move(const Move &source);                   // Copy Constructor
 *      ~Move();                                    // Destructor
 * };
 * 
 * [Move class copy constructor]
 * Move::Move(const Move &source){ => The code for the copy constructor, pretty standard deep copy. Allocate storage and copy the data. 
 *      data = new int;
 *      *data = *source.data;
 * }
 * Allocate storage and copy
 * 
 * [Inefficient copying]
 * 
 * Vector<Move> vec;            => creates a vector of some move objects, and we call the vector vec, and we push_back to move object. 
 * 
 * vec.push_back(Move{10});     => Notice what's happening in the argument list. Move 10 and 20 are creating temporary objects, they're unnamed. So they're going to be R-values.
 * vec.push_back(Move{20});
 * Copy constructors will be called to copy the temps
 * 
 * Constructor for: 10
 * Constructor for: 10
 * Copy constructor - deep copy for: 10
 * Destructor freeing data for: 10
 * Constructor for: 20
 * Constructor for: 20
 * Copy constructor - deep copy for: 20
 * Constructor for: 10
 * Copy constructor - deep copy for: 10
 * Destructor freeing data for: 10
 * Destructor freeing data for: 20
 * 
 * Let's add the move constructor to the class to make it much more efficient. ]
 * 
 * [What does it do?]
 * Instead of making a deep copy of the move constructor        => instead of making a deep copy like the copy constructor does, it simply moves the resource that's on the heap. And the way we do that is just to assign the pointer from the source object to the current object. You might be thinking isn't that what default member-wise copy is. The difference is that we know out the pointer in the source object. So what we have now is an object who owns the data on the heap and then the original object with a null pointer to that data.
 *                                                                  This is real efficient since we're not doing a copy at all. 
 *  'moves' the resource
 *  Simply copies the address of the resource from source to the current object
 *  And, nulls out the pointer in the source pointer
 * 
 * Very efficient
 * 
 * [syntax - r-value reference]
 * There's no const qualifier for the parameter source. There can't be because we need to modify it in order to null out its pointer.
 * The parameter is an r-value reference, and with the double ampersands. 
 * Prototype might look like for a player class and the move class. 
 * 
 * Type::Type(Type &&source);
 * Player::Player(Player &&source);
 * Move::Move(Move &&source);
 * 
 * [Move class move constructor]
 * We're not copying what it's pointing to, we're not doing a deep copy. Then we null out source.data. Otherwise, we end up with the equivalent of a shallow copy and not a move.
 * Many resources that describe  the move constructor say that it steals or pilfers the data and then it nulls out the source pointer, and that's really a good way to think about it, that'sa exactly what it's doing.
 * 
 * Move::Move(Move &&source) : data {source.data} {
 *      source.data = nullptr;
 * }
 * 
 * 'Steal' the data and then null out the source pointer
 * 
 * [Efficient]
 * When we execute it, instead of the copy constructors being called for those temporary objects, the move constructors will be called because there are values. And it's going to be much more efficient than doing deep copies. 
 * 
 * Vector<Move> vec;
 * 
 * vec.push_back(Move{10});
 * vec.push_back(Move{20});
 * 
 * Move constructors will be called for the temp r-values
 * 
 * See when the destructors are called for null pointer. That's destroying the object that we just moved and set its data pointer to null. That's a basic introduction to R-value references in the move constructor. 
 * When overload the assignment operator to do both copy and move. There's so much more to move semantics in the move constructor that are better left for a more advanced course 
 * 
 * Constructor for: 10
 * Move constructor - moving resource: 10
 * Destructor freeing data for nullptr
 * Constructor for: 20
 * Move constructor - moving resource: 20
 * Move constructor - moving resource: 10
 * Destructor freeing data for nullptr
 * Destructor freeing data for nullptr
 * Destructor freeing data for: 10
 * Destructor freeing data for: 20
 * ****/

#include <iostream>
#include <vector>

using namespace std;

class Move{
    private:
        int *data;
    public:
        void set_data_value(int d) {*data = d;}
        int get_data_value() {return *data;}
        //Constructor
        Move(int d);
        //Copy constructor
        Move(const Move&source);
        //Move constructor
        Move(Move &&source) noexcept;
        //Destructor
        ~Move();
};

Move::Move(int d){
    data = new int;         // 2. It's going to allocate that object on the heap and store whatever we passed it into it. // 2.3 Create that 10
    *data = d;              // 4. Delegating to the constructor. => create another 10
    cout << "Constructor for: " << d << endl;
}

//Copy ctor
Move::Move(const Move&source) : Move {*source.data} {       //3. just created this temporary. This temporary now needs to be copied into the vector. => We're in the copy constructor.
    cout << "Move constructor - moving resource: " << endl;
} //5. deep copied that 10, which is exactly what we did.

//Move ctor
Move::Move(Move &&source) noexcept : data{source.data} {    //2.4 Move constructor got called. The move constructor with the double ampersand. We got called rather than the copy constructor. Because this is an R-value temporary.  
    source.data = nullptr;      // 2.5 Now we're basically going to steal the data and null out the pointer to the source object. We're going to move it rather than copy it.
    cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move(){
    if(data != nullptr){    //7. Destroyed copy of 10. // 2.7 The object we're destroying. Notice it's a null. The data's a null. That's the one we just nulled out.
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;  // 2.8 Message
    }
    delete data;
}

int main(){
    vector <Move> vec;

    vec.push_back(Move{10});    // 1. Create that temporary object. We're going to use the constructor to do that. // 6. Need to destroy that copy we made. // 2.2 Create that move object, that's a regular constructor to create that. That create temporary R-value.
    //The fact that this is an R-value, that comes into play when we use the move constructor. 
    // 2.6 Delete that object

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});
    //About 15 deep copies. That's much more that you would expect. In code, there's only 8 pushbacks. vector is actually growing behind the scenes. And when the vector grows, those objects ned to be copied to the new storage. The vector is using contiguous storage. So it's making copies of the objects behind the scenes as well. So you can see that a lot of times there's a lot of times there's a lot of copying going on behind the scenes that we're not aware of.

    //2.1 Move constructor simply copying the source data and nulling out the pointer.
    //2.9 There is not one single copy constructor being called. So we're doing no deep copies, we're only moving resources using the move constructor.
    return 0;
}