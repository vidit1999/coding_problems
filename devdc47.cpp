#include <bits/stdc++.h>
using namespace std;

/*
you are asked to replace every letter with its position in the
alphabet for a given string where 'a' = 1, 'b'= 2, etc.

For example:

alphabet_position("The sunset sets at twelve o' clock.")
should return 20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11 as a string.
*/

string alphabet_position(string s){
    string res = "";

    // no space at the end
    // so i < s.length()-1
    for(int i=0;i<s.length()-1;i++){
        if(s[i] >= 65 && s[i] <= 90){
            res += to_string(tolower(s[i])-'a'+1);
            res += ' ';
        }
        else if(s[i] >= 97 && s[i] <=122){
            res += to_string(s[i]-'a'+1);
            res += ' ';
        }
    }
    // for last element
    if(s[s.length()-1] >= 65 && s[s.length()-1] <= 90)
        res += to_string(tolower(s[s.length()-1])-'a'+1);
    else if(s[s.length()-1] >= 97 && s[s.length()-1] <=122)
        res += to_string(s[s.length()-1]-'a'+1);
    return res;
}

// main function
int main(){
    cout << alphabet_position("The sunset sets at twelve o' clock.") << "\n";
    return 0;
}