#include <bits/stdc++.h>
using namespace std;

/*
For this challenge, implement a function that will return true if a number is Automorphic.
Automorphics are numbers whose square ends in the same digits as the number itself.
The number will always be positive.

Examples
autoMorphic(13) => false
13 squared is 69. Since 69 does not end in 13, return false.

autoMorphic(25) => true
25 squared is 625. Since 625 ends in 25, return true.

Tests
autoMorphic(6)

autoMorphic(625)

autoMorphic(225)
*/

bool autoMorphic(int num){

    // num = 25 , num*num = 625
    // 625-25 = 600
    // 600 % (1 followed by zeros whose count is same as no. of digits in 25)
    // i.e. 600 % 1 followed by 2 zeors
    // i.e. 600 % 100 = 0
    // there fore 25 is Automorphic

    int divisibleBy = 1;
    int temp_num = num;
    while(temp_num){
        temp_num /= 10;
        divisibleBy *= 10;
    }

    return ((num*num - num)%divisibleBy)==0;
}

void testCases(int num){
    if(autoMorphic(num))
        cout << "true\n";
    else
        cout << "false\n";
}

// main function
int main(){
    testCases(13);
    testCases(25);
    testCases(6);
    testCases(625);
    testCases(225);
    return 0;
}