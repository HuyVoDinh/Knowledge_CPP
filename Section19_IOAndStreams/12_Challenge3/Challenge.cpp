/****
 * Ask the user to enter a word
 * Process the Romeo and Juliet file and determine how many total words there are and how many times the word the user entered appears as a substring of a word in the play.
 * 
 * For example. 
 * If the user enters: love
 * Then the words love, lovely, and beloved will all be considered matches. 
 * You decide whether you want to be case sensitive or not. My solution is case sensitive
 * 
 * Sample are some sample runs: 
 *  
 *  Enter the substring to search for: love
 *  xxxxxx words were searched... 
 *  The substring love was found xx times
 * 
 *  Enter the substring to search for: Romeo
 *  xxxxxx words were searched... 
 *  The substring love was found xx times
 * 
 *  Enter the substring to search for: Juliet
 *  xxxxxx words were searched... 
 *  The substring love was found xxx times
 * ****/

#include <iostream>
#include <iomanip>
#include <fstream>

bool find_substring(const std::string &word_to_find, const std::string &target){
    std::size_t found = target.find(word_to_find);
    if (found != std::string::npos)
        return true;
    return false;
}

int main() {

    std::ifstream in_file {};
    std::string word_to_find {};
    std::string word_read {};
    int word_count {0};
    int match_count {0};
    
    in_file.open("challenge.txt");
    if(!in_file){
        std::cerr << "Problem opening file\n";
        return 1;
    }

    std::cout << "Enter the substring to search for: ";
    std::cin >> word_to_find;
    while (in_file >> word_read){
        ++word_count;
        if(find_substring(word_to_find, word_read)){
            ++match_count;
        }
    }

    std::cout << word_count << " words were searched...\n";
    std::cout << "The substring " << word_to_find << " was found " << match_count << " times \n";

    return 0;
}