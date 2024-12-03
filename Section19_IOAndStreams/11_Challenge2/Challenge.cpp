/****
 * Write a program that reads a file named 'responses.txt' that contains the answer key for a quiz as well as student responses for the quiz. 
 * 
 * The answer key is the first item in the file. 
 *  Student1 name
 *  Student1 responses
 *  Student2 name
 *  Student2 responses
 * ... 
 * 
 * Here is a sample file
 *  ABCDE
 *  Frank
 *  ABCDE
 *  Larry
 *  ABCDE
 *  Moe
 *  BBCDE
 *  Curly
 *  BBAAE
 *  Michael
 *  BBCDE
 * 
 * You should read the file and display: 
 * Each student's name and score (#correct out of 5)
 * At the end, the class average should be displayed
 * You may assume that data in the file is properly formatted
 * 
 * Program should output to the console the following
 * Student          Score
 * ------------------------------
 * Frank                5
 * Larry                3
 * Moe                  4
 * Curly                2
 * Michael              4
 * ------------------------------
 * Average score        3.6
 * ****/
#include <iostream>
#include <fstream>
#include <iomanip>

void print_header(){
    std::cout << std::setw(15) << std::left << "Student"
            << std::setw(5) << "Score" << std::endl;
    std::cout <<std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(double average){
    std::cout << std::setw(20) << std::setfill('-') << "\n";
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << std::left << "Average score"
            << std::setw(5) << std::right << average;
}

void print_student(const std::string &student, int score){
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << student << std::setw(5) << std::right << score << std::endl;
}

//return the number of correct responses
int process_response(const std::string &response, const std::string &answer_key){
    int score {0};
    for(size_t i = 0; i < answer_key.size(); ++ i){
        if (response.at(i) == answer_key.at(i)){
            score++;
        }
    }
    return score;
}

int main(){
    std::ifstream  in_file;
    std::string answer_key {};
    std::string name {};
    std::string response {};
    int running_sum {0};
    int total_students {0};
    double average_score {0.0};

    in_file.open("responses.txt");
    if(!in_file){
        std::cerr << "Problem opening file\n";
        return 1;
    }

    in_file >> answer_key;

    print_header();
    
    while(in_file >> name >> response){
        ++total_students;
        int score = process_response(response, answer_key);
        running_sum += score;
        print_student(name,score);
    }

    if (total_students != 0)
        average_score = static_cast<double>(running_sum)/total_students;

    print_footer(average_score);

    in_file.close();
    std::cout << std::endl << std::endl;
    return 0;


}