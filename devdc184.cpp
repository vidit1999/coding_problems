#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, implement a function that will return the
lowest possible number that can be formed from these digits.
You cannot use the same number more than once, even if it appears in the array multiple times.

Examples
minValue({1, 3, 1}) ==> return 13

minValue({5, 7, 5, 9, 7}) ==> return 579

Tests
minValue({1, 2, 3, 4})

minValue({1, 1, 7, 0})

minValue({9, 2, 1, 4, 3, 9, 5})
*/

vector<int> minValueHelper(vector<int> v){
    set<int> s;
    int presentZero = false;
    for(int i : v){
        if(i==0)
            presentZero = true;
        s.insert(i);
    }
    if(presentZero){
        // because 0 cannot be in front of any number
        // example : minValue({1, 1, 7, 0}) should not return 017 but should return 107
        vector<int> v(s.begin(),s.end());

        // if only zero is given in vector return zero
        // else swaping
        if(v.size() > 1)
            swap(v[0],v[1]);
        return v;
    }
    return vector<int>(s.begin(),s.end());
}

int minValue(vector<int> v){
    vector<int> minVector = minValueHelper(v);
    string s = "";
    for(int i : minVector)
        s += to_string(i);
    return stoi(s);
}

// main function
int main(){
    cout << minValue({1, 3, 1}) << "\n";
    cout << minValue({5, 7, 5, 9, 7}) << "\n";
    cout << minValue({1, 2, 3, 4}) << "\n";
    cout << minValue({1, 1, 7, 0}) << "\n";
    cout << minValue({9, 2, 1, 4, 3, 9, 5}) << "\n";
    cout << minValue({0}) << "\n";
    cout << minValue({0,1}) << "\n";
}