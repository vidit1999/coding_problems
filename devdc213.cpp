#include <bits/stdc++.h>
using namespace std;

/*
Given two arrays a and b write a function comp(a, b) (compSame(a, b) in Clojure)
that checks whether the two arrays have the "same" elements, with the same multiplicities.
"Same" means, here, that the elements in b are the elements in a squared, regardless of the order.

Examples
Valid arrays
a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]
comp(a, b) returns true because in b 121 is the square of 11, 14641 is the square of 121,
20736 the square of 144, 361 the square of 19, 25921 the square of 161, and so on.

It gets obvious if we write b's elements in terms of squares:
a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]


Invalid arrays
If we change the first number to something else, comp may not return true anymore:

a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]
comp(a,b) returns false because in b 132 is not the square of any number of a.

a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]
comp(a,b) returns false because in b 36100 is not the square of any number of a.

Remarks
a or b might be . a or b might be nil or null or None or nothing
(except in Haskell, Elixir, C++, Rust, R, Shell, PureScript).

If a or b are nil (or null or None), the problem doesn't make sense so return false.
If a or b are empty then the result is self-evident.

Tests
a1 = [121, 144, 19, 161, 19, 144, 19, 11]
a2 = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
*/

bool comp(vector<int> a, vector<int> b){
    // if both of them have no element then return true
    if(a.size() == 0 || b.size() == 0)
        return true;

    // if they have different size then return false
    if(a.size() != b.size())
        return false;
    
    int size = a.size(); // or b.size() as both of them have same size
    unordered_map<int, int> squareCount;

    // squares a number of a, increment squareCount[squareNumber_a] by 1 i.e. squareCount[squareNumber_a]++
    // decrement sqareCount[squareNumber_b] by 1 i.e. squareCount[squareNumber_a]--
    for(int i=0;i<size;i++){
        squareCount[a[i]*a[i]]++;
        squareCount[b[i]]--;
    }

    // if they are "same" then all the values of corresponding
    // keys of sqaureCount will be zero
    // if any one of them is not zero then return false
    for(auto it : squareCount){
        if(it.second != 0)
            return false;
    }
    return true;
}

// main function
int main(){
    vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
    vector<int> b = {11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19};
    if(comp(a,b))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}