#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will return an inputted numerical year in century format.
The output should have the appropriate written ending ('st','nd','rd','th') as well.

Examples
In: 2259 Out: 23rd
In: 1124 Out: 12th
In: 2000 Out: 21st
*/

string centuryFormat(int year){
    int centuryNumber = year/100 + 1;
    string centuryString = "";
    if(centuryNumber == 11 || centuryNumber == 12)
        centuryString += "th";
    else{
        switch(centuryNumber%10){
            case 1:
                centuryString += "st";break;
            case 2:
                centuryString += "nd";break;
            case 3:
                centuryString += "rd";break;
            default:
                centuryString += "th";
        }
    }
    return to_string(centuryNumber) + centuryString;
}

// main function
int main(){
    cout << centuryFormat(2259) << "\n";
    cout << centuryFormat(1124) << "\n";
    cout << centuryFormat(2000) << "\n";
    cout << centuryFormat(2176) << "\n";
    cout << centuryFormat(1045) << "\n";
    cout << centuryFormat(1221) << "\n";
    return 0;
}