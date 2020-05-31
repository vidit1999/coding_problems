#include <bits/stdc++.h>
using namespace std;

/*
Imagine you have 8 coins of equal weight, except for one.
The odd one weighs less than the others because it is not made of pure gold.
How many iterations are needed to find this counterfeit coin using a two plate scale?

Write a function that represents this logic puzzle and returns the minimum
number of weightings it will take to measure n coins, without relying on luck at all.
It can help to think recursively.
*/

int minWeightings(int n){
	return floor(log2(n));
}

// main function
int main(){
	cout << minWeightings(9) << "\n";
	return 0;
}