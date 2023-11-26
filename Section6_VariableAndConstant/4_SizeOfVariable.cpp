#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    /***
     * The sizeof operator
     *      determines the size in bytes of a type or variable
     *      Ex: sizeof(int)
     *          sizeof(double)
     * **/

    /***
     * The climits and cfloat include files contain size and precision information about your implementation of C++
     *      INT_MAX
     *      INT_MIN
     *      LONG_MIN
     *      LONG_MAX
     *      ...
     * **/

        cout << "sizeof information" << endl;
        cout << "======================" << endl;

        cout << "char: " << sizeof(char) << " bytes" << endl;
        cout << "int: " << sizeof(int) << " bytes" << endl;
        cout<< "unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
        cout << "short: " << sizeof(short) << " bytes" << endl;
        cout << "long: " << sizeof(long) << " bytes" << endl;
        cout << "long long: " << sizeof(long long)  << " bytes" << endl;

        cout << "======================" << endl;

        cout << "Minimum values: " << endl;
        cout << "char: " << CHAR_MIN << endl;
        cout << "int: " << INT_MIN << endl;
        cout << "short: " << SHRT_MIN << endl;
        cout << "long: " << LONG_MIN << endl;
        cout << "long long: " << LLONG_MIN << endl;

        cout << "======================" << endl;

        cout << "Maximum values: " << endl;
        cout << "char: " << CHAR_MAX << endl;
        cout << "int: " << INT_MAX << endl;
        cout << "short: " << SHRT_MAX << endl;
        cout << "long: " << LONG_MAX << endl;
        cout << "long long: " << LLONG_MAX << endl;

        //sizeof can also be used with variable names
        cout << "sizeof using variable names" << endl;
        int age{21};
        cout << "Age is " << sizeof(age) << " bytes" << endl;
        //or
        cout << "Age is " << sizeof age << " bytes" << endl;
}