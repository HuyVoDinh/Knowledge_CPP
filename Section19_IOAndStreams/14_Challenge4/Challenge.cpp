/****
 * Copy Text with line numbers
 * 
 * I have provided the text to Text in a file named text.txt
 * 
 * For this challenge you have to make copy of the text file and save it to another file. 
 * This new copy should have line numbers at the beginning of each line in the play. 
 * Please format the numbers nicely so everything lines up. 
 * ***/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main(){

    std::ifstream in_file {"text.txt"};
    std::ofstream out_file {"text_out.txt"};

    if(!in_file.is_open()){
        std::cerr << "Error opening input file\n";
        return 1;
    }
    if(!out_file.is_open()){
        std::cerr << "Error opening input file\n";
        return 1;
    }

    std::string line {};
    int line_number {0};
    while (getline(in_file, line)){
        if (line == "")
            out_file << std::endl;
        else{
            ++line_number;
            out_file << std::setw(7) << std::left << line_number << line << std::endl;
        }
    }

    std::cout << "\nCopy complete\n";
    in_file.close();
    out_file.close();
    return 0;
}