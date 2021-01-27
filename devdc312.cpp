#include <bits/stdc++.h>
using namespace std;

/*
You have to create a function calcType, which receives 3 arguments:
2 numbers, and the result of an unknown operation performed on
them (also a number).

Based on those 3 values you have to return a string, that describes
which operation was used to get the given result.

The possible return strings are:
"addition", "subtraction", "multiplication", "division".

In case of division you should expect that the result of
the operation is obtained by using / operator on the input values

Example:
calcT_type(1, 2, 3) --> 1 ? 2 = 3 --> "addition"

Tests
calc_type(1, 2, 3)
calc_type(10, 5, 5)
calc_type(10, 4, 40)
calc_type(9, 5, 1.8)
*/

string calc_type(float a, float b, float c){
    if(a + b == c) return "addition";
    if(a - b == c) return "subtraction";
    if(a * b == c) return "multiplication";
    if(b != 0 && a / b == c) return "division";
    return "not supported";
}

// main function
int main(){
    cout << calc_type(1, 2, 3) << "\n";
    cout << calc_type(10, 5, 5) << "\n";
    cout << calc_type(10, 4, 40) << "\n";
    cout << calc_type(9, 5, 1.8) << "\n";
    return 0;
}
