#include <bits/stdc++.h>
using namespace std;

/*
Write a function that returns a string in which an
individual's first name is swapped with their last name.

Example: nameShuffler('Emma McClane'); => "McClane Emma"
*/

string nameShuffler(string name){
    string firstName = "";
    string lastName = "";
    bool isFirst = true;
    for(char c : name){
        if(c == ' '){
            isFirst = false;
            continue;
        }
        if(isFirst)
            firstName += c;
        else
            lastName += c;
        
    }
    return lastName + ' ' + firstName;
}

// main function
int main(){
    cout << nameShuffler("Emma McClane") << "\n";
    return 0;
}