/***
 * If the person is not 16 or older then you should display, "Sorry, come back in n  years and be sure you own a car when you come back.", where n is how many years until the person turns 16 year old.

If the person is 16 or older but they do NOT own a car, then your program should display, "Sorry, you need to buy a car before you can drive!" .

If the person is 16 or older and they DO own a car, then your program should display, "Yes - you can drive!"
 * ***/

#include <iostream>
using namespace std;

void can_you_drive(int age, bool has_car) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    if(age >= 16)
    {
        if(!has_car)
        {
            cout <<  "Sorry, you need to buy a car before you can drive!";
        }
        else
        {
            cout << "Yes - you can drive!";
        }
    }
    else
    {
        cout << "Sorry, come back in " << 16 - age << " years and be sure you own a car when you come back.";
    }
    
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

int main()
{
    return 0;
}