#include <bits/stdc++.h>
using namespace std;

/*
Define a function that takes in two non-negative integers a and b
and returns the last decimal digit of a^b. Note that a and b may be very large!

For example, the last decimal digit of 9^7 is 9, since 9^7 = 4782969.
The last decimal digit of (2^200)^(2^300), which has over 10^92 decimal digits,
is 6. Also, please take 0^0 to be 1.

You may assume that the input will always be valid.

Examples
lastDigit 4 1 shouldBe 4
lastDigit 4 2 shouldBe 6
lastDigit 9 7 shouldBe 9
*/

unordered_map<int, vector<int>> lastDigitCycle = {
    {0, {0}},
    {1, {1}},
    {2, {6, 2, 4, 8}},
    {3, {1, 3, 9, 7}},
    {4, {6, 4}},
    {5, {5}},
    {6, {6}},
    {7, {1, 7, 9, 3}},
    {8, {6, 8, 4, 2}},
    {9, {1, 9}}
};

int lastDigit(long a, long b){
    if((a == 0 && b == 0) || b == 0)
        return 1;
    
    int lastDigitOfA = a%10;
    int len = lastDigitCycle[lastDigitOfA].size();
    int reqIndex = b%len;
    return lastDigitCycle[lastDigitOfA][reqIndex];
}

int main(){
    cout << lastDigit(4, 1) << "\n"; // output -> 4
    cout << lastDigit(4, 2) << "\n"; // output -> 6
    cout << lastDigit(9, 7) << "\n"; // output -> 9
    cout << lastDigit(1, 0) << "\n"; // output -> 1
    cout << lastDigit(2, 0) << "\n"; // output -> 1
    cout << lastDigit(0, 0) << "\n"; // output -> 1
    cout << lastDigit(0, 7) << "\n"; // output -> 0
    cout << lastDigit(29, 157) << "\n"; // output -> 9
}