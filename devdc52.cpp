#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will draw a pyramid.
The function should take one integer parameter that will describe how many lines tall the pyramid should be.

This challenge is simple, but requires a bit of reflection to get it right.

Example
pyramid(5);

    *
   ***
  *****
 *******
*********
*/

string pyramid(int n){
    string s = "";
    for(int i=0;i<n;i++){
        int starCount = 2*i+1;
        int spaceCount = (n-1-i);
        while(spaceCount--)
            s += " ";
        while(starCount--)
            s += "*";
        if(i != n-1)
            s += "\n";
    }
    return s;
}

// main function
int main(){
    cout << pyramid(10) << "\n";
    return 0;
}