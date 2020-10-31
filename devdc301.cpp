#include <bits/stdc++.h>
using namespace std;

/*
In this challenge, you will be given an array of arrays and your task will be
to return the number of unique arrays that can be formed by picking exactly
one element from each subarray.

Examples
For example: solve([[1,2],[4],[5,6]]) = 4,
because it results in only 4 possibilities.
They are [1,4,5],[1,4,6],[2,4,5],[2,4,6].

Make sure that you don't count duplicates;
for example solve([[1,2],[4,4],[5,6,6]]) = 4,
but the extra outcomes are just duplicates.

Tests
solve([[1,2],[4,4],[5,6,6]])
solve([[1,2],[3,4],[5,6]])
solve([[1,2,3],[3,4,6,6,7],[8,9,10,12,5,6]])
*/

int solve(vector<vector<int>> arr){
	int ans = 1;
	
	for(auto& v : arr){
		int size = unordered_set<int>(v.begin(), v.end()).size();
		ans *= size;
	}

	return ans;
}

// main function
int main(){
	cout << solve({{1,2},{4},{5,6}}) << "\n";
	cout << solve({{1,2},{4,4},{5,6,6}}) << "\n";
	cout << solve({{1,2},{3,4},{5,6}}) << "\n";
	cout << solve({{1,2,3},{3,4,6,6,7},{8,9,10,12,5,6}}) << "\n";
	return 0;
}