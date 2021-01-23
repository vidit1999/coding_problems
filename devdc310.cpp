#include <bits/stdc++.h>
using namespace std;

/*
Implement a function which will convert the given
boolean value into its string representation.

So for the boolean false, return "false"
and for the boolean true, return "true"
*/

string booleanToString(bool b){
    return b ? "true" : "false";
}

// main function
int main(){
    cout << booleanToString(true) << "\n";
    cout << booleanToString(false) << "\n";
    cout << booleanToString(0) << "\n";
    cout << booleanToString(1) << "\n";
    return 0;
}
