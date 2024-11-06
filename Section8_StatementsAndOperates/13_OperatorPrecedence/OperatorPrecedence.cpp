#include <iostream>
using namespace std;

int main()
{
    /***
     * [Operator Precedence]
     * 
     * |                Operator                |       Associativity       |
     * |====================================================================|
     * |            []  ->  /  ()               |       left to right       |
     * | ++ -- not -(unary) *(de-ref) & size of |       right to left       |
     * |            *  /  %                     |       left to right       |
     * |            +   -                       |       left to right       |
     * |            <<  >>                      |       left to right       |
     * |        <  <=  >  >=                    |       left to right       |
     * |        ==      !=                      |       left to right       |
     * |            &                           |       left to right       |
     * |            ^                           |       left to right       |
     * |            |                           |       left to right       |
     * |            &&                          |       left to right       |
     * |            ||                          |       left to right       |
     * |        =  op=  ?:                      |       right to left       |
     * |====================================================================|
     * 
     * What is associativity?
     * Use precedence rules when adjacent operators are different
     * 
     * expr1 op1 expr2 op2 expr3            //precedence
     * 
     * Use associativity rules when adjacent operators have the same precedence
     * 
     * expr1 op1 expr2 op1 expr3            // associativity
     * 
     * Use parenthesis to absolutely remove any doubt
     * 
     * [Example]
     * 
     * result = num1 + num2 * num3;
     * result = (num1 + (num2 * num3));
     * 
     * result1 = num1 + num2 - num3;
     * result1 = ((num1 + num2) - num3);
     * ***/
    return 0;
}