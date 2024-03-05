#include <iostream>
using namespace std;

/***
 * In this exercise you will create a program that determines the eligibility of an individual applying for a job as a delivery driver. 

In order for the individual to be eligible, they must be 18  years of age or older, or be above the age of  15  and have their parents consent to work. Additionally they must possess a valid social security number and have no driving accidents.

Let the variable age  represent the individual's age, and the boolean variables parental_consent  represent parental consent, ssn  represent a valid social security number, and accidents   represent whether they have had any car accidents.

You do not need to declare these variables, they will be set to various values automatically by our automated tester.

For this exercise you will write your code within the parenthesis of the if  statement provided.

In the case that the person cannot work, do not display any output - our tester assumes no output means the person can't work.
 * 
 * ***/

void logical_operators(int age, bool parental_consent, bool ssn, bool accidents)
{
    if(ssn && !accidents && age >= 18 || (age > 15 && parental_consent))
    {
        cout << "Yes, you can work";
    }
}


int main()
{}