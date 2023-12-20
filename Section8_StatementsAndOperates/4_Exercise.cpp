//Convert EUR to USD

#include <iostream>

using namespace std;

int main()
{
    const double uds_per_eur = 1.19;
    double euros = 0, dollars = 0;

    cout << "Welcome to the EUR to USD converter" << endl;
    cout << "Enter the value in EUR: ";

    cin >> euros;
    dollars = euros * uds_per_eur;
    
    cout << euros << "euros is equivalent to " << dollars << " dollars\n";
    return 0;
}