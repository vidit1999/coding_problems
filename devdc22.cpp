#include <bits/stdc++.h>
using namespace std;

/*
Write a function that moves the first letter of each word to the end of the word,
then add "ay". Leave punctuation untouched.

Examples:
pig_it('Pig latin is cool') # igPay atinlay siay oolcay
pig_it('Hello world !') # elloHay orldway !

Turn back to English.
*/

// split a string wrt space
// returns vector of the parts
vector<string> splitString(string s){
    string part = "";
    int start = 0;
    vector<string> splitted;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            if(part.length() > 0)
                splitted.push_back(part);
            part = "";
            start = i+1;
        }
        else{
            part += s[i];
        }
    }
    if(part.length() > 0)
        splitted.push_back(part);
    return splitted;
}

// pigify
// Pig -> igPay
// latin -> atinlay
// a -> aay
string pigify(string s){
    string pigified = "";
    for(int i=1;i<s.length();i++)
        pigified += s[i];
    pigified += s[0];
    pigified += "ay";
    return pigified;
}

// reverse of pigify
// returns original string given a pigified string
// igPay -> Pig
// atinlay -> latin
// aay -> a
// bug there
string reversePigify(string s){
    string reversePigified = "";
    for(int i=s.length()-4;i>=0;i--){
        reversePigified = s[i] + reversePigified;
    }
    reversePigified = s[s.length()-3] + reversePigified;
    return reversePigified;
}

// returns true if string contains only a-z and A-Z
// else returns false
bool isAlphaString(string s){
    for(char c : s){
        if(!(c >= 65 && c <= 90) && !(c >= 97 && c <= 122))
            return false;
    }
    return true;
}

// pifify a given sentence and returns the pigified one
string pig_it(string s){
    string pigIt = "";
    vector<string> splited = splitString(s);
    for(int i=0;i<splited.size()-1;i++){
        if(isAlphaString(splited[i])){
            pigIt += (pigify(splited[i]) + " ");
        }
        else{
            pigIt += (splited[i] + " ");
        }
    }
    if(isAlphaString(splited[splited.size()-1])){
        pigIt += (pigify(splited[splited.size()-1]));
    }
    else{
        pigIt += (splited[splited.size()-1]);
    }
    return pigIt;
}

// returns the original sentence from the given pigified sentence
string reverse_pig_it(string s){
    string reversePigit = "";
    vector<string> splited = splitString(s);
    for(int i=0;i<splited.size()-1;i++){
        if(isAlphaString(splited[i])){
            reversePigit += (reversePigify(splited[i]) + " ");
        }
        else{
            reversePigit += (splited[i] + " "); 
        }
    }
    if(isAlphaString(splited[splited.size()-1])){
        reversePigit += (reversePigify(splited[splited.size()-1]));
    }
    else{
        reversePigit += (splited[splited.size()-1]); 
    }
    return reversePigit;
}

// main function
int main(){
    cout << pig_it("Pig latin is cool") << "\n";
    cout << reverse_pig_it(pig_it("Pig latin is cool")) << "\n";
    cout << pig_it("Hello world !") << "\n";
    cout << reverse_pig_it(pig_it("Hello world !")) << "\n";
    return 0;
}