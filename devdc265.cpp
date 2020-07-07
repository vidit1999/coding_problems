#include <bits/stdc++.h>
using namespace std;

/*
You are going to be given an array of integers.
Your job is to take that array and find an index N where
the sum of the integers to the left of N is equal to the
sum of the integers to the right of N.
If there is no index that would make this happen, return -1.

For example:

Let's say you are given the array {1,2,3,4,3,2,1}:
Your function will return the index 3, because at
the 3rd position of the array, the sum of left side
of the index ({1,2,3}) and the sum of the right
side of the index ({3,2,1}) both equal 6.

Let's look at another one.
You are given the array {1,100,50,-51,1,1}:
Your function will return the index 1, because
at the 1st position of the array, the sum of
left side of the index ({1}) and the sum of
the right side of the index ({50,-51,1,1}) both equal 1.

Input:
An integer array of length 0 < arr < 1000.
The numbers in the array can be any integer positive or negative.

Output:
The lowest index N where the side to the
left of N is equal to the side to the right of N.
If you do not find an index that fits these rules,
then you will return -1.

Note:
If you are given an array with multiple answers, return the lowest correct index.

Tests
{1,2,3,4,3,2,1}
{1,100,50,-51,1,1}
{20,10,30,10,10,15,35}
{-8505, -5130, 1926, -9026}

Good luck!
*/

int leftRightEqual(vector<int> arr){
	// if vector length is less than 3
	// then return -1
	if(arr.size() < 3) return -1;

	// vector to hold the right cumulative sum
	vector<int> right_sum(arr.size());
	int left_sum = arr[0];

	for(int i=arr.size()-2;i>=0;i--)
		right_sum[i] = right_sum[i+1] + arr[i+1];
	
	for(int i=1;i<arr.size()-1;i++){
		if(left_sum == right_sum[i])
			return i;
		left_sum += arr[i];
	}

	return -1;
}

void testFunc(vector<vector<int>> v){
	for(auto arr : v){
		cout << leftRightEqual(arr) << "\n";
	}
}

// main function
int main(){
	testFunc({
		{1,2,3,4,3,2,1},
		{1,100,50,-51,1,1},
		{20,10,30,10,10,15,35},
		{-8505, -5130, 1926, -9026}
	});
	return 0;
}