#include <bits/stdc++.h>
using namespace std;

/*
Your task is to find all the elements of an array that are non consecutive.
A number is considered non consecutive if it is not exactly one larger than
the previous element in the array. The first element always gets a pass.

You should return the results as an array of objects with
two values i: and n: .

Example
For the the array [1,2,3,4,6,7,8,10], the result should be:
nconsecutive([1,2,3,4,6,7,8,10])
[
  {'i': 4, 'n': 6},
  {'i': 7, 'n': 15}
]

Tests
[6,7,8,9,11,12]
[100,101,102,112,113,114,129]
*/

vector<pair<int, int>> nconsecutive(vector<int> arr){
	vector<pair<int, int>> res;

	for(int i=1; i<arr.size(); i++){
		if(arr[i] != arr[i-1] + 1)
			res.push_back({i, arr[i]});
	}

	return res;
}

void testFunc(vector<vector<int>> v){
	for(auto arr : v){
		for(auto p : nconsecutive(arr)){
			cout << "{" << p.first << ", " << p.second << "} ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{1,2,3,4,6,7,8,15,16},
		{6,7,8,9,11,12},
		{100,101,102,112,113,114,129}
	});
	return 0;
}