/****
 * [Output files (fstream and ofstream)]
 * 
 * fstream and ofstream are commonly used for output files
 * 
 *  1. #include <fstream> 
 *  2. Declare an fstream or ofstream object
 *  3. Connect it to a file on your file system (opens it writing)
 *  4. Write data to the file via the stream
 *  5. Close the stream
 * 
 *  Output files will be created if they don't exist    => But have to make sure that if provide a path along with the file name when we open the file that path must exists. Otherwise, get an error when creating the file.
 *  Output files will be overwritten (truncated) by default
 *  Can be opened so that new writes append
 *  Can be open in text or binary modes
 * 
 * 
 * [Opening a file for writing with (fstream)]
 *  std::fstream out_file {"../myfile.txt", std::ios::out};     => this means to open the file in output mode. 
 * By default, files are opened in text mode. 
 * 
 * Open for writing in binary mode
 *  std::fstream out_file {"../myfile.txt", std::ios::out | std::ios::binary};
 * 
 * [Opening a file for writing with (ofstream)]
 * 
 *  std::ofstream out_file {"../myfile.txt", std::ios::out};
 * 
 *  std::ofstream out_file {"../myfile.txt"};
 * 
 * Opening for writing in binary mode
 *  std::ofstream out_file {"../myfile.txt", std::ios::binary};
 * 
 * By default, the file is opened for truncation, and can explicitly specify.
 * // truncate  (discard content) when opening
 *  std::ofstream out_file {"../myfile.txt", std::ios::trunc};
 * 
 *  If want the file open, but want all further output to append to the end of the file, then can use std::ios::app when open file. 
 * // append on each write
 *  std::ofstream out_file {"../myfile.txt", std::ios::app};
 * 
 * Want to open a file that exists  and want to set the initial position of the next right to the end of the existing file. 
 * // seek to end of stream when opening
 *  std::ofstream out_file {"../myfile.txt", std::ios::ate};
 * But we're free to move around using random access. We aren't going to use random access file.
 * 
 * [Opening a file for writing with open]
 *  std::ofstream out_file;
 *  std::string filename;
 *  std::cin >> filename;       // get the file name
 * 
 *  out_file.open(filename);
 *  // or
 *  out_file.open(filename, std::ios::binary);
 * 
 * [Check if file opened successfully (is_open)]
 *  if (out_file.is_open()){
 *      // read from it
 *  } else {
 *      // file could not be created or opened
 *      // does it exist?
 *      // should the program terminate?
 *  }
 * 
 *  [Check if file opened successfully - test the stream object]
 *  => If the stream object was not instantiated, then this will return false and can decide what to do next. Otherwise, it's good to go, and can proceed writing to the file. 
 *  if (out_file){  // just check the object
 *      // read from it
 *  } else {
 *      // file could not be opened
 *      // does it exist?
 *      // should the program terminate?
 *  }
 * 
 *  
 * [Closing a file]
 *  Always close any open files to flush out any unwritten data => this is very important since it flushes out any buffers that may not have been written out to file yet. 
 * 
 *      out_file.close();     
 * 
 * [Writing to files using (<<)]
 * 
 *  We can use the insertion operator for formatted write
 *  Same way we used it with cout
 * 
 *  int num {100};
 *  double total {255.67};
 *  std::string name {"Larry"};
 * 
 *  out_file << num << "\n"
 *          << total << "\n"
 *          << name << std::endl;
 * 
 * [Copying a text file one line at a time]
 *  std::ifstream in_file {"../myfile.txt"};        // open file
 *  std::ofstream out_file {../copy.txt};           // If the output file does not exist, it'll be created. If it does exist, it will be truncated.
 * 
 *  if (!in_file) {     // check if file is open
 *      std::cerr << "File open error\n";
 *      return 1;       // exit the program (main)
 *  }
 *  if (!out_file) {    // check if file is open
 *      std::cerr << "File create error\n";
 *      return 1;       // exit the program (main)
 *  }
 * 
 *  std::string line {};
 * 
 *  while(std::getline(in_file, line))          // read a line
 *      out_file << line << std::endl;          // write a line
 * 
 *  in_file.close();        // close the files
 *  out_file.close();
 * 
 * [Copying a text file one character at a time (get/put)]
 * 
 *  std::ifstream in_file {"../myfile.txt"};        // open file
 *  std::ofstream out_file {"../copy.txt"};         
 * 
 *  if (!in_file){           // check if file is open
 *      std::cerr << "File open error\n";
 *      return 1;
 *  }
 * 
 *  if (!out_file){             // check if file is open
 *      std::cerr << "File create error\n";
 *      return 1;
 *  }
 *  char c;
 *  while (in_file.get(c))      // read a character
 *      out_file.put(c);
 * 
 *  in_file.close();            // close the files
 *  out_file.close();
 * ***/
#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ofstream out_file1 {"output.txt", std::ios::app}; 
    if(!out_file1){
        std::cerr << "Error creating file\n";
        return 1;
    }

    std::string line;
    std::cout << "Enter something to write to the file: ";
    std::getline(std::cin, line);
    out_file1 << line << std::endl;

    out_file1.close();

    // Copy file
    std::ifstream in_file {"../12_Challenge3/challenge.txt"};
    std::ofstream out_file {"copy.txt"};

    if(!in_file){
        std::cerr << "Error opening input file\n";
        return 1;
    }
    if(!out_file){
        std::cerr << "Error opening output file\n";
        return 1;
    }

    while (std::getline(in_file, line))
        out_file << line << std::endl;

    std::cout << "File copied\n";

    // Copy char
    char c;
    while(in_file.get(c))
        out_file.put(c);

    std::cout << "File copied\n";
    in_file.close();
    out_file.close();
    return 0;

}