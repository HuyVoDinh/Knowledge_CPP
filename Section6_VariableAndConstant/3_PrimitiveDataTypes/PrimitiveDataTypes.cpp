#include <iostream>
using namespace std;

int main()
{
    /****
     * Fundamental data types implemented directly by the C++ language
     * 
     * Character types
     * Integer types
     *      signed and unsigned
     * Floating-point types
     * Boolean type
     * 
     * Size and precision is often compiler-dependent
     *      #include <climits>
     * ***/

    /***
     * [Type sizes]
     * Expressed in bits
     * The more bits the more values that can be represented
     * The more bits the more storage required
     * 
     * Size (in bits) 
     * 8 = 2^8
     * 16 = 2^16
     * 32 = 2^32
     * 64 = 2^64
     * ***/

    /***
     * [Character Types]
     * Used to represent single character. 'A', 'X', '@'
     * Wider types are used to represent wide character sets
     * Type Name    | Size/Precision
     * char         | Exactly one byte. At least 8 bits
     * char16_t     | At least 16 bits
     * char32_t     | At least 32 bits
     * wchar_t      | can represent the largest available character set
     * ***/

    char middle_initial {'H'};
    cout << "My middle initial is " << middle_initial << endl;

    /***
     * [Integer types]
     * 
     * Type name            | Size/Precision
     * signed short int     | At least 16 bits
     * signed int           | At least 16 bits
     * signed long int      | At least 32 bits
     * signed long long int | At least 64 bits
     * unsigned short int     | At least 16 bits
     * unsigned int           | At least 16 bits
     * unsigned long int      | At least 32 bits
     * unsigned long long int | At least 64 bits
     * ***/
    unsigned short int exam_score {55};
    cout << "My exam score was " << exam_score << endl;

    int countries_represented {65};
    cout << "There were " << countries_represented << " countries represented in my meeting" << endl;

    long people_in_florida {20610000};
    cout << "There are about " << people_in_florida << " people in Florida" << endl;

    long long people_on_earth {7'600'000'000};
    // If declare this variable is long type. Error is error: narrowing conversion of '7600000000' from 'long long int' to 'long int'
    // If I did a regular initialization like a c style initialization with an equal sign or an assignment statement
    //      Ex: long people_on_earth = 7'600'000'000;
    //      Result is -989934592-> It's an overflow -> We didn't get error
    //Change it from long to long long
    cout << "There are about " << people_on_earth << " people on earth" << endl;

    long long distance_to_alphe_centaun {9'461'000'000'000};
    cout << "The distance to alpha centaun is " << distance_to_alphe_centaun << " kilometers" << endl;

    /***
     * [Floating-point Type]
     * Used to represent non-integer numbers
     * Represented by mantissa and exponent (scientific notation)
     * Precision is the number of digits in the mantissa
     * Precision and size are complier dependent
     * 
     * Type name    | Size/Typical Precision                    | Typical Range
     * float        | / 7 decimal digits                        | 1.2 x 10^-38 to 3.4 x 10^38
     * double       | No less than float / 15 decimal           | 2.2 x 10^-308 to 1.8 x 10^308
     * long double  | No less than double / 19 decimal digits   | 3.3 x 10^-4932 to 1.2 x 10^4932
     *  **/

    float car_payment {401.23};
    cout << "My car payment is " << car_payment << endl;

    double pi {3.14159};
    cout << "Pi is " << pi << endl;

    long double large_amount {2.7e120};
    cout << large_amount << " is a very big number" << endl;
    /***
     * [Boolean Type]
     * Used to represent true and false
     * Zero is false
     * Non-zero is true
     * ***/

    bool game_over {false};
    cout << "The value of gameOver is " << game_over  << endl;


    // [Overflow example]

    short value1 {30000};
    short value2 {1000};
    short product {value1 * value2};

    cout << "The sum of " << value1 << " and " << value2 << " is " << product << endl;

    
    return 0;
}