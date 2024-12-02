/***
 * [Field width, align and fill]
 * 
 *  Default when displaying floating point values is:
 *      setw - not set by default
 *      left - when no field width, right - when using field width
 *      fill - not set by default - blank space is used
 * 
 *  Some of these manipulators affect only the next data element put on the stream
 * 
 * [Default]
 *  
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 * 
 *  std::cout << num << hello << std::endl;
 * 
 *  //Will display
 *  1234.57Hello
 * 
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 * 
 *  std::cout << num << std::endl;
 *  std::cout << hello << std::endl;
 * 
 *  // Will display
 *  1234.57
 *  Hello
 * 
 * [Field width - setw]
 * 
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 * 
 *  std::cout << std::setw(10) << num
 *            << hello << std::endl;
 * 
 *  //Will display
 *  1234567890123456789012345678901234567890
 *     1234.57Hello        //=> can see the alignment, This ruler isn't displayed by the code. Notice that the last digit in number, the 7 in this case is displayed in position 10. That's the rightmost side of the field width we set earlier. 
 *                          // Hello displays right next to the number starting in column 11. That's because the field width and the justification only apply to the next data item placed on the stream. In this case, that data item was num. So hello has no field width associated with it, and it uses just the defaults. 
 * 
 * 
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 *  std::cout << std::setw(10) << num
 *            << std::setw(10) << hello
 *            << std::setw(10) << hello << std::endl;
 * 
 *  //Will display
 *  1234567890123456789012345678901234567890
 *     1234.57     Hello     Hello      //=> Remember, we have a field width, the default justification is right. SO in this case, num is displayed right justified in a width of 10. THe first hello is displayed right justified also in a field of 10. And the last hello is also displayed right justified in the width of 10. 
 *                                      //And can see from the display in the ruler exactly what's happening. 
 * 
 * [Field width - justification]
 * 
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 * 
 *  std::cout << std::setw(10)
 *            << std::left
 *            << num        // only affects num
 *            << hello << std::endl;
 * 
 *  //Will display
 *  1234567890123456789012345678901234567890
 *  1234.57   Hello         // => In this case, set a field width of 10, and want left justification for the next data item, which is num. Num is displayed in a field width of 10, and it's left justified. Now want to display hello. Notice that hello has no field width associated with it, so it will display starting in column 11. 
 * 
 *  [Field width - setw]
 * 
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 * 
 *  std::cout << std::setw(10) << num
 *            << std::setw(10) << std::right << hello
 *            << std::setw(15) << std::right << hello
 *            << std::endl;
 * 
 *  //Will display
 *  1234567890123456789012345678901234567890
 *     1234.57     Hello          Hello         //=>Num will have a field width of 10, it will be right justified by default. The first hello will have a field width of 10, and we're explicitly setting right justification.We don't have to do this since it's the default, but we can to it to be very explicit. 
 *                                              // And the second hello will have a field width of 15, and it will also be right justified. Can see the output is exactly as we expect. Num is right justified in a field width of 10. The first hello is right justified in a field width of 10. And the final hello is right justified in a field width of 15. 
 * 
 * [Filling fixed width - setfill]
 * 
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 * 
 *  std::cout << std::setfill('-');
 *  std::cout << std::Setw(10) << num
 *            << hello << std::endl;
 * 
 * //Will display
 *  1234567890123456789012345678901234567890
 *  ---1234.57Hello     
 * 
 * 
 *  double num {1234.5678};
 *  std::string hello {"Hello"};
 * 
 *  std::cout << std::setfill(*);
 *  std::cout << std::setw(10) << num
 *            << std::setfill('-') << std::setw(10) << hello
 *            << std::setw(15) << hello
 *            << set::endl;
 * 
 * //Will display
 *  1234567890123456789012345678901234567890
 *  ***1234.57-----Hello----------Hello
 * ***/


#include <iostream>
#include <iomanip>

void ruler(){
    std::cout <<"\n12345678901234567890123456789012345678901234567890\n";
}

int main(){

    int num1{1234};
    double num2{1234.5678};
    std::string hello {"Hello"};

    //Defaults
    std::cout << "\n---Defaults--------------------------------------\n";
    ruler();
    std::cout << num1 << num2 << hello << std::endl;

    // Defaults - one per line
    std::cout << "\n---Defaults- one per line-------------------------------------\n";
    ruler();
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << hello << std::endl;

    // Set field width to 100
    // Note the default justification is right for num1 only!
    std::cout << "\n---width 10 for num 1--------------------------------------\n";
    ruler();
    std::cout << std::setw(10) << num1 << num2 << hello << std::endl;

    // Set field width to 10 for the first 2 outputs
    // Note the default justification is right for both
    std::cout << "\n---width 10 for num1 and num 2--------------------------------------\n";
    ruler();
    std::cout << std::setw(10) << num1 << std::setw(10) << num2 << hello << std::endl;

    // Set field width to 10 for all 3 outputs
    // Note the default justification is right for all
    std::cout << "\n---width 10 for num1 and num2 and hello--------------------------------------\n";
    ruler();
    std::cout << std::setw(10) << num1 << std::setw(10) << num2 << std::setw(10) << hello << std::endl;

    // Set field width to 10 for all 3 outputs and justify all left
    std::cout << "\n---width 10 for num1 and num2 and hello left for all--------------------------------------\n";
    ruler();
    std::cout << std::setw(10) << std::left << num1 << std::setw(10) << std::left << num2 << std::setw(10) << std::left << hello << std::endl;

    //setfill to a dash
    // this is persistent
    std::cout << std::setfill('-');
    std::cout << "\n---width 10 for num1 and num2 and hello left for all setfill to dash--------------------------------------\n";
    ruler();
    std::cout << std::setw(10) << std::left << num1 << std::setw(10) << std::left << num2 << std::setw(10) << std::left << hello << std::endl;

    // Set width to 10 for all, left justify all and cary the setfill character
    std::cout << "\n---width 10 for num1 and num2 and hello - setfill varies--------------------------------------\n";
    ruler();
    std::cout << std::setw(10) << std::left << std::setfill('*') << num1 
            << std::setw(10) << std::left << std::setfill('#') << num2 
            << std::setw(10) << std::left << std::setfill('-') << hello 
            << std::endl;

    std::cout << std::endl << std::endl;
    
    
    return 0;
}