#include <bits/stdc++.h>
using namespace std;

/*
A number (n) of lamps are placed in a line, some are switched on and some are off.
Write a function that will return the smallest number of lamps that need to
be switched on or off so that the line of lamps alternate.

You are given an array of 0s and 1s as input. 1 means on, 0 means off.
Return the minimum number of switches needed.

Example
For a = [1, 0, 0, 1, 1, 1, 0], the result should be 3.
1 0 0 1 1 1 0 --> 0 1 0 1 0 1 0

Tests
lamps([1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1])

lamps( [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1])

lamps([1, 0, 1])

lamps([1, 0, 1, 0])

lamps([0, 1, 0, 1, 0])

lamps([1, 0, 1, 0, 0, 1, 0, 1])

lamps([1,0,0,1,1,0,0,0,0,1,0])
*/

int lamps(vector<int> line){
	// stores the number of lamps needed to switch on or off
	// for two cases respectively
	int startsWith0 = 0, startsWith1 = 0;
	
	for(int i=0;i<line.size();i++){
		if(line[i] == i%2)
			startsWith1++;
		else
			startsWith0++;
	}
		
	return min(startsWith0, startsWith1);
}

// main function
int main(){
	cout << lamps({1, 0, 0, 1, 1, 1, 0}) << "\n";
	cout << lamps({1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1}) << "\n";
	cout << lamps({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) << "\n";
	cout << lamps({1, 0, 1}) << "\n";
	cout << lamps({1, 0, 1, 0}) << "\n";
	cout << lamps({0, 1, 0, 1, 0}) << "\n";
	cout << lamps({1, 0, 1, 0, 0, 1, 0, 1}) << "\n";
	cout << lamps({1,0,0,1,1,0,0,0,0,1,0}) << "\n";
	return 0;
}