/***
 * [Input files (fstream and ifstream)]
 * 
 * fstream and ifstream are commonly used for input files
 * 
 *  1. #include <fstream> 
 *  2. Declare an fstream or ifstream object
 *  3. Connect it to a file on your file system (opens it for reading)
 *  4. Read data from the file via the stream
 *  5. Close the stream
 * 
 * [Opening a file for reading with (fstream)]
 * 
 *  std::fstream in_file {"../myfile.txt", std::ios::in};
 * 
 * Opening for reading in binary mode       => This is necessary when reading non-text files that contain binary data. 
 *  std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary};
 * 
 * fstream class can actually open up a file for reading and writing at the same time. 
 * 
 * [Opening a file for reading with (ifstream)]
 * ifstream is used for input files only. 
 * std::ios::in optional since it's already the default. 
 * 
 *  std::ifstream in_file {"../myfile.txt", std::ios::in};
 * 
 *  std::ifstream in_file {"../myfile.txt"};
 * 
 *  Open for reading in binary mode
 * 
 *  std::ifstream in_file {"../myfile.txt", std::ios::binary};
 * 
 * [Opening a file for reading with open]
 * 
 *  std::ifstream in_file;
 *  std::string filename;
 *  std::cin >> filename;       // get the file name
 * 
 *  in_file.open(filename);
 *  // or
 *  in_file.open(filename, std::ios::binary);
 * 
 * [Check if file opened successfully (is_open)]
 * have to be sure that the file was opened successfully. Maybe it wasn't found or there was some sort of hardware or permission issue. 
 * 
 *  if(in_file.is_open()){
 *      // read from it
 *  } else {
 *      // file could not be opened
 *      // does it exist?
 *      // should the program terminate?
 *  }
 * 
 * [Check if file opened successfully - test the stream object]
 * 
 *  if (in_file) {      // just check the object 
 *      // read from it
 *  } else {
 *      // file could not be opened
 *      // does it exist?
 *      // should the program terminate?
 *  }
 * 
 * [Closing a file]
 *  Always close any open files to flush out any unwritten data
 * 
 * in_file.close();
 * 
 * [Reading from files using (>>)]
 * 
 *  We can use the extraction operator for formatted read
 *  Same way we used it with cin
 * 
 *  100
 *  255.67
 *  Larry
 * 
 *  int num {};
 *  double total {};
 *  std::string name{};
 * 
 *  in_file >> num;
 *  in_file >> total >> name;
 * 
 * [Reading from files using getline]
 *  We can use getline to read the file one line at a time. Since the extraction operators will stop when they see any white space. So can use the getline method.
 * 
 *  This is a line
 * 
 *  std::string line{};
 *  std::getline(in_file, line);
 * 
 * 
 * [Reading text file one line at a time]
 * 
 *  std::ifstream in_file {"../myfile.txt"};        // open file
 *  std::string line{};
 * 
 *  if(!in_file){       // check if file is open
 *      std::cerr << "File open error\n";
 *      return 1;
 *  }
 *  while (!in_file.eof()){     // while not at the end
 *      std::getline(in_line, line);        // read a line
 *      cout << line << std::endl;
 *  }
 *  in_file.close();        // close the file
 * 
 *  -------
 *  std::ifstream in_file {"../myfile.txt"};        // open file
 *  std::string line {};
 * 
 *  if(!in_file){       // check if file is open
 *      std::cerr << "File open error\n";
 *      return 1;       // exit the program (main)
 *  }
 *  while (std::getline(in_file, file))         // read a line      => return true value when the read was successful. 
 *      cout << line << std::endl;              // display the line
 *  
 *  in_file.close();        // close the file
 * 
 * [Reading text file one character at a time (get)]
 * 
 *  std::ifstream in_file {"../myfile.txt"};        // open file
 *  char c;
 * 
 *  if (!in_file){          // check if file is open
 *      std::cerr << "File open error\n";
 *      return 1;
 *  }
 *  while (in_file.get(c))      // read a character
 *      cout << c;                  //display the character
 * 
 *  in_file.close();            // close the file 
 * ***/

#include <iostream>
#include <fstream>
#include <iomanip>

int main(){

    std::ifstream in_file;
    std::string line;
    int num;
    double total;

    in_file.open("test.txt");
    if (!in_file){
        std::cerr << "Problem opening file\n";
        return 1;
    }

    std::cout << "File is good to go\n";

    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    
    
    in_file.close();

    in_file.open("test2.txt");
    if(!in_file){
        std::cerr << "Problem opening file\n";
        return 1;
    }

    while(!in_file.eof()){
        in_file >> line >> num >> total;
        std::cout << std::setw(10) << std::left << line
                << std::setw(10) << num 
                << std::setw(10) << total 
                << std::endl;
    }
    in_file.close();
    
    return 0;
}