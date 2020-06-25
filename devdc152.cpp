#include <bits/stdc++.h>
using namespace std;

/*
The strength of an even number is determined by the amount of times we can successfully
divide by 2 until we reach an odd number.

For example, if n = 12, then:
12 / 2 = 6
6 / 2 = 3
We have divided 12 in half twice and reached 3, so the strength of 12 is 2.

Given a closed interval [n, m], return the strongest even number in the interval.
If multiple solutions exist, return the smallest of the possible solutions.

Examples
for [1, 2], return 2. (1 has a strenght of 0; 2 has a strength of 1)
for [5, 10], return 8.

Tests
[48, 56]
[129, 193]

Good luck~!
*/

int getStrength(int number){
	int count = 0;
	while((number & 1) == 0){
		number >>= 1;
		count++;
	}
	return count;
}

int maxStrength(int a, int b){
	int numSt, maxSt = -1;
	for(int i=a;i<=b;i++){
		int strength = getStrength(i);
		if(maxSt < strength){
			maxSt = strength;
			numSt = i;
		}
	}
	return numSt;
}

// main function
int main(){
	cout << maxStrength(1, 2) << "\n";
	cout << maxStrength(5, 10) << "\n";
	cout << maxStrength(48, 56) << "\n";
	cout << maxStrength(129, 193) << "\n";
	cout << maxStrength(84, 109) << "\n";
	return 0;
}