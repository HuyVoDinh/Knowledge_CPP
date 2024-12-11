/***
 * [Algorithms]
 *  STL algorithms work on sequences of container elements provided to them by an iterator
 * 
 *  STL has many common and useful algorithms
 *  
 *  Too many to describe in this section
 *      http://en.cppreference.com/w/cpp/algorithm
 * 
 *  Many algorithms require extra information in order to do their work
 *      Functions (functions objects)
 *      Function pointers
 *      Lambda expressions (C++11)
 * 
 * [Algorithms and iterators]
 *  #include <algorithm>
 *  
 *  Different containers support different types of iterators
 *      Determines the types of algorithms supported
 * 
 *  All STL algorithms expect iterators as arguments
 *      Determines the sequence obtained from the container
 * 
 * [Iterator invalidation]
 * 
 *  Iterators point to container elements
 * 
 *  It's possible iterators become invalid during processing
 * 
 *  Suppose we are iterating over a vector of 10 elements
 *      And we clear() the vector while iterating? What happens?        => this deletes all the elements from the vector, but the iterator doesn't know that. This iterator will happily continue iterating until it sees the end of the vector, but this is no longer valid. If something like this happens, then the behavior is undefined in C++. 
 *      Undefined behavior - our iterators are pointing to invalid locations
 * 
 * [Example algorithm - find with primitive types]
 * 
 *  The type algorithm tries to locate the first occurrence of an element in a container
 * 
 *  Lots of variations
 * 
 *  Returns an iterator pointing to the located element or end()
 * 
 *  std::vector<int> vec {1, 2, 3};
 *  auto loc = std::find(vec.begin(), vec.end(), 3);
 *  if (loc != vec.end())                   // found it
 *      std::cout << *loc << std::endl;     // 3
 * 
 * [Example algorithm - find with user-defined types]
 * 
 *  Find needs to be able to compare object
 * 
 *  operator== is used and must be provided by your class
 * 
 *  std::vector<Player> team { assume initialized };
 *  Player p {"Hero", 100, 12};
 * 
 *  auto loc = std::find(team.begin(), team.end(), p);
 *  if(loc != vec.end())                        // found it!
 *      std::cout << *loc << std::endl;         // operator<< called
 * 
 * [Example algorithm - for_each]
 *  for_each algorithm applies a function to each element in the iterator sequence
 * 
 *  Function must be provided to the algorithm as: 
 *      Functor (function object)
 *      Function pointer
 *      Lambda expression (C++ 11)
 * 
 *  Let's square each element
 * 
 * [for_each - using a functor]
 * 
 *  struct Square_Functor {
 *      void operator() (int x) {       // overload () operator
 *          std::cout << x * x << " ";
 *      }
 *  };
 * 
 *  Square_Functor square;              // Function object
 * 
 *  std::vector<int> vec {1,2,3,4};
 * 
 *  std::for_each(vec.begin(), vec.end(), square);      // we're going to iterate through each element in the vector. And in each interation the overloaded function call operator function for the square object will be called, and the current container element it passed to it. 
 *  // 1 4 9 16
 * 
 * [for_each - using a function pointer]
 * 
 * The square parameter is not a function object, it's the name of a regular function.
 * What's being passed into the for each function is a pointer to the square function, which is really the address of the function square itself. 
 * So at each iteration of the for each loop, the square function will be called and the current container element passed into it. 
 * Notice that we only use the function name as the parameter, we don't place paren these after it since that would call the function, that's not what we want. 
 * 
 *  void square (int x){        // function
 *      std::cout << x * x << " ";
 *  }
 * 
 *  std::vector<int> vec {1,2,3,4};
 * 
 *  std::for_each(vec.begin(), vec.end(), square);
 *  // 1 4 9 16
 * 
 * [for_each - using a lambda expression]
 * 
 *  std::vector<int> vec {1, 2, 3, 4};
 * 
 *  std::for_each(vec.begin(), vec.end(), [] (int x) {std::cout << x * x << " ";})      // lambda
 *  // 1 4 9 16
 * 
 * 
 * ****/