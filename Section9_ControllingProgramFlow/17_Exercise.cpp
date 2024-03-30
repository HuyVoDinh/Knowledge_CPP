// Given a vector of integers, determine how many integers are present before you see the value -99 . Note, it's possible -99  is not in the vector! If -99  is not in the vector then the result will be equal to the number of elements in the vector.

// The final result should be stored in an integer variable named count .

#include <iostream>
#include <vector>
using namespace std;

int count_numbers(const vector<int> &vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count = 0;
    int i = 0;
    while (i < vec.size() && vec[i] != -99)
    {
        count ++;
        i++;
        /* code */
    }
    
    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE-----
    return count;
}

int main()
{
    const vector<int> vec {1,2,3,4,-99};
    cout << count_numbers(vec);
    return 0;
}