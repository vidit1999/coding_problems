#include <bits/stdc++.h>
using namespace std;

/*
There's an ATM with unlimited money in bills of 10, 20, 50, 100, 200, and 500 dollars.
You're given an amount of money n to withdraw with 1<=n<=1500.

Try to find the minimal number of bills that must be used to cash out n, or output -1 if it's impossible.

Example:
solve(1250) => 4 bills (500x2, 50x1, 200x1)
solve 1500 => 3 bills ($500x3)

Tests:
solve(10)
solve(550)
solve(770)
*/

int solve(int n){
    if(n < 10 || n > 1500 || n%10 != 0)
        return -1;
    
    int count = 0;
    for(int dollar : {500,200,100,50,20,10}){
        count += n/dollar;
        n %= dollar;
    }

    return count;
}

// main function
int main(){
    cout << solve(1250) << "\n";
    cout << solve(1500) << "\n";
    cout << solve(10) << "\n";
    cout << solve(550) << "\n";
    cout << solve(770) << "\n";
    return 0;
}