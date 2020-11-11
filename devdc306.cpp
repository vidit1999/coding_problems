#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the largest possible product obtained
by multiplying two adjacent numbers in an array.

Examples
adjacentProduct([1, 2, 3]) ==> returns 6
adjacentProduct([3, 4, 5]) ==> returns 20

Tests
adjacentProduct([3, 7, 9])
adjacentProduct([-3, -4, 15])
adjacentProduct([-4, -1, -10])
*/

int adjacentProduct(vector<int> arr){
	int n = arr.size();
	
	if(n == 0) return 0;
	if(n == 1) return arr[0];
	
	int ans = INT_MIN;
	
	for(int i=0; i<n-1; i++){
		ans = max(ans, arr[i]*arr[i+1]);
	}
	
	return ans;
}

// main function
int main(){
	cout << adjacentProduct({1, 2, 3}) << "\n";
	cout << adjacentProduct({3, 4, 5}) << "\n";
	cout << adjacentProduct({3, 7, 9}) << "\n";
	cout << adjacentProduct({-3, -4, 15}) << "\n";
	cout << adjacentProduct({-4, -1, -10}) << "\n";
	return 0;
}