/***
 * Reading a text file
Please complete the code in the function read_file.

The file name will be passed to the function by the test harness. 

Try to open the filename supplied for reading and read each word from the file and display it to cout followed by a std::endl
Be sure to test to see if the file was opened successfully.

If the file cannot be opened, please display "Error opening file" to std::cerr followed by std::endl
 * ***/
#include <iostream>
#include <fstream>

void read_file(std::string file_name) {
    //---- YOU WRITE YOUR CODE BELOW THIS LINE----
    std::ifstream in_file;
    std::string name;
    in_file.open(file_name);
    if(in_file)
    {
        while (in_file >> name){
            std::cout << name << std::endl;
        }
    }
    else 
        std::cerr << "Error opening file\n";
   
    in_file.close();
    //---- YOU WRITE YOUR CODE ABOVE THIS LINE----
}

int main(){
    read_file("data.txt");
    return 0;
}