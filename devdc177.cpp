#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that rearranges an integer into its largest possible value.
If the integer is already in its maximum possible value, simply return it.

Examples
superSize(123456) //654321
superSize(105) //510

Tests
superSize(513)
superSize(2020)
superSize(4194)
superSize(608719)
superSize(123456789)
superSize(700000000001)
superSize(666666)
*/

// takes number and returns the largest possible number
// that can be created using its digits
string superSize(string number){
    sort(number.begin(), number.end(),greater<char>());
    return number;
}

// function for testing
void testFunction(string number){
    cout << number << " ===> " << superSize(number) << "\n";
}

// main function
int main(){
    testFunction("123456");
    testFunction("105");
    testFunction("513");
    testFunction("2020");
    testFunction("4194");
    testFunction("608719");
    testFunction("123456789");
    testFunction("700000000001");
    testFunction("666666");
    return 0;
}