#include <bits/stdc++.h>
using namespace std;

/*
You are given three piles of casino chips: white, green and black chips in the form of an array. 
Each day you need exactly two chips of different colors to play at the casino.
You can chose any color, but you are not allowed to use two chips of the same
color in a single day.

You will be given an array representing the number of chips of each color and
your task is to return the maximum number of days you can play.

Examples:
solve([1,1,1]) = 1, because after you pick on day one, there will be only one chip left
solve([1,2,1] = 2, you can pick twice; you pick two chips on day one then on day two
solve([4,1,1]) = 2

Brute force is not the way to go here. Look for a simplifying mathematical approach.

Tests:
solve([8,1,4])
solve([7,4,10])
solve([12,12,12])
solve([1,23,2])
*/

int solve(vector<int> piles){
	int max_num = 0, sum = 0;
	
	for(int i : piles){
		max_num = max(i, max_num);
		sum += i;
	}
	
	return min(max_num, sum-max_num);
}

void testFunc(vector<vector<int>> v){
	for(auto piles : v){
		cout << solve(piles) << "\n";
	}
}

// main function
int main(){
	testFunc({
		{1,1,1},
		{1,2,1},
		{4,1,1},
		{8,1,4},
		{7,4,10},
		{12,12,12},
		{1,23,2},
	});
	return 0;
}