#include <bits/stdc++.h>
using namespace std;

/*
Given the sum and greatest common divisor of two numbers,
return those two numbers in ascending order.
If the numbers do not exist, return -1 or your language's equivalent.

Examples
Given sum = 12 and gcd = 4...

solve(12,4) = [4,8]. The two numbers 4 and 8 sum to 12 and have a gcd of 4.

solve(12,5) = -1. No two numbers exist that sum to 12 and have gcd of 5.

solve(10,2) = [2,8]. Note that [4,6] is also a possibility
but we pick the one with the lower first element: 2 < 4, so we take [2,8].

Tests
solve(12,4)
solve(16,8)
solve(21,7)
*/

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

pair<int, int> solve(int sum, int gcd_num){
	for(int i=1; i<=sum/2+1; i++){
		if(gcd(i, sum-i) == gcd_num){
			return {i, sum-i};
		}
	}

	return {-1, -1};
}

void testFunc(vector<pair<int, int>> v){
	for(auto it : v){
		auto ans = solve(it.first, it.second);
		cout << ans.first << ", " << ans.second << "\n";
	}
}

// main function
int main(){
	testFunc({
		{12,4},
		{12,5},
		{10,2},
		{12,4},
		{16,8},
		{21,7},
	});
	return 0;
}