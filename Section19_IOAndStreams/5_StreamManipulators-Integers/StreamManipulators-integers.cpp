/***
 * [Formatting Integer types]
 * 
 * Default when displaying integer values is: 
 *  dec (base 10)       => also have option of displaying integers in base 8, which is called octal and base 16 which is called hexadecimal. Remember, computers work in base 2 or binary. So we need alternate base systems. It's not so intuitive to convert decimal to binary. The alternate bases are often used in computing since they allow us to group information more like a computer would.
 *  noshowbase - prefix used to show hexadecimal or octal
 *  nouppercase - when displaying a prefix and hex values it will be lower case
 *  noshowpos - no '+' is displayed for positive numbers
 * 
 * These manipulators affect all further output to the stream
 * 
 * int num {255};
 * std::cout << std::dec << num << std::endl;
 * std::cout << std::hex << num << std::endl;
 * std::cout << std::oct << num << std::endl;
 * 
 * //Will display
 * 255
 * ff
 * 377
 * 
 * 
 * 
 * int num {255};
 * std::cout << std::showbase;      // std::noshowbase
 * std::cout << std::dec << num << std::endl;
 * std::cout << std::hex << num << std::endl;
 * std::cout << std::oct << num << std::endl;
 * 
 * //Will display
 * 255
 * 0xff         // note the 0x prefix for hexadecimal
 * 0377         // note the o prefix for octal
 * 
 * 
 * int num {255};
 * 
 * std::cout << std::showbase << std::uppercase;
 * std::cout << std::hex << num << std::endl;
 * //Will display
 * 0XFF     //Note capitalized XFF
 * 
 * 
 * int num1{255};
 * int num2{-255};
 * 
 * std::cout << num1 << std::endl;
 * std::cout << num2 << std::endl;
 * 
 * std::cout << std::showpos;       //std::noshowpos
 * 
 * std::cout << num1 << std::endl;  // +255
 * std::cout << num2 << std::endl;  // -255
 * 
 * 
 * [Setting/resetting integer types]
 * 
 *  Set using setf
 *      std::cout.setf(std::ios::showbase);
 *      std::cout.setf(std::ios::uppercase);
 *      std::cout.setf(std::ios::showpos);
 * 
 *  Reset to defaults
 *      std::cout << std::resetiosflags(std::ios::basefield);
 *      std::cout << std::resetiosflags(std::ios::showbase);
 *      std::cout << std::resetiosflags(std::ios::showpos);
 *      std::cout << std::resetiosflags(std::ios::uppercase);
 * ***/

#include <iostream>
#include <iomanip>

int main(){

    int num{255};
    
    //Displaying using different bases
    std::cout << "\n-------------------------------------------\n";
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    
    //Displaying showing the base prefix for hex and oct
    std::cout << "\n-------------------------------------------\n";
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    //Displaying the hex value in uppercase
    std::cout << "\n-------------------------------------------\n";
    std::cout << std::showbase << std::uppercase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    //Display the hex value in uppercase
    std::cout << "\n-------------------------------------------\n";
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    //Display the + sign in front of positive base 10 numbers
    std::cout << "\n-------------------------------------------\n";
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    //resetting to default
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    std::cout << "\n-------------------------------------------\n";
    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << "Decimal default: " << num << std::endl;

    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::nouppercase << num << std::endl; 
    
    std::cout << "Octal: " << std::oct << num << std::endl;
    std::cout << "Hexadecimal: " << std::hex << std::showbase << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;
    return 0;
}