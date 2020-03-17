#include <bits/stdc++.h>
using namespace std;

/*
Write a method that takes an array of consecutive (increasing) letters as input
and that returns the missing letter in the array.

You will always get a valid array. And it will be always exactly one letter be missing.
The length of the array will always be at least 2.
The array will always contain letters in only one case.

Example:
['a','b','c','d','f'] => 'e'
['O','Q','R','S'] => 'P'
*/

char missingChar(vector<char> letters){
    int expectedSum = (letters.size()+1)*(letters[0] + letters[letters.size()-1])/2;
    for(char c : letters){
        expectedSum -= c;
    }
    return expectedSum;
}

// main function
int main(){
    cout << missingChar({'a','b','c','d','f'}) << "\n";
    cout << missingChar({'O','Q','R','S'}) << "\n";
    return 0;
}