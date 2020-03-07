#include <bits/stdc++.h>
using namespace std;

/*
You'll be given an array with a length of at least three,
containing (possibly quite large) integers.
The array is either comprised of entirely odd integers or even integers with one exception.
Write a method that returns the integer that is not like the others.

Example:
findOutlier([2, 4, 0, 100, 4, 11, 2602, 36]) => 11

Additional practice arrays:
[160, 3, 1719, 19, 11, 13, -21]
[4, 8, 15, 16, 24, 42]
[16, 6, 40, 66, 68, 28] 
*/

// returns the integer that is not like others
// if not found then returns INT_MAX
long long findOutlier(vector<long long> numbers){
    int evenCount = 0;
    int oddCount  = 0;
    long long evenNumber;
    long long oddNumber;
    for(long long num : numbers){
        if(num%2 == 0){
            evenCount++;
            evenNumber = num;
        }
        else{
            oddCount++;
            oddNumber = num;
        }
    }
    if(oddCount==1)
        return oddNumber;
    if(evenCount==1)
        return evenNumber;
    return INT_MAX;
}

// main function
int main(){
    cout << findOutlier({2, 4, 0, 100, 4, 11, 2602, 36}) << "\n";
    cout << findOutlier({160, 3, 1719, 19, 11, 13, -21}) << "\n";
    cout << findOutlier({4, 8, 15, 16, 24, 42}) << "\n";
    cout << findOutlier({16, 6, 40, 66, 68, 28}) << "\n";
    return 0;
}