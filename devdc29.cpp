#include <bits/stdc++.h>
using namespace std;

/*
Can you check to see if a string has the same amount of 'x's and 'o's?

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false

Note: The method must return a boolean and be case insensitive. The string can contain any character
*/

bool XO(string s){
    int xCount = 0, oCount = 0;
    for(char c: s){
        if(c == 'X' || c == 'x')
            xCount++;
        else if(c == 'O' || c == 'o')
            oCount++;
    }
    return xCount == oCount;
}

string test(string s){
    if(XO(s))
        return "True";
    return "False";
}

// main function
int main(){
    cout << test("ooxx") << "\n";
    cout << test("xooxx") << "\n";
    cout << test("ooxXm") << "\n";
    cout << test("zpzpzpp") << "\n";
    cout << test("zzoo") << "\n";
    return 0;
}