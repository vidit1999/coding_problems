#include <bits/stdc++.h>
using namespace std;

/*
Typically, reversing an array is a pretty straightforward task even for novice programmers.
But not when a crowd of angry zombies scratching your door, looking for a fresh brains.
In this case even skilled ninja-geek probably prefers to quickly push his code on github
to have enough time to find a chainsaw. So there's two obstacles:

Your code needs to be as short as possible, in fact not longer than 28 characters
Because you are scared and stressed you have forgotten how to use the standard reverse() method

Input: an array containing data of any types.
Ex: [1,2,3,'a','b','c',[]]
Output: [[],'c','b','a',3,2,1]

Tests
[1,2,3,4,5]
[2,4,6,8,10]
["pineapple", "pumpkin", "pear", "peach"]
*/

void reverseArr(vector<int>& arr){
	int low = 0, high = arr.size()-1;

	while(low < high){
		int temp = arr[low];
		arr[low++] = arr[high];
		arr[high--] = temp;
	}
}

void testFunc(vector<vector<int>> v){
	for(auto arr : v){
		reverseArr(arr);
		for(int i : arr)
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{1,2,3,4,5},
		{2,4,6,8,10}
	});
	return 0;
}