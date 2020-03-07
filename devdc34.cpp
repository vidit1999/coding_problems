#include <bits/stdc++.h>
using namespace std;

/*
write a function that accepts a string and returns the same string with all
even indexed characters uppercased and all odd indexed characters lowercased.

This indexing should be zero-based with the index in position zero being considered even.
The input string will consist of only alphabetical characters and spaces.
Spaces should only be present when there are multiple words.

Example:
to_weird_case('String'); # => returns 'StRiNg'
to_weird_case('Weird string case') # => returns 'WeIrD StRiNg CaSe'
*/

//split a string wrt space
vector<string> splitString(string s){
    string part = "";
    vector<string> splited;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            if(part.length() > 0)
                splited.push_back(part);
            part = "";
        }
        else
            part += s[i];
    }
    if(part.length() > 0)
        splited.push_back(part);
    return splited;
}

// convert a single word to weired case
string singleWeiredCase(string s){
    string weired = "";
    for(int i=0;i<s.length();i++){
        if(i%2 == 0)
            weired += (s[i] >= 97 && s[i] <= 122)? s[i]-32 : s[i];
        else
            weired += (s[i] >= 65 && s[i] <= 90)? s[i]+32 : s[i];
    }
    return weired;
}


// convert a normal string to weired case
string to_weird_case(string s){
    vector<string> splited = splitString(s);
    string weired = "";
    for(int i=0;i<splited.size()-1;i++)
        weired += (singleWeiredCase(splited[i]) + " ");
    weired += singleWeiredCase(splited[splited.size()-1]);
    return weired;
}

// main function
int main(){
    cout << to_weird_case("String") << "\n";
    cout << to_weird_case("Weird string case") << "\n";
    return 0;
}