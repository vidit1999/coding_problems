#include <bits/stdc++.h>
using namespace std;

/*
Given the following sequence, what is the number of total values for the odd terms of the sequence,
up to the n-th term. The number n will be given as a positive integer.

f(0) = 0
f(1) = 1
f(2) = 1
f(3) = 2
f(4) = 4;
f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5);

1 is the only value that will be duplicated in the sequence, it should only be counted once.

Examples:

countPentafib(5) => 1
because the terms up to 5 are: [0, 1, 1, 2, 4, 8], 1 is the only odd and is only counted once.

countPentafib(10) => 3
[1, 1, 31, 61] are each odd and should be counted.

countPentafib(15) => 5
[1, 1, 31, 61, 1793, 3525] are all odd and 1 is only counted once.
*/

void Pentabonacci(int arr[], int n){
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 4;
	
	for(int i=5;i<=n;i++)
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4] + arr[i-5];
}

int countPentafib(int n){
	int m = (n >= 4)? n : 4;
	int arr[m+1];
	Pentabonacci(arr, n);
	
	int oddCount = 0;
	for(int i=0;i<n;i++)
		if(arr[i]%2 == 1)
			oddCount++;
	
	return (n > 1)? --oddCount : oddCount;
}

// main function
int main(){
	cout << countPentafib(3) << "\n";
	cout << countPentafib(10) << "\n";
	cout << countPentafib(15) << "\n";
	return 0;
}