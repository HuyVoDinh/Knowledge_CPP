/***
 * [L-values]
 *  values that have names and are addressable
 *  modifiable if they are not constants
 * 
 * int x = 100;         // x is an l-value
 * x = 1000;
 * x = 1000 + 20;
 * 
 * string name;         // name is an l-value
 * name = "Frank";
 * 
 * 100 = x;             // 100 is NOT an l-value
 * string name;
 * name = "Frank";
 * "Frank" = name;      // Frank is NOT an l-value
 * 
 * [R-value]
 *  r-values can be assigned to l-values explicitly
 * 
 * int x = 100;
 * int y = 0;
 * 
 * y = 100;             // r-value 100 assigned to l-value y
 * x = x + y;           // r-value (x+y) assigned to l-value x
 * 
 * [l-value references]
 * The references we've used are l-value references
 *  Because we are referencing l-values
 * 
 * int x = 100;
 * int &ref1 = x;       // ref1 is reference to l-value
 * ref1 = 1000;
 * 
 * int &ref2 = 100;     // Error 100 is an r-value
 * 
 * The same when we pass-by-reference
 * 
 * int square(int &n){
 *      return n*n;
 * }
 * 
 * int num = 10;
 * square(num);         // OK
 * square(5);           // Error - can't reference r-value 5
 * ***/