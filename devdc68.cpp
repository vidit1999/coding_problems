#include <bits/stdc++.h>
using namespace std;

/*
Today's challenge is to write a function that accepts three integer values,
calculates the mean, then returns the letter value associated with that grade.
If the mean of those three integers ends in a number greater than five,
append a plus sign to the letter grade. If it is less than five, append a minus sign.

Numerical Score      Letter Grade
90 <= score <= 100    'A'
80 <= score < 90      'B'
70 <= score < 80      'C'
60 <= score < 70      'D'
0 <= score < 60       'F'

Examples:
grade(64, 55, 92) => C- (70.3)
grade(99, 89, 93) => A- (93.6)
grade(33, 99, 95) => C+ (75.6)
*/

string grade(int x, int y, int z){
    float mean = float(x+y+z)/3;
    string res = "";
    if(mean >= 90 && mean <= 100)
        res += "A";
    else if(mean >= 80)
        res += "B";
    else if(mean >= 70)
        res += "C";
    else if(mean >= 60)
        res += "D";
    else
        res += "E";
    res += (int(mean)%10 == 5)? "+" : "-";
    return res;
}

// main function
int main(){
    cout << grade(64, 55, 92) << "\n";
    cout << grade(99, 89, 93) << "\n";
    cout << grade(33, 99, 95) << "\n";
    return 0;
}