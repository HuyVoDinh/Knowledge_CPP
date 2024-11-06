/***
 * This challenge is about using a collection (list) of integers and allowing the user to select option from a menu to perform operations on the list
 * 
 * Your program should display a menu options to the user as follows:
 * 
 * P - Print numbers
 * A - Add a number
 * M - Display mean of the numbers
 * S - Display the smallest number
 * L - Display the largest number
 * Q - Quit
 * 
 * Enter your choice:
 * 
 * The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
 * If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be displayed again
 * 
 * If the user enters 'P' or 'p', you should display all of the elements (ints) in the list
 * If the list is empty you should display '[] - the list is empty'
 * If the list is not empty then all the list element should be displayed inside square brackets separated by a space
 * For example [1 2 3 4 5]
 * 
 * If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
 * which you will add to the list and then display it was added. For example, if the user enters 5
 * You should display "5 added"
 * Duplicate list entries are OK
 * 
 * If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it
 * If the list is empty you should display, "Unable to calculate the mean - no data"
 * 
 * If the user enter 'S' or 's' you should display the smallest element in the list\
 * For example, if the list contains [2 4 5 1] you should display "The smallest number is 1"
 * If the list is empty you should display, "Unable to determine the smallest number - list is empty"
 * 
 * If the user enters 'L' or 'l' you should display the largest element in the list
 * For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
 * If the list is empty you should display, "Unable to determine the largest number - list is empty"
 * 
 * If the user enters 'Q' or 'q' then you should display 'Goodbye' and the program should terminate
 * 
 * Before you begin. Write out the steps you need to take and decide in what order they should be done.
 * Think about what loops you should use as well as what you will use for your selection logic
 * 
 * This exercise can be challenging! It may likely take a few attempt before you complete it -- that's OK
 * 
 * Finally, be sure to test your program as you go and at the end
 * 
 * Hint: use a vector!
 * 
 * Additional functionality if you wish to extend this program
 * 
 * - search for a number in the list and if found display the number of times it occurs in the list
 * - Clearing out the list (make it empty again) (Hint: The vector class has a clear() method)
 * - Don't allow duplicate entries
 * - Come up with your own ideas!
 * 
 * Good luck! 
 * 
 * **/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers {1,2,3,4};
    char selection {};

    do{
        cout << "P - Print numbers\n";
        cout << "A - Add a number\n";
        cout << "M - Display mean of the numbers\n";
        cout << "S - Display the smallest number\n";
        cout << "L - Display the largest number\n";
        cout << "Q - Quit\n";
        cout << "Enter your choice:\n";

        cin >> selection;

        if(selection == 'p' || selection == 'P')
        {
            if (numbers.size() == 0)
                cout << "[] - the list is empty" << endl;
            else {
                cout << "[";
                for(auto num : numbers)
                    cout << num << " ";
                cout << "]\n";
                
            }
        } else if (selection == 'a' || selection == 'A') {
            int num_to_add {};
            cout << "Enter an integer to add to the list: ";
            cin >> num_to_add;
            numbers.push_back(num_to_add);
            cout << num_to_add << " added" << endl;
        } else if (selection == 'm' || selection == 'M') {
            if (numbers.size() == 0){
                cout << "Unable to calculate mean- no data" << endl;
            } else {
                int total {};
                for (auto num : numbers) {
                    total += num;
                }
                cout << "The mean is: " << static_cast<double>(total)/numbers.size() << endl;
            }

        } else if (selection == 'S' || selection == 's') {
            if(numbers.size() == 0){
                cout << "Unable to determine the smallest - list is empty.\n";
            } else {
                int smallest = numbers.at(0);
                for (auto num : numbers){
                    if (num < smallest) {
                        smallest = num;
                    }
                }
                cout << "The smallest number is: " << smallest << endl;
            }
        } else if (selection == 'l' || selection == 'L') {
            if(numbers.size() == 0){
                cout << "Unable to determine the largest - list is empty.\n";
            } else {
                int largest = numbers.at(0);
                for (auto num : numbers){
                    if (num > largest) {
                        largest = num;
                    }
                }
                cout << "The largest number is: " << largest << endl;
            }
        } else if (selection == 'q' || selection == 'Q') {
            cout << "Goodbye\n";
        } else {
            cout << "Unknown selection, please try again\n";
        }

    } while(selection != 'q' && selection != 'Q');
}