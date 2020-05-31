#include <bits/stdc++.h>
using namespace std;

/*
Implement an algorithm which increases number and returns the result.
Start from number and increment by step as many times as iterations demands.
Input: number, iterations, step.

Example:
alg(2, 5, 10) => 2 + 10 + 10 + 10 + 10 + 10 = 52
alg(17, 3, 6) => 17 + 6 + 6 + 6 = 35

Tests:
alg(100, 5, 50)
alg(14, 20, 4)
*/

int alg(int number, int iterations, int step){
	return number + iterations*step;
}

// main function
int main(){
	cout << alg(2, 5, 10) << "\n";
	cout << alg(17, 3, 6) << "\n";
	cout << alg(100, 5, 50) << "\n";
	cout << alg(14, 20, 4) << "\n";
	return 0;
}