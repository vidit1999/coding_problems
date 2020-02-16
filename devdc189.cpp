#include <bits/stdc++.h>
using namespace std;

/*
Write a function that takes a random number as input and converts it
into an array with the digits of that number appearing in reverse order.

Example
convertNtA(348597) => [7,9,5,8,4,3]

Tests
convertNtA(6581554)
convertNtA(123456)
convertNtA(987123)
*/

vector<int> convertNtA(long number){
    vector<int> numDigits;
    if(number == 0) // if number is zero then return vector with only 0
        return vector<int>({0});
    
    while(number > 0){
        numDigits.push_back(number%10);
        number /= 10;
    }
    return numDigits;
}

// function for testing purpose
void testFunction(vector<int> numDigits){
    for(int i : numDigits)
        cout << i << " ";
    cout << "\n";
}

// main function
int main(){
    testFunction(convertNtA(348597));
    testFunction(convertNtA(6581554));
    testFunction(convertNtA(123456));
    testFunction(convertNtA(987123));
    testFunction(convertNtA(0));
    testFunction(convertNtA(1));
    testFunction(convertNtA(10));
    return 0;
}