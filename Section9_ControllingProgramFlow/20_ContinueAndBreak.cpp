#include <iostream>
using namespace std;

/***
 * [Continue and break statements]
 * 
 * continue 
 *  no further statements in the body of the loop are executed
 *  control immediately goes directly to the beginning of the loop for the next iteration
 * 
 * break
 *  no further statements in the body of the loop are executed
 *  loop is immediately terminated
 *  control immediately goes to the statement following the loop construct
 * 
 * [Example]
 * vector <int> values {1,2,-1,-3,-1,-99,7,8,10};
 * for (auto val : values)
 * {
 *  if (val == -99)
 *       break;
 *  else if (val == -1)
 *      continue;
 * else
 *      cout << val << endl;
 * }
 * 
 * 1
 * 2
 * 3
 * 
 * 
 * 
 * **/

int main()
{
    return 0;
}