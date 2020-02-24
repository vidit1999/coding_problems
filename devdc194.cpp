#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that will create an array and fill it
with numbers ranging from 1 to n. The numbers will always be positive.

Examples
spreadNumber(1) => [1]
spreadNumber(2) => [1, 2]
spreadNumber(5) => [1, 2, 3, 4, 5]

Tests
spreadNumber(3)
spreadNumber(6)
spreadNumber(9)
*/

vector<int> spreadNumber(int number){
    vector<int> v(number);
    generate(v.begin(),v.end(),[i=1]()mutable{return i++;});
    return v;
}

void testFunc(vector<int> v){
    for(int i : v){
        vector<int> spread = spreadNumber(i);
        for(int i : spread)
            cout << i << " ";
        cout << "\n";
    }
}

// main function
int main(){
    testFunc({1,2,5,3,6,9});
    return 0;
}