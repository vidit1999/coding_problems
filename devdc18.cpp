#include <bits/stdc++.h>
using namespace std;

/*
Write a function tripledouble(num1,num2) which takes numbers num1 and num2 and
returns 1 if there is a straight triple of a number at any place in num1 and
also a straight double of the same number in num2. If this isn't the case, return 0

Example :
num1 = 8777
num2 = 8779
returns 1

num1 = 44411
num2 = 41411
returns 0

num1 = 8881
num2 = 8119
returns 0
*/

int tripledouble(int num1, int num2){
    string n1 = to_string(num1);
    string n2 = to_string(num2);
    if(n1.size() < 3 || n2.size() < 2)
        return 0;
    unordered_set<char> uset; // stores the digits which appears 3 or more consecutive times
    for(int i=2;i<n1.length();i++){
        if(n1[i] == n1[i-1] && n1[i-1] == n1[i-2]){
            uset.insert(n1[i]);
        }
    }
    for(int i=1;i<n2.length();i++){
        if(n2[i] == n2[i-1]){
            if(uset.find(n2[i]) != uset.end())
                return 1;
        }
    }
    return 0;
}

// main function
int main(){
    cout << tripledouble(8777,877) << "\n";
    cout << tripledouble(44411,41411) << "\n";
    cout << tripledouble(8881,8119) << "\n";
    return 0;
}