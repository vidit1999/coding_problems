#include <bits/stdc++.h>
using namespace std;

/*
It has officially been decided that numbers that end with zeroes are boring.
They might be fun in your world, but definitely not here.
Implement a function to eradicate any trailing zeroes.
If the given number is 0, just leave him alone. Poor guy anyway.

Examples
1450 -> 145
960000 -> 96
1050 -> 105
-1050 -> -105

Tests
9070
210000
10210
0
*/

int removeZeros(int number){
    if(number == 0)
        return 0;
    
    // if number is not 0 then divide the number by 10
    // until last digit of number is non-zero
    while(number%10 == 0){
        number /= 10;
    }
    return number;
}

// main function
int main(){
    cout << removeZeros(9070) << "\n";
    cout << removeZeros(210000) << "\n";
    cout << removeZeros(10210) << "\n";
    cout << removeZeros(-1050) << "\n";
    cout << removeZeros(1050) << "\n";
    cout << removeZeros(0) << "\n";
    cout << removeZeros(4) << "\n";
    cout << removeZeros(-7) << "\n";
    return 0;
}