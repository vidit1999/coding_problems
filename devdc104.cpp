#include <bits/stdc++.h>
using namespace std;

/*
Given an array with 50 indices, write a function that takes the array and a number n as
input and builds a matrix with n columns.
*/

void printColumn(int size, int n){
	for(int i=0;i<size;i++){
		cout << i;
		if((i+1)%n==0)
			cout << "\n";
		else
			cout << " ";
	}
}

// main function
int main(){
	printColumn(11,4);
	return 0;
}