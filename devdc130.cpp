#include <bits/stdc++.h>
using namespace std;

/*
Given the sum and gcd of two numbers, return those two numbers in ascending order.
If the numbers do not exist, return -1, (or return NULL in C).

For example:
Given sum = 12 and gcd = 4...

solve(12,4) = [4,8].
The two numbers 4 and 8 sum to 12 and have a gcd of 4.

solve(12,5) = -1.
No two numbers exist that sum to 12 and have gcd of 5.

solve(10,2) = [2,8].
Note that [4,6] is also a possibility but we pick the one with
the lower first element: 2 < 4, so we take [2,8].
*/

pair<int, int> gcdSum(int sum, int gcd){
	if(__gcd(gcd, sum-gcd) == gcd && sum != gcd)
		return {min(gcd, sum-gcd), max(gcd, sum-gcd)};
	return {-1, -1};
}

void testFunc(vector<pair< int, int>> v){
	for(auto it : v){
		auto ans = gcdSum(it.first, it.second);
		cout << ans.first << " " << ans.second << "\n";
	}
}

// main function
int main(){
	testFunc({
		{12, 4},
		{12, 5},
		{10, 2}
	});
	return 0;
}