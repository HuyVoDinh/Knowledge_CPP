/***
 * Add an overloaded constructor to an existing class
 * 
 * Given the dog class defined in dog.h, add an overloaded constructor that expect a std::string and int as parameters
 * 
 * The constructor should allow us to create Dog objects as follows:
 *      Dog fido {"Fido", 4};
 *      Dog spot {"Spot", 5};
 * ***/
#include <string>
#include "15_Dog.h"
using namespace std;

int main()
{
    Dog fido {"Fido", 4};
    Dog spot {"Spot", 5};
    return 0;
}