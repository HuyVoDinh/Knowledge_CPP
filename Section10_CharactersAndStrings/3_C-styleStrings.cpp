/***
 * [C-style Strings]
 * 
 * Sequence of characters
 *  contiguous in memory
 *  implemented as an array of characters
 *  terminated by a null character (null)
 *      null - character with a value of zero
 *  Referred to as zero or null terminated strings
 * 
 * String literal
 *  sequence of characters in double quotes. e.g "Frank"
 *  constant
 *  terminated with null character
 * 
 * [Example]
 * 
 * "C++ is fun"
 *  C|+|+| |i|s| |f|u|n|\0|
 * 
 *  char my_name[] = "Frank";
 *      F|r|a|n|k|\0|
 *  my_name [5] = 'y' // Problem => The size of array is fixed => So if i want to add a y to Frank and create Franky, => It could without having some potential problems since the new string would no be null terminated. You won't get a compiler error or even a warning
 * 
 *  char my_name[8] = "Frank";
 *      F|r|a|n|k|\0|\0|\0|
 *  my_name [5] = 'y'; // Ok
 * 
 * 
 *  char my_name [8];
 *  |?|?|?|?|?|?|?|?|
 *  my_name = "Frank"; // Error => =>that's not the way c-style strings work =>  If use this array as a string, all c-style string functions expect to find a null character
 *      => In this case, we start at the first element of the array and iterate through the array, At every character, if it's the null character, stop since reach the end of the string, if it's not, print the character and then move to the next character 
 *  strcpy(my_name, "Frank"); // OK => To assign one string to another, need to use function copy strcpy
 * 
 * [C-style strings]
 *  #include<cstring>
 * 
 *  Functions that work with C-style Strings
 *      Copying
 *      Concatenation
 *      Comparison
 *      Searching
 *      and others
 * 
 * [Example]
 * 
 * char str[80];
 * 
 * strcpy(str,"Hello"); // copy
 * strcat(str,"there"); // concatenate
 * cout << strlen(str); // 11
 * strcmp (str, "Another"); // > 0
 * 
 * [Convert C-style String to]
 * 
 *  #include <cstdlib>
 * 
 *  Includes function to convert C-style Strings to
 *      integer
 *      float
 *      long   
 *      etc
 * 
 * 
 * ***/