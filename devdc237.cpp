#include <bits/stdc++.h>
using namespace std;

/*
Alice and Bob were on a holiday. Both of them took many pictures of the places they've been,
and now they want to show Charlie their entire collection.
However, Charlie doesn't like these gallery sessions, since the setting usually repeats.
He isn't fond of seeing the Eiffel tower 40 times in a row.
He tells them that he will only sit during the session if they only show the same setting at most N times.
Luckily, Alice and Bob are able to encode each setting as a number.
Can you help them to remove numbers such that their list contains each number only up to N times,
without changing the order?

Given a list lst and a number N, create a new list that contains each number
of lst at most N times without reordering. For example if N = 2,
and the input is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2],
drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times,
and then take 3, which leads to [1,2,3,1,2,3].

Examples
delete_nth([1,1,1,1],2) # return [1,1]
delete_nth([20,37,20,21],1) # return [20,37,21]

Tests
delete_nth([1,1,3,3,7,2,2,2,2]), N= 3
delete_nth([20,37,20,21]), N = 1
*/

vector<int> delete_nth(vector<int> arr, int occ){
	// stores the numbers and its corresponding count in answer vector
	unordered_map<int, int> numCount;
	// the answer vector
	vector<int> ans;
	
	// if count of any number is less than occ,
	// only then add it in ans
	for(int num : arr){
		if(numCount[num] < occ){
			ans.push_back(num);
			numCount[num]++;
		}
	}
	
	return ans;
}

// function for testing
void testFunc(vector<int> arr, int occ){
	for(int num : delete_nth(arr, occ))
		cout << num << " ";
	cout << "\n";
}

// main function
int main(){
	testFunc({1,1,1,1},2); // output -> 
	testFunc({20,37,20,21},1); // output -> 
	testFunc({1,1,3,3,7,2,2,2,2},3); // output -> 
	testFunc({20,37,20,21},1); // output -> 
	return 0;
}