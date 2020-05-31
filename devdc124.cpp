#include <bits/stdc++.h>
using namespace std;

/*
Write a function that will take a key of X and place it in the middle of Y repeated N times.

Rules:
If X cannot be placed in the middle, return X.
N will always be > 0.

Example:

X = 'A';
Y = '*';
N = 10;
Y repeated N times = '**********';
X in the middle of Y repeated N times = '*****A*****';
*/

string placeMiddle(char X, char Y, int N){
	if(N%2 != 0) return string(1, X);
	return string(N/2,Y) + X + string(N/2, Y);
}

// main function
int main(){
	cout << placeMiddle('A', '*', 10) << "\n";
	return 0;
}