#include <bits/stdc++.h>
using namespace std;

/*
We want to calculate the sum of the squares of the binomial coefficients
on a given line with a function called easyline (or easyLine or easy-line).
Can you write a program which calculates easyline(n) where n is the line number?
The function will take n (with: n >= 0) as parameter and will return the
sum of the squares of the binomial coefficients on line n.

Examples:
easyline(0) => 1
easyline(1) => 2
easyline(4) => 70
easyline(50) => 100891344545564193334812497256

Tests
easyline(7)
easyline(13)
easyline(3)
easyline(19)
*/

// calculate nCr in O(r) time
long long binCoef(int n, int r){
    r = min(r, n-r);
    int ans = 1;
    for(int i=0;i<r;i++){
        ans *= (n-i);
        ans /= i+1;
    }
    return ans;
}

// calculate the sum
// sum will be 2nCn
// O(n) solution
long long easyline(int n){
    return binCoef(2*n, n);
}

// main function
int main(){
    cout << easyline(0) << "\n";
    cout << easyline(1) << "\n";
    cout << easyline(4) << "\n";
    cout << easyline(3) << "\n";
    cout << easyline(7) << "\n";
    cout << easyline(19) << "\n";
    return 0;
}