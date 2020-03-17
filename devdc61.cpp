#include <bits/stdc++.h>
using namespace std;

/*
Write a function getEvolutionRateMessage which takes two numbers before & after.
The before value is the initial value of the evolution. The after value is the value after its evolution.
An evolution can be calculated as follows:

evolution = (after - before) / before * 100

This function will return a string such that there are three possible outputs:
"A positive evolution of X%."
"A negative evolution of Y%."
"No evolution."

Examples:

getEvolutionRateMessage 11.29 45.79
getEvolutionRateMessage 95.12 66.84
getEvolutionRateMessage 0 27.35
getEvolutionRateMessage 41.26 0
getEvolutionRateMessage 1.26 1.26

"A positive evolution of 306%."
"A negative evolution of 30%."
"A positive evolution of 2735%."
"A negative evolution of 4126%."
"No evolution." 
*/

string getEvolutionRateMessage(float before, float after){
    if(before == after)
        return "No evolution.";
    string posOrNeg = (after > before)? "positve" : "negative";
    if(before && after){
        float evolution = round(abs(after-before)/before*100);
        return "A " + posOrNeg + " evolution of " + to_string(int(evolution)) + "%";
    }
    after = (after > before)? after : before;
    return "A " + posOrNeg + " evolution of " + to_string(int(round(abs(after)*100))) + "%";
}

// main function
int main(){
    cout << getEvolutionRateMessage(11.29, 45.79) << "\n";
    cout << getEvolutionRateMessage(95.12, 66.84) << "\n";
    cout << getEvolutionRateMessage(0, 27.35) << "\n";
    cout << getEvolutionRateMessage(41.26, 0) << "\n";
    cout << getEvolutionRateMessage(1.26, 1.26) << "\n";
    return 0;
}