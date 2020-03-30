#include <bits/stdc++.h>
using namespace std;

/*
Write a function, persistence, that takes in a positive parameter num and
returns its multiplicative persistence, which is the number of times you must
multiply the digits in num until you reach a single digit.

Examples
persistence(39) === 3 // because 3*9 = 27, 2*7 = 14, 1*4=4
                    // and 4 has only one digit

persistence(999) === 4 // because 9*9*9 = 729, 7*2*9 = 126,
                    // 1*2*6 = 12, and finally 1*2 = 2

persistence(4) === 0 // because 4 is already a one-digit number

Tests
persistence(5)
persistence(52)
persistence(377)
*/

/*
Recursion :
persistence(num) = 0 if num < 10
                 = [1 + persistence(multiplication of digits of num)] if num >= 10
*/

int persistence(int num){
    // Given number is positive, so no need to check for negative numbers

    // if number is already single digit return 0
    if(num < 10)
        return 0;
    
    // get the multiplication of digits
    int mul = 1;
    while(num > 0){
        mul *= (num%10);
        num /= 10;
    }
    
    // return 1 + persistence(mul)
    return 1 + persistence(mul);
}

// main function
int main(){
    cout << persistence(39) << "\n";
    cout << persistence(4) << "\n";
    cout << persistence(999) << "\n";
    cout << persistence(5) << "\n";
    cout << persistence(52) << "\n";
    cout << persistence(377) << "\n";
    return 0;
}