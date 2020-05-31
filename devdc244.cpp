#include <bits/stdc++.h>
using namespace std;

/*
Create a function which accepts one arbitrary string as an argument,
and return a string of length 26. The objective is to set each of the 26
characters of the output string to either '1' or '0' based on the fact whether
the Nth letter of the alphabet is present in the input (independent of its case).

So if an 'a' or an 'A' appears anywhere in the input string (any number of times),
set the first character of the output string to '1', otherwise to '0'. if 'b' or 'B'
appears in the string, set the second character to '1', and so on for the rest of the alphabet.

For instance:
"a **& cZ" => "10100000000000000000000001"
'Abc e $$ z' => "11101000000000000000000001"

Tests
change("!!a$%&RgTT")
change("")
change("abcdefghijklmnopqrstuvwxyz")
change("aaaaaaaaaaa")
*/

string change(string s){
    string st(26, '0');

    for(char c : s)
        if(islower(c) || isupper(c))
            st[tolower(c)-'a'] = '1';
    
    return st;
}

// main function
int main(){
    cout << change("a **& cZ") << "\n";
    cout << change("Abc e $$ z") << "\n";
    cout << change("!!a$%&RgTT") << "\n";
    cout << change("") << "\n";
    cout << change("abcdefghijklmnopqrstuvwxyz") << "\n";
    cout << change("aaaaaaaaaaa") << "\n";
	return 0;
}