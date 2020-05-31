#include <bits/stdc++.h>
using namespace std;

/*
Write a function that takes an array of integers and a target number.

The function should find two different integers in the array that give
the target value when added together. Return the indices in a tuple
[e.g. (index1, index2)]. Some tests will have multiple solutions.

Test Cases
[1234,5678,9012], 14690
[1,2,3], 4
[2,2,3], 4
[5,10,15,20,25,30], 50
*/

vector<pair<int, int>> twoSum(vector<int> numbers, int sum){
	// stores the number with its corresponding indices
	unordered_map<int, unordered_set<int>> numIndex;
	vector<pair<int, int>> ans;
	
	for(int i=0;i<numbers.size();i++){
		if(sum != 2*numbers[i] && numIndex.find(sum - numbers[i]) != numIndex.end()){
			auto indices = numIndex[sum - numbers[i]];
			for(int index : indices)
				ans.push_back({i, index});
		}
		numIndex[numbers[i]].insert(i);
	}
	
	return ans;
}

void testFunc(vector<pair<vector<int>, int>> v){
	for(auto it : v){
		auto ans = twoSum(it.first, it.second);
		for(auto indices : ans)
			cout << "(" << indices.first << ", " << indices.second << ") ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{{1234,5678,9012}, 14690},
		{{1,2,3}, 4},
		{{2,2,3}, 4},
		{{5,10,15,20,25,30}, 50},
		{{2,1,2,3,1,1,3,2,3}, 4}
	});
	return 0;
}