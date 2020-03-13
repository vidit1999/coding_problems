#include <bits/stdc++.h>
using namespace std;

/*
construct a building which will be made of a pile of n cubes.
The cube at the bottom will have a volume of n3, the cube above will
have volume of (n-1)3 and so on until the top with a volume of 13.

You are given the total volume m of the building. Being given m
can you find the number n of cubes you will have to build?

The parameter of the function f will be an integer m and you have to
return the integer n (such as n3 + (n-1)3 + ... + 13 = m) or 0 if there is no such n.

Examples
f(1071225) --> 45
f(91716553919377) --> 0
*/

int f(long long m){
    long double n = (sqrtl(1+8*sqrtl(m))-1)/2;
    return (floorl(n) == n)? n : 0;
}

// main function
int main(){
    cout << f(1071225) << "\n";
    cout << f(91716553919376) << "\n";
    return 0;
}