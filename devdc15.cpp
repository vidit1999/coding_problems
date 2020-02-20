#include <bits/stdc++.h>
using namespace std;

/*
s'yadoT egnellahc semoc from user xDranik on sraWedoC!

Write a function that takes in a string of one or more words
and returns the same string, but with all words with five letters or more reversed.
Strings passed in will consist of only letters and spaces.

Be sure to keep the order of the words the same and only reverse the letters.
*/


// helper function to revrse a string
// takes the string and a starting and ending position
// if substring length is less than 5 returns the substring
// else reverses substring and returns it
string reverseHepler(string s, int start, int end){
    if(end - start < 4)
        return s.substr(start,end-start+1);
    
    string sub = s.substr(start,end-start+1);
    reverse(sub.begin(),sub.end());
    return sub;
}


string reverseFive(string s){
    int start = 0; // starting position of a substring
    string reversed = ""; // holds the reversed string

    for(int i=0;i<s.length();i++){
        if((i+1 < s.length() && s[i+1] == ' ') || i+1 == s.length()){

            // if s[i+1] is a space then include a space in reversed string
            // else if i is last letter include nothing
            reversed += (reverseHepler(s,start,i) + ((i==s.length())? "" : " "));
            i++;
            start = i+1;
        }
    }
    return reversed;
}

// main function
int main(){
    cout << reverseFive("s'yadoT egnellahc semoc from user xDranik on sraWedoC") << "\n";
    cout << reverseFive("yppaH gniedoc") << "\n";
    cout << reverseFive("Me") << "\n";
    cout << reverseFive("sraWedoC") << "\n";
    cout << reverseFive("") << "\n";
    return 0;
}