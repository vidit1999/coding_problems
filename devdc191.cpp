#include <bits/stdc++.h>
using namespace std;

/*
Write a function that can add letters together.
Each letter will be valued based on their position in the alphabet.

Rules:

Letters will always be lowercase.
Letters can overflow (see second to last example of the description)
If no letters are given, the function should return 'z'

Examples
addLetters('a', 'b', 'c') = 'f'
addLetters('a', 'b') = 'c'
addLetters('z') = 'z'
addLetters('z', 'a') = 'a'
addLetters('y', 'c', 'b') = 'd' // notice the letters overflowing
addLetters() = 'z'

Tests
addLetters('a', 'b', 'c')
addLetters('z')
addLetters('a','b')
addLetters('c')
addLetters('y', 'c', 'b')
addLetters()
*/

// takes letters in a vector
char addLetters(vector<char> letters){
    int sumLetters = 0; // holds the sum
    for(char c : letters){
        sumLetters += (c-'a'+1);
    }

    // if empty vector is passed returns 'z'
    if(sumLetters==0)
        return 'z';
    return (sumLetters-1)%26 +97;
}

// overloaded function for special case : addLetters()
// return 'z'
char addLetters(){
    return 'z';
}

// main function
int main(){
    cout << addLetters({'a', 'b', 'c'}) << "\n";
    cout << addLetters({'z'}) << "\n";
    cout << addLetters({'a', 'b'}) << "\n";
    cout << addLetters({'c'}) << "\n";
    cout << addLetters({'y', 'c', 'b'}) << "\n";
    cout << addLetters({'z', 'a'}) << "\n";
    cout << addLetters() << "\n";

    return 0;
}