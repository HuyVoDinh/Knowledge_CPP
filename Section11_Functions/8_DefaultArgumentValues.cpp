/****
 * When a function is called, all arguments must be supplied
 * Sometimes some of the arguments have the same values most of the time
 * 
 * We can tell the compiler to use default values if the arguments are not supplied
 * 
 * Default values can be in the prototype or definition, not both
 *  best practice - in the prototype
 *  must appear at the tail end of the parameter list
 * 
 * Can have multiple default values
 *  must appear consecutively at the tail end of the parameter list 
 * 
 * [Example - no default arguments]
 * 
 * double calc_cost(double base_cost, double tax_rate);
 * 
 * double calc_cast(double base_cost, double tax_rate){
 *      return base_cost += (base_cost * tax_rate);
 * }
 * 
 * int main()
 * {
 *      double cost = 0;
 *      cost = calc_cost (100.0, 0.06);
 *      return 0;
 * }
 * 
 * double calc_cost(double base_cost, double tax_rate = 0.06);
 * 
 * double calc_cast(double base_cost, double tax_rate){
 *      return base_cost += (base_cost * tax_rate);w
 * }
 * 
 * int main()
 * {
 *      double cost = 0;
 *      cost = calc_cost(200.0);            // will use the default tax
 *      cost = calc_cost (100.0, 0.08);     // will use 0.08 not the default
 *      return 0;
 * }
 * ***/

#include <iostream>
#include <iomanip>

using namespace std;

double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50);


void greeting(string name, string prefix = "Mr.", string suffix = "");

double calc_cost(double base_cost, double tax_rate, double shipping){
    return base_cost += (base_cost * tax_rate) + shipping;
}


void greeting(string name, string prefix = "Mr.", string suffix = "")
{
    cout << "Hello " << prefix + " " + name + " " + << suffix << endl;
}

int main(){
    double cost = 0;
    cost = calc_cost(100.0,0.08, 4.25);

    cout << fixed << setprecision(2);
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(100.0,0.08);
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(200.0);
    cout << "Cost is: " << cost << endl;

    greeting("Glen Jones", "Dr.", "M.D");
    greeting("James Rogers", "Professor", "Ph.D");
    greeting("Frank Miller", "Dr.");
    greeting("William Smith");

    cout << endl;
    return 0;
}
