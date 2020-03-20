#include <bits/stdc++.h>
using namespace std;

/*
Given a list lst and a number N, create a new list that contains each number in lst at most N times without reordering.

For example if N = 2, and the input is [1,2,3,1,2,1,2,3],
you take [1,2,3,1,2], skip the next 1 and 2 because this would lead to
those numbers being in the result more than N times. Finally, take 3, which leads to [1,2,3,1,2,3].

deleteNth([1,1,1,1],2) // return [1,1]

deleteNth([20,37,20,21],1) // return [20,37,21]

Tests
deleteNth([20,37,20,21], 1)
deleteNth([1,1,3,3,7,2,2,2,2], 3)
*/

vector<int> deleteNth(vector<int> numbers, int n){
	unordered_map<int, int> numCount; // stores the number and its corresponding count
	vector<int> result; // output vector
	
	for(int i : numbers){
		// if a number occurs less than n times then push it in the result vector
		// and increment its corresponding count by 1
		if(numCount[i] < n){
			result.push_back(i);
			numCount[i]++;
		}
	}
	
	// return the result vector
	return result;
}

// main function
int main(){
	vector<int> res = deleteNth({1,1,3,3,7,2,2,2,2},3);
	for(int i : res)
		cout << i << " ";
	cout << "\n";
	return 0;
}