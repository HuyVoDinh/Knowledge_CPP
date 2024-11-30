/***
 * [Formatting boolean types]
 * 
 * Default when displaying boolean values is 1 or 0
 * Sometimes the strings true or false are more appropriate.
 * 
 * std::cout << (10 == 10) << std::endl;
 * std::cout << (10 == 20) << std::endl;
 * 
 * // Will display
 * 1
 * 0
 * 
 * 
 * 
 * std::cout << std::boolalpha;
 * std::cout << (10 == 10) << std::endl;
 * std::cout << (10 == 20) << std::endl;
 * 
 * // Will display
 * true
 * false
 * 
 * 
 * All further boolean output will be affected
 * std::cout << std::noboolalpha;   // 1 or 0
 * std::cout << std::boolalpha;     // true or false
 * 
 * 
 * Method version   => We can use setf method. 
 *  std::cout.setf(std::ios::boolalpha);
 *  std::cout.setf(std::ios::noboolalpha);
 * Reset to default
 *  std::cout << std::resetiosflags(std::ios::boolalpha);
 * ***/

#include <iostream>
#include <iomanip>

int main(){
    //default
    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    //Set to true/false formatting
    std::cout << std::boolalpha;        // change to true/false
    std::cout << "boolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    //setting still stays for future boolean insertions
    std::cout << "boolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    //Toggle to 0/1
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    //Set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha);
    std::cout << "boolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    //resets to default which is 0/1
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "Default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "Default (10 == 20): " << (10 == 20) << std::endl;

    return 0;
}