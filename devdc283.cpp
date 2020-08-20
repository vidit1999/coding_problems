#include <bits/stdc++.h>
using namespace std;

/*
In this challenge, we will calculate the minimum number that is
not a possible sum from a list of positive integers.

Examples
solve([1,2,8,7]) = 4
we can get 1, 2, 3 (from 1+2), but we cannot get 4. 4 is the
smallest number not retrievable from the list.

solve([4,1,2,3,12]) = 11
We can get 1, 2, 3, 4, 4+1=5, 4+2=6, 4+3=7, 4+3+1=8,
4+3+2=9, 4+3+2+1=10. But we can't get to 11.

solve([2,3,2,3,4,2,12,3]) = 1. We cannot get 1.

Tests
solve([4,2,8,3,1])
solve([4,2,7,3,1])
solve([1,2,8,7])
solve([4,2,12,3])
*/

int solve(vector<int> arr){
	sort(arr.begin(), arr.end());

	int ans = 1;

	for(int num : arr){
		if(ans < num) break;
		ans += num;
	}

	return ans;
}

// main function
int main(){
	cout << solve({1,2,8,7}) << "\n";
	cout << solve({4,1,2,3,12}) << "\n";
	cout << solve({4,2,8,3,1}) << "\n";
	cout << solve({4,2,7,3,1}) << "\n";
	cout << solve({1,2,8,7}) << "\n";
	cout << solve({4,2,12,3}) << "\n";
	return 0;
}