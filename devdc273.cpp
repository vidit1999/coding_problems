#include <bits/stdc++.h>
using namespace std;

/*
In this challenge, you will remove the left-most duplicates
from a list of integers and return the result.

// Remove the 3's at indices 0 and 3
// followed by removing a 4 at index 1
solve([3, 4, 4, 3, 6, 3]); // => [4, 6, 3]

Tests:
solve([3,4,4,3,6,3])
solve([1,2,1,2,1,2,3])
solve([1,1,4,5,1,2,1])
solve([1,2,1,2,1,1,3])
*/

vector<int> solve(vector<int> arr){
	unordered_set<int> unique;
	vector<int> ans;
	
	for(int i=arr.size()-1; i>=0; i--){
		if(unique.find(arr[i]) == unique.end()){
			ans.push_back(arr[i]);
			unique.insert(arr[i]);
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

void testFunc(vector<vector<int>> v){
	for(auto arr : v){
		for(int i : solve(arr))
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{3,4,4,3,6,3},
		{1,2,1,2,1,2,3},
		{1,1,4,5,1,2,1},
		{1,2,1,2,1,1,3},
	});
	return 0;
}