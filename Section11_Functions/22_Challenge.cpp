/***
 * [Challenge - Solution]
 * Recall the challenge from Section 9 below
 * Your challenge for section 11 is to modularize your solution to the Section 9
 * challenge by refactoring your solution so that it uses uses functions
 * 
 * Here are a few hints:
 *  - Create functions for each major function
 *  - Keep the functions small
 *  - Remember the Boss/Worker analogy
 *  - Keep the vector declaration  in the main function and pass the vector object to any function that requires it
 * 
 *  DO NOT move the vector object outside main and make it a global variable
 * 
 *  - You can start by defining a function that displays the menu
 *  - You can then define a function that reads the selection from the user and returns it in uppercase
 *  - Create functions for each menu option
 *  - Create functions that display the list of numbers, calculates the mean and so forth
 * 
 * Take it one function at a time and take your time
 * If you get frustrated, take a break -- this isn;t as easy as it looks the first time you do it
 * 
 * Finally, don't forget to use function prototypes
 * 
 * Good luck -- I know you can do it.
 * ***/
#include <iostream>
#include <vector>
using namespace std;

//Prototypes for displaying the menu and getting user selection-

void display_menu();
char get_selection();

//Menu handling function prototypes
void handle_display(const vector<int> &v);
void display_list(const vector<int> &v);
double calculate_mean(const vector<int> &v);
void handle_add(vector<int> &v);
void handle_mean(const vector<int> &v);
void handle_find(const vector<int> &v);
void handle_smallest(const vector<int>v);
void handle_largest(const vector<int>v);
void handle_quit();
void handle_unknown();

//Prototypes for functions that work with the list to display it, calculate mean, etc
void display_list(const vector<int> &v);
double calculate_mean(const vector<int> &v);
int get_smallest(const vector<int> &v);
int get_largest(const vector<int> &v);
bool find(const vector<int> &v, int target);



int main(){
    vector<int>numbers;                 //our list of numbers
    char selection{};

    do{
        display_menu();
        selection = get_selection();
        switch(selection){
            case 'P':
                handle_display(numbers);
                break;
            case 'A':
                handle_add(numbers);
                break;
            case 'M':
                handle_mean(numbers);
                break;
            case 'S':
                handle_smallest(numbers);
                break;
            case 'L':
                handle_largest(numbers);
                break;
            case 'F':
                handle_find(numbers);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_unknown();
        }
    } while (selection != 'Q');
    cout << endl;
    return 0;
}


// This function displays the menu to the console
void display_menu(){
    cout << "\nP - Print numbers\n";
    cout << "A - Add a number\n";
    cout << "M - Display mean of the numbers\n";
    cout << "S - Display the smallest number\n";
    cout << "L - Display the largest number\n";
    cout << "F - Find a number\n";
    cout << "Q- Quit\n";
    cout << "\nEnter your choice: "; 
}

char get_selection(){
    char selection {};
    cin >> selection;
    return toupper(selection);
}

/***
 * This function is called when the user selects the display list option from the main menu
 * Note that the parameter is a const reference parameter this function should NOT modify the list of numbers
 * ****/

void handle_display(const vector<int> &v){
    if(v.size() == 0)
        cout << "[] - the list is empty\n";
    else
        display_list(v);
}

/***
 * This function is called when the user selects add a number to the list from the main menu
 * Note that the vector parameter must NOT be const since it will be changing the list of numbers
 * ***/

void display_list(const vector<int> &v){
    cout << "[ ";
    for(auto num : v)
        cout << num << " ";
    cout << "]\n";
}

/***
 * This function expects a list of integers as a vector and returns the calculated mean
 * Note that the parameter is a const reference parameter this function should NOT modify the list of numbers
 * Note: the list must not be empty
 * **/

double calculate_mean(const vector<int> &v){
    int total {};
    for(auto num : v){
        total += num;
    }
    return static_cast<double>(total)/v.size();
}

/***
 * This function is called when the user selects add a number to the list from the main menu
 * 
 * Note that the vector parameter must NOT be const since it will be changing the list of numbers
 * **/

void handle_add(vector<int> &v){
    int num_to_add {};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    v.push_back(num_to_add);
    cout << num_to_add << " added\n";
}

/***
 * This function is called when the user selects calculate the mean from the main menu
 * 
 * Note that the parameter is a const reference parameter this function should NOT modify the list of numbers
 * ***/

void handle_mean(const vector<int> &v){
    if(v.size() == 0)
        cout << "Unable to calculate mean - list is empty\n";
    else
        cout << "The mean is " << calculate_mean(v) << endl;
}


int get_smallest(const vector<int> &v){
    int smallest = v.at(0);
    for(auto num : v){
        if(num < smallest)
            smallest = num;
    }
    return smallest;
}

int get_largest(const vector<int> &v){
    int largest = v.at(0);
    for(auto num : v){
        if(num > largest)
            largest = num;
    }
    return largest;
}


void handle_smallest(const vector<int> v){
    cout << "The smallest is: " << get_smallest(v) << endl;
}

void handle_largest(const vector<int> v){
    cout << "The smallest is: " << get_largest( v) << endl;
}

void handle_find(const vector<int> &v){
    int target {};
    cout << "Enter the number to find: ";
    cin >> target;
    if(find(v,target)){
        cout << target << " was found\n";
    }
    else {
        cout << target << " wasn't found\n";
    }
}

bool find(const vector<int> &v, int target){
    for(auto num:v){
        if(num == target){
            return true;
        }
        return false;
    }
}

void handle_quit(){
    cout << "Goodbye\n";
}

void handle_unknown(){
    cout << "Unknown selection - try again\n";
}