/***
 * [When to use pointers vs. references parameters]
 * 
 * Pass-by-value
 *  when the function does not modify the actual parameter, and the parameter is small and efficient to copy like simple types (int, char, double, etc)
 *  Note: the collection types, like strings and vectors and others have certain amount of overhead involved when they're copied. So you want to think twice before you pass those by value.
 * 
 * Pass-by-reference using a pointer
 *  When the function does modify the actual parameter and the parameter is expensive to copy and ItsOK to the pointer is allowed a nullptr value => This is important because a lot of data structures rely on pointers becoming null at the end of lists or the end of trees. So in those cases, you really want to pass pointers and not references because references can't be null
 * 
 * Pass-by-reference using a pointer to const
 *  when the function does not modify the actual parameter and the parameter is expensive to copy and Its OK to the pointer is allowed a nullptr value
 * 
 * Pass-by-referencing using a const pointer to const
 *  when the function dose not modify the actual parameter and the parameter is expensive to copy and Its OK to the pointer is allowed a nullptr value and You don't want to modify the pointer itself. So this is a good example of where you would pass something in, and you're guaranteed that the pointer is not moving and the data it's pointing to is not going to change
 * 
 * Pass-by-reference using a reference 
 *  When the function dose modify the actual parameter and the parameter is expensive to copy and the parameter will never be nullptr
 * 
 * Pass-by-reference using a const reference
 *  when the function does not modify the actual parameter and the parameter is expensive to copy and the parameter will never be nullptr => So if you need null values, go with the pointers 
 * ***/