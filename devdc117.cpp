#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of integers, find the smallest number in the array,
the largest number in the array, and the smallest number between the two array bounds that are not in the array.

For instance, given the array [-1, 4, 5, -23, 24], the smallest number is -23,
the largest number is 24, and the smallest number between the array bounds is -22.
You may assume the input is well-formed.

Your solution should return an array [smallest, minimumAbsent, largest]

The smallest integer should be the integer from the array with the lowest value.

The largest integer should be the integer from the array with the highest value.

The minimumAbsent is the smallest number between the largest and the smallest number that is not in the array.

minMinMax([-1, 4, 5, -23, 24]); //[-23, -22, 24]
minMinMax([1, 3, -3, -2, 8, -1]); //[-3, 0, 8]
minMinMax([2, -4, 8, -5, 9, 7]); //[-5, -3,9]
*/

vector<int> minMinMax(vector<int> arr){
	if(arr.size() < 2)
		return {};
	
	unordered_set<int> numbers;
	vector<int> ans(3);
	
	int maxNum = INT_MIN, minNum = INT_MAX;
	for(int i : arr){
		maxNum = max(maxNum, i);
		minNum = min(minNum, i);
		numbers.insert(i);
	}
	ans[0] = minNum, ans[2] = maxNum;
	
	for(int i=minNum+1;i<maxNum;i++){
		if(numbers.find(i) == numbers.end()){
			ans[1] = i;
			return ans;
		}
	}
	
	ans[1] = INT_MAX;
	return ans;
}

void testFunc(vector<vector<int>> v){
	for(auto ans : v){
		for(int i : minMinMax(ans))
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{-1, 4, 5, -23, 24},
		{1, 3, -3, -2, 8, -1},
		{2, -4, 8, -5, 9, 7}
	});
	return 0;
}