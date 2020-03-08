#include <bits/stdc++.h>
using namespace std;

/*
Given a non-negative integer, 3 for example, return a string with a murmur:
"1 sheep...2 sheep...3 sheep...".
Input will always be valid, i.e. no negative integers.
*/

string sheepCount(int count){
    string s = "";
    for(int i=1;i<=count;i++){
        s += to_string(i) + " sheep...";
    }
    return s;
}

// main function
int main(){
    cout << sheepCount(3) << "\n";
    return 0;
}