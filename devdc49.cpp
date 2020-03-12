#include <bits/stdc++.h>
using namespace std;

/*
Create a function that will take a float and return the amount formatted in dollars and cents.
For example: 6.2 becomes $6.20
*/

void dollersCents(float amount){
    float round2Dec = round(100*amount)/100;
    cout << round2Dec;
}

// main function
int main(){
    dollersCents(6.2);
    cout << "\n";
    return 0;
}