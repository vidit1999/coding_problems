#include <bits/stdc++.h>
using namespace std;

/*
An array arr consisting of n integers is given.
The dominator of arr is the value that occurs in more than half of the elements of arr.

Write a function dominator(arr) that returns the dominator of arr.
The function should return −1 if array does not have a dominator.
All values in arr will be >=0.

For example, consider the array such that arr = [3,4,3,2,3,1,3,3]
The dominator of arr is 3 because it occurs in 5 out of 8 elements of arr and 5 is more than half of 8.

dominator([3,4,3,2,3,1,3,3]) => 3
dominator([1,2,3,4,5]) => -1

Tests:
dominator([3,4,3,2,3,1,3,3])
dominator([1,1,1,2,2,2]),
dominator([1,1,1,2,2,2,2])
*/

int dominator(vector<int> arr){
	// stores the number with its count
	unordered_map<int, int> numCount;
	
	// if count of any number becomes more than arr.size()/2
	// then return that number
	for(int num : arr){
		if(++numCount[num] > arr.size()/2)
			return num;
	}
	
	// if no number has count more than arr.size()/2
	// then return -1
	return -1;
}

// main function
int main(){
	cout << dominator({3,4,3,2,3,1,3,3}) << "\n";
	cout << dominator({1,2,3,4,5}) << "\n";
	cout << dominator({1,1,1,2,2,2}) << "\n";
	cout << dominator({1,1,1,2,2,2,2}) << "\n";
	return 0;
}