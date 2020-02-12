#include <bits/stdc++.h>
using namespace std;

/*
Consider a sequence u, where u is defined as follows:

The number u(0) = 1 is the first one in u.
For each x in u, y = 2 * x + 1 and z = 3 * x + 1 must also be in u.
There are no other numbers in u.
Ex: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]

1 gives 3 and 4. 3 gives 7 and 10 while 4 gives 9 and 13. This pattern continues as far you as allow it to.
Your task is to create a function dbl_linear with a parameter of n that returns the
element u(n) in an ordered sequence (excluding duplicates).
*/

long dbl_linear(int n){
    unordered_set<long> uset;
    vector<long> numbers;
    numbers.push_back(1);
    uset.insert(1);
    for(int i=0;i<2*n;i++){
        long y = 2*numbers[i]+1;
        long z = 3*numbers[i]+1;
        if(uset.find(y) == uset.end()){
            numbers.push_back(y);
            uset.insert(y);
        }
        if(uset.find(z) == uset.end()){
            numbers.push_back(z);
            uset.insert(z);
        }
    }
    return numbers[n-1];
}

// main function
int main(){
    long numbers = dbl_linear(10000);
    cout << numbers << "\n";
    return 0;
}