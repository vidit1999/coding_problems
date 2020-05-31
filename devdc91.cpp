#include <bits/stdc++.h>
using namespace std;

/*
Given a string of letters a, b, n how many different ways can you make
the word "banana" by crossing out various letters and then reading left-to-right?

(Use - to indicate a crossed-out letter)

Example

Input
bbananana

Output
b-anana--
b-anan--a
b-ana--na
b-an--ana
b-a--nana
b---anana
-banana--
-banan--a
-bana--na
-ban--ana
-ba--nana
-b--anana
*/

vector<string> bananaSolve(string s, string target="banana"){
    if(s.empty() && target.empty())
        return {""};
    if(s.empty())
        return {};
    
    if(s[0] != target[0]){
        vector<string> v, ans = bananaSolve(s.substr(1), target);
        for(string st : ans)
            v.push_back("-"+st);
        return v;
    }
    vector<string> v1, v2 = bananaSolve(s.substr(1), target.substr(1)), v3 = bananaSolve(s.substr(1), target);
    for(string st : v2)
        v1.push_back(s[0]+st);
    for(string st : v3)
        v1.push_back("-"+st);
    return v1;
}

// main function
int main(){
    for(string st : bananaSolve("bbananana"))
        cout << st << "\n";
    return 0;
}