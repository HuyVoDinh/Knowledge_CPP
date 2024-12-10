/***
 * [Containers]
 * 
 *  Data structures that can store object of almost any type
 *      Template-based classes
 * 
 *  Each container has member functions
 *      Some are specific to the container
 *      Other are available to all containers
 * 
 *  Each container has an associated header file
 *      #include <container_type> 
 * 
 * [Containers - common]
 * 
 *  |       Function                    |           Description         
 *  |   Default constructor             |   Initializes an empty container
 *  |   Overloaded constructors         |   Initializes containers with many options        => That allow you to initialize the containers in many ways. You have to refer to the specific container you want to use to see the various overloaded constructors. 
 *  |   Copy constructor                |   Initializes a container as a copy of another container
 *  |   Move constructor                |   Moves existing container to new container
 *  |   Destructor                      |   Destroys a container
 *  |   Copy assignment (operator=)     |   Copy one container to another
 *  |   Move assignment (operator=)     |   Move one container to another
 *  |   size                            |   Returns the number of elements in the container
 *  |   empty                           |   Returns boolean - is the container empty?
 *  |   insert                          |   Insert an element into the container
 *  |   operator < and operator <=      |   Returns boolean - compare contents of 2 containers
 *  |   operator > and operator >=      |   Returns boolean - compare contents of 2 containers
 *  |   operator== and operator !=      |   Returns boolean - are the contents of 2 containers equal or not
 *  |   swap                            |   Swak the elements of 2 containers
 *  |   erase                           |   Remove elements(s) from a container
 *  |   clear                           |   Remove all elements from a container
 *  |   begin and end                   |   Return iterators to first element or end
 *  |   rbegin and rend                 |   Return reverse iterators to first element or end
 *  |   cbegin and cend                 |   Returns constant iterators to first element or end
 *  |   crbegin and crend               |   Returns constant reverse iterators to first element or end
 *  
 * [Container elements]
 * 
 * What types of elements can we store in containers?
 *  A copy of the element will be stored in the container
 *      All primitives OK (int, float, double,...)
 * 
 *  Element should be       // It's important to remember that when we store an element in a container the container makes a copy of that element. So we must be sure that our objects are copyable and assignable. This means they must have default copy constructors or our own copy constructors as well as copy assignment. We can also provide move semantics for efficiency.
 *      Copyable and assignable (copy constructor / copy assignment)
 *      Moveable for efficiency (move Constructor / move assignment)
 * 
 *  Ordered associative containers must be able to compare elements     // => Your objects must support these operators via operator overloading. 
 *      operator<, operator==
 * ***/