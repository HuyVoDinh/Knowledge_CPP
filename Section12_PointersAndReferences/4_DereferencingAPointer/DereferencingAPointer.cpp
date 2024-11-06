/***
 * [Dereferencing a Pointer]
 * 
 * Access the data we're pointing to - dereferencing a pointer
 * 
 * If score_ptr is a pointer and has a valid address
 * Then you can access the data at the address contained in the score_ptr using the dereferencing operator *
 * ------------
 * ***/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int score = 100;
    int *score_ptr = &score;

    cout << *score_ptr << endl;

    *score_ptr = 200;
    
    cout << *score_ptr << endl;
    cout << score << endl;


    double high_temp = 100.7;
    double low_temp = 37.4;
    double *temp_ptr = &high_temp;
    
    cout << *temp_ptr << endl;       // 100.7
    
    temp_ptr = &low_temp;
    
    cout << *temp_ptr << endl;       // 37.4


    vector<string> stoogers {"Larry" , "Moe", "Curly"};
    vector<string> *vector_ptr = nullptr;

    vector_ptr = &stoogers;
    cout << "First stooge: " << (*vector_ptr).at(0) << endl;

    cout << "Stooges: ";
    for(auto stooge: *vector_ptr)
        cout << stooge << " ";
    cout << endl;
    return 0;
}