#include <bits/stdc++.h>
using namespace std;

/*
Write a function areCurlyBracesMatched that takes in a
string s containing only { and/or } and returns true if s is properly matched, and false otherwise.

A string s is considered properly matched if the string is empty
or if every open brace has a corresponding close brace.

Examples
{{}} is properly matched.
{{{ is not properly matched.
{}{}{} is properly matched.

areCurlyBracesMatched("{{{}{}}}"), true;
areCurlyBracesMatched("{{"), false;
areCurlyBracesMatched("{}}"), false;
areCurlyBracesMatched(""), true;
*/


bool areCurlyBracesMatched(string s){
    int check = 0; // if this variable is less than zero then string is certainly unbalanced
    for(char c : s){
        if(c == '{')
            check++; // for opening brackets increment by one
        if(c == '}')
            check--; // for closing decrement by one
        if(check < 0)
            return false;
    }
    if(check > 0) // if greater than zero then opening brackets number are greater than closing ones
        return false;
    return true;
}

// function for testing
void testFunc(string s){
    if(areCurlyBracesMatched(s))
        cout << "True\n";
    else
        cout << "False\n";
}

// main function
int main(){
    testFunc("{{{}{}}}");
    testFunc("{{");
    testFunc("{}}");
    testFunc("");
    testFunc("{}{}{}");
    return 0;
}