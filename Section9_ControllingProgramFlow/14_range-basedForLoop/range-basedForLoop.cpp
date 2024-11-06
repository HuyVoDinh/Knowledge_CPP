#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/***
 * [Range-based for Loop]
 * introduced in C++11
 * 
 *  for (var_type var_name : sequence)
 *  {
 *      statements;
 *  }
 * 
 * [Example]
 *  int scores [] {100,90,97};
 * 
 *  for(auto score : scores)
 *      cout << score << endl;
 * ***/

int main()
{
    // int scores[] {10,20,30};

    // for(int score:scores)
    // {
    //     cout << score << endl;
    // }

    // vector <double> temperatures {86.5,77.5,88.9,54.3};
    // double total {};
    // double average_temp {};

    // for(auto temp:temperatures)
    // {
    //     total += temp;
    // }
    
    // if(temperatures.size() != 0)
    // {
    //     average_temp = total / temperatures.size();
    // }

    // cout << fixed << setprecision(2);
    // cout << "Average temperature is " << average_temp << endl;

    for(auto val : {1,2,3,4,5})
    {
        cout << val << endl;
    }

    return 0;
}