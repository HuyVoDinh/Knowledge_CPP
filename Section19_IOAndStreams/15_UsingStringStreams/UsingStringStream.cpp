/****
 * [Using string streams]
 * 
 *  Allows us to read or write from strings in memory much as we would read and write to files
 * 
 *  Very powerful
 * 
 *  Very useful for data validation
 * 
 *  stringstream, istringstream, ostringstream
 * 
 *  1. #include <sstream>
 *  2. Declare an stringstream, istringstream, or ostringstream object
 *  3. Connect it to a std::string 
 *  4. Read/write data from/to the string stream using formatted I/O
 * 
 * [Reading from a stringstream]
 * 
 * #include <sstream>
 * 
 * int num{};
 * double total {};
 * std::string name {};
 * std::string info {"Moe 100 1234.5"};
 * 
 * std::istringstream iss {info};
 * iss >> name >> num >> total;
 * 
 * [Writing to a stringstream]
 * #include <sstream> 
 * 
 * int num {100};
 * double total {1234.5};
 * std::string name {"Moe"};
 * 
 * std::ostringstream oss {};
 * oss << name << " " << num << " " << total;       // => can use any stream manipulators to format that data that we're putting on the stream. 
 * std::cout << oss.str() << std::endl;
 * 
 * Notice that we didn't connect the ostringstream to any string object, we could have just like we did with the istringstream. The stringstream has a string buffer that is use internally and we can use that. 
 * So if want to display that string, all we have to do is call the stringstream.str method
 * 
 * [Validating input with stringstream]
 * 
 * => I want to be sure that they do enter an integer, not some invalid data like a name. 
 * 
 * int value {};
 * std::String input {};
 * 
 * std::cout << "Enter an integer: ";
 * std::cin >> input;
 * 
 * std::stringstream ss {input};       
 * if (ss >> value){             // try to extract an integer from ss and store it in value. Can do that using the stream extraction operator. 
 *      std::cout << "An integer was entered\n";
 *  } else {
 *      std::cout << "An integer was NOT entered\n";
 *  }
 * ****/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

int main(){

    int num {};
    double total {};
    std::string name {};

    std::string info {"Moe 100 1234.5"};
    std::istringstream iss {info};

    iss >> name >> num >> total;
    std::cout << std::setw(10) << std::left << name 
            << std::setw(5) << num 
            << std::setw(10) << total << std::endl;

    std::cout << "\n----------------------------------\n";

    std::ostringstream oss{};       // The stringstream class has its own string buffer. 
    oss << std::setw(10) << std::left << name       // going to write to the stream, and the stream is going to store that information in that string buffer that is has. 
        << std::setw(5) << num 
        << std::setw(10) << total << std::endl;

    std::cout << oss.str() << std::endl;

    std::cout << "\n---------Data validation-----------------------\n";

    int value {};
    std::string entry {};
    bool done = false;
    do {
        std::cout << "Please enter an integer: ";
        std::cin >> entry;      // But can't , seen how we can;t just ask the user for an integer and then do something like cin, so we could read the console input into that value variable. That doesn't work real well. Then they type strings and whey they type just silly stuff on the keyboard, it's going to fail. So we've got to have a better way to do that. We have to be able to validate the type that they;re entering.
        std::istringstream validator {entry};// So rather than read directly into an integer, we're going to read into a string. And we're going to do this in a loop, and we're going to keep doing it until they enter something that's valid. 
        if (validator >> value) // They can type in numbers letters decimals whatever they want. We'll try to validate that to make sure that what they typed in is an integer. This is where the stringstream comes in, and we're going to use an istringstream. Here we could have just used a regular stringstream, it doesn't really matter because it goes both ways, but this is an input stringstream. And going to call it validator, could have called it anything you want. Be going  to try to extract a value from the stream. 
            done = true;
        else 
            std::cout << "Sorry, that's not an integer\n";

        // discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');// Example with 12.38, if extract in validator, 12 will be put into value. But then have all this stuff left over (.38) on the stream. So the next stream read doesn't really know .38. So ignore, because that's where we're reading data from.  We're going ignore, everything in that stream up to the new line, and that's what we're doing here, and th'at where that limits header file comes in. Using std::numeric_limits up to whatever the std::stream size is and that's dependent on your platform. So however big that stream is the maximum number. 
        //I'm getting rid of all of .38 stuff, just ignoring all that clearing out that stream. So that the next time read from the stream, it's clean and there's nothing left over. Remember, the user could have typed in: 12 Hello there. grabs that 12 and t hat 12 goes into value. And condition is true, So we've got an integer. They did type in an integer. They typed in a bunch of other stuff as well. But what we can do is we can grab the 12 and just delete that rest of that stuff. So the next time we read,  we're clean.  
    } while(!done);
    std::cout << "You entered the integer: " << value << std::endl;

    std::cout << std::endl;

    return 0;
}