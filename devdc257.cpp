#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer n, calculate the following sum:
n + n/2 + n/4 + n/8 + ...

All elements of the sum are the results of integer division.
Continue dividing the number until you reach a decimal (no decimals allowed in final answer).

Example
25 => 25 + 12 + 6 + 3 + 1 = 47

Tests
halvingSum(25)
halvingSum(127)
*/

int halvingSum(int n){
	int sum = 0;
	
	while(n > 0){
		sum += n;
		n /= 2;
	}
	
	return sum;
}

// main function
int main(){
	cout << halvingSum(25) << "\n";
	cout << halvingSum(127) << "\n";
	return 0;
}