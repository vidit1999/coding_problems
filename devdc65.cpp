#include <bits/stdc++.h>
using namespace std;

/*
Given u0 = 1, u1 = 2 and the relation 6unun+1-5unun+2+un+1un+2 = 0 calculate un for any integer n >= 0.

Example:
fcn(n) returns un: fcn(17) -> 131072, fcn(21) -> 2097152

Note:
You can look at this as

-Purely algorithmic from the definition of un
-the second one - not at all mandatory,
but as a compliment - is to get a bit your head around and find which sequence is hidden behind un 

*/

// recursive
// worst exponential solution
long long fcn(int n){
	if(n < 2)
		return n+1;
	return 6*fcn(n-2)*fcn(n-1)/(5*fcn(n-2) - fcn(n-1));
}

// DP based
// O(n) solution
long long fcnDP(int n){
	long long fcnArr[n+1];
	fcnArr[0] = 1;
	fcnArr[1] = 2;
	for(int i=2;i<=n;i++){
		fcnArr[i] = 6*fcnArr[i-2]*fcnArr[i-1]/(5*fcnArr[i-2]-fcnArr[i-1]);
	}
	return fcnArr[n];
}

// main function
int main(){
	cout << fcn(17) << "\n";
	cout << fcn(21) << "\n";
	cout << fcnDP(17) << "\n";
	cout << fcnDP(21) << "\n";
	return 0;
}